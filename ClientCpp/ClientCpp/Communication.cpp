/*!
 * \file Communication.h
 * \brief Classe Communication
 * \author SEGOUAT Elias - HOUANG Lucas
 */
#include "Communication.h"

#pragma comment(lib, "ws2_32.lib") // specifique a VISUAL C++
#pragma warning (disable : 4996)


using namespace std;

// Si les DLL sont ouvertes ou non
static int active = 0;

/*!
 * \brief Constructeur
 *
 * Constructeur de la classe Communication
 *
 * \param char* AdresseIP
 * \param short portServeur : port sur lequel on se connecte
 */
Communication::Communication(const char* adresseIP, const short portServeur) {

	try {

		//On ouvre les dll qu'une seule fois
		if (!active) {
			this->init(); 
		}

		
		//Création du socket
		int familleAdresses = AF_INET;			// IPv4
		int typeSocket = SOCK_STREAM;           // mode connecté TCP
		int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
												// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

		sock = socket(familleAdresses, typeSocket, protocole);

		if (sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
			throw Erreur(oss.str().c_str());
		}

		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(adresseIP);		// inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

		//-------------- connexion du client au serveur ---------------------------------------

		int r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																		// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

		if (r == SOCKET_ERROR)
			throw Erreur("La connexion a échoué");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe communication
 */
Communication::~Communication() {}

/*!
 * \brief initialisation ressources librairie winsock
 *
 */
void Communication::init() const {

	try {
		//-------------- initialisation ressources librairie winsock -------------------------------

		WSADATA wsaData; //TODO structure contenant les données de la librairie winsock à initialiser

		int r;

		r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

		/* en cas de succes, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

		if (r) throw Erreur("L'initialisation a échoué");

		active = 1;

	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Fermeture du socket
 *
 * Coupe la connexion apres l'envoi et la reception
 */
void Communication::close() const {

	try {

		int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
																// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
		if (r == SOCKET_ERROR)
			throw Erreur("la coupure de connexion a échoué");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
		if (r) throw Erreur("La fermeture du socket a échoué");

		WSACleanup();

		active = 0;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Permet d'envoyer un message au serveur java
 * \param char* message
 *
 */
void Communication::envoyer(const char* message) const {

	try {

		int l = strlen(message);
		int r = send(sock, message, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
														// envoie au plus  l octets
		if (r == SOCKET_ERROR)
			throw Erreur("échec de l'envoi de la requête");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

/*!
 * \brief Récupération du message du serveur java
 *
 */
string Communication::recevoir() const {

	char reponse[L];

	try {

		int r = recv(sock, reponse, L, 0);             //----------- réception de la réponse du serveur -----------------------------
													// reçoit au plus L octets
													// en cas de succès, r contient le nombre d'octets reçus
		if (r == SOCKET_ERROR)
			throw Erreur("La réception de la réponse a échoué");

		char * p = strchr(reponse, '\n');
		*(p + 1) = '\0';
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
	string msg(reponse);
	return msg;
}