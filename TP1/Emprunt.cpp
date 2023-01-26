#include <string.h>
#include "Emprunt.h"
#include <iostream>
using namespace std;
    Emprunt::Emprunt(std::string isbn):
            _isbn(isbn),_idLecteur("0"),_status(false){

    }
    Emprunt::Emprunt(std::string isbn,std::string idLecteur,bool status):
            _isbn(isbn),_idLecteur(idLecteur),_status(status){}
    string Emprunt::getidLecteur(){
        return _idLecteur;
    }
    bool Emprunt::getstatus(){
        return _status;
    }
    Date Emprunt::getdatedemprunt(){
        return _datedemprunt;
    }
    string Emprunt::getisbn(){
        return _isbn;
    }
    void Emprunt::rendre(){
        _status=false;
        _idLecteur="0";
    }
     void Emprunt::emprunter(std::string idLecteur){
        _status=true;
        _idLecteur=idLecteur;
     }
     ostream& operator<<(ostream& os, Emprunt const& E)
    {
       if(E._status==false)
       {
         os << "Le livre n'a pas ete emprunter";
       }
       else
       {
        os << "Emprunter par " << E._idLecteur;
       }
      return os;
    }
