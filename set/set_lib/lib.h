#include <stdexcept>
using namespace std;

#include <bits/stdc++.h>

#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

template <class T>
class AVLTree
{

public:
    AVLTree();

    AVLTree(std::initializer_list<T> lst)
    {
        this->root = nullptr;
        this->count = 0;
        for (auto elm : lst)
        {
            this->insert(elm);
        }
    }
    // template AVLTree<double>(std::initializer_list<int>);

    // Конструктор копирования
	AVLTree(const AVLTree &copy){
        cout << "copy\n";
        this->root = copy.root;
    }
    
    AVLTree& operator=(const AVLTree &tree)
    {
        cout << "=\n";
        this->root = tree.root;
        return *this;
    }

    void insert(T x);

    // AVLTree& operator=AVLTree(const AVLTree& src) default;

    void erase(T x);

    int size() const{
        // cout << this->root->value << endl;
        // return this->root->count;
        return this->count;
    }

private:
    struct node
    {
        T value;
        int count;
        node *left;
        node *right;
        int height;
    };

    node *root;
    int count;

    int height(node *vertex);

    node *insert(T val, node *vertex);

    node *erase(T val, node *vertex);

    node *smallRightRotate(node *vertex);

    node *smallLeftRotate(node *vertex);

    node *bigRightRotate(node *vertex);

    node *bigLeftRotate(node *vertex);
};

template class AVLTree<int>;
template class AVLTree<double>;

// template void TestClass::templateFunction<int, int>(int, int);
// template class AVLTree<int>(std::initializer_list<int>);
// template class AVLTree<double>(std::initializer_list<double>);


#endif