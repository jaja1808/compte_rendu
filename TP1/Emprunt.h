#include <string.h>
#include "date.h"
#ifndef _EMPRUNT
#define _EMPRUNT
class Emprunt {
private:
    Date _datedemprunt;
    std::string _isbn;
    std::string _idLecteur;
    bool _status;
public:
    Emprunt(std::string isbn);
    Emprunt(std::string isbn,std::string idLecteur,bool status);
    std::string getidLecteur();
    void rendre();
    void emprunter(std::string idLecteur);
    Date getdatedemprunt();
    bool getstatus();
    std::string getisbn();
    friend std::ostream& operator<<(std::ostream& os,Emprunt const& E);
       
};

#endif //Emprunt