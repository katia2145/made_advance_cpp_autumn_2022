#include <stdexcept>
using namespace std;

#include <bits/stdc++.h>

#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

class AVLTree
{

public:
    AVLTree()
    {
        root = nullptr;
    }

    template <typename T>
    AVLTree(std::initializer_list<T> lst)
    {
        root = nullptr;
        for (auto elm : lst)
        {
            this->insert(elm);
        }
    }

    void insert(int x);

    void remove(int x);

private:
    struct node
    {
        int value;
        int count;
        node *left;
        node *right;
        int height;
    };

    node *root;

    int height(node *vertex);

    node *insert(int val, node *vertex);

    node *smallRightRotate(node *vertex);

    node *smallLeftRotate(node *vertex);

    node *bigRightRotate(node *vertex);

    node *bigLeftRotate(node *vertex);
};

#endif