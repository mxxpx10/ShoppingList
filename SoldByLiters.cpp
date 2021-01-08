//
// Created by Asus on 14.12.2020.
//
#include "SoldByLiters.h"
#include "iostream"

void SoldByLiters::print() const {
    std::cout << "name: " << itemName << std::endl << "   amount of liters: " << amount << std::endl;
}

void SoldByLiters::ask() {
    std::cout << "Amount of liters: ";
}

Product *SoldByLiters::createCopy() {
    return new SoldByLiters(*this);
}

