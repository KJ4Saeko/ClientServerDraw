#ifndef SEGMENT_H_
#define SEGMENT_H_
#pragma once

/*!
 * \file Segment.h
 * \brief Classe Segment
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include "ConstruireForme.h"

using namespace std;

/*! \class Segment
 * \brief Classe représentant un Segment, définit par son son nombre de points et une liste de points
 *
 * Classe fille de DessinerForme, permet d'envoyer des informations pour dessiner un Segment.
 */
class Segment : public ConstruireForme {

private:
	Point A, B; /*!< Points du segments*/
public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Segment
	 *
	 * \param Point A, B : points du segment
	 */
	Segment(Point A, Point B, int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe Segment
	 *
	 */
	~Segment();

	/*!
	 * \brief Aire du Segment
	 *	Calcul l'aire du Segment
	 */
	double aire() const;

	/*!
	 * \brief Translate le Segment
	 *	Modifie les coordonnées du centre du Segment
	 */
	void translatationF(int px, int py);

	/*!
	 * \brief Homothetie du Segment
	 *	Agrandi ou diminue le Segment
	 */
	void homothetieF(double facteur);

	/*!
	 * \brief Rotation d'un Segment
	 *	Rotation
	 */
	void rotationF(int angle);

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors traité par le serveur java
	 */
	operator string() const;
};

#endif
