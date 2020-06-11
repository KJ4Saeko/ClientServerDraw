/*!
 * \file ConstruireFormeCompose.h
 * \brief Classe ConstruireFormeCompose
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "ConstruireFormeCompose.h"

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe ConstruireFormeCompose
  *
  * \param size_t nbForme
  * \param vector<FormeGeometrique*> listeForme
  */
ConstruireFormeCompose::ConstruireFormeCompose(size_t nbForme, vector<FormeGeometrique*> listeForme, int couleur) : FormeGeometrique(couleur), nbForme(nbForme), listeForme(listeForme)
{
	try {
		if (nbForme < 2) {
			throw Erreur("Pour constuire une forme composé il faut au moins 2 formes");
		}
		if (nbForme != listeForme.size()) {
			throw Erreur("Nombre de formes passe en parametre differents du nombre de formes dans la liste");
		}
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe ConstreireFormeCompose
 */
ConstruireFormeCompose::~ConstruireFormeCompose(){}

/*!
 * \brief Getter du nombre de forme
 *
 */
const size_t ConstruireFormeCompose::getNbForme() const{return nbForme;}

/*!
 * \brief Getter de la liste de forme géométrique contenu dans la forme composé
 *
 */
const vector<FormeGeometrique*> ConstruireFormeCompose::getListeForme() const{return listeForme;}

/*!
 * \brief Calcul l'aire de la forme composé
 *
 */
double ConstruireFormeCompose::aire() const
{
	int somme = 0;
	for (size_t i = 0; i < nbForme; i++) {
		somme += listeForme[i]->aire();
	}
	return (double)somme;
}

void ConstruireFormeCompose::RotationF(int angle) {
	for (size_t i = 0; i < nbForme; i++) {
		listeForme[i]->RotationF(angle);
	}
}

void ConstruireFormeCompose::TranslatationF(int px, int py){
	for (size_t i = 0; i < nbForme; i++) {
		listeForme[i]->translatationF(px, py);
	}
}

void ConstruireFormeCompose::HomotetieF(double facteur)
{
	for (size_t i = 0; i < nbForme; i++) {
		listeForme[i]->homothetieF(facteur);
	}
}

/*!
*  \brief Envoi les informations de la forme au serveur java
*
*/
string ConstruireFormeCompose::dessinerForme() {
	Communication* flux = new Communication(ADRESSE_IP, PORT_SERVEUR);//Création du socket et de la connection

	string msg = (string)*this;
	msg += "\n";

	flux->envoyer(msg.c_str());		//Envoie des points

	msg.assign(flux->recevoir());			//Réception de la réponse du serveur java

	delete (flux);		// Fermeture de la connexion et du socket							

	return msg;
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
ConstruireFormeCompose::operator string() const
{
	ostringstream oss;
	oss << "FormeCompose :" << nbForme << " " << getCouleur() << " ";
	for (size_t i = 0; i < nbForme; i++) {
		if (((string)*listeForme[i]).find("Polygone") != string::npos) {
			string t4 = ((string)*listeForme[i]).substr(10, ((string)*listeForme[i]).size()-12);
			oss << "," << ".... :" << t4 <<" ";
		}
		if (((string)*listeForme[i]).find("Triangle") != string::npos) {
			string t1 = ((string)*listeForme[i]).substr(10, ((string)*listeForme[i]).size()-12);
			oss << ","<< "... :"<< t1 << " ";
		}
		if (((string)*listeForme[i]).find("Segment") != string::npos) {
			string t2 = ((string)*listeForme[i]).substr(9, ((string)*listeForme[i]).size()-11);
			oss << "," << ".. :" << t2 << " ";
		}
		if (((string)*listeForme[i]).find("Cercle") != string::npos) {
			string t3 = ((string)*listeForme[i]).substr(8, ((string)*listeForme[i]).size()-10);
			oss << "," << ". :" << t3 << " ";
		}
	}
	string msg = oss.str();
	return msg;
}

