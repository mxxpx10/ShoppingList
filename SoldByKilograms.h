//
// Created by Asus on 13.12.2020.
//

#ifndef PODRAZAMONIKA_ETAP1_SOLDBYKILOGRAMS_H
#define PODRAZAMONIKA_ETAP1_SOLDBYKILOGRAMS_H
#include "Product.h"

class SoldByKilograms : public Product {

public:
    SoldByKilograms(std::string name, std::string unit = "kg") : Product(name, unit) {};
    void print() const;
    void ask();
    Product* createCopy();

};
#endif //PODRAZAMONIKA_ETAP1_SOLDBYKILOGRAMS_H


