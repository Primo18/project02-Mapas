#include "MapAVL.h"

Node::Node(pair<string, int> par)
{
    this->key = par.first;
    this->value = par.second;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;
}

Node *newNode(pair<string, int> par)
{
    Node *node = new Node(par);
    return node;
}

MapAVL::MapAVL()
{
    this->mapSize = 0;
    this->root = NULL;
}

void MapAVL::deleteRecursive(Node *&node)
{
    if (node == NULL)
        return;
    deleteRecursive(node->left);
    deleteRecursive(node->right);
    delete node;
}

MapAVL::~MapAVL()
{
    this->mapSize = 0;
    // delete recursively the tree in postorder
    deleteRecursive(this->root);
}

// return the max of two integers
int MapAVL::max(int a, int b)
{
    return (a > b) ? a : b;
}

// function to get the height of the tree
int MapAVL::height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// function to update the height of the tree
void MapAVL::updateHeight(Node *&node)
{
    int lh = height(node->left);
    int rh = height(node->right);
    node->height = max(lh, rh) + 1;
}

// function to rotate the tree to the left
void MapAVL::rotateLeft(Node *&node)
{
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    updateHeight(node);
    updateHeight(temp);
    node = temp;
}

// function to rotate the tree to the right
void MapAVL::rotateRight(Node *&node)
{
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    updateHeight(node);
    updateHeight(temp);
    node = temp;
}

// function to balance the tree
void MapAVL::balance(Node *&node)
{
    if (node == NULL)
        return;

    updateHeight(node);
    if (height(node->left) - height(node->right) == 2)
    {
        if (height(node->left->left) >= height(node->left->right))
            rotateRight(node);
        else
        {
            rotateLeft(node->left);
            rotateRight(node);
        }
    }
    else if (height(node->right) - height(node->left) == 2)
    {
        if (height(node->right->right) >= height(node->right->left))
            rotateLeft(node);
        else
        {
            rotateRight(node->right);
            rotateLeft(node);
        }
    }
}

// function to insert a key-value pair in the tree
void MapAVL::insert(pair<string, int> par)
{
    Node *node = newNode(par);
    if (root == NULL)
    {
        root = node;
        mapSize++;
        return;
    }
    Node *temp = root;
    while (true)
    {
        if (node->key < temp->key)
        {
            if (temp->left == NULL)
            {
                temp->left = node;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = node;
                break;
            }
            else
                temp = temp->right;
        }
    }
    mapSize++;
    balance(root);
}

// return the value associated with the given key
// if the key is not found, return -1
int MapAVL::at(const string &key)
{
    if (this->root == NULL)
        return -1;
    Node *temp = this->root;
    while (temp != NULL)
    {
        if (temp->key == key)
            return temp->value;
        if (key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return -1;
}

int MapAVL::size()
{
    return this->mapSize;
}

bool MapAVL::empty()
{
    return this->mapSize == 0;
}

// print the tree inorder
void MapAVL::printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << "\t" << node->key << " " << node->value << endl;
    printInorder(node->right);
}

void MapAVL::print()
{
    cout << "MapAVL: " << endl;
    printInorder(this->root);
}

// delete the node with the given key
void MapAVL::erase(const string &key)
{
    // if the tree is empty, do nothing
    if (root == NULL)
        return;

    Node *temp = root;
    Node *parent = NULL;

    // if the key is not found, do nothing
    while (temp != NULL)
    {
        if (temp->key == key)
            break;
        parent = temp;
        if (key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (temp == NULL)
        return;

    // *** if the key is found, delete the node and rebalance the tree ***

    // if the node is a leaf, delete it
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent == NULL)
            root = NULL;
        else if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete temp;
        mapSize--;
        balance(root);
        return;
    }

    // if the node has one child, delete it and replace it with its child
    if (temp->left == NULL || temp->right == NULL)
    {
        Node *child = (temp->left == NULL) ? temp->right : temp->left;
        if (parent == NULL)
            root = child;
        else if (parent->left == temp)
            parent->left = child;
        else
            parent->right = child;
        delete temp;
        mapSize--;
        balance(root);
        return;
    }

    // if the node has two children, delete it and replace it with its successor
    Node *successor = temp->right;
    parent = temp;
    while (successor->left != NULL)
    {
        parent = successor;
        successor = successor->left;
    }
    if (parent->left == successor)
        parent->left = successor->right;
    else
        parent->right = successor->right;
    temp->key = successor->key;
    temp->value = successor->value;
    delete successor;
    mapSize--;
    balance(root);

    // *** end of delete ***
}
