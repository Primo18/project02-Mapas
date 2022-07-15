#include "MapSV.h"

MapSV::MapSV(int N)
{
    map.reserve(N);
}

MapSV::~MapSV()
{
}

void MapSV::insert(pair<string, int> par)
{
    auto it = upper_bound(map.begin(), map.end(), par);
    // if it->first == par.first, then key is already in the map
    if (it == map.end() || it->first != par.first)
    {
        map.insert(it, par);
    }
}

void MapSV::erase(const string &key)
{
    // binary search in the map to find the key and erase it
    auto it = upper_bound(map.begin(), map.end(), make_pair(key, 0));
    if (it != map.end() && it->first == key)
    {
        map.erase(it);
    }
}

int MapSV::at(const string &key)
{
    // binary search in the map to find the key
    auto it = upper_bound(map.begin(), map.end(), make_pair(key, 0));
    if (it == map.end() || it->first != key)
    {
        return -1;
    }
    else
    {
        return it->second;
    }
}

int MapSV::size()
{
    return map.size();
}

bool MapSV::empty()
{
    return map.empty();
}

void MapSV::print()
{
    cout << "MapSV:" << endl;
    for (int i = 0; i < map.size(); i++)
    {
        cout << "     "
             << "index " << i
             << ": (" << map[i].first << ", " << map[i].second << ")"
             << endl;
    }
}