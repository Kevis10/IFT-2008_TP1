/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Étudiant(e)
 * \version 0.1
 * \date juin 2018
 *
 */

#include "Porte.h"

namespace TP1
{

	//Mettez l'implémentation de vos méthodes ici.


    /**
     * \brief Constructeur par défaut
     */
    Porte::Porte() {

    }

    /**
     * \brief Constructeur avec initialisation de la couleur et la destination de la porte
     * @param c La Couleur du joueur qui peut passer par cette porte
     * @param d La destination de la porte
     */
    Porte::Porte(Couleur c, Piece *d) : color(c), destination(d) {

    }

    /**
     * \brief Permet d'initialiser l'attribut destination
     * @param destination Un pointeur vers la pièce de destination
     */
    void Porte::setDestination(Piece *destination) {
        this->destination = destination;
    }

    /**
     * \brief Constructeur par copie
     * @param source L'objet Porte duquel la copie sera effectuée
     */
    Porte::Porte(const Porte &source) {
        *this = source;
    }

    /**
     * \brief Destructeur
     */
    Porte::~Porte() {

    }

    /**
     * \brief Surcharge de l'opérateur =
     * @param source L'objet Porte duquel l'assignation sera effectuée
     * @return Un objet Porte
     */
    const Porte &Porte::operator=(const Porte &source) {
        this->color = source.getCouleur();
        this->destination = source.getDestination();
    }

    /**
     * \brief Surcharge de l'opérateur ==
     * @param source L'objet Porte avec lequel nous voulons comparer
     * @return Booléen indiquant si les deux objets sont identiques
     */
    bool Porte::operator==(const Porte &source) const {
        return this->getDestination() == source.getDestination() &&
                this->getCouleur() == source.getCouleur();
    }

    /**
     * \brief Accesseur de l'attribut couleur
     * @return La Couleur de la porte
     */
    Couleur Porte::getCouleur() const {
        return this->color;
    }

    /**
     * \brief Accesseur de l'attribut destination
     * @return La pièce de destination de la porte
     */
    Piece *Porte::getDestination() const {
        return this->destination;
    }



}
