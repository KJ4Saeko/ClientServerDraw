#ifndef FORMEGEOMETRIQUE_H_
#define FORMEGEOMETRIQUE_H_
#pragma once

/*!
 * \file FormeGeometrique.h
 * \brief Classe Geometrique
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include <string>
#include <math.h>
#include "Point.h"
#include "Erreur.h"
#include <sstream>
#include "Communication.h"
#include <vector>
#include "Couleur.h"
#include <fstream>

using namespace std;

/*! \class FormeGeometrique
 * \brief Classe mère, regroupe les méthodes de calcul d'aire, transformation
 *
 */
class FormeGeometrique
{
private : 
	Couleur couleur; /*!< Couleur de la forme géometrique*/
public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe FormeGeometrique
	 *
	 * \param int couleur : couleur de la forme géométrique
	 */
	FormeGeometrique(int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe FormeGeometrique
	 */
	~FormeGeometrique();

	/*!
	 * \brief Dessine une forme
	 *
	 * Virtuel car redéfinie
	 */
	virtual string dessinerForme();

	/*!
	 * \brief Aire d'une forme géométrique
	 *	Virtual : redéfini dans les classes de forme géométrique
	 */
	virtual double aire() const = 0;

	/*!
	 * \brief Getter de la couleur
	 *
	 */
	const int getCouleur() const;

	/*!
	 * \brief Sauvegarde une forme dans un fichier texte (coordonnée, couleur et type de la forme)
	 *
	 */
	void sauvegarderForme();

	 /*!
	  * \brief Translatation d'une forme géométrique
	  *	Modifie les coordonnées d'une forme géométrique
	  */
	virtual void translatationF(int px, int py);

	/*!
	 * \brief Homothetie une forme géométrique
	 *	Agrandi ou diminue une forme géométrique
	 */
	virtual void homothetieF(double facteur);

	/*!
	 * \brief Rotation d'une forme géométrique
	 *	Rotation
	 */
	virtual void RotationF(int angle);

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors traité par le serveur java
	 */
	virtual operator string() const;

	/*!
	 * \brief operator <<
	 *	Redéfinition de l'opérateur <<
	 */
	friend ostream& operator<<(ostream& f, FormeGeometrique& obj);
};

#endif