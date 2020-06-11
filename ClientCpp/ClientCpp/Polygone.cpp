#include "Polygone.h"

/*!
 * \file Polygone.h
 * \brief Classe Polygone
 * \author SEGOUAT Elias - HOUANG Lucas
 */

using namespace std;

/*!
 * \brief Constructeur
 *
 * Constructeur de la classe polygone
 *
 * \param size_t nbPoints : nombre de points
 * \param vector <Point>listePoint : liste des points
 * \param int couleur : couleur du polygone
 */
Polygone::Polygone(size_t nbPoints, vector<Point> listePoint, int couleur) : ConstruireForme(couleur), nbPoints(nbPoints), listePoint(listePoint)
{
	try {
		if (nbPoints < 3) {
			throw Erreur("Nombre de points insuffisant pour un polygone");
		}
		
		if (nbPoints != listePoint.size()) {
			throw Erreur("Nombre de points passe en parametre differents du nombre de points dans la liste");
		}
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}

}

/*!
 * \brief Destructeur
 *
 * Destructeur de la classe polygone
 *
 */
Polygone::~Polygone() {}

 /*!
  * \brief Getter Nombre de points du polygone
  *
  */
const size_t Polygone::getNbPoints() const
{
	return nbPoints;
}

/*!
 * \brief Getter Liste des points du polygone
 *
 */
const vector<Point> Polygone::getListePoint() const
{
	return listePoint;
}

/*!
 * \brief operator string()
 *	Forme le message qui sera alors traité par le serveur java
 */
Polygone::operator string() const
{
	ostringstream oss;
	oss << "Polygone :" << nbPoints;
	for (unsigned int i = 0; i < nbPoints; i++) {
		oss << " " << listePoint[i].getX() << " " << listePoint[i].getY();
	}
	oss << " " << getCouleur();

	string msg = oss.str();
	return msg;
}

/*!
 * \brief Aire du polygone
 *	Calcul l'aire du polygone
 */
double Polygone::aire() const
{
	double aire = 0;
	for (size_t i = 0; i < nbPoints-1; i++) {
		aire += (listePoint[i].getX() * listePoint[i+1].getY() - listePoint[i+1].getX()*listePoint[i].getY());
	}
	aire += (listePoint.back().getX() * listePoint[0].getY() - listePoint[0].getX()*listePoint.back().getY());
	return abs(aire / 2);
}

/*!
 * \brief Translate le polygone
 *	Modifie les coordonnées du centre du polygone
 */
void Polygone::translatationF(int px, int py)
{
	for (size_t i = 0; i < nbPoints; i++) {
		listePoint[i].translatation(px, py);
	}
}

/*!
 * \brief Homothetie du polygone
 *	Agrandi ou diminue le polygone
 */
void Polygone::homothetieF(double facteur)
{
	for (size_t i = 0; i < nbPoints; i++) {
		listePoint[i].homothetie(facteur);
	}
}

/*!
 * \brief Rotation d'un polygone
 *	Rotation
 */
void Polygone::RotationF(int angle)
{
	int centreX = 0;
	int centreY = 0;
	for (size_t i = 0; i < nbPoints; i++) {
		centreX += listePoint[i].getX();
		centreY += listePoint[i].getY();
	}
	centreX = centreX / nbPoints;
	centreY = centreY / nbPoints;
	Point centre(centreX, centreY);
	for (size_t i = 0; i < nbPoints; i++) {
		listePoint[i].rotation(angle, centre);
	}
}
