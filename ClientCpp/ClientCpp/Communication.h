#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
#pragma once

/*!
 * \file Communication.h
 * \brief Classe Communication
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "Erreur.h" 

using namespace std;

#define ADRESSE_IP "192.168.56.1" 
#define PORT_SERVEUR 8000

const static int L = 400; // Taille maximale de la reponse

/*! \class Communication
 * \brief Classe Communication, communique avec le seveur java
 *
 * Classe permettant la connection a un socket distant avec l'adresse ip ainsi qu'avec un port predefini
 */

class Communication {
private:
	SOCKET sock; /*!< Socket */

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Communication
	 *
	 * \param char* AdresseIP
	 * \param short portServeur : port sur lequel on se connecte
	 */
	Communication(const char* adresseIP, short portServeur);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe communication
	 */
	~Communication();
	
	/*!
	 * \brief initialisation des ressources librairie winsock
	 *	
	 */
	void init() const;

	/*!
	 * \brief Fermeture du socket
	 *
	 * Coupe la connexion apres l'envoi et la reception
	 */
	void close() const;
		
	/*!
	 * \brief Permet d'envoyer un message au serveur java
	 * \param char* message
	 */
	void envoyer(const char* message) const;

	/*!
	 * \brief Recuperation du message du serveur java
	 *
	 */
	string recevoir() const;

};

#endif