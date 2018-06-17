/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date juin 2018
 *
 */

#include "Piece.h"
#include "iostream"

namespace TP1
{

	//Mettez l'implémentation de vos méthodes ici.

    /**
     * \brief Constructeur par défaut
     */
    Piece::Piece() {

    }

    /**
     * \brief Constructeur avec affectation du nom à la pièce
     * @param s Le nom de la pièce
     */
    Piece::Piece(const std::string &s) : nom(s) {
    }

    /**
     * \brief Constructeur de copie
     * @param source L'objet Piece de laquelle effectuée la copie
     */
    Piece::Piece(const Piece &source) {
        *this = source;
    }

    /**
     * \brief Surcharge de l'opérateur =
     * @param source L'objet Piece de laquelle effectuée l'assignation
     * @return Objet Piece
     */
    const Piece &Piece::operator=(const Piece &source) {
        this->nom = source.nom;
        this->distanceDuDebut = source.distanceDuDebut;
        this->parcourue = source.parcourue;
        this->portes = source.portes;
    }

    /**
     * \brief Accesseur du nom
     * @return Le nom de la pièce
     */
    std::string Piece::getNom() const {
        return this->nom;
    }

    /**
     * \brief Pour initialiser l'attribut parcourue à true ou false
     * @param p True ou False
     */
    void Piece::setParcourue(bool p) {
        this->parcourue = p;
    }

    /**
     * \brief Pour initialiser l'attribut distanceDuDebut
     * @param d La distance parcourue
     */
    void Piece::setDistanceDuDebut(int d) {
        this->distanceDuDebut = d;
    }

    /**
     * \brief Accesseur de l'attribut parcourue
     * @return Un booleen indiquant si la pièce a été parourue
     */
    bool Piece::getParcourue() const {
        return this->parcourue;
    }


    /**
     * \brief Accesseur de l'attribut portes
     * @return La liste des portes de la pièce
     */
    const std::list<Porte> &Piece::getPortes() const {
        return this->portes;
    }

    /**
     * \brief Acceseur de l'attribut distanceDuDebut
     * @return Un entier indiquant le nombre de déplacement pour se rencdre à cette pièce depuis la pièce "début"
     */
    int Piece::getDistanceDuDebut() const {
        return this->distanceDuDebut;
    }

    /**
     * \brief Ajouter une porte à la pièce
     * @param p Une reference vers la porte à ajouter
     */
    void Piece::ajoutePorte(const Porte &p) {

        //On fait certain  qu'une porte de cette couleur ne mèmne pas déjà à cette destination
        for(std::list<Porte>::iterator it = portes.begin(); it != portes.end(); ++it){
            if(*it == p)
                return;
        }

        this->portes.push_back(p);

        //On ajoute la même porte, mais "à sens inverse"
        //ToDo : Pas optimal... on double le nom de porte. Autre solution ?
        Porte porteInverse(p.getCouleur(), this);
        p.getDestination()->ajoutePorte(porteInverse);
    }


    /**
     * \brief Destructeur
     */
    Piece::~Piece() {

    }

}
