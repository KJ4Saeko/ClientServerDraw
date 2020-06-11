#ifndef CONSTRUIREFORME_H_
#define CONSTRUIREFORME_H_
#pragma once
/*!
 * \file ConstruireForme.h
 * \brief Classe ConstruireForme
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "FormeGeometrique.h"

using namespace std;

/*! \class ConstruireForme
 * \brief Classe abstraite qui représente une forme géométrique simple. Elle est envoyé au serveur qui la dessinera par la suite
 *
 */
class ConstruireForme : public FormeGeometrique{
public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe ConstruireForme
	 *
	 * \param int couleur : couleur de la forme géometrique
	 */
	ConstruireForme(int couleur);

	/*!
	*  \brief Envoi les informations de la forme au serveur java
	*
	*/
	string dessinerForme();
};

#endif
