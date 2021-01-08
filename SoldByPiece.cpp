//
// Created by Asus on 13.12.2020.
//
#include "iostream"
#include "SoldByPiece.h"

void SoldByPiece::print() const {
    std::cout << "name: " << itemName << std::endl << "   amount of items: " << amount << std::endl;
}

void SoldByPiece::ask() {
    std::cout << "Amount of items: ";
}

Product *SoldByPiece::createCopy() {
    return new SoldByPiece(*this);
}

