#include <iostream>
#include <string.h>

#ifndef PRODUCT
#define PRODUCT

class Product
{
private:
    /* data */
    
   std::string _title;
   std::string _description;
   int _available;
   float _amount;

public:
    Product( std::string title ="",
             std::string description = "",
             int available = 0,
             float amount =0.0);

    //getters

    std::string getTitle() const;
    float getAmount() const;
    int getAvailable() const;
    std::string getDescr() const;
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    

    //setters

    void setTitle(std::string title);
    void setAmount(float amount);
    void setAvailable(int available);
    void setDescr(std::string description);

    //methods

    void decrAvailable(); 
    void incrAvailable();
};

void getProduct(Product &p);

#endif //PRODUCT