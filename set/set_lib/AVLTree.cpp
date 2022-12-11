#include <iostream>
#include "lib.h"
#include <bits/stdc++.h>

using namespace std;

template <class T>
Set<T>::Set()
{
    this->root = NULL;
    this->count = 0;
}

template <class T>
Set<T>::Set(std::initializer_list<T> lst)
{
    this->root = NULL;
    this->count = 0;
    for (auto elm : lst)
    {
        this->insert(elm);
    }
}

template <class T>
Set<T>::Set(const Set &copy)
{
    cout << "copy\n";
    this->root = copy.root;
}

template <class T>
typename Set<T>::Set &Set<T>::operator=(const Set &tree)
{
    cout << "=\n";
    this->root = tree.root;
    return *this;
}

template <class T>
int Set<T>::size() const
{
    return this->count;
}

template <class T>
bool Set<T>::empty() const
{
    if (this->root == NULL)
        return true;
    return false;
}

template <class T>
int Set<T>::height(Set<T>::node *vertex)
{
    if (vertex == NULL)
        return -1;
    return vertex->height;
}


// template <class T>
// void Set<T>::erase(T x)
// {
//     erase(x, this->root);
// }

// template <class T>
// typename Set<T>::node* erase(T value, typename Set<T>::node* vertex)
// {
//     if(vertex == NULL)
//         return NULL;

//     Set<T>::node* tmp;

//     if(value < vertex->value)
//         vertex->left = erase(value, vertex->left);
//     else if(value < vertex->value)
//         vertex->right = erase(value, vertex->right);

//     // Element found
//     // With 2 children
//     else if(vertex->left && vertex->right)
//     {
//         tmp = findMin(vertex->right);
//         vertex->value = tmp->value;
//         vertex->right = erase(tmp->value, vertex->right);
//     }
//     // With one or zero child
//     else
//     {
//         tmp = vertex;
//         if(vertex->left == NULL)
//             vertex = vertex->right;
//         else if(vertex->right == NULL)
//             vertex = vertex->left;
//         delete tmp;
//     }
//     if(vertex == NULL)
//         return vertex;

//     vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

//     // If node is unbalanced
//     // If left node is deleted, right case
//     if(height(vertex->left) - height(vertex->right) == 2)
//     {
//         // right right case
//         if(height(vertex->left->left) - height(vertex->left->right) == 1)
//             return singleLeftRotate(vertex);
//         // right left case
//         else
//             return doubleLeftRotate(vertex);
//     }
//     // If right node is deleted, left case
//     else if(height(vertex->right) - height(vertex->left) == 2)
//     {
//         // left left case
//         if(height(vertex->right->right) - height(vertex->right->left) == 1)
//             return singleRightRotate(vertex);
//         // left right case
//         else
//             return doubleRightRotate(vertex);
//     }
//     return vertex;
// }
