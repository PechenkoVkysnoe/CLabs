#include "tree.h"

Tree::Tree()
{
    my_size = 0;
    my_root = nullptr;
}
Tree::~Tree()
{
    RecursiveDeleteNode(my_root);
}
void Tree::clear()
{
    RecursiveDeleteNode(my_root);
}
int Tree::size()
{
    return my_size;
}
void Tree::RecursiveDeleteNode(Node* node)
{
    if (node)
    {
        RecursiveDeleteNode(node->left);
        RecursiveDeleteNode(node->right);
        delete node;
    }
}
bool Tree::empty()
{
    return (my_size == 0);
}
typename Tree::Node* Tree::find(Node* node, char key)
{
    if (key == node->key)
    {
        return node;
    }
    if (key < node->key)
    {
        if (node->left == nullptr)
        {
            return find(node->left, key);
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        if (node->right == nullptr)
        {
            return find(node->right, key);
        }
        else
        {
            return nullptr;
        }
    }
}
typename Tree::Node* Tree::find(char key)
{
    if (my_root == nullptr || key == my_root->key)
    {
        return my_root;
    }
    if (key < my_root->key)
    {
        return find(my_root->left, key);
    }
    else
    {
        return find(my_root->right, key);
    }
}
typename Tree::Node* Tree::next(char key)
{
    Node* now = my_root;
    Node* tmp = nullptr;
    while (now != nullptr)
    {
        if (now->key > key)
        {
            tmp = now;
            now = tmp->left;
        }
        else
        {
            now = now->right;
        }
    }
    return tmp;
}
typename Tree::Node* Tree::prev(char key)
{
    Node* now = my_root;
    Node* tmp = nullptr;
    while (now != nullptr)
    {
        if (now->key < key)
        {
            tmp = now;
            now = tmp->right;
        }
        else
        {
            now = now->left;
        }
    }
    return tmp;
}
void Tree::insert(char key)
{
    if (my_root == nullptr)
    {
        my_root = new Node(key);
        my_root->tree = this;
        my_size++;
    }
    else
    {
        insert(my_root, key);
    }
}
void Tree::insert(Node* node, char key)
{
    if ((int)key < (int)(node->key))
    {
        if (node->left == nullptr)
        {
            node->left = new Node(key);
            node->left->tree = this;
            node->left->next = next(node->left->key);
            node->left->prev = prev(node->left->key);
            if (node->left->next!= nullptr)
            {
                node->left->next = node->left;
            }
            if (node->left->prev != nullptr)
            {
                node->left->prev->next = node->left;
            }
        }
        else
        {
            insert(node->left, key);
        }
    }
    else if ((int)key > (int)(node->key))
    {
        if (node->right == nullptr)
        {
            node->right = new Node(key);
            node->right->tree = this;
            node->right->next = next(node->right->key);
            node->right->prev = prev(node->right->key);
            if (node->right->next != nullptr)
            {
                node->right->next->prev = node->right;
            }
            if (node->right->prev != nullptr)
            {
                node->right->prev->next = node->right;
            }
        }
        else
        {
            insert(node->right, key);
        }
    }
}
void Tree::erase(char key)
{
    if (my_root != nullptr)
    {
        erase(my_root, key);
    }
}
void Tree::erase(Node* node, char key)
{
    if (node->key > key)
    {
        erase(my_root->left, key, my_root);
    }
    else if (node->key < key)
    {
        erase(my_root->right, key, my_root);
    }
}
void Tree::erase(Node* node, char key, Node* parent)
{
    if (node->key < key)
    {
        erase(node->right, key, node);
    }
    if (node->key > key)
    {
        erase(node->left, key, node);
    }
    if (node->key == key)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (parent->left == node)
            {
                parent->left = nullptr;
                delete node;
                my_size--;
            }
            if (parent->right == node)
            {
                parent->right = nullptr;
                delete node;
                my_size--;
            }
        }
        if (node->left != nullptr && node->right != nullptr)
        {
            Node* tmpNode = node->right;
            Node* tmpParent = node;
            while (tmpNode->left != nullptr)
            {
                tmpNode = tmpNode->left;
                tmpParent = tmpNode;
            }
            char tmp = tmpNode->key;
            erase(tmpNode, tmp, tmpParent);
            node->key = tmp;
        }
        if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr))
        {
            if (node->left != nullptr)
            {
                if (parent->left == node)
                {
                    parent->left = node->left;
                    delete node;
                    my_size--;
                }
                if (parent->right == node)
                {
                    parent->right = node->left;
                    delete node;
                    my_size--;
                }
            }
            if (node->right != nullptr)
            {
                if (parent->left == node)
                {
                    parent->left = node->right;
                    delete node;
                    my_size--;
                }
                if (parent->right == node)
                {
                    parent->right = node->right;
                    delete node;
                    my_size--;
                }
            }
        }
    }
}
int Tree::MaxDepth()
{
    return MaxDepth(my_root);
}
int Tree::MaxDepth(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int lchild = MaxDepth(node->left);
        int rchild = MaxDepth(node->right);
        if (lchild <= rchild)
        {
            return rchild + 1;
        }
        else
        {
            return lchild + 1;
        }
    }
}