#ifndef POLYGONE_H_
#define POLYGONE_H_
#pragma once

/*!
 * \file Polygone.h
 * \brief Classe Polygone
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include "ConstruireForme.h"
#include <vector>


using namespace std;

/*! \class Polygone
 * \brief Classe représentant un polygone, définit par son son nombre de points et une liste de points
 *
 * Classe fille de DessinerForme, permet d'envoyer des informations pour dessiner un polygone.
 */
class Polygone : public ConstruireForme {
private:
	
	size_t nbPoints; /*!< nombre de points du polygone*/
	vector <Point> listePoint; /*!< liste de points du polygone*/

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe polygone
	 *
	 * \param size_t nbPoints : nombre de points
	 * \param vector <Point>listePoint : liste des points
	 * \param int couleur : couleur du polygone
	 */
	Polygone(size_t nbPoints, vector <Point>listePoint, int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe polygone
	 *
	 */
	~Polygone();

	/*!
	 * \brief Getter Nombre de points du polygone
	 * 
	 */
	const size_t getNbPoints() const;

	/*!
	 * \brief Getter Liste des points du polygone
	 *
	 */
	const vector<Point> getListePoint() const;

	/*!
	 * \brief Aire du polygone
	 *	Calcul l'aire du polygone
	 */
	double aire() const;

	/*!
	 * \brief Translate le polygone
	 *	Modifie les coordonnées du centre du polygone
	 */
	void translatationF(int px, int py);

	/*!
	 * \brief Homothetie du polygone
	 *	Agrandi ou diminue le polygone
	 */
	void homothetieF(double facteur);

	/*!
	 * \brief Rotation d'un polygone
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