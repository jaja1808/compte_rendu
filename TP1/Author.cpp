#include "Author.h"
#include<iostream>
using namespace std;
    Author::Author(std::string id,std::string nom,std::string prenom,Date datedenaissance):
      _id(id),_nom(nom),_prenom(prenom),_datedenaissance(datedenaissance){
    };
    Author::Author():
      _id("1234567"),_nom("hugo"),_prenom("victor"),_datedenaissance(10,12,2018){

    };
    void Author::afficherAuthor(){
      cout<<_nom<<" "<<_prenom;
     }
    std::string Author::nom() {
     return _nom;    
    }
    std::string Author::prenom(){
      return _prenom;
    }
    std::string Author::getId(){
      return _id;
    }
    bool operator==(Author const& a, Author const& b)
    {
    if (a._nom==b._nom && a._prenom==b._prenom) 
    {
        return true;
    }
    return false;
    }
    ostream& operator<<(ostream& os, Author const& A)
    {
       os << A._nom << " " << A._prenom << " " << A._id;
       return os;
    }
