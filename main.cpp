#include <iostream>
#include <string>
#include <fstream>
#include "List.h"

void addProduct(List & List);
void deleteProduct(List & List);
void editList(std::vector <List> & main);
void printList(std::vector <List> & main);
void createList(std::vector <List> & main);
int chooseList(std::vector <List> & main);
void deleteList(std::vector <List> & main);
void duplicateList(std::vector <List> & main);
bool isEmpty(std::vector <List> & main);
std::string readString();
int readInt();
int chooseCategory();
void moveProduct(std::vector <List> & main);
void mergeLists(std::vector <List> & main);
float readFloat();
void updateIndex(std::vector<int> & indexL, int i);
void finalList(List & List1, List & List2, std::vector<int> & indexL1, std::vector<int> & indexL2 );
int compare(List & List1, List & List2);

bool readFile = false;
std::ifstream sourceFile;

int main(int argc, char *argv[]) {

    if(argc==2) {
        sourceFile = std::ifstream(argv[1]);
        readFile = true;
    }
    std::vector <List> main;

    int choice;
    do {
        std::cout << "\n___________ MENU __________" << std::endl;
        std::cout << "1: Create new list\n"
                     "2: Edit list\n"
                     "3: Show list\n"
                     "4: Duplicate list\n"
                     "5: Move product between lists\n"
                     "6: Delete list\n"
                     "7: Merge lists\n"
                     "8: Exit\n"

                     "Choose action: ";
    choice = readInt();

        switch (choice) {
            case 1:
                createList(main);
                break;
            case 2:
                std::cout << "\n_________ Options _________" << std::endl;
                std::cout << "1: Add item\n"
                             "2: Delete item\n"
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
                moveProduct(main);
                break;
            case 6:
                deleteList(main);
                break;
            case 7:
                mergeLists(main);
                break;
            case 8:
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }

    } while (choice != 8);

    main.clear();
    return 0;
}


void duplicateList(std::vector <List> & main) {
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

void editList(std::vector <List> & main) {
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

int chooseCategory() {
    std::cout << "Choose category of product" << std::endl;
    std::cout << "\n_______ Categories _______ " << std::endl;
    std::cout << "0. Sold by pieces\n"
                 "1. Sold by kilograms\n"
                 "2. Sold by liters\n"
                 "Choose category of product: ";
    return readInt();
}

void addProduct(List & List) {
    if(List.getCounter() == PRODUCT_COUNT) {
        std::cout <<"List is already full";
        return;
    }
    std::cout << "Name of product: ";
    std::string name = readString();
    int choice = chooseCategory();

    Product *wsk;
    switch (choice) {
        case 0:
            wsk = new SoldByPiece(name);
            break;
        case 1:
            wsk = new SoldByKilograms(name);
          break;
        case 2:
            wsk = new SoldByLiters(name);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return;
    }
    wsk->ask();
    float amount = readFloat();
    wsk->setAmount(amount);
    List.putItem(wsk);
    delete wsk;
}

void moveProduct(std::vector <List> & main) {
    if(isEmpty(main)) return;
    std::cout << "\nSelect a source list.";
    int source = chooseList(main);
    main[source].showList();

    std:: cout << "Choose index of product to move: ";
    int prodChoice = readInt();

    Product* product = main[source].take(prodChoice);

    std::cout << "\nSelect a destination list.";
    int dest = chooseList(main);
    main[dest].putItem(product);

    delete product;
}


int chooseList(std::vector <List> & main) {
//    int choice;
    int size = main.size();
    std::cout << "\n______ Current lists ______ " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        std::cout << main[i].getName() << std::endl;
    }
    std::cout << "Choose list 0-" << size-1 << ": ";
//    return choice = readInt();
    return readInt();
}

void printList(std::vector < List> & main) {
    if(isEmpty(main)) return;
    int choice = chooseList(main);
    main[choice].showList();
}


void createList(std::vector <List> & main) {
    std::cout << "List name: ";
    std::string name = readString();

    main.emplace_back(List(name));

    std::cout << "An empty list has been created" << std::endl;
}

void finalList(List & List1, List & List2, std::vector<int> & indexL1, std::vector<int> & indexL2) {

    List1.listName = List1.listName + " & " + List2.listName;
    int size = indexL1.size();
    if(size) {
        for (int i = 0; i < size; i++) {
            *List1.products[indexL1[i]] += *List2.products[indexL2[i]];
            List2.deleteItem(indexL2[i]);
            updateIndex(indexL2, i);
        }
    }
    for(int i = 0; i <List2.counter; i++) {
        List1.putItem(List2.products[i]);
    }
 }

int compare(List & List1, List & List2) {
    int counter = List1.counter + List2.counter;
    std::vector <int> indexList1;
    std::vector <int> indexList2;

    for(int i = 0; i < List1.counter; i++) {
        for(int j = 0; j < List2.counter; j++) {

            if(*List1.products[i] == *List2.products[j]) {
                indexList1.push_back(i);
                indexList2.push_back(j);
                counter--;
                break;
            }
        }
    }

    if(counter > 10) return 0;
    finalList(List1, List2, indexList1, indexList2);

    return 1;
}

void mergeLists(std::vector <List> & main) {
    std::cout << "Choose first list. ";
    int first = chooseList(main);

    std::cout << "Choose second list.";
    int second = chooseList(main);

    if(!compare(main[first], main[second])) {
        std::cout <<"Lists can't be merged."
                    "\nThe sum of products from chosen lists exceeds 10";
        return;
    }

    auto it = main.begin();
    for(int i = 0; i <= second; ++i, ++it) {
        if(i == second) main.erase(it);
    }
}

void updateIndex(std::vector<int> & indexL, int i) {
    int inx = indexL[i];
    int j = i+1;
    while (j!= indexL.size()) {
        if(indexL[j] > inx) indexL[j]--;
        j++;
    }
    return;
}
void deleteList(std::vector <List> & main) {
    if(isEmpty(main)) return;
    auto it = main.begin();
    int choice = chooseList(main);
    for(int i = 0; i <= choice; ++i, ++it) {
        if(i == choice) {
            main.erase(it);
        }
    }
}

void deleteProduct(List & List) {
    List.showList();
    std:: cout << "Choose index of product to delete: ";
    int choice = readInt();
    List.deleteItem(choice);

}
bool isEmpty(std::vector <List> & main) {
    if(main.empty()) {
        std::cout << "No lists available" << std::endl;
    }
    return main.empty();
}

std::string readString() {
    std::string line;
    if(readFile) {
        std::getline(sourceFile, line);
        std::cout << line << std::endl;
    }
    else std::getline(std::cin, line);
    return line;
}

int readInt() {
    std::string line;
    if(readFile) {
        std::getline(sourceFile, line);
        std::cout << line << std::endl;
    }
    else std::getline(std::cin, line);
    return atoi(line.c_str());
}

float readFloat() {
    std::string line;
    if(readFile) {
        std::getline(sourceFile, line);
        std::cout << line << std::endl;
    }
    else std::getline(std::cin, line);
    return std::stof(line);
}

