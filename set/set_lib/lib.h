#include <stdexcept>
#include <iterator>
using namespace std;

#include <bits/stdc++.h>

#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

template <typename T>
class Set
{

public:
    Set();

    Set(std::initializer_list<T> lst);

    Set(const Set &copy);

    Set &operator=(const Set &tree);

    void insert(T x);

    // void erase(T x);

    int size() const;

    bool empty() const;

private:
    struct node
    {
        T value;
        int count;
        node *left = NULL;
        node *right = NULL;
        int height;
    };

    node *root;
    int count;

    int height(node *vertex);

    node *find(T x, node *vertex) const;

    // typename Iterator lower_bound(T x, node * nearest = NULL, node * vertex = this->root);

    node *find_min(node *vertex) const;

    node *find_max(node *vertex) const;

    node *insert(T val, node *vertex);

    // node *erase(T val, node *vertex);

    node *smallRightRotate(node *vertex);

    node *smallLeftRotate(node *vertex);

    node *bigRightRotate(node *vertex);

    node *bigLeftRotate(node *vertex);

public:
    class Iterator
    {
    public:
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        Iterator() = default;
        explicit Iterator(node *vertex)
        {
            sort_nodes(vertex);
            sorted_nodes.push_back(nullptr);
        }

        reference operator*() const
        {
            return sorted_nodes[current]->value;
        }

        Iterator &operator++()
        {
            ++current;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++current;
            return tmp;
        }

        Iterator &operator--()
        {
            --current;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator tmp = *this;
            --current;
            return tmp;
        }

        bool operator==(const Iterator &rhs)
        {
            return sorted_nodes[current] == rhs.sorted_nodes[rhs.current];
        }

        bool operator!=(const Iterator &rhs)
        {
            return !(*this == rhs);
        }

    private:
        void sort_nodes(node *vertex)
        {
            if (vertex)
            {
                sort_nodes(vertex->left);
                sorted_nodes.push_back(vertex);
                sort_nodes(vertex->right);
            }
        }

        std::vector<node *> sorted_nodes;

        int current = 0;
    };

    typename Set::Iterator begin() const
    {
        return Iterator(root);
    }

    typename Set::Iterator end() const
    {
        return Iterator(nullptr);
    }

    typename Set::Iterator find(T x);

    typename Set<T>::Iterator lower_bound(T x);
    typename Set<T>::node *lower_bound(T x, node *nearest, node *vertex);
};

template class Set<int>;
template class Set<double>;

// template Set<int>::Iterator Set<int>::find(int);
// template void TestClass::templateFunction<int, int>(int, int);
// template class Set<int>(std::initializer_list<int>);
// template class Set<double>(std::initializer_list<double>);

#endif