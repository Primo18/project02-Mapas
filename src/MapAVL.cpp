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

// function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// A utility function to get the height of the tree
int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void rotateLeft(Node *&node)
{
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    node = temp;
}

void rotateRight(Node *&node)
{
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    node = temp;
}

void balance(Node *&node)
{
    if (node == NULL)
        return;
    if (height(node->left) - height(node->right) > 1)
    {
        if (height(node->left->left) >= height(node->left->right))
            rotateRight(node);
        else
        {
            rotateLeft(node->left);
            rotateRight(node);
        }
    }
    else if (height(node->right) - height(node->left) > 1)
    {
        if (height(node->right->right) >= height(node->right->left))
            rotateLeft(node);
        else
        {
            rotateRight(node->right);
            rotateLeft(node);
        }
    }
    node->height = max(height(node->left), height(node->right)) + 1;
}

MapAVL::MapAVL()
{
    this->mapSize = 0;
    this->root = NULL;
}

MapAVL::~MapAVL()
{
}

void MapAVL::insert(pair<string, int> par)
{
    Node *node = newNode(par);
    if (this->root == NULL)
    {
        this->root = node;
        this->mapSize++;
        return;
    }
    Node *temp = this->root;
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
        else if (node->key > temp->key)
        {
            if (temp->right == NULL)
            {
                temp->right = node;
                break;
            }
            else
                temp = temp->right;
        }
        else
        {
            temp->value = node->value;
            delete node;
            return;
        }
    }
    balance(this->root);
    this->mapSize++;
}

void MapAVL::erase(const string &)
{
}

int MapAVL::at(const string &)
{
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
void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->key << " " << node->value << endl;
    printInorder(node->right);
}

void MapAVL::print()
{
    printInorder(this->root);
}
