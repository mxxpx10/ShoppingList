//
// Created by Asus on 29.11.2020.
//
#include <iostream>
#include "List.h"

List::List(const std::string & name, int counter) : listName(name), counter(counter){
    products.assign(PRODUCT_COUNT, nullptr);
}

List::List(const List & model) : List(model.listName, model.counter) {
    for(int i = 0; i < PRODUCT_COUNT; ++i) {
        if(!model.products[i]) break;
        Product* wsk = model.products[i];
        products[i] = wsk->createCopy();
    }
}

List::~List() {
    for(int i = 0; i < counter; ++i){
        delete products[i];
        products[i] = nullptr;
    }
}
void List::putItem(Product *product) {
    products[counter] = product ->createCopy();
    counter++;
}

void List::showList() const {
    if(!counter) {
        std::cout <<"List is empty" << std::endl;
        return;
    }
    std::cout <<"\nList: " << listName << std::endl;
    for(int i = 0; i < PRODUCT_COUNT; ++i){
        std::cout << i <<". ";
        if(products[i])
            products[i]->print();
        else
            std::cout << "name:---------------" << std::endl <<"   amount:-------------" << std::endl;
    }
}


void List::deleteItem(int choice) {
    if(!counter) {
        std::cout <<"List is empty" << std::endl;
        return;
    }
    auto it = products.begin();
    for(int i = 0; i <= choice; ++i, ++it) {
       if(i == choice) {
            delete products[choice];
            products.erase(it);
            products.push_back(nullptr);
        }
    }
    counter--;
}


List &List::operator=(const List & model) {
    if(&model == this) return *this;

    for(int i = 0; i < PRODUCT_COUNT; ++i) {
        if (products[i] == nullptr && model.products[i] == nullptr) break;
        delete products[i];
        if (model.products[i])
            products[i] = model.products[i]->createCopy();
        else
            products[i] = nullptr;
    }
    listName = model.listName;
    counter = model.counter;
    return *this;
}

Product *List::take(int index) {
    Product *product =  products[index]->createCopy();
    (*this).deleteItem(index);
    return product;
}







