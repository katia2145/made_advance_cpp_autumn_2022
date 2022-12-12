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
    int counter;
    Set()
    {
        this->root = NULL;
        this->counter = 0;
    }

    Set(std::initializer_list<T> lst)
    {
        // cerr  << "initializer" << endl;
        this->counter = 0;
        this->root = new node;
        for (auto elm : lst)
        {
            // cerr  << "initializer " << elm << endl;
            this->root = this->insert(elm, NULL);
            this->counter += 1;
            // cerr  << "insert ok " << endl;
        }
        // cerr  << "initializer " << this->counter << endl;
    }

    template<class InputIterator>
    Set(InputIterator begin_set, InputIterator end_set){
        this->counter = 0;
        this->root = NULL;
        for (auto i = begin_set; i != end_set; ++i)
        {
            auto v = *i;
            this->insert(v);
        }
        // this->display();
        // cerr  << "two initializer " << this->counter << endl;
    }

    Set(const Set &copy)
    {
        // cerr  << "copy " << copy.counter << endl;
        // this->counter = copy.counter;
        this->root = NULL;
        for(auto elm : copy){
            // cerr << elm << endl;
            this->insert(elm);
            // cerr << "ok insert" << endl;
        }
        // this->root = copy_nodes(copy.root);
        // this->root = copy.root;
        // cerr << "ok copy" << endl;
    }

    ~Set()
    {
        deep_delete(this->root);
        // cerr << "return " << this->counter << endl;
        // delete &(this->counter);
    }

    Set &operator=(const Set &tree)
    {
        // cerr  << "=" << endl;
        this->root = tree.root;
        this->counter = tree.counter;
        // cerr << "= ok" << endl;
        return *this;
    }

    void insert(T x)
    {
        // cerr  << "insert " << x << endl;
        this->counter += 1;
        this->root = insert(x, this->root);
        // cerr  << "ok in insert " << x << endl;
    }

    // void erase(T x);

    int size() const
    {
        return this->counter;
    }

    bool empty() const
    {
        if (this->root == NULL)
            return true;
        return false;
    }

private:
    struct node
    {
        T value;
        int counter;
        node *left = NULL;
        node *right = NULL;
        int height;
    };

    node *root;

    int height(node *vertex)
    {
        if (vertex == NULL)
            return -1;
        return vertex->height;
    }

    node *find(T x, node *vertex) const
    {
        if (vertex == NULL)
        {
            return NULL;
        }
        if (x < vertex->value)
        {
            return find(x, vertex->left);
        }
        else if (vertex->value < x)
        {
            return find(x, vertex->right);
        }
        else
        {
            return vertex;
        }
    }

    node *find_min(node *vertex) const
    {
        if (vertex->left == NULL)
            return vertex;
        return find_min(vertex->left);
    }

    node *find_max(node *vertex) const
    {
        if (vertex->right == NULL)
            return vertex;
        return find_max(vertex->right);
    }

    node *insert(T value, node *vertex)
    {
        if (vertex == NULL)
        {
            // cerr  << "vertex null" << endl;
            vertex = new node;
            vertex->value = value;
            vertex->counter = 1;
            vertex->height = 0;
            vertex->left = NULL;
            vertex->right = NULL;
            return vertex;
        }

        // cerr  << "vertex val " << vertex->value << endl;
        if (value < vertex->value)
        {
            // cerr  << "to left" << endl;
            vertex->left = insert(value, vertex->left);
            // cerr  << "return from insert to left" << endl;
            // cerr  << "height " << height(vertex->left) << " " << height(vertex->right) << endl;
            if (height(vertex->left) - height(vertex->right) == 2)
            {
                // cerr  << "swap" << endl;
                if (value < vertex->left->value)
                    vertex = smallRightRotate(vertex);
                else
                    vertex = bigRightRotate(vertex);
            }
        }
        else if (vertex->value < value)
        {
            // cerr  << "to right" << endl;
            vertex->right = insert(value, vertex->right);
            // cerr  << "return from insert to right" << endl;
            // cerr  << "height " << height(vertex->right) << " " << height(vertex->left) << endl;
            if (height(vertex->right) - height(vertex->left) == 2)
            {
                // cerr  << "swap" << endl;
                if (vertex->right->value < value)
                    vertex = smallRightRotate(vertex);
                else
                    vertex = bigRightRotate(vertex);
            }
        }
        else
        {
            // cerr  << "eq" << endl;
            return vertex;
        }

        // cerr  << "main " << height(vertex->left) << " " << height(vertex->right) << endl;
        vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

        // cerr  << "return" << endl;
        return vertex;
    }

    // node *erase(T val, node *vertex);

    void deep_delete(node *vertex)
    {
        if (vertex == NULL)
        {
            // cerr  << "vertex null" << vertex << endl;
            return;
        }
        // cerr  << "delete " << vertex->value << endl;
        deep_delete(vertex->left);
        deep_delete(vertex->right);
        // cerr  << "was deleted " << endl;
        delete vertex;
    }

    node *copy_nodes(node *cp_vertex)
    {
        if (cp_vertex == NULL)
        {
            cerr << "copy null" << endl;
            return NULL;
        }
        cerr << "cur " << cp_vertex->value << endl;
        cerr << "to left" << endl;
        node *tmp_left = copy_nodes(cp_vertex->left);
        cerr << "to right" << endl;
        node *tmp_right = copy_nodes(cp_vertex->right);
        node *vertex;
        vertex->left = tmp_left;
        vertex->right = tmp_right;
        cerr << "return vertex" << endl;
        return vertex;
    }

    node *smallRightRotate(node *vertex)
    {
        if(vertex == NULL){
            return NULL;
        }
        // cerr  << "smallRightRotate1" << endl;
        node *v_left = vertex->left;

        // cerr  << "smallRightRotate2" << endl;
        if (v_left == NULL)
        {
            // cerr  << "smallRightRotate3" << endl;
            vertex->left = NULL;
            v_left = new node;
        }
        else
        {
            // cerr  << "smallRightRotate4" << endl;
            vertex->left = v_left->right;
        }
        // cerr  << "smallRightRotate5" << endl;
        v_left->right = vertex;
        v_left->height = max(height(v_left->left), vertex->height) + 1;
        vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

        // cerr  << "smallRightRotate6" << endl;
        return v_left;
    }

    node *smallLeftRotate(node *vertex)
    {   
        if(vertex == NULL){
            return NULL;
        }
        // cerr  << "smallLeftRotate1" << endl;
        node *v_right = vertex->right;

        // cerr  << "smallLeftRotate2" << endl;
        if (v_right == NULL)
        {
            // cerr  << "smallLeftRotate3" << endl;
            vertex->right = NULL;
            v_right = new node;
        }
        else
        {
            // cerr  << "smallLeftRotate4" << endl;
            vertex->right = v_right->left;
        }

        // cerr  << "smallLeftRotate5" << endl;
        v_right->left = vertex;
        v_right->height = max(height(v_right->right), vertex->height) + 1;
        vertex->height = max(height(vertex->left), height(vertex->right)) + 1;

        // cerr  << "smallLeftRotate6" << endl;
        return v_right;
    }

    node *bigRightRotate(node *vertex)
    {
        // cerr  << "bigRightRotate1 " << " " << vertex->value << endl;
        vertex->left = smallLeftRotate(vertex->left);
        // cerr  << "bigRightRotate2" << endl;
        vertex = smallRightRotate(vertex);
        // cerr  << "bigRightRotate3" << endl;
        return vertex;
    }

    node *bigLeftRotate(node *vertex)
    {
        vertex->right = smallRightRotate(vertex->right);
        vertex = smallLeftRotate(vertex);
        return vertex;
    }

