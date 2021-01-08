//
// Created by Asus on 13.12.2020.
//
#include "SoldByKilograms.h"
#include "iostream"
void SoldByKilograms::print() const {
    std::cout << "name: " << itemName << std::endl << "   amount of kg: " << amount << std::endl;
}

void SoldByKilograms::ask() {
    std::cout << "Amount of kilograms: ";
}

Product *SoldByKilograms::createCopy() {
    return new SoldByKilograms(*this);
}




