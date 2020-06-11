#include "FormeGeometrique.h"

/*!
 * \file FormeGeometrique.h
 * \brief Classe Geometrique
 * \author SEGOUAT Elias - HOUANG Lucas
 */

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe FormeGeometrique
  *
  * \param int couleur : couleur de la forme géométrique
  */
FormeGeometrique::FormeGeometrique(int couleur) : couleur(Couleur(couleur)) {}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe FormeGeometrique
 */
FormeGeometrique::~FormeGeometrique() {}

/*!
 * \brief Dessine une forme
 *
 * Virtuel car redéfinie
 */
string FormeGeometrique::dessinerForme()
{
	Communication* flux = new Communication(ADRESSE_IP, PORT_SERVEUR);//Création du socket et de la connection

	string msg = (string)*this;

	flux->envoyer(msg.c_str());		//Envoie des points

	msg.assign(flux->recevoir());			//Réception de la réponse du serveur java

	delete (flux);		// Fermeture de la connexion et du socket							

	return msg;
}

/*!
 * \brief Getter de la couleur
 *
 */
const int FormeGeometrique::getCouleur() const
{
	return couleur.getCouleur();
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
FormeGeometrique::operator string() const{
	ostringstream oss;

	oss << "Forme geometrique :" << endl;
	string msg = oss.str();
	return msg;
}

/*!
 * \brief operator <<
 *	Redéfinition de l'opérateur <<
 */
ostream & operator<<(ostream & f, FormeGeometrique & obj)
{
	return f << (string)obj;
}

/*!
 * \brief Sauvegarde une forme dans un fichier texte (coordonnée, couleur et type de la forme)
 *
 */
void FormeGeometrique::sauvegarderForme()
{
	ofstream fichier("./Sauvegarde/sauvegardeForme.txt", std::ios_base::app);  // ouverture en écriture avec effacement du fichier ouvert

	if (fichier)
	{
		fichier << (string)*this << "\n";

		fichier.close();
		cout << "Sauvegarde reussi" << endl;
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}

/*!
 * \brief Translatation d'une forme géométrique
 *	Modifie les coordonnées d'une forme géométrique
 */
void FormeGeometrique::translatationF(int px, int py){}

/*!
 * \brief Homothetie une forme géométrique
 *	Agrandi ou diminue une forme géométrique
 */
void FormeGeometrique::homothetieF(double facteur){}

/*!
 * \brief Rotation d'une forme géométrique
 *	Rotation
 */
void FormeGeometrique::RotationF(int angle){}

