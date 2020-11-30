//
// Created by Asus on 29.11.2020.
//

#ifndef SHOPPINGLIST_LIST_H
#define SHOPPINGLIST_LIST_H
#include "Product.h"
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
    void putItem(Product);
    int getCounter() {return counter;};
    void showList() const;
    void deleteItem(int index);
    List & operator=(const List & model);

};

#endif //SHOPPINGLIST_LIST_H
