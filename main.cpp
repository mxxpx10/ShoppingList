#include <iostream>
#include <vector>
#include "List.h"

void addProduct(List & List);
void deleteProduct(List & List);
void editList(std::vector <List> &main);
void printList(std::vector <List> &main);
void createList(std::vector <List> &main);
int chooseList(std::vector <List> &main);
void deleteList(std::vector <List> &main);
void duplicateList(std::vector <List> &main);
bool isEmpty(std::vector <List> &main);
std::string readString();
int readInt();

int main() {

    std::vector <List> main;

    int choice;
    do {
        std::cout << "\n___________ MENU __________" << std::endl;
        std::cout << "0: Exit\n"
                     "1: Create new list\n"
                     "2: Edit list\n"
                     "3: Show list\n"
                     "4: Duplicate list\n"
                     "5: Delete list\n"

                     "Choose action: ";
        choice = readInt();

        switch (choice) {
            case 0:
                break;
            case 1:
                createList(main);
                break;
            case 2:
                std::cout << "\n_________ Options _________" << std::endl;
                std::cout << "1: Add item\n"
                             "2: Delete last item\n"
                             "Choose action: ";
                editList(main);
                break;
            case 3:
                printList(main);
                break;
            case 4:
                std::cout << "\n_________ Options _________" << std::endl;
                std::cout << "1: Overwrite existing list\n"
                             "2: Create copy from scratch\n"
                             "Choose action: ";
                duplicateList(main);
                break;
            case 5:
                deleteList(main);
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }

    } while (choice);

    main.clear();
    return 0;
}

void duplicateList(std::vector <List> &main) {
    int choice = readInt();
    if(isEmpty(main)) return;
    if(choice == 1) {
        std::cout <<"List to copy:" << std::endl;
        int copy = chooseList(main);
        std::cout <<"List to overwrite:" << std::endl;
        int overwrite = chooseList(main);
        main[overwrite] = main[copy];
    }
    else if (choice == 2){
        std::cout <<"List to copy: \n";
        int copy = chooseList(main);
        List List = main[copy];
        main.push_back(List);
    }
}

void editList(std::vector <List> &main) {
    int action = readInt();
    if( isEmpty(main) ) return;
    int choice = chooseList(main);
    if(action == 1) {
        addProduct(main[choice]);
    }
    else if(action == 2) {
        deleteProduct(main[choice]);
    }
}

void addProduct(List & List) {
    if(List.getCounter() == PRODUCT_COUNT) {
        std::cout <<"List is already full";
        return;
    }
    std::cout << "Name of product: ";
    std::string name = readString();
    std::cout << "Amount: ";
    int amount = readInt();

    Product item1(name, amount);

    List.putItem(item1);
}

void deleteProduct(List & List) {
    if(!List.getCounter()) {
        std::cout <<"List is empty";
        return;
    }
    List.deleteItem();
}

int chooseList(std::vector <List> &main) {
    int choice;
    int size = main.size();
    std::cout << "\n______ Current lists ______ " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        std::cout << main[i].getName() << std::endl;
    }
    std::cout << "Choose list 0-" << size-1 << ": ";
    return choice = readInt();
}

void printList(std::vector < List> &main) {
    if(isEmpty(main)) return;
    int choice = chooseList(main);
    main[choice].showList();
}


void createList(std::vector <List> &main) {
    std::cout << "List name: ";
    std::string name = readString();

    List List(name);
    main.push_back(List);
    std::cout << "List is empty" << std::endl;
}

void deleteList(std::vector <List> &main) {
    if(isEmpty(main)) return;
    auto it = main.begin();
    int choice = chooseList(main);
    for(int i = 0; i <= choice; ++i, ++it) {
        if(i == choice) {
            main.erase(it);
        }
    }
}

bool isEmpty(std::vector <List> &main) {
    if(main.empty()) {
        std::cout << "No lists available" << std::endl;
    }
    return main.empty();
}

std::string readString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int readInt() {
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}