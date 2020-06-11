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
 * \brief Classe m�re, regroupe les m�thodes de calcul d'aire, transformation
 *
 */
class FormeGeometrique
{
private : 
	Couleur couleur; /*!< Couleur de la forme g�ometrique*/
public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe FormeGeometrique
	 *
	 * \param int couleur : couleur de la forme g�om�trique
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
	 * Virtuel car red�finie
	 */
	virtual string dessinerForme();

	/*!
	 * \brief Aire d'une forme g�om�trique
	 *	Virtual : red�fini dans les classes de forme g�om�trique
	 */
	virtual double aire() const = 0;

	/*!
	 * \brief Getter de la couleur
	 *
	 */
	const int getCouleur() const;

	/*!
	 * \brief Sauvegarde une forme dans un fichier texte (coordonn�e, couleur et type de la forme)
	 *
	 */
	void sauvegarderForme();

	 /*!
	  * \brief Translatation d'une forme g�om�trique
	  *	Modifie les coordonn�es d'une forme g�om�trique
	  */
	virtual void translatationF(int px, int py);

	/*!
	 * \brief Homothetie une forme g�om�trique
	 *	Agrandi ou diminue une forme g�om�trique
	 */
	virtual void homothetieF(double facteur);

	/*!
	 * \brief Rotation d'une forme g�om�trique
	 *	Rotation
	 */
	virtual void RotationF(int angle);

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors trait� par le serveur java
	 */
	virtual operator string() const;

	/*!
	 * \brief operator <<
	 *	Red�finition de l'op�rateur <<
	 */
	friend ostream& operator<<(ostream& f, FormeGeometrique& obj);
};

#endif