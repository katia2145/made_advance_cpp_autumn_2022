#include <iostream>
#include "lib.h"
#include <bits/stdc++.h>

using namespace std;

// template <class T>
// void Set<T>::erase(T x)
// {
//     erase(x, this->root);
// }

// template <class T>
// typename Set<T>::node* erase(T value, typename Set<T>::node* vertex)
// {
//     Set<T>::node* cur;
//     if(vertex == NULL)
//         return NULL;

//     if(value < vertex->value)
//         vertex->left = erase(value, vertex->left);
//     else if(value < vertex->value)
//         vertex->right = erase(value, vertex->right);

//     else if(vertex->left && vertex->right)
//     {
//         cur = findMin(vertex->right);
//         vertex->value = cur->value;
//         vertex->right = erase(cur->value, vertex->right);
//     }
//     else
//     {
//         cur = vertex;
//         if(vertex->left == NULL)
//             vertex = vertex->right;
//         else if(vertex->right == NULL)
//             vertex = vertex->left;
//         delete cur;
//     }
//     if(vertex == NULL)
//         return vertex;

//     vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

//     if(height(vertex->left) - height(vertex->right) == 2)
//     {
//         if(height(vertex->left->left) - height(vertex->left->right) == 1)
//             return singleLeftRotate(vertex);
//         else
//             return doubleLeftRotate(vertex);
//     }
//     else if(height(vertex->right) - height(vertex->left) == 2)
//     {
//         if(height(vertex->right->right) - height(vertex->right->left) == 1)
//             return singleRightRotate(vertex);
//         else
//             return doubleRightRotate(vertex);
//     }
//     return vertex;
// }
