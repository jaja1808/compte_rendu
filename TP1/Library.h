#include <iostream>
#include <vector>
#include "book.h"
#include "Author.h"
#include "Lecteur.h"
#include "Emprunt.h"
#include "date.h"
#include <string>
class Library{
    private:
        std::vector<Book> _livres;
        std::vector<Lecteur> _lecteurs;
        std::vector<Author> _auteurs;
        std::vector<Emprunt> _emprunts;
        std::vector<std::string> _isbn;
    public:
        Library()=default;
        void addLivre(std::string titre, std::string nom,
                  std::string prenom, std::string id, std::string langue,
                  std::string type,Date publication,std::string isbn,
                  Date datedenaissance,std::vector <std::string> list);
        void afficherLivres();
        bool livreEstPresent(Book const& l);
        void EmprunterLivre(std::string idlivre,std::string idlecteur);

        void addLecteur(std::string nom, std::string prenom,std::string idLecteur,std::vector<std::string> idlivres);
        bool lecteurEstPresent(Lecteur const& x);
        void afficherLecteurs();
        //void afficherLivresLecteur(std::string titrelivre,std::string idLecteur);
    

        void addAuteur(std::string id,std::string nom, std::string prenom,Date datedenaissance);
        bool auteurEstPresent(Author const& x);
        void afficherAuteur();
        void restituerlivre(std::string idLecteur,std::string idLivre);
        void afficherLivresAuteur();
        void pourcentageEmprunt();
        //void classementLecteurs();
};   

