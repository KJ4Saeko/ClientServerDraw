/*!
 * \file Couleur.h
 * \brief Classe Couleur
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "Couleur.h"

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe couleur
  *
  */
Couleur::Couleur(){}

/*!
 * \brief Constructeur
 *
 * Constructeur de la classe couleur
 *
 * \param int couleur
 */
Couleur::Couleur(int couleur) : couleur(couleur)
{
	try {
		if (couleur < 0 || couleur > 5) {
			throw Erreur("Cette couleur n'est pas reconnue");
		}
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe couleur
 */
Couleur::~Couleur(){}

/*!
 * \brief Getter couleur
 *	retourne la couleur
 */
const int Couleur::getCouleur() const
{
	return couleur;
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
Couleur::operator string() const
{
	ostringstream oss;

	oss << getCouleur();

	string msg = oss.str();
	return msg;
}

/*!
 * \brief operator <<
 *	Redéfinition de l'opérateur <<
 */
ostream & operator<<(ostream & f, const Couleur & obj) 
{
	return f << (string)obj;
}
