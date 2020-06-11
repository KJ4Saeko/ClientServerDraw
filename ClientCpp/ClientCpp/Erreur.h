#ifndef ERREUR_H_
#define ERREUR_H_
#pragma once

/*!
 * \file Erreur.h
 * \brief Classe Erreur
 * \author SEGOUAT Elias - HOUANG Lucas
 */
using namespace std;

#include <string>
#include <iostream>

/*! \class Erreur
 * \brief Classe permettera de gérer les potentiels erreurs
 *
 */
class Erreur
{
public:
	const static int LONGUEURMESSAGE = 100;
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	Erreur(const char * messageErreur);

	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);

#endif