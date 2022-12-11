#include <iostream>
#include "lib.h"
using namespace std;

template <class T>
void Set<T>::insert(T x)
{
    this->count += 1;
    this->root = insert(x, this->root);
}

template <class T>
typename Set<T>::node *Set<T>::insert(T value, Set<T>::node *vertex)
{
    if (vertex == NULL)
    {
        vertex = new node;
        vertex->value = value;
        vertex->count = 1;
        vertex->height = 0;
        vertex->left = NULL;
        vertex->right = NULL;
        return vertex;
    }

    if (value == vertex->value)
        return vertex;

    if (value < vertex->value)
    {
        vertex->left = insert(value, vertex->left);
        if (height(vertex->left) - height(vertex->right) == 2)
        {
            if (value < vertex->left->value)
                vertex = smallRightRotate(vertex);
            else
                vertex = bigRightRotate(vertex);
        }
    }
    else if (value > vertex->value)
    {
        vertex->right = insert(value, vertex->right);
        if (height(vertex->right) - height(vertex->left) == 2)
        {
            if (value > vertex->right->value)
                vertex = smallRightRotate(vertex);
            else
                vertex = bigRightRotate(vertex);
        }
    }

    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

    return vertex;
}

template <class T>
typename Set<T>::node *Set<T>::smallRightRotate(Set<T>::node *vertex)
{
    node *v_left = vertex->left;

    if (v_left == NULL)
    {
        vertex->left = NULL;
        v_left = new node;
    }
    else
    {
        vertex->left = v_left->right;
    }
    v_left->right = vertex;
    v_left->height = max(height(v_left->left), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

    return v_left;
}

template <class T>
typename Set<T>::node *Set<T>::smallLeftRotate(Set<T>::node *vertex)
{
    node *v_right = vertex->right;

    if (v_right == NULL)
    {
        vertex->right = NULL;
        v_right = new node;
    }
    else
    {
        vertex->right = v_right->left;
    }

    v_right->left = vertex;
    v_right->height = max(height(v_right->right), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

    return v_right;
}

template <class T>
typename Set<T>::node *Set<T>::bigRightRotate(Set<T>::node *vertex)
{
    vertex->left = smallLeftRotate(vertex->left);
    vertex = smallRightRotate(vertex);
    return vertex;
}

template <class T>
typename Set<T>::node *Set<T>::bigLeftRotate(Set<T>::node *vertex)
{
    vertex->right = smallRightRotate(vertex->right);
    vertex = smallLeftRotate(vertex);
    return vertex;
}
