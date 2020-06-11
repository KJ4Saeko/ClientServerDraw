#ifndef COULEUR_H_
#define COULEUR_H_
#pragma once

/*!
 * \file Couleur.h
 * \brief Classe Couleur
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Erreur.h"

using namespace std;

/*! \class Couleur
 * \brief Donne une couleur a une forme geometrique
 *
 */
class Couleur
{
private : 

	enum couleurs { /*!< Couleur disponible*/
		black = 0,
		blue = 1,
		red = 2,
		green = 3,
		yellow = 4,
		cyan = 5,
	};

	int couleur;

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe couleur
	 *
	 */
	Couleur();

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe couleur
	 *
	 * \param int couleur
	 */
	Couleur(int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe couleur
	 */
	~Couleur();

	/*!
	 * \brief Getter couleur 
	 *	retourne la couleur 
	 */
	const int getCouleur() const;

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors traité par le serveur java
	 */
	operator string() const;

	/*!
	 * \brief operator << 
	 *	Redéfinition de l'opérateur << 
	 */
	friend ostream& operator<<(ostream& f, const Couleur& obj);
};

#endif