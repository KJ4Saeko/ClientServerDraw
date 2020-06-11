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
  * \param int couleur : couleur de la forme g�ometrique
  */
ConstruireForme::ConstruireForme(int couleur): FormeGeometrique(couleur){}

/*!
*  \brief Envoi les informations de la forme au serveur java
*
*/
string ConstruireForme::dessinerForme() {
	Communication* flux = new Communication(ADRESSE_IP, PORT_SERVEUR);//Cr�ation du socket et de la connection

	string msg = (string)*this;
	msg += "\n";

	flux->envoyer(msg.c_str());		//Envoie des points

	msg.assign(flux->recevoir());			//R�ception de la r�ponse du serveur java

	delete (flux);		// Fermeture de la connexion et du socket							

	return msg;
}


