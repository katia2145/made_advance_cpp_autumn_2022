#include <iostream>
#include "lib.h"
#include <bits/stdc++.h>

using namespace std;


template <class T>
typename Set<T>::Iterator Set<T>::find(T x)
{
    node *answer = find(x, this->root);
    return Iterator(answer);
}

template <class T>
typename Set<T>::Iterator Set<T>::lower_bound(T x){
    node * answer = lower_bound(x, NULL, this->root);
    cout << "return " << answer->value << endl; 
    return Iterator(answer);
}

template <class T>
typename Set<T>::node* Set<T>::lower_bound(T value, node * nearest, node * vertex)
{
    if(vertex == NULL){
        cout << "vertex null nearest  val " << nearest->value << endl;
        return nearest;
    }

    cout << "cur_ver " << vertex->value << endl;
    if(vertex->value == value){
        cout << "eq" << endl;
        return vertex;
    }

    if(vertex->value < value){
        cout << "to right" << endl;
        if(nearest != NULL){
            cout << "nearest_val " << nearest->value << endl;
        }
        if(nearest == NULL || vertex->value > nearest->value){
            cout << "upd near" << endl;
            nearest = vertex;
        }
        return lower_bound(value, nearest, vertex->right);
    }
    if(vertex->value > value){
        cout << "to left " << endl;
        if(nearest != NULL){
            cout << "nearest_val " << nearest->value << endl;
        }
        if(nearest == NULL || vertex->value < nearest->value){
            cout << "upd near"<< endl;
            nearest = vertex;
        }
        return lower_bound(value, nearest, vertex->left);
    }
}

template <class T>    
typename Set<T>::node *Set<T>::find(T x, Set<T>::node *vertex) const
{
    if (vertex == NULL)
    {
        return NULL;
    }
    if (vertex->value == x){
        return vertex;
    }
    if(vertex->value < x){
        return find(x, vertex->right);
    }
    return find(x, vertex->left);
}

template <class T>    
typename Set<T>::node *Set<T>::find_min(Set<T>::node *vertex) const
{
    if (vertex->left == NULL)
        return vertex;
    return find_min(vertex->left);
}

template <class T>    
typename Set<T>::node *Set<T>::find_max(Set<T>::node *vertex) const
{
    if (vertex->right == NULL)
        return vertex;
    return find_max(vertex->right);
}