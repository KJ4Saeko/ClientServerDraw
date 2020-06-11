/*!
 * \file Cercle.pp
 * \brief Classe Cercle
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "Cercle.h"

 /*! \class Cercle
  * \brief Classe fille de ConstruireForme representant un cercle, definit par son centre et son rayon
  * et qui permet d'envoyer des informations pour dessiner un cercle.
  */

/*!
 * \brief Constructeur
 *
 * Constructeur de la classe cercle
 *
 * \param Point A : centre du cercle
 * \param int rayon : rayon du cercle
 * \param int couleur : couleur du cercle
 */
Cercle::Cercle(Point A, int rayon, int couleur) : A(A), rayon(rayon), ConstruireForme(couleur) {}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe cercle
 */
Cercle::~Cercle() {}

/*!
 * \brief Getter Point cercle
 *	Getter du centre du cercle
 */
Point Cercle::getCentre() const
{
	return A;
}

/*!
 * \brief Getter rayon cercle
 *	Getter pour le rayon du cercle
 */
int Cercle::getRayon() const
{
	return rayon;
}

/*!
 * \brief Aire du cercle
 *	Calcul l'aire du cercle
 */
double Cercle::aire() const
{
	return PI * (rayon*rayon);
}

/*!
 * \brief Translate le cercle
 *	Modifie les coordonnees du centre du cercle
 * \param int px : abscisse a ajouter a l'abscisse du centre
 * \param int py : ordonnee a ajouter a l'ordonnee du centre
 */
void Cercle::translatationF(int px, int py)
{
	A.translatation(px, py);
}

/*!
 * \brief Homothetie du cercle
 *	Agrandi ou diminue le cercle en fonction du facteur != 0 (>1 <=> agrandir)
 * \param double facteur : quotient d'agrandissement
 */
void Cercle::homothetieF(double facteur)
{
	if(facteur != 0)
	rayon = (int)(getRayon() * fabs(facteur));
}

/*!
 * \brief operator string()
 *	Construit la chaine a envoyer au serveur java
 */
Cercle::operator string() const {

	ostringstream oss;
	oss << "Cercle :" << A.getX() << " " << A.getY() << " " << rayon << " " << getCouleur();

	string msg = oss.str();
	return msg;
}