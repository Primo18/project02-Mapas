#if !defined(MAPAVL_H)
#define MAPAVL_H

#include "Map.h"

class Node
{
public:
    string key;
    int value;
    Node *left;
    Node *right;
    int height;
    Node(pair<string, int>);
};

class MapAVL : public Map
{
private:
    int mapSize;
    Node *root;
    void deleteRecursive(Node *&node);
    int max(int a, int b);
    int height(Node *node);
    void updateHeight(Node *&node);
    void rotateLeft(Node *&node);
    void rotateRight(Node *&node);
    void balance(Node *&node);
    void printInorder(Node *node);

public:
    MapAVL();
    ~MapAVL();

    void insert(pair<string, int>);
    void erase(const string &);
    int at(const string &);
    int size();
    bool empty();
    void print();
};

#endif // MAPAVL_H