#include "Point.h"

/*!
 * \file Point.h
 * \brief Classe Point
 * \author SEGOUAT Elias - HOUANG Lucas
 */

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe Point
  *
  * \param int x : abscisse
  * \param int y : ordonnée
  */
Point::Point(int x, int y): x(x), y(y){
}

/*!
 * \brief Constructeur
 *
 * Constructeur de la classe Point
 *
 */
Point::Point() : x(0), y(0){
}

/*!
 * \brief Setter Point abscisse
 *
 */
void Point::setX(int _x) {
	x = _x;
}

/*!
 * \brief Setter Point ordonnée
 *
 */
void Point::setY(int _y) {
	y = _y;
}

/*!
 * \brief Getter Point abscisse
 *
 */
int Point::getX()const {
	return x;
}

/*!
 * \brief Getter Point ordonnée
 *
 */
int Point::getY()const {
	return y;
}

/*!
 * \brief Donne la distance entre deux points
 *
 */
int Point::distance(const Point &p1) const {
	int dx = this->x - p1.x;
	int dy = this->y - p1.y;
	return (int)sqrt(dx*dx + dy * dy);
}

/*!
 * \brief Affiche un point
 *
 */
void Point::afficherPoint()const {
	cout << "Abscisse : " << this->x << endl;
	cout << "Ordonnee : " << this->y << endl;
}

/*!
 * \brief Translate un point
 *	Modifie les coordonnées d'un point
 */
void Point::translatation(int px, const int py) 
{
	x = x + px;
	y = y + py;
}

/*!
 * \brief Homothetie d'un point
 *	Agrandi ou diminue un point
 */
void Point::homothetie(double facteur)
{
	x = (int)(x * facteur);
	y = (int)(y * facteur);
}

/*!
 * \brief Rotation d'un point
 *	Rotation
 */
void Point::rotation(double angle, Point centre)
{
	double xP, yP;
	angle *= PI / 180;
	xP = this->getX() - centre.getX();
	yP = this->getY() - centre.getY();
	this->setX(round( xP * cos(angle) + yP * sin(angle) + centre.getX()));
	this ->setY(round( -xP * sin(angle) + yP * cos(angle) + centre.getY()));
}
