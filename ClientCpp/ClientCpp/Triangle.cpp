/*!
 * \file Triangle.h
 * \brief Classe Triangle
 * \author SEGOUAT Elias - HOUANG Lucas
 */

#include "Triangle.h"

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe Triangle
  *
  * \param Point A, B : points du Triangle
  */
Triangle::Triangle(Point A, Point B, Point C, int couleur) : ConstruireForme(couleur), A(A), B(B), C(C){}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe Triangle
 *
 */
Triangle::~Triangle(){}

/*!
 * \brief Aire du Triangle
 *	Calcul l'aire du Triangle
 */
double Triangle::aire() const
{
	return 0.5 * fabs(((B.getX() - A.getX()) *
		(C.getY() - A.getY())) -
		((C.getX() - A.getX()) * (B.getY() - A.getY())));
}

/*!
 * \brief Translate le Triangle
 *	Modifie les coordonnées du centre du Triangle
 */
void Triangle::translatationF(int px, int py)
{
	A.translatation(px, py);
	B.translatation(px, py);
	C.translatation(px, py);
}

/*!
 * \brief Homothetie du Triangle
 *	Agrandi ou diminue le Triangle
 */
void Triangle::homothetieF(double facteur)
{
	A.homothetie(facteur);
	B.homothetie(facteur);
	C.homothetie(facteur);
}

/*!
 * \brief Rotation d'un Triangle
 *	Rotation
 */
void Triangle::RotationF(int angle) { // Fonctionne que pour un Angle supérieur ou égal à 180
	int cTx = (A.getX() + B.getX() + C.getX()) / 3;
	int cTy = (A.getY() + B.getY() + C.getY()) / 3;
	Point centre(cTx, cTy);
	A.rotation(angle, centre);
	B.rotation(angle, centre);
	C.rotation(angle, centre);
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
Triangle::operator string() const
{
	ostringstream oss;
	oss << "Triangle :" << A.getX() << " " << A.getY() << " " << B.getX() << " " << B.getY() << " " << C.getX() << " " << C.getY() << " " << getCouleur();

	string msg = oss.str();
	return msg;
}

