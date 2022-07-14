#include "Map.h"

class MapSV : public Map
{
private:
    int sizeMap;

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