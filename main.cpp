#include <iostream>
#include "List.h"

void addProduct(List&);
void printList(List &);
void deleteProduct(List&);
std::string readString();
int readInt();

int main() {

    std::vector <List> main;

    List List1 = List("Zakupy");
    addProduct(List1);
    addProduct(List1);
    List List2("usun");
    addProduct(List2);

    //demo działania operatora przypisania
    List2 = List1;
    std::cout <<"\nPo uzyciu operatora przypisania: List2 = List1" << std::endl;
    printList(List1);
    printList(List2);

    addProduct(List2);
    deleteProduct(List2);
    printList(List1);
    printList(List2);

    //demo dzialania konstruktora kopiującego
    std::cout <<"\nKonstruktor kopiujacy" << std::endl;
    List List3 = List1;
    printList(List1);
    printList(List3);
    deleteProduct(List3);
    printList(List1);
    printList(List3);

    main.push_back(List1);
    main.push_back(List2);
    main.push_back(List3);

    return 0;
}

void addProduct(List &list) {
    if(list.getCounter() == 10) {
        std::cout <<"\nYour list is already full.";
        return;
    }
    std::cout << "\nName of product: ";
    std::string name = readString();
    std::cout << "\nAmount of this product: ";
    int amount = readInt();

    Product item1(name, amount);

    list.putItem(item1);
}

void printList(List &list) {
    list.showList();
}

//DO TESTU
void deleteProduct(List &list) {
    list.deleteItem(0);
}

std::string readString() {
    std::string line;
    std::getline(std::cin, line); //wczytanie z klawiatury tekstu i umieszczenie go w stringu line
    return line;
}

int readInt() {
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}


