/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date juin 2018
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"

namespace TP1
{
 using namespace std;


// -------------------------------------------------------------------------------------------------
//	Méthodes fournies
// -------------------------------------------------------------------------------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
	int nbCols, nbRangs;

    if (!entree.is_open())
        throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

	entree >> nbCols >> nbRangs;
	entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

	for (int i = 0; i < nbCols; i++)
	{
		for (int j = 0; j < nbRangs; j++)
		{
			s << i << "," << j;
			Piece p(s.str());
			s.str("");
			ajoutePieceLabyrinthe(p);
		}
	}

	for (int i = 0; i < nbCols; i++)
	{
		if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeDepart(nom);
		}
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
				+ 1] == 'A' || ligne[i * 4 + 1] == 'a')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeArrivee(nom);
		}
	}

	for (int j = 0; j < nbRangs; j++)
	{
		entree.getline(ligne, MAX_LIGNE);

		for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
		{
			if (j & 1)
			{
				if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
						+ 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
						+ 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
						+ 1] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
			else
			{
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j + 1, i, j);
				}
				if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
						+ 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
						+ 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
						+ 3] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
		}
	}
}


/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */
void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
{

	NoeudListePieces *piece1, *piece2;
	string nomPiece1, nomPiece2;
	ostringstream s;

	s << i1 << "," << j1;
	nomPiece1 = s.str();

	s.str("");

	s << i2 << "," << j2;
	nomPiece2 = s.str();

	s.str("");

	piece1 = trouvePiece(nomPiece1);
	piece2 = trouvePiece(nomPiece2);

	Porte nouvellePorte(couleur, &(piece2->piece));

	piece1->piece.ajoutePorte(nouvellePorte);
}


