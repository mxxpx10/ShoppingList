//
// Created by Asus on 29.11.2020.
//
#include <iostream>
#include "List.h"

List::List(const std::string &name, int counter) : listName(name), counter(counter){
    for(int i = 0; i < PRODUCT_COUNT; ++i){
        products.push_back(nullptr);
    }
}

void List::putItem(Product product) {
    products[counter] = new Product(product);
    counter++;
}

List::~List() {
    for(int i = 0; i < counter; ++i){
        delete products[i];
        products[i] = nullptr;
    }
}

void List::showList() const {
    if(!counter) {
        std::cout <<"\nYour list is empty";
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

void List::deleteItem(int index) {
    Product item1("Monika", 1);
    *products[index] = item1;
}

//wariant dobry dla opcji w ktorej moge dodawac tylko elem na koniec listy i przypisuje do pustej listy inna
//List &List::operator=(const List & model) {
//    if(&model == this) return *this;
//
//    for(int i = 0; i < PRODUCT_COUNT; ++i) {
//        if(model.products[i]) {
//            delete products[i];
//            products[i] = new Product(*(model.products[i]));
////            *products[i] = *(model.products[i]);
//        }
//    }
//    listName = model.listName;
//    counter = model.counter;
//}

List &List::operator=(const List & model) {
    if(&model == this) return *this;

    for(int i = 0; i < PRODUCT_COUNT; ++i) {
        if (!(products[i]== nullptr && model.products[i]== nullptr)) {
            delete products[i];
            if (model.products[i])
                products[i] = new Product(*(model.products[i]));
            else
                products[i] = nullptr;
        }
    }
    listName = model.listName;
    counter = model.counter;
}

List::List(const List &model) : List(model.listName, model.counter) {
    for(int i = 0; i < PRODUCT_COUNT; ++i) {
        if(model.products[i]) {
            products[i] = new Product(*(model.products[i]));
//            *products[i] = *(model.products[i]);
        }
    }
}
