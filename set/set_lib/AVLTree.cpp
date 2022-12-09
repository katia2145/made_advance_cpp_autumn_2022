#include <iostream>
#include "lib.h"
#include <bits/stdc++.h>

using namespace std;

template <class T>
AVLTree<T>::AVLTree()
{
    this->root = nullptr;
    this->count = 0;
}

// typename AVLTree<T>::AVLTree* AVLTree<T>::operator=(AVLTree<T>::AVLTree* tree)
// {
//     // this->
//     return *this;
// }

template <class T>
void AVLTree<T>::insert(T x)
{   
    cout << "insert" << endl;
    this->count += 1;
    cout << this->count << endl;
    insert(x, this->root);
    // AVLTree<T>::node * new_root = insert(x, this->root);
    // this->root = new_root;
    // cout << "insert " << this->root->value << endl;
}

template <class T>
int AVLTree<T>::height(AVLTree<T>::node *vertex)
{
    return (vertex == NULL ? -1 : vertex->height);
}

template <class T>
typename AVLTree<T>::node *AVLTree<T>::insert(T value, AVLTree<T>::node *vertex)
{
    cout << "cur vertex " << vertex->value << endl;
    if (vertex == nullptr)
    {
        cout << "new node" << endl;
        vertex = new node;
        vertex->value = value;
        vertex->count = 1;
        vertex->height = 0;
        vertex->left = nullptr;
        vertex->right = nullptr;
        return vertex;
    }

    if (value == vertex->value)
    {
        cout << "equal" << endl;
        vertex->count += 1;
        return vertex;
    }

    if (value < vertex->value)
    {
        cout << "<" << endl;
        vertex->left = insert(value, vertex->left);
        if (height(vertex->left) - height(vertex->right) == 2)
        {
            if (value < vertex->left->value)
                vertex = smallRightRotate(vertex);
            else
                vertex = bigRightRotate(vertex);
        }
    }
    else
    {
        cout << ">" << endl;
        vertex->right = insert(value, vertex->right);
        if (height(vertex->right) - height(vertex->left) == 2)
        {
            if (value < vertex->right->value)
                vertex = bigRightRotate(vertex);
            else
                vertex = smallRightRotate(vertex);
        }
    }

    cout << "get_height" << endl;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;
    cout << vertex->height << endl;

    cout << "return" << endl;
    return vertex;
}

template <class T>
typename AVLTree<T>::node *AVLTree<T>::smallRightRotate(AVLTree<T>::node *vertex)
{
    node *v_left = vertex->left;
    vertex->left = v_left->right;
    v_left->right = vertex;
    v_left->height = max(height(v_left->left), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

    return v_left;
}

template <class T>
typename AVLTree<T>::node *AVLTree<T>::smallLeftRotate(AVLTree<T>::node *vertex)
{
    node *v_left = vertex->right;
    vertex->right = v_left->left;
    v_left->left = vertex;
    v_left->height = max(height(v_left->right), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

    return v_left;
}

template <class T>
typename AVLTree<T>::node *AVLTree<T>::bigRightRotate(AVLTree<T>::node *vertex)
{
    vertex->left = smallLeftRotate(vertex->left);
    vertex = smallRightRotate(vertex);
    return vertex;
}

template <class T>
typename AVLTree<T>::node *AVLTree<T>::bigLeftRotate(AVLTree<T>::node *vertex)
{
    vertex->right = smallRightRotate(vertex->right);
    vertex = smallLeftRotate(vertex);
    return vertex;
}

template <class T>
void AVLTree<T>::erase(T x)
{
    // erase(x, this->root);
}

// template <class T>
// typename AVLTree<T>::node* erase(T value, typename AVLTree<T>::node* vertex)
// {
//     if(vertex == nullptr)
//         return nullptr;

//     AVLTree<T>::node* tmp;

//     if(value < vertex->value)
//         vertex->left = remove(value, vertex->left);
//     else if(value < vertex->value)
//         vertex->right = remove(value, vertex->right);

//     // Element found
//     // With 2 children
//     else if(vertex->left && vertex->right)
//     {
//         tmp = findMin(vertex->right);
//         vertex->value = tmp->value;
//         vertex->right = remove(vertex->value, vertex->right);
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
//     if(vertex == nullptr)
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