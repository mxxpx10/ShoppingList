//
// Created by Asus on 29.11.2020.
//

#ifndef SHOPPINGLIST_PRODUCT_H
#define SHOPPINGLIST_PRODUCT_H

#include <string>

class Product {
    std::string itemName;
    int amount;

public:
    Product(const std::string & name = "", int amount = 0);
    Product(Product & product);
    void print() const;

};

#endif //SHOPPINGLIST_PRODUCT_H
