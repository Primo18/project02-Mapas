#include "Map.h"

class MapSV : public Map
{
private:
    vector<pair<string, int>> map;

public:
    MapSV(int N);
    ~MapSV();

    void insert(pair<string, int>);
    void erase(const string &);
    int at(const string &);
    int size();
    bool empty();
    void print();
};