//
// Created by Asus on 13.12.2020.
//

#ifndef PODRAZAMONIKA_ETAP1_SOLDBYPIECE_H
#define PODRAZAMONIKA_ETAP1_SOLDBYPIECE_H
#include "Product.h"

class SoldByPiece : public Product {

public:
    SoldByPiece(std::string name, std::string unit = "no_units") : Product(name, unit) {};
    void print() const;
    void ask();
    Product* createCopy();
};
#endif //PODRAZAMONIKA_ETAP1_SOLDBYPIECE_H


