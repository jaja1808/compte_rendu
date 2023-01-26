#include "client.h"
#include <iostream>

#ifndef _ORDER
#define _ORDER

enum Status{
    Delivered, Not_Delivered
};

class Order{

private:

    /* data */
    Client _client;
    std::vector <Product> _chosenProducts;
    Status _status;

public:

    Order( Client client = Client (),
           std::vector <Product> chosenProducts = {Product ()},
           Status status = Not_Delivered );

   //getters

   Client getClient() const;
   std::string getClientId() const;
   void displayClient();
   friend std::ostream& operator<<(std::ostream& os, const Order& o);
   void displayProductList();
   void getStatus() const;

   // setters

   void setStatus(std::string stat);
   void linkProducts();
   void addProducts(Product &p);
   void removeProducts(std::string name);
   void addProductsFromPanier(std::string name);
   void validOrder();
   void setClient(Client& c);
   Product& findProductByName(std::string name);
};

// bool isValidOrder(Order o);
// void displayOrders(Order o);

#endif //_ORDER