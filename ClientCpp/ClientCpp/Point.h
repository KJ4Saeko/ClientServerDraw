#ifndef POINT_H_
#define POINT_H_
#pragma once

/*!
 * \file Point.h
 * \brief Classe Point
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include <cmath>
#include <math.h>

const double PI = 3.14159265358979323846;

using namespace std;

/*! \class Point
 * \brief Classe représentant un Point, définit par son abscisse et son ordonnée
 *
 */
class Point{
private:
	int x; /*!< Abscisse*/
	int y; /*!< Ordonnée*/

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Point
	 *
	 */
	Point();

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Point
	 *
	 * \param int x : abscisse
	 * \param int y : ordonnée
	 */
	Point(int x, int y);

	/*!
	 * \brief Getter Point abscisse
	 *
	 */
	int getX() const;

	/*!
	 * \brief Getter Point ordonnée
	 *
	 */
	int getY() const;

	/*!
	 * \brief Setter Point abscisse
	 *
	 */
	void setY(int y);

	/*!
	 * \brief Setter Point ordonnée
	 *
	 */
	void setX(int x);

	/*!
	 * \brief Donne la distance entre deux points
	 *
	 */
	int distance(const Point &p1) const;

	/*!
	 * \brief Affiche un point
	 *
	 */
	void afficherPoint() const;

	/*!
	 * \brief Translate un point
	 *	Modifie les coordonnées d'un point
	 */
	void translatation(int px, int py);

	/*!
	 * \brief Homothetie d'un point
	 *	Agrandi ou diminue un point
	 */
	void homothetie(double facteur);

	/*!
	 * \brief Rotation d'un point
	 *	Rotation
	 */
	void rotation(double angle, Point centre);
};

#endif