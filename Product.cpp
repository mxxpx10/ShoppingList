//
// Created by Asus on 29.11.2020.
//
#include "iostream"
#include "Product.h"

Product::Product(const std::string & name, const std::string & unit, float amount) : itemName(name), unit(unit), amount(amount){}

Product::Product(Product & product) : Product(product.itemName, product.unit, product.amount) {}

void Product::setAmount(float value) {
    amount = value;
}

int Product::operator==(Product & pr1) {
    if((*this).unit.compare(pr1.unit)) return 0;
    return !(((*this).itemName).compare(pr1.itemName));
}

void Product::operator+=(Product & pr) {
    (*this).amount += pr.amount;
}




