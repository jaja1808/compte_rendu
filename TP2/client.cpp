#include "client.h"
#include <vector>
#include <iostream>
#include <algorithm>

// constructor

Client::Client(std::string name, std::string prenom, std::string id, std::vector<Product> panier):
               _name(name),_prenom(prenom),_id(id),_panier(panier){
}

// OVERLOADING

// // ==
// bool operator==(Product &p, std::vector<Product> &_panier){ 
//   return true;
// }

// Overloading output of Client

std::ostream &operator<<(std::ostream &os, const Client &c){
     //parameters to be displayed
    os<< c.getName() << " " << c.getPrenom() << " " << c.getId()  << std::endl;
    for (auto it=c._panier.begin(); it!=c._panier.end(); it++){
        os << *it << std::endl;
    }
    return os;
}

//getters

std::string Client::getName() const{
    return _name;
}

std::string Client::getPrenom() const{
    return _prenom;
}

std::string Client::getId() const{
    return _id;
}

std::vector<Product> Client::getPanier() const{
    return _panier;
}

void Client::displayPanier() const{
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
        std::cout << *it << std::endl;
    }
}

// setters

void Client::setname(std::string name){
    _name = name;
}

void Client::setprenom(std::string prenom){
    _prenom = prenom;
}

void Client::setId(std::string id){
    _id = id;
}

void Client::setPanier(std::vector<Product> panier){
    _panier = panier;
}

void Client::addPanier(Product& p, int quantity){
     if((p.getAvailable())>= quantity){
        _panier.push_back(p);
     }else{
        std::cout << "Product quantity unavailable" << std::endl;
     }
}

void Client::removePanier(std::string name){
     for (auto it = _panier.begin(); it != _panier.end(); it++){
        if(it ->getTitle() == name){
            _panier.erase(it);
        }
     }
}

void Client::delProductProd(Product& p,int qty){
  for (int a = 0; a < (int) _panier.size(); a++) {       
        if (_panier.at(a).getTitle() == p.getTitle()) {
       _panier.erase(_panier.begin() + a);
       _panier.at(a).setAvailable(_panier.at(a).getAvailable() - qty);
       break;
    }
 }
}

void Client::emptyPanier(){
    for (auto it=_panier.begin(); it!=_panier.end(); it+1){
    _panier.erase(it);
    std::cout <<"Your Char size is now:"<<_panier.size() <<std::endl;
    }
}

int Client::countTheOccurance(std::string name){
    int count = 0;
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
    Product q = *it ;
    if (findByName(name).getTitle()== q.getTitle()){
        count ++;
    }
    q.setAvailable(q.getAvailable() - count);
  }
  return count;
}

void Client::changeProdQtyinPnr(std::string name, int qty){

 if(findByName(name).getAvailable() >= qty){
   if(countTheOccurance(name)<qty){ 
   while (countTheOccurance(name) <= qty ){
      addPanier(findByName(name),qty);
     }
    }
   }else{
    std::cout <<"Please we have: "<< findByName(name).getAvailable()<<" "<< findByName(name).getTitle()<<" remaining"<<std::endl;
  }

   if(countTheOccurance(name)>qty){ 
   while (countTheOccurance(name) > qty ){
    removePanier(name);
    findByName(name).incrAvailable();
    }
   }
}

Product& Client::findByName(std::string name){
  auto it = std::find_if(_panier.begin(), _panier.end(), 
    [&name](const Product& p){return p.getTitle() == name;});
    return *it;
  }   

void getTheClient(Client& c){
    std::cout<< c << std::endl;
    c.getPanier();
}
