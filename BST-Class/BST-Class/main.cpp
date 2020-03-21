/*
 * Author: Steven Herrera
 * Project: BST Class
 * Purpose: this is a binary search tree its meant to hold items within it 
 *          the smaller the item the more to the left it goes the bigger the
 *          more to the right it goes
 * Notes: 
 *
 */

#include <iostream>
#include "BST.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    BST<int> tree;
    string input = "";
    (srand(time(NULL)));
    while (true) {
        cout << "[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it: ";
        cin >> input;
        if (input == "r" || input == "R") {
            int num = (rand() % 100) + 1;
            cout << "-- Inserting " << num << "\nTree_node tree: item: " << num << endl;
            tree.insert(num);
            cout << tree << "\n\n=========================\n";
        } else if (input == "i" || input == "I") {
            int num = 0;
            cout << "? ";
            cin >> num;
            cout << "-- Inserting " << num << "\nTree_node tree: item: " << num << endl;
            tree.insert(num);
            cout << tree << "\n\n=========================\n";
        } else if (input == "s" || input == "S") {
            int num = 0;
            cout << "? ";
            cin >> num;
            tree_node<int>* foundPtr = NULL;
            if (tree.search(num, foundPtr)) {
                cout << "item is found. |" << foundPtr->_item << "|\n";
            } else {
                cout << "Item not found.\n";
            }
            cout << tree << "\n\n=========================\n";
        } else if (input == "c" || input == "C") {
            tree.clear();
            cout << tree << "\n\n=========================\n";
        } else if (input == "x" || input == "X") {
            break;
        }
    }
    cout <<"\n\n=========================\n";
}
