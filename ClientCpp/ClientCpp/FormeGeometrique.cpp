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
  * \param int couleur : couleur de la forme g�om�trique
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
 * Virtuel car red�finie
 */
string FormeGeometrique::dessinerForme()
{
	Communication* flux = new Communication(ADRESSE_IP, PORT_SERVEUR);//Cr�ation du socket et de la connection

	string msg = (string)*this;

	flux->envoyer(msg.c_str());		//Envoie des points

	msg.assign(flux->recevoir());			//R�ception de la r�ponse du serveur java

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
 *	Forme le message qui sera alors trait� par le serveur java
 */
FormeGeometrique::operator string() const{
	ostringstream oss;

	oss << "Forme geometrique :" << endl;
	string msg = oss.str();
	return msg;
}

/*!
 * \brief operator <<
 *	Red�finition de l'op�rateur <<
 */
ostream & operator<<(ostream & f, FormeGeometrique & obj)
{
	return f << (string)obj;
}

/*!
 * \brief Sauvegarde une forme dans un fichier texte (coordonn�e, couleur et type de la forme)
 *
 */
void FormeGeometrique::sauvegarderForme()
{
	ofstream fichier("./Sauvegarde/sauvegardeForme.txt", std::ios_base::app);  // ouverture en �criture avec effacement du fichier ouvert

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
 * \brief Translatation d'une forme g�om�trique
 *	Modifie les coordonn�es d'une forme g�om�trique
 */
void FormeGeometrique::translatationF(int px, int py){}

/*!
 * \brief Homothetie une forme g�om�trique
 *	Agrandi ou diminue une forme g�om�trique
 */
void FormeGeometrique::homothetieF(double facteur){}

/*!
 * \brief Rotation d'une forme g�om�trique
 *	Rotation
 */
void FormeGeometrique::RotationF(int angle){}

