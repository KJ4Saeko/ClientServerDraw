#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#pragma once

/*!
 * \file Triangle.h
 * \brief Classe Triangle
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include "ConstruireForme.h"

using namespace std;

/*! \class Triangle
 * \brief Classe représentant un Triangle, définit par son son nombre de points et une liste de points
 *
 * Classe fille de DessinerForme, permet d'envoyer des informations pour dessiner un Triangle.
 */
class Triangle : public ConstruireForme {
private:

	Point A, B, C; /*!< Points du Triangle*/

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Triangle
	 *
	 * \param Point A, B : points du Triangle
	 */
	Triangle(Point A, Point B, Point C, int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe Triangle
	 *
	 */
	~Triangle();

	/*!
	 * \brief Aire du Triangle
	 *	Calcul l'aire du Triangle
	 */
	double aire() const;

	/*!
	 * \brief Translate le Triangle
	 *	Modifie les coordonnées du centre du Triangle
	 */
	void translatationF(int px, int py);

	/*!
	 * \brief Homothetie du Triangle
	 *	Agrandi ou diminue le Triangle
	 */
	void homothetieF(double facteur);

	/*!
	 * \brief Rotation d'un Triangle
	 *	Rotation
	 */
	void RotationF(int angle);

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors traité par le serveur java
	 */
	operator string() const;
};

#endif