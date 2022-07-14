#include "Map.h"

class MapSV : public Map
{
private:
    int mapSize;

public:
    MapSV();
    ~MapSV();

    void insert(pair<string, int>);
    void erase(const string &);
    int at(const string &);
    int size();
    bool empty();
    void print();
};