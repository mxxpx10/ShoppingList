//
// Created by Asus on 14.12.2020.
//

#ifndef PODRAZAMONIKA_ETAP1_SOLDBYLITERS_H
#define PODRAZAMONIKA_ETAP1_SOLDBYLITERS_H
#include "Product.h"

class SoldByLiters : public Product {

public:
    SoldByLiters(std::string name, std::string unit = "l") : Product(name, unit) {};
    void print() const;
    void ask();
    Product* createCopy();

};
#endif //PODRAZAMONIKA_ETAP1_SOLDBYLITERS_H
