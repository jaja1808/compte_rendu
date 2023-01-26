#include "store.h"
#include "order.h"
#include "client.h"
#include "product.h"
#include <vector>
#include <iostream>
#include <algorithm>


//constructor

Store::Store(std::string name,std::vector<Product> products, std::vector<Client> clients, std::vector<Order> orders):
              _name(name),_products(products),_clients(clients),_orders(orders){
}

//getters

void Store::displayClients(){
     for(auto it = _clients.begin() ; it != _clients.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::displayProducts(){
     for(auto it = _products.begin() ; it != _products.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::dispalyOrders(){
     for(auto it = _orders.begin() ; it != _orders.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::displayThisClient(std::string Id){
    std::cout << getClient(Id) << std::endl;
}

void Store::displayThisProduct(std::string name){
    std::cout << getProduct(name) << std::endl;
}

void Store::displayOrderOfclient(std::string Id){
    std::cout << getOrderByClntId(Id) << std::endl;
}

std::string Store::getStoreName(){
    return _name;
}

std::vector<Product> Store::getProductsList(){
    return _products;
}

std::vector<Client> Store::getClientsList(){
    return _clients;
}

std::vector<Order> Store::getOrdersList(){
    return _orders;
}

//setters

void Store::setStoreName(std::string name){
    _name = name;
}

void Store::addClients(Client& c){
    _clients.push_back(c);
}

void Store::newClientInStore(std::string name, std::string prenom, std::string Id, std::string nameProd,int qty){
    Client c;
    c.setname(name);
    c.setprenom(prenom);
    c.setId(Id);
    addPctToCntPnr(Id,nameProd,qty);
    addClients(c);
}

void Store::newProdInStore(std::string name, std::string Descr, float cost, int quant){
     Product p;
    p.setTitle(name);
    p.setDescr(Descr);
    p.setAvailable(quant);
    p.setAmount(cost);
    addProducts(p);
}

void Store::newOrderLinkPanier(std::string Id){
    Order o;
    o.setClient(getClient(Id));
    o.linkProducts();
    addOrders(o);
}

void Store::newOrderNewPr(std::string name, std::string Id){
    Order o;
    o.setClient(getClient(Id));
    o.addProducts(getProduct(name));
    addOrders(o);
}

void Store::addProducts(Product& p){
    _products.push_back(p);
}

void Store::addOrders(Order& o){
    _orders.push_back(o);
}

void Store::validateOrder(std::string Id){
    getOrderByClntId(Id).validOrder();
}

void Store::changeStOrd(std::string Id, std::string stat){
    getOrderByClntId(Id).setStatus(stat);
}

Product& Store::getProduct(std::string name){
    auto it = std::find_if(_products.begin(), _products.end(), 
    [&name](const Product& p){return p.getTitle() == name;});
    return *it;
}

Client& Store::getClient(std::string Id){
    auto it = std::find_if(_clients.begin(), _clients.end(), 
    [&Id](const Client& p){return p.getId() == Id;});
    return *it;
}

Order &Store::getOrderByClntId(std::string Id){
  // TODO: insert return statement here
  auto it = std::find_if(_orders.begin(), _orders.end(), [&Id](const Order &o)
    { return o.getClient().getId() == Id; });
  return *it;
}

void Store::changeAvailablePct(std::string name, int available){
  getProduct(name).setAvailable(getProduct(name).getAvailable() + available);
}

void Store::addPctToCntPnr(std::string Id,std::string name,int qty){
    if(getProduct(name).getAvailable()>=qty){
      getClient(Id).addPanier(getProduct(name),qty);
      getClient(Id).findByName(name).setAvailable(qty);
      getProduct(name).setAvailable(getProduct(name).getAvailable() - qty);
    }else{
      std::cout << "The quantity you want is not in available in stock" << std::endl;
    }
}

void Store::removePctToCntPnr(std::string Id,std::string name){
    getClient(Id).removePanier(name);
}

void Store::changeqtyPctInCntPnr(std::string Id,std::string name, int quantity){
    if (getProduct(name).getAvailable() >= quantity){
    getClient(Id).findByName(name).setAvailable(quantity);
    getProduct(name).setAvailable(getProduct(name).getAvailable() - quantity);
    }else if(getProduct(name).getAvailable() < quantity){
    std::cout << "Not enough available in stock" << std::endl;
    }else{
    getClient(Id).findByName(name).setAvailable(quantity);
    getProduct(name).setAvailable(getProduct(name).getAvailable() + (getClient(Id).findByName(name).getAvailable()-quantity ));
    }
    getClient(Id).displayPanier();
}

void Store::removeClient(std::string Id){
    for (auto it = _clients.begin(); it != _clients.end(); it++){
    if (it ->getId() == Id ) {
        _clients.erase(it);
        break;
    }
  }
}

void Store::removeProduct(std::string name){
 for (auto it = _products.begin(); it != _products.end(); it++){
    if (it ->getTitle() == name ) {
        _products.erase(it);
        break;
    }
 }
}

void Store::removeOrder(std::string Id){
 for (auto it = _orders.begin(); it != _orders.end(); it++){
    if (it ->getClientId() == Id ) {
        _orders.erase(it);
        break;
    }
 }
}

void Store::emptyProducts(){
    for (auto it=_products.begin(); it!=_products.end(); it+1){
    _products.erase(it);
    }
}

void Store::emptyClients(){
    for (auto it=_clients.begin(); it!=_clients.end(); it+1){
    _clients.erase(it);
    }
}

void Store::emptyOrders(){
   for (auto it=_orders.begin(); it!=_orders.end(); it+1){
    _orders.erase(it);
    }
}

bool Store::checkIdClients(std::string Id){
    if(getClient(Id).getId()== Id){
    return true;
    }else{ return false;}
}

bool Store::checkProdName(std::string name){
    if(getProduct(name).getTitle()== name){
    return true;
    }else{ return false;}
}
