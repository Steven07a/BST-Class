#ifndef BST_H_
#define BST_H_
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BST-Functions\BTS_Functions\BTS_Functions/BST_Functions.h"
using namespace std;

template <typename T>
class BST {
public:
    BST() {
        root = NULL;
    }
    BST(const T* sorted_list, int size = -1) {
        this->root = tree_from_sorted_list(sorted_list, size);
    }

    BST(tree_node<T>* roots) {
        root = roots;
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me);
    BST<T>& operator =(const BST<T>& rhs) {
        if (root != NULL) {
            tree_clear(root);
            return tree_copy(root);
        }
    }
    ~BST() {
        if (root != NULL) {
            tree_clear(root);
        }
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me) {
        tree_insert(this->root, insert_me);
    }

    void erase(const T& target) {
        tree_erase(this->root, target);
    }

    bool search(const T& target, tree_node<T>*& found_ptr) {
        return tree_search(root, target, found_ptr);
    }

    friend ostream& operator <<(ostream& outs, const BST<T>& tree) {
        tree_print(tree.root);
        return outs;
    }

    void clear() {
        tree_clear(root);
    }

    BST<T>& operator +=(const BST<T>& rhs) {
        tree_add(root, rhs.root);
        return *this;
    }
private:
    tree_node<T>* root;
};

#endif // !BST_H_

