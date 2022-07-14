#include "Map.h"

class MapAVL : public Map
{
private:
    int sizeMap;

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