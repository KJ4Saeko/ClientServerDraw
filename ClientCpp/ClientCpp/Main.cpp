/**
 * \file Main.c
 * \brief Programme de gestion de forme Géométrique
 * \author SEGOUAT Elias - HOUANG Lucas
 *
 * Programme de gestion de forme géométrique C++, avec un server de dessin JAVA
 *
 */

#include <iostream>
#include "Cercle.h"
#include "Segment.h"
#include "Point.h"
#include "Triangle.h"
#include "Polygone.h"
#include "ConstruireFormeCompose.h"

using namespace std;

int main()
{
	try
	{
		int black = 0;
		int blue = 1;
		int red = 2;
		int green = 3;
		int yellow = 4;
		int cyan = 5;

		Point A(1, 0);
		Point B(4, -2);
		Point C(4, 2);
		Point D(7, 0); //Centre Cercle
		Point E(11, -1);
		Point F(15, -1);
		Point G(15, 1);
		Point H(11, 1);
		Point I(17, 0); //Centre Cercle 2

		//Polygone
		vector <Point> listePoint {E, F, G, H}; //Points polygone
		double d = A.distance(B);
		double aire;

		Triangle T1 = Triangle(A, B, C, green);
		Cercle C1 = Cercle(D, 2, yellow);
		Polygone R1 = Polygone(4, listePoint, blue);
		Cercle C2 = Cercle(I, 1, yellow);

		FormeGeometrique *f1 = new Triangle(A, B, C, green);
		FormeGeometrique *f2 = new Cercle(D, 2, yellow);
		FormeGeometrique *f3 = new Polygone(4, listePoint, blue);
		FormeGeometrique *f4 = new Cercle(I, 1, yellow);
		vector <FormeGeometrique*> listeForme{f1, f2, f3, f4};

		ConstruireFormeCompose G1 = ConstruireFormeCompose(4, listeForme, red);

		T1.translatationF(7, 7);
		C1.translatationF(50, 50);
		R1.translatationF(7, 7);
		C2.translatationF(50, 50);

		G1.RotationF(90);
		aire = G1.aire();
		cout << "Aire de la forme composee : " << G1.aire() << endl;
		G1.TranslatationF(-4, 0);
		G1.TranslatationF(8, 8);
		G1.HomotetieF(50);

		T1.homothetieF(50);
		C1.homothetieF(50);
		R1.homothetieF(50);
		C2.homothetieF(50);

		
		cout << "Forme 1 : " << (string)T1 << endl;
		cout << "Forme 2 : " << (string)C1 << endl;
		cout << "Forme 3 : " << (string)R1 << endl;
		cout << "Forme 4 : " << (string)C2 << endl;
		cout << "Forme 5 : " << (string)G1 << endl;

		G1.sauvegarderForme();
		
		

		//cout << T1.dessinerForme();
		//cout << C1.dessinerForme();
		//cout << R1.dessinerForme();
		//cout << C2.dessinerForme();
		cout << G1.dessinerForme();

	}
	catch (Erreur e)
	{
		cerr << e << endl;
	}
	char ch;
	cin >> ch;

	return 0;
}