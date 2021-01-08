//
// Created by Asus on 29.11.2020.
//

#ifndef SHOPPINGLIST_PRODUCT_H
#define SHOPPINGLIST_PRODUCT_H

#include <string>

class Product {
protected:
    std::string itemName;
    std::string unit;
    float amount;
public:
    Product(const std::string & name = "", const std::string & unit = "", float amount = 0);
    Product(Product & product);
    virtual void print() const = 0;
    virtual void ask() = 0;
    void setAmount(float value);
    virtual Product* createCopy() = 0;
    int operator== (Product & pr1);
    void operator+=(Product & pr);

};




#endif //SHOPPINGLIST_PRODUCT_H