/**
 * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
 * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
 * \param[in]	p La pièce à ajouter
 * \post	la pièce appartient au labyrinthe;
 */
    void Labyrinthe::ajoutePieceLabyrinthe(const Piece& p) {

        Labyrinthe::NoeudListePieces* noeud = new Labyrinthe::NoeudListePieces;
        noeud->piece = p;

        if (dernier == 0)
        {
            noeud->suivant = noeud;
            dernier = noeud;
        }
        else if (!appartient(p)) {
            noeud->suivant = dernier->suivant;
            dernier->suivant = noeud;
        }


    }

    /**
     * \brief Constructeur par défaut
     */
	Labyrinthe::Labyrinthe() {
        this->dernier = 0;
        this->arrivee = 0;
        this->depart = 0;
	}

    /**
     *  \brief Constructeur par copie
     * @param source L'objet Labyrinthe duquel la copie sera faite.
     */
	Labyrinthe::Labyrinthe(const Labyrinthe &source) {
        *this = source;
	}

    /**
     * \brief Destructeur
     */
	Labyrinthe::~Labyrinthe() {

        NoeudListePieces *noeudCourant = this->dernier;
        NoeudListePieces *noeudSupprimer;

        do{
            noeudSupprimer = noeudCourant;
            noeudCourant = noeudCourant->suivant;

            delete noeudSupprimer;

        } while(noeudCourant != this->dernier);

	}

    /**
     * \brief Surcharge de l'opérateur =
     * @param source L'objet Labyrinthe duquel la la copie sera faite.
     * @return Un objet Labyrinthe
     */
	const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source) {
		this->depart = source.depart;
        this->arrivee = source.arrivee;
        this->dernier = source.dernier;
	}


    /**
     * \brief Solutionne la labyrinthe pour un joueur
     * \param joueur Le joueur pour lequel on solutionne
     * \return Le nombre de déplacement requis pour atteindre la fin du labyrinthe. Retourne -1 si le labyrinthe ne peut
     * pas être résolu par ce joueur.
     */
	int Labyrinthe::solutionner(Couleur joueur) {

        //On va indiquer que chaque pièce n'est pas parcourue
        NoeudListePieces *noeudCourrant = this->dernier;
        do{
            noeudCourrant = noeudCourrant->suivant;
            noeudCourrant->piece.setParcourue(false);
            noeudCourrant->piece.setDistanceDuDebut(-1);

        }while(noeudCourrant != (this->dernier));

        queue<Piece*> file;
        file.push(this->depart);

        list<Porte>::const_iterator it;
        Piece* pieceCourrante;

        int compteur = 0;
        this->depart->setDistanceDuDebut(compteur);
        this->depart->setParcourue(true);

        while(!file.empty()){

            pieceCourrante = file.front();
            file.pop();

            for(it = pieceCourrante->getPortes().begin(); it != pieceCourrante->getPortes().end(); ++it){
                if(it->getDestination()->getParcourue() == false && it->getCouleur() == joueur){
                    it->getDestination()->setParcourue(true);
                    it->getDestination()->setDistanceDuDebut(pieceCourrante->getDistanceDuDebut() + 1);
                    file.push(it->getDestination());
                }
            }
        }

        return this->arrivee->getDistanceDuDebut();
	}

    /**
     * \brief Trouve le gagnant du labyrinthe (celui qui peut compléter le labyrinthe avec le moins de déplacements)
     * @return La Couleur (le joueur) qui peut compléter le labyrinthe en le moins de déplacements. En cas d'égalité, Rouge > Vert > Bleu > Jaune
     */
	Couleur Labyrinthe::trouveGagnant() {

        Couleur vainqueur = Aucun;

        int rouge = solutionner(Rouge);
        int vert = solutionner(Vert);
        int bleu = solutionner(Bleu);
        int jaune = solutionner(Jaune);

        int min = -1;

        if(jaune != -1){
            vainqueur = Jaune;
            min = jaune;
        }

        if(bleu != -1 && (bleu <= min || min == -1)){
            vainqueur = Bleu;
            min = bleu;
        }

        if(vert != -1 && (vert <= min || min == -1)){
            vainqueur = Vert;
            min = vert;
        }

        if(rouge != -1 && (rouge <= min || min == -1)){
            vainqueur = Rouge;
        }



        return vainqueur;
	}

    /**
     * \brief Vérifie si une pièce portant le nom de la pièce fournie se trouve dans le labyrinthe
     * \param p Une régérence vers la pièce que l'on recherche
     * \return Un booléen inquant si une pièce portant le nom de la pièce fournie  se trouve dans le labyrinthe
     */
	bool Labyrinthe::appartient(const Piece &p) const {


        try{

            this->trouvePiece(p.getNom());
            return true;
        }
        catch(logic_error) {
            return false;
        }


	}

    /**
     * \breif Définie la pièce de départ du labnyrinthe
     * @param nom Le nom de la pièce de départ
     */
	void Labyrinthe::placeDepart(const std::string &nom) {

        try{
            this->depart = &(this->trouvePiece(nom)->piece);
        }
        catch (logic_error ex){
            throw  logic_error(ex.what());
        }

	}

    /**
     * \breif Définie la pièce d'arrivée du labnyrinthe
     * @param nom Le nom de la pièce d'arrivée
     */
	void Labyrinthe::placeArrivee(const std::string &nom) {
        try{
            this->arrivee = &(this->trouvePiece(nom)->piece);
        }
        catch (logic_error ex){
            throw  logic_error(ex.what());
        }
	}

    /**
     * \brief Méthode privée. Retourne l'adresse du noeud de la liste de pièces contenue dans le labyrinthe
     * qui correspond à la pièce portant le nom nom, la méthode doit lancer une exception invalid_argument si le nom de
     * la pièce est vide. La méthode doit lancer également une exception logic_error si la pièce est introuvable.
     * Remarquez qu'il faut retourner l'adresse du noeud et non l'adresse de la pièce.
     * \param nom Chaêne de caractères de la pièce à trouver
     * \return L'objet NoeudListePieces de la pièce trouvée.
     */
	Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const std::string &nom) const {


		if(std::string(nom).empty()){
            throw invalid_argument("Le parametre nom ne doit pas être vide.");
        }

        NoeudListePieces *noeudCourrant = this->dernier;
        bool trouve = false;

        do{
            noeudCourrant = noeudCourrant->suivant;
            if((*noeudCourrant).piece.getNom() == nom){
                trouve = true;
                break;
            }
        }while(noeudCourrant != (this->dernier));

        if(!trouve){
            throw logic_error("Aucune pièce avec le nom " + nom + " n'a été trouvé.");
        }


        return noeudCourrant;
	}

}//fin du namespace