public:
    void display() const
    {
        inorder(this->root);
        cout << endl;
    }
    
    void inorder(node* t) const
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->value << " ";
        inorder(t->right);
    }

    class iterator
    {
    public:
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        iterator() = default;
        explicit iterator(node *vertex)
        {
            sort_nodes(vertex);
            sorted_nodes.push_back(nullptr);
        }

        reference operator*() const
        {
            return sorted_nodes[current]->value;
        }

        iterator &operator++()
        {
            ++current;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++current;
            return tmp;
        }

        iterator &operator--()
        {
            --current;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp = *this;
            --current;
            return tmp;
        }

        bool operator==(const iterator &rhs)
        {
            return sorted_nodes[current] == rhs.sorted_nodes[rhs.current];
        }

        bool operator!=(const iterator &rhs)
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

    typename Set::iterator begin() const
    {
        return iterator(root);
    }

    typename Set::iterator end() const
    {
        return iterator(nullptr);
    }

    typename Set::iterator find(T x) const
    {
        node *answer = find(x, this->root);
        return iterator(answer);
    }

    typename Set<T>::iterator lower_bound(T x)
    {
        node *answer = lower_bound(x, NULL, this->root);
        // cerr  << "return " << answer->value << endl;
        return iterator(answer);
    }

    typename Set<T>::node *lower_bound(T value, node *nearest, node *vertex)
    {
        if (vertex == NULL)
        {
            // cerr << "vertex null nearest  val " << nearest->value << endl;
            return nearest;
        }

        // cerr  << "cur_ver " << vertex->value << endl;

        if (vertex->value < value)
        {
            // cerr  << "to right" << endl;
            if (nearest != NULL)
            {
                // cerr  << "nearest_val " << nearest->value << endl;
            }
            if (nearest == NULL || nearest->value < vertex->value)
            {
                // cerr  << "upd near" << endl;
                nearest = vertex;
            }
            return lower_bound(value, nearest, vertex->right);
        }
        else if (value < vertex->value)
        {
            // cerr  << "to left " << endl;
            if (nearest != NULL)
            {
                // cerr  << "nearest_val " << nearest->value << endl;
            }
            if (nearest == NULL || vertex->value < nearest->value)
            {
                // cerr  << "upd near" << endl;
                nearest = vertex;
            }
            return lower_bound(value, nearest, vertex->left);
        }
        else{
            // cerr  << "eq" << endl;
            return vertex;
        }
    }
};

// template class Set<int>;
// template class Set<double>;
// template class Set<string>;
// template class Set<pair<int, int>>;

// template Set<int>::iterator Set<int>::find(int);
// template void TestClass::templateFunction<int, int>(int, int);
// template class Set<int>(std::initializer_list<int>);
// template class Set<double>(std::initializer_list<double>);

#endif