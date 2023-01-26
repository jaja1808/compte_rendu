#include "Library.h"
#include<iostream>
using namespace std;
    void Library::addLivre(std::string titre, std::string nom,
        std::string prenom, std::string id, std::string langue,
         std::string type,Date publication,std::string isbn,
         Date datedenaissance,std::vector <std::string> list){
            Book b(titre,nom,prenom,id,langue,type,publication,isbn,datedenaissance,list);
             _livres.push_back(b);
    }
    void Library::afficherLivres(){
        std::cout<<(int)_livres.size()<<std::endl;
        
        for (int i=0 ; i<(int)_livres.size() ; i++)
        {
            cout << i+1 << ": ";
            std::cout<<_livres[i].afficherTitre() << std::endl;
           
        }
    }
    bool Library::livreEstPresent(Book const& l){
        for (int i=0 ; i<(int)_livres.size() ; i++)
        {
            if (_livres[i]==l)
            {
                cout<<"le livre est present dans la bibliotheque"<<endl;
                return true;
            
            }
        }
        _livres.push_back(l);
         cout << "Le livre a bien ete ajoute a la bibliotheque" << endl;
         return false;      
    }
    void Library::EmprunterLivre(string idlivre,string idlecteur)
    {
        for(int i=0;i<(int)_livres.size();i++)
        {
            if(_livres[i].getISBN()==idlivre)
            {
               //_livres.erase(i);
               break;
            }
        }
        for (int i=0 ; i<(int)_lecteurs.size() ; i++)
        {
            if (_lecteurs[i].getidLecteur()==idlecteur)
            {
                _lecteurs[i].addlivres(idlivre);
            }
        }
            
    }
    void Library::addLecteur(std::string nom, std::string prenom,std::string idLecteur,std::vector<std::string> idlivres){
        Lecteur L(nom,prenom,idLecteur,idlivres);
           _lecteurs.push_back(L);

    }
    bool Library::lecteurEstPresent(Lecteur const& l){
         for (int i=0 ; i<(int)_lecteurs.size() ; i++)
        {
            if (_lecteurs[i]==l)
            {
                cout<<"le lecteur est present "<<endl;
                return true;
            
            }
        }
        _lecteurs.push_back(l);
        cout << "Le nouveau lecteur a bien ete ajoute a la bibliotheque" << endl;
        return false;
        
    }
    void Library::afficherLecteurs(){
        cout<<_lecteurs.size()<<endl;
        for(int i=0;i<(int)_lecteurs.size();i++)
        {
           cout<<_lecteurs[i].afficherNom() << " ";
           cout<<_lecteurs[i].afficherPrenom()<<endl;
        }
    }
    void Library::addAuteur(std::string id,std::string nom, std::string prenom,Date datedenaissance){
        Author a(id,nom,prenom,datedenaissance);
         _auteurs.push_back(a);
    }
    bool Library::auteurEstPresent(Author const& l){
         for (int i=0 ; i<(int)_auteurs.size() ; i++)
        {
            if (_auteurs[i]==l)
            {
                cout<<"l'auteur est present "<<endl;
                return true;
            
            }
        }
        _auteurs.push_back(l);
        cout << "Le nouveau auteur a bien ete ajoute a la bibliotheque" << endl;
        return false;          
        
    }
    void Library::afficherAuteur(){
        cout<<_auteurs.size()<<endl;
        for(int i=0;i<(int)_auteurs.size();i++)
        {
           cout<<_auteurs[i].nom() << " ";
           cout<<_auteurs[i].prenom()<<endl;
        }
    }
    void Library::afficherLivresAuteur(){
        string nomAuteur;
        string prenomAuteur;
        cout << "Saisisez le nom de l'auteur ";
        getline(cin,nomAuteur);
        cout << "Saisisez le prenom de l'auteur ";
        getline(cin,prenomAuteur);
        cout << "L'auteur " << nomAuteur <<" "<< prenomAuteur << " a ecrit:" << endl;
        for(int i=0; i<(int)_livres.size() ;i++)
        {
            if(_livres[i].getNomAuthor()==nomAuteur && _livres[i].getPrenomAuthor()==prenomAuteur)
            {
                cout << i+1 << ": "  ;
                cout<<_livres[i].afficherTitre();
                cout<<endl;
            }
        }
    }
    void Library::restituerlivre(std::string idLecteur,std::string idLivre){
        for (int i=0 ; i<(int)_livres.size() ; i++)
        {
          if(_livres[i].getLecteur()==idLecteur)
         {
             cout << "Le livre";
             cout<<_livres[i].afficherTitre();
             cout << "emprunter par " << idLecteur << " a bien ete restitue" << endl;
              _livres[i].rendreLivre();
              for (int i=0 ; i<(int)_lecteurs.size() ; i++)
              {
                if(_lecteurs[i].getidLecteur()==idLecteur)
                {
                  _lecteurs[i].removelivres(idLivre);
                }
              }
         }
        } 
        cout << "Vous n'etes pas la personne qui a emprunter le livre" << endl;   
    }
    /*void Library::afficherLivresLecteur(string titrelivre,string idLecteur)
    {
          cout << "Les livres empruntes par " << idLecteur << " sont:" << endl;
          for(int i=0;i<(int) _livres.size();i++)
          {
              if (_livres[i].getLecteur==idLecteur)
             {
                cout<<_livres[i].afficherTitre();
             } 
          }
    }*/

    void Library::pourcentageEmprunt()
    {
    int j=0;
    for(int i=0;i<(int)_livres.size();i++)
    {
        if(_livres[i].estEmprunter())
        {
            cout << i+1 << ": ";
            _livres[i].afficherTitre();
            cout << endl;
            j+=1;
        }
    }
    cout << j << " livres sont empruntes, cela represente " << (j*100)/_livres.size() << "% des livres" << endl;
    }

 