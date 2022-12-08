#include<iostream>
#include "lib.h"

using namespace std;

int AVLTree::height(AVLTree::node* vertex)
{
    return (vertex == NULL ? -1 : vertex->height);
}

void AVLTree::insert(int x){
    node * root = this->root;
    insert(x, root);
}

AVLTree::node* AVLTree::insert(int value, node* vertex)
{
    if(vertex == nullptr)
    {
        vertex = new node;
        vertex->value = value;
        vertex->count = 1;
        vertex->height = 0;
        vertex->left = nullptr;
        vertex->right = nullptr;
        return vertex;
    }
    
    if(value == vertex->value){
        vertex->count += 1;
        return vertex;
    }

    if(value < vertex->value)
    {
        vertex->left = insert(value, vertex->left);
        if(height(vertex->left) - height(vertex->right) == 2)
        {
            if(value < vertex->left->value)
                vertex = smallRightRotate(vertex);
            else
                vertex = bigRightRotate(vertex);
        }
    }
    else
    {
        vertex->right = insert(value, vertex->right);
        if(height(vertex->right) - height(vertex->left) == 2)
        {
            if(value < vertex->right->value)
                vertex = bigRightRotate(vertex);
            else
                vertex = smallRightRotate(vertex);
        }
    }

    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;
    return vertex;
}

AVLTree::node* AVLTree::smallRightRotate(AVLTree::node* vertex)
{
    node* v_left = vertex->left;
    vertex->left = v_left->right;
    v_left->right = vertex;
    v_left->height = max(height(v_left->left), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;
    
    return v_left;
}

AVLTree::node* AVLTree::smallLeftRotate(AVLTree::node* vertex)
{
    node* v_left = vertex->right;
    vertex->right = v_left->left;
    v_left->left = vertex;
    v_left->height = max(height(v_left->right), vertex->height) + 1;
    vertex->height = max(height(vertex->left), height(vertex->right)) + 1;
    
    return v_left;
}

AVLTree::node* AVLTree::bigRightRotate(AVLTree::node* vertex){
    vertex->left = smallLeftRotate(vertex->left);
    vertex = smallRightRotate(vertex);
    return vertex;
}

AVLTree::node* AVLTree::bigLeftRotate(AVLTree::node* vertex){
    vertex->right = smallRightRotate(vertex->right);
    vertex = smallLeftRotate(vertex);
    return vertex;
}