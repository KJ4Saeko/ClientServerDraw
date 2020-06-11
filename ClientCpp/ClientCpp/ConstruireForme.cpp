/*!
 * \file ConstruireForme.h
 * \brief Classe ConstruireForme
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "ConstruireForme.h"
#include "Communication.h"

 /*!
  * \brief Constructeur
  *
  * Constructeur de la classe ConstruireForme
  *
  * \param int couleur : couleur de la forme géometrique
  */
ConstruireForme::ConstruireForme(int couleur): FormeGeometrique(couleur){}

/*!
*  \brief Envoi les informations de la forme au serveur java
*
*/
string ConstruireForme::dessinerForme() {
	Communication* flux = new Communication(ADRESSE_IP, PORT_SERVEUR);//Création du socket et de la connection

	string msg = (string)*this;
	msg += "\n";

	flux->envoyer(msg.c_str());		//Envoie des points

	msg.assign(flux->recevoir());			//Réception de la réponse du serveur java

	delete (flux);		// Fermeture de la connexion et du socket							

	return msg;
}


