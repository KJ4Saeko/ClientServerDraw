#ifndef CERCLE_H_
#define CERCLE_H_
#pragma once

/*!
 * \file Cercle.h
 * \brief Classe Cercle
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include "ConstruireForme.h"

using namespace std;

/*! \class Cercle
 * \brief Classe fille de ConstruireForme representant un cercle, definit par son centre et son rayon
 * et qui permet d'envoyer des informations pour dessiner un cercle.
 */
class Cercle : public ConstruireForme {
private:
	
	Point A; /*!< Centre (Point) du cercle*/
	int rayon; /*!< Rayon (int) du cercle*/

public:
	
	/*! 
	 * \brief Constructeur
	 *
	 * Constructeur de la classe cercle 
	 *
	 * \param Point A : centre du cercle 
	 * \param int rayon : rayon du cercle 
	 * \param int couleur : couleur du cercle
	 */
	Cercle(Point A, int rayon, int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe cercle
	 */
	~Cercle();

	/*!
	 * \brief Getter Point cercle
	 *	Getter du centre du cercle
	 */
	Point getCentre() const;

	/*!
	 * \brief Getter rayon cercle
	 *	Getter pour le rayon du cercle
	 */
	int getRayon() const;

	/*!
	 * \brief Aire du cercle
	 *	Calcul l'aire du cercle
	 */
	double aire() const;

	/*!
	 * \brief Translate le cercle
	 *	Modifie les coordonnees du centre du cercle
	 * \param int px : abscisse a ajouter a l'abscisse du centre
	 * \param int py : ordonnee a ajouter a l'ordonnee du centre
	 */
	void translatationF(int px, int py);

	/*!
	 * \brief Homothetie du cercle
	 *	Agrandi ou diminue le cercle en fonction du facteur != 0 (>1 <=> agrandir)
	 * \param double facteur : quotient d'agrandissement
	 */
	void homothetieF(double facteur);

	/*!
	 * \brief operator string()
	 *	Construit la chaine a envoyer au serveur java
	 */
	operator string() const;
};

#endif