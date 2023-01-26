#include "order.h"
#include <vector>
#include <iostream>
#include <algorithm>


//constructor

Order::Order(Client client, std::vector<Product> chosenProducts, Status status): 
            _client(client),_chosenProducts(chosenProducts),_status(status){
}

//Friend Output Overloading

std::ostream &operator<<(std::ostream &os, const Order &o)
{
  // TODO: insert return statement here
    os<< o.getClient() << " " << std::endl;
    o.getStatus();
    for (auto it=o._chosenProducts.begin() ; it!=o._chosenProducts.end(); it++){
        os << *it << std::endl;
    }
    return os;
}

Client Order::getClient() const{
    return _client;
}

std::string Order::getClientId() const{
    return _client.getId();
}

void Order::displayClient(){
    std::cout << _client << std::endl;
}

void Order::displayProductList(){
    for(auto it = _chosenProducts.begin() ; it != _chosenProducts.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Order::getStatus() const{
    
    if (_status == 0){
        std::cout<<"Delivered"<<std::endl;
    }else{
        std::cout<<"Not-Delivered"<<std::endl;
    };
}

void Order::setStatus(std::string stat){
     if(stat == "Delivered"){
       _status = Delivered;
     }else if(stat == "Not-Delivered"){
       _status = Not_Delivered;
     }else{
       std::cout << "please input Status as Delivered or Not-Delovered" << std::endl;
     }
}

void Order::linkProducts(){
    _chosenProducts = _client.getPanier();
}

void Order::addProductsFromPanier(std::string name){
     _chosenProducts.push_back(_client.findByName(name));
}

void Order::addProducts(Product& p){
    _chosenProducts.push_back(p);
}

void Order::removeProducts(std::string name){
    for (auto it = _chosenProducts.begin(); it !=_chosenProducts.end(); it++) {       
        if (it->getTitle() == name ) {
       _chosenProducts.erase(it);
        break;
    }
 }
}

void Order::validOrder(){
    _client.emptyPanier();
    _chosenProducts.clear();
}

void Order::setClient(Client& c){
    _client.setname(c.getName());
    _client.setprenom(c.getPrenom());
    _client.setId(c.getId());
    _client.setPanier(c.getPanier());
}

Product& Order::findProductByName(std::string name){
     auto it = std::find_if(_chosenProducts.begin(), _chosenProducts.end(), 
    [&name](const Product& p){return p.getTitle() == name;});
  return *it;
  if (it == _chosenProducts.end()) {
      throw std::runtime_error("Product not found");
  }
}

/*
bool isValidOrder(Order o){
   if(o.getClient()= Client())
    return true;
}

void displayOrders(Order o){
    if(isValidOrder){
      o.getStatus();
    }else{
        std::cout <<" your order is not valid yet"<<std::endl;
    }
}
*/

