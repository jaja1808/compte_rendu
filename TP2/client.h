#include "product.h"
#include <vector>
#include <iostream>

#ifndef _CLIENT
#define _CLIENT

class Client
{
private:
    /* data */

    std::string _name;
    std::string _prenom;
    std::string _id;
    std::vector <Product> _panier;

public:
  //constructor

    Client(std::string name = "jaja",
           std::string prenom = "Ja",
           std::string id ="Jajaja",
           std::vector <Product> panier = {});

    // getters 

    std::string getName() const;
    std::string getPrenom() const;
    std::string getId() const;
    std::vector<Product> getPanier() const;
    void displayPanier() const;

    //setters

    void setname(std::string name);
    void setprenom(std::string prenom);
    void setId(std::string id);
    void setPanier(std::vector<Product> panier);
    friend std::ostream& operator<<(std::ostream& os, const Client& c);

    //helpers

    void addPanier(Product& p, int quantity);
    void removePanier(std::string name);
    void delProductProd(Product& p,int qty);
    void emptyPanier();
    int countTheOccurance(std::string name);
    void changeProdQtyinPnr(std::string name, int qty);
    Product& findByName(std::string name);
};
 
 void getTheClient(Client& c);

#endif //_CLIENT