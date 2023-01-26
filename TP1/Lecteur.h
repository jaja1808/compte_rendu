#include <iostream>
#include <string>
#include <vector>
//#ifndef _LECTEUR
#define _LECTEUR
class Lecteur {
private:
     std::string _nom;
     std::string _prenom;
     std::string _idLecteur;
     std::vector<std::string> _idlivres;
public:
     Lecteur(std::string nom,std::string prenom,std::string idLecteur,std::vector<std::string> idlivres);
     Lecteur();
     std::string afficherNom();
     std::string afficherPrenom();
     std::string getidLecteur();
     std::vector<std::string> getidlivres();
     int  getVectorSize();
     void addlivres(std::string newid);
     void removelivres(std::string oldid);
     bool estEgal(Lecteur const& b) const ;
     friend bool operator==(Lecteur const& a, Lecteur const& b);
     friend std::ostream& operator<<(std::ostream& os, Lecteur const& L);

};     