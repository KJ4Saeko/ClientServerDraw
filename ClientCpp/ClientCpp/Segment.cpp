/*!
 * \file Segment.h
 * \brief Classe Segment
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "Segment.h"

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe Segment
  *
  * \param Point A, B : points du segment
  */
Segment::Segment(Point A, Point B , int couleur) : ConstruireForme(couleur), A(A), B(B) {}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe Segment
 *
 */
Segment::~Segment(){}

/*!
 * \brief Aire du Segment
 *	Calcul l'aire du Segment
 */
double Segment::aire() const
{
	return 0;
}

/*!
 * \brief Translate le Segment
 *	Modifie les coordonnées du centre du Segment
 */
void Segment::translatationF(int px, int py)
{
	A.translatation(px, py);
	B.translatation(px, py);
}

/*!
 * \brief Homothetie du Segment
 *	Agrandi ou diminue le Segment
 */
void Segment::homothetieF(double facteur)
{
	A.homothetie(facteur);
	B.homothetie(facteur);
}

/*!
 * \brief Rotation d'un Segment
 *	Rotation
 */
void Segment::rotationF(int angle)
{
	int sTx = (A.getX() + B.getX()) / 2;
	int sTy = (A.getY() + B.getY()) / 2;
	Point centre(sTx, sTy);
	A.rotation(angle, centre);
	B.rotation(angle, centre);
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
Segment::operator string() const {
	ostringstream oss;
	oss << "Segment :" << A.getX() << " " << A.getY() << " " << B.getX() << " " << B.getY() << " " << getCouleur();

	string msg = oss.str();
	return msg;
}