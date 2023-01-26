#include "order.h"
#include <iostream>

#ifndef _STORE
#define _STORE

class Store
{
private:
    /* data */
    std::string _name;
    std::vector <Product> _products;
    std::vector <Client> _clients;
    std::vector <Order> _orders;

public:
    Store( std::string name = "",std::vector <Product> products = {Product ()},
           std::vector <Client> clients = {Client ()},
           std::vector <Order> orders = {Order ()});

     //getters

     void displayClients ();
     void displayProducts();
     void dispalyOrders();
     void displayThisClient(std::string Id);
     void displayThisProduct(std::string name);
     void displayOrderOfclient(std::string Id);
     std::string getStoreName();
     std::vector<Product> getProductsList();
     std::vector<Client> getClientsList();
     std::vector<Order> getOrdersList();

     //setters

     void setStoreName(std::string name);

     //adding and creating new
     void addClients(Client& c);
     void newClientInStore(  std::string name,std::string prenom,std::string Id,std::string nameProd,int qty);
     void newProdInStore( std::string name,std::string Descr,float cost,int quant);
     void newOrderLinkPanier(std::string Id);
     void newOrderNewPr(std::string name,std::string Id);
     void addProducts(Product& p);
     void addOrders(Order& o);

     //order changes
     void validateOrder(std::string Id);
     void changeStOrd(std::string Id,std::string stat);

     //getters
     Product& getProduct(std::string name);
     Client& getClient(std::string Id);
     Order &getOrderByClntId(std::string Id);

     //manipulation different options in the store
     void changeAvailablePct(std::string name, int availlable);
     void addPctToCntPnr(std::string Id,std::string name,int qty);
     void removePctToCntPnr(std::string Id,std::string name);
     void changeqtyPctInCntPnr(std::string Id,std::string name, int quantity);

     //removers
     void removeClient(std::string Id);
     void removeProduct(std::string name);
     void removeOrder(std::string Id);

     //Deleting all 
     void emptyProducts();
     void emptyClients();
     void emptyOrders();

     //checking the Id of the client
     bool checkIdClients(std::string Id);
     bool checkProdName(std::string name);
};


#endif //_STORE