#if !defined(MAPHASH_H)
#define MAPHASH_H

#include "Map.h"

class MapHash : public Map
{
private:
    int mapSize;
    int capacity;
    vector<int> primes;
    pair<string, int> *hashtable;
    void duplicate();
    int hashfunction(string);
    int d(string); // new function for double hashing
    void insert(pair<string, int>, pair<string, int> *hashtable);
    int smallestPrime(int);

public:
    MapHash(int N);
    ~MapHash();

    void insert(pair<string, int>);
    void erase(const string &);
    int at(const string &);
    int size();
    bool empty();
    void print();
};

#endif // MAPHASH_H