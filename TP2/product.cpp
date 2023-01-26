#include "product.h"
#include <string.h>
#include <iostream>

Product::Product( std::string title,
                  std::string description,
                  int available,
                  float amount):_title(title),_description(description),_available(available),_amount(amount){
                  }

//Friend

std::ostream& operator << (std::ostream& os,const Product& p){
     //parameters to be displayed
   os << p.getTitle() <<","<< p.getAvailable() <<","<< p.getAmount()<<","<<p.getDescr();
   return os;
}

void getProduct(Product &p){
   std::cout << p << std::endl;
}

//getters 

std::string Product::getTitle() const{
    return _title;
}

float Product::getAmount() const{
    return _amount;
}

int Product::getAvailable() const{
    return _available;
}

std::string Product::getDescr() const{
    return _description;
}

//setters

void Product::setTitle(std::string title){
    _title = title;
}

void Product::setAmount(float amount){
    _amount = amount;
}

void Product::setAvailable(int available){
    _available = available;
}

void Product::setDescr(std::string description){
    _description = description;
}

void Product::decrAvailable(){ 
   if(_available >= 1){
    _available -= 1;
   }else{
    std::cout << "we don't have that product "<< std::endl;
   }
}

void Product::incrAvailable(){
     if(_available >= 0){
    _available += 1;
   }
}
