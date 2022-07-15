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
    // Node *newNode(pair<string, int>);
    // int height(Node *node);
    // void rotateLeft(Node *&node);
    // void rotateRight(Node *&node);
    // void balance(Node *&node);
    // void print(Node *node);

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