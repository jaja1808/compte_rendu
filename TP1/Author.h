#include <iostream>
#include "date.h"
#include <string>
#ifndef _AUTHOR
#define _AUTHOR
class Author {
private:
    std::string _id;
    std::string _nom;
    std::string _prenom;
    Date _datedenaissance;
public:
    Author(std::string id,std::string nom,std::string prenom,Date datedenaissance);
    Author();
    void afficherAuthor();
    std::string getId();
    std::string nom();
    std::string prenom();
    friend bool operator==(Author const& a, Author const& b);
    friend std::ostream& operator<<(std::ostream& os, Author const& A);
};
#endif //AUTHOR_H
