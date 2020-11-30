//
// Created by Asus on 29.11.2020.
//
#include "iostream"
#include "Product.h"

Product::Product(const std::string &name, int amount) : itemName(name), amount(amount){}

Product::Product(Product &product) : Product(product.itemName, product.amount) {}

void Product::print() const {
    std::cout << "name: " << itemName << std::endl << "   amount: " << amount << std::endl;
}
