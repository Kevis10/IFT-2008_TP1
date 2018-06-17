/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main pour tester le labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date mai 2018
 * 
 */

#include "Labyrinthe.h"

using namespace std;
using namespace TP1;

int main()
{
	try
	{
		Labyrinthe lab;

		ifstream entree;
		entree.open("data/rouge2x3.txt", ios::in);
		if (!entree.is_open())
		{
			cout << "Fichier rouge introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Rouge, entree);
		cout << "\nLabyrinthe rouge chargé.\n";
		entree.close(); //on ferme le fichier

		entree.open("data/vert2x3.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier vert introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Vert, entree);
		cout << "\nLabyrinthe vert chargé.\n";
		entree.close();

		entree.open("data/bleu2x3.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier bleu introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Bleu, entree);
		cout << "\nLabyrinthe bleu chargé.\n";
		entree.close();

		entree.open("data/jaune2x3.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier jaune introuvable.\n\n";
			return 1;
		}

		lab.chargeLabyrinthe(Jaune, entree);
		cout << "\nLabyrinthe jaune chargé.\n";
		entree.close();

		cout << "\nLe joueur rouge peut solutionner le labyrinthe en "
				<< lab.solutionner(Rouge) << " déplacements.\n";
		cout << "\nLe joueur vert peut solutionner le labyrinthe en "
				<< lab.solutionner(Vert) << " déplacements.\n";
		cout << "\nLe joueur bleu peut solutionner le labyrinthe en "
				<< lab.solutionner(Bleu) << " déplacements.\n";
		cout << "\nLe joueur jaune peut solutionner le labyrinthe en "
				<< lab.solutionner(Jaune) << " déplacements.\n";

		Couleur LeGagnant = lab.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "Le joueur gagnant: Rouge" << endl << endl; break;
		case 1:
			cout << endl << "Le joueur gagnant: Vert" << endl << endl; break;
		case 2:
			cout << endl << "Le joueur gagnant: Bleu" << endl << endl; break;
		case 3:
			cout << endl << "Le joueur gagnant: Jaune" << endl << endl; break;
		default:
			cout << endl << "Le joueur gagnant: aucun!!" << endl << endl; break;
		}

	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}
	cout << "Labyrinthe 10x10 :" << endl;
	try
	{
		Labyrinthe lab2;

        ifstream entree;

		entree.open("data/rouge10x10.txt", ios::in);

        if (!entree.is_open())
		{
			cout << "Fichier rouge introuvable.\n";
			return 1;
		}

		lab2.chargeLabyrinthe(Rouge, entree);
		cout << "\nLabyrinthe rouge chargé.\n";
		entree.close(); //on ferme le fichier

		entree.open("data/vert10x10.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier vert introuvable.\n";
			return 1;
		}

		lab2.chargeLabyrinthe(Vert, entree);
		cout << "\nLabyrinthe vert chargé.\n";
		entree.close();

		entree.open("data/bleu10x10.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier bleu introuvable.\n";
			return 1;
		}

		lab2.chargeLabyrinthe(Bleu, entree);
		cout << "\nLabyrinthe bleu chargé.\n";
		entree.close();

		entree.open("data/jaune10x10.txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier jaune introuvable.\n\n";
			return 1;
		}

		lab2.chargeLabyrinthe(Jaune, entree);
		cout << "\nLabyrinthe jaune chargé.\n";
		entree.close();

		cout << "\nLe joueur rouge peut solutionner le labyrinthe en "
				<< lab2.solutionner(Rouge) << " déplacements.\n";
		cout << "\nLe joueur vert peut solutionner le labyrinthe en "
				<< lab2.solutionner(Vert) << " déplacements.\n";
		cout << "\nLe joueur bleu peut solutionner le labyrinthe en "
				<< lab2.solutionner(Bleu) << " déplacements.\n";
		cout << "\nLe joueur jaune peut solutionner le labyrinthe en "
				<< lab2.solutionner(Jaune) << " déplacements.\n";

		Couleur LeGagnant = lab2.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "Le joueur gagnant: Rouge" << endl << endl; break;
		case 1:
			cout << endl << "Le joueur gagnant: Vert" << endl << endl; break;
		case 2:
			cout << endl << "Le joueur gagnant: Bleu" << endl << endl; break;
		case 3:
			cout << endl << "Le joueur gagnant: Jaune" << endl << endl; break;
		default:
			cout << endl << "Le joueur gagnant: aucun!!" << endl << endl; break;
		}



	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
