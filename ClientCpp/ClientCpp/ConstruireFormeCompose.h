#ifndef CONSTRUIREFORMECOMPOSE_H_
#define CONSTRUIREFORMECOMPOSE_H_
#pragma once
/*!
 * \file ConstruireFormeCompose.h
 * \brief Classe ConstruireFormeCompose
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "FormeGeometrique.h"

 /*! \class ConstruireFormeCompose
  * \brief Classe abstraite qui représente une forme géométrique compose. Elle est envoyé au serveur qui la dessinera par la suite
  *
  */
class ConstruireFormeCompose : public FormeGeometrique
{
private:

	size_t nbForme; /*!< Nombre de formes de la forme composé*/
	vector <FormeGeometrique*> listeForme; /*!< vecteur de forme géométrique qui compose la forme composé*/

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe ConstruireFormeCompose
	 *
	 * \param size_t nbForme
	 * \param vector<FormeGeometrique*> listeForme
	 */
	ConstruireFormeCompose(size_t nbForme, vector<FormeGeometrique*> listeForme, int couleur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe ConstreireFormeCompose
	 */
	~ConstruireFormeCompose();

	/*!
	 * \brief Getter du nombre de forme
	 *
	 */
	const size_t getNbForme() const;

	/*!
	 * \brief Getter de la liste de forme géométrique contenu dans la forme composé
	 *
	 */
	const vector<FormeGeometrique*> getListeForme() const;

	/*!
	 * \brief Calcul l'aire de la forme composé
	 *
	 */
	double aire() const;

	/*!
	*  \brief Envoi les informations de la forme au serveur java
	*
	*/
	string dessinerForme();

	/*!
	 * \brief operator string()
	 *	Forme le message qui sera alors traite par le serveur java
	 */
	operator string () const;

	void RotationF(int angle);
	void TranslatationF(int px, int py);
	void HomotetieF(double facteur);
};

#endif