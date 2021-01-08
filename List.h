//
// Created by Asus on 29.11.2020.
//

#ifndef SHOPPINGLIST_LIST_H
#define SHOPPINGLIST_LIST_H
#include "SoldByKilograms.h"
#include "SoldByPiece.h"
#include "SoldByLiters.h"

#include <vector>

constexpr int PRODUCT_COUNT {10};

class List {
     std::vector <Product*> products;
     std::string listName;
     int counter;

public:
    List(const std::string &, int counter = 0);
    List(const List & model);
    ~List();
    void putItem(Product*);
    int getCounter() const {return counter;};
    std::string getName () const {return listName;};
    void showList() const;
    void deleteItem(int choice);
    List & operator=(const List & model);
    Product* take(int index);
    friend void finalList(List & List1, List & List2, std::vector<int> & indexL1, std::vector<int> & indexL2);
    friend int compare(List & List1, List & List2);


};

#endif //SHOPPINGLIST_LIST_H
