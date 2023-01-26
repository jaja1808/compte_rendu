
#include <string.h>
#include <vector>
#include "Lecteur.h"
#include <iostream>
using namespace std;
    Lecteur::Lecteur(std::string nom,std::string prenom,std::string idLecteur,std::vector<std::string> idlivres):
                _nom(nom),_prenom(prenom),_idLecteur(idLecteur),_idlivres(idlivres){

    }
    Lecteur::Lecteur():_nom("Labnihi"),_prenom("mehdi"),_idLecteur("LABNIHI"),_idlivres({" "}){

    }
    std::string Lecteur::afficherNom(){
        return _nom;
    }
    std::string Lecteur::afficherPrenom(){
       return _prenom;
    }
    std::string Lecteur::getidLecteur(){
        return _idLecteur;
    }
    vector<std::string> Lecteur::getidlivres(){
        return _idlivres;
    }
    int Lecteur::getVectorSize(){
        return _idlivres.size();
    }
    void Lecteur::addlivres(std::string newid){
        _idlivres.push_back(newid);
    }
    void Lecteur::removelivres(std::string oldid){
        for(int i=0;i<_idlivres.size();i++)
        {
            if(_idlivres[i]==oldid)
            {
                _idlivres.erase(_idlivres.begin()+i);
            }
        }
    }
    bool operator==(Lecteur const& a, Lecteur const& b)
    {
        return a.estEgal(b);
    }
    bool Lecteur::estEgal(Lecteur const& b) const
    {
        return (_nom==b._nom && _prenom==b._prenom && _idLecteur==b._idLecteur );
    }
    ostream& operator<<(std::ostream& os, Lecteur const& L)
    {
      os << L._nom << " " << L._prenom << " " << "id:" << L._idLecteur;
      return os;
    }