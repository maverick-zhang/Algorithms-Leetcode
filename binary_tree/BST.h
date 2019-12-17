//
// Created by maverick on 2019/12/16.
//

#ifndef ALGORITHMS_BST_H
#define ALGORITHMS_BST_H

#include <queue>


//BST:binary_search_tree 二分查找树
//二分查找树满足如下条件：树的每个节点有key和value组成，左子树的key小于自身的key, 右子树的key大于当前的key


template <typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node * left;
        Node * right;

        Node(Key key_, Value value_, Node * l = nullptr, Node * r = nullptr )
        :key(key_), value(value_), left(l), right(r){}

        explicit Node(Node * node)
        {
            key = node->key;
            value = node->value;
            left = node->left;
            right = node->right;
        }

    };

    Node * root;
    int count;

    Node *__search(Node * node, Key key)
    {

        if (node == nullptr or node->key == key)
            return node;
        else if (node->key < key)
            return __search(node->right, key);
        else
            return __search(node->left, key);
    }


    void __for_each_pre(Node * node_, void (*func)(Node * node))
    {
        if (node_ == nullptr)
            return;
        func(node_);
        __for_each_pre(node_->left, func);
        __for_each_pre(node_->right, func);
    }


    void __for_each_in(Node * node_, void (*func)(Node * node))
    {
        if (node_ == nullptr)
            return;
        __for_each_in(node_->left, func);
        func(node_);
        __for_each_in(node_->right, func);
    }


    void __for_each_post(Node * node_, void (*func)(Node * node))
    {
        if (node_ == nullptr)
            return;
        __for_each_post(node_->left, func);
        __for_each_post(node_->right, func);
        func(node_);

    }

    void __insert(Node * node1, Key key, Value value)
    {

        if (node1->key == key)
        {
            node1->value = value;
            return;
        }
        if (node1->key < key)
        {
            if (node1->right == nullptr)
            {
                Node * node = new Node(key, value);
                count ++;
                node1->right = node;
                return;
            }
            return __insert(node1->right, key, value);

        }
        if (node1->key > key)
        {
            if (node1->left == nullptr)
            {
                Node * node = new Node(key, value);
                count ++;
                node1->left = node;
                return;
            }
            return __insert(node1->left, key, value);
        }
    }

    Node * find_min(Node * node)
    {
        if (node->left == nullptr)
            return node;
        else
            return find_min(node->left);
    }

    bool __remove(Node * node, Key key)
    {
        if (node == nullptr)
            return false;
        if (node->key > key)
            return __remove(node->left, key);
        if (node->key < key)
            return __remove(node->right, key);

        Node * temp = new Node(node);

        if (node->left == nullptr)
        {
            delete node;
            node = temp->right;
            delete temp;
            count --;
            return true;
        }
        if (node->right == nullptr)
        {
            delete node;
            node = temp->left;
            delete temp;
            count --;
            return true;
        }
        delete node;
        Node * min_right_child;
        min_right_child = find_min(node->right);
        min_right_child->left = temp->left;
        min_right_child->right = temp->right;
        node = Node(min_right_child);
        delete min_right_child;
        count --;
        return true;
    }



public:
    BST (Key key, Value value)
    {
        root = new Node (key, value);
        count = 1;
    }

    ~BST()
    {

    }

    Node * search(Key key)
    {
        if (is_empty())
            return nullptr;
        return __search(root, key);
    }

    bool is_empty()
    {
        return count == 0;
    }

    void for_each_preOrder(void (*func)(Node * node))
    {
        __for_each_pre(root, func);
    }

    void for_each_inOrder(void (*func)(Node * node))
    {
        __for_each_in(root, func);
    }

    void for_each_postOrder(void(*func)(Node * node))
    {
        __for_each_post(root, func);
    }

    void for_each_width_first(void(*func)(Node * node))
    {
        std::queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node * node = que.front();
            que.pop();
            func(node);
            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
                que.push(node->right);
        }
    }

    void insert(Key key, Value value)
    {
        __insert(root, key, value);
    }

    bool remove(Key key)
    {
        return __remove(root, key);
    }

};




#endif //ALGORITHMS_BST_H
