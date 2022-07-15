#include "MapHash.h"

MapHash::MapHash(int N)
{
    mapSize = 0;
    capacity = N;
    primes = {
        11,
        23,
        43,
        101,
        503,
        1009,
        2053,
        3001,
        4111,
        5003,
        6007,
        7001,
        8231,
        9203,
        10007,
        12037,
        14009,
        16477,
        20021,
        41011,
        100003,
    };
    hashtable = new pair<string, int>[smallestPrime(capacity)];
}

MapHash::~MapHash()
{
    delete[] hashtable;
}

int MapHash::smallestPrime(int N)
{
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] >= N)
        {

            return primes[i];
        }
    }
    return -1;
}

// Hash Codes: Component sum with 7-bit encoding, base 128 number
int MapHash::hashfunction(string s)
{
    int h = 0;
    int a = 127;
    for (char c : s)
    {
        h = (a * h + c) % capacity;
    }
    return h;
}

//  second hash function: cyclick-shift
int MapHash::d(string s)
{
    unsigned int h = 0;

    for (char c : s)
    {
        h = (h << 5) | (h >> 27);
        h += (int)c;
    }

    return 7 - (h % 7);
}

void MapHash::insert(pair<string, int> par)
{
    string s = par.first;
    int i = hashfunction(s);
    int k = d(s);
    int p = 0;

    mapSize++;
    double alfa = mapSize / (double)capacity; // Factor de carga alfa
    if (alfa >= 0.5)
    {
        duplicate();
        i = hashfunction(s);
    }

    for (int j = 0; j < capacity; j++)
    {
        if (hashtable[i].first.empty() || hashtable[i].first == "NULL" || hashtable[i].first == s)
        {
            hashtable[i] = par;
            return;
        }
        else
        {
            i = (i + p * k) % capacity;
            p++;
        }
    }
}

// Para insertar elementos al hacer rehashing con duplicate() en la hashtable temporal
void MapHash::insert(pair<string, int> par, pair<string, int> *hashtable)
{
    string s = par.first;
    int i = hashfunction(s);
    int k = d(s);
    int p = 0;

    for (int j = 0; j < capacity; j++)
    {
        if (hashtable[i].first.empty() || hashtable[i].first == "NULL" || hashtable[i].first == s)
        {
            hashtable[i] = par;
            return;
        }
        else
        {
            i = (i + p * k) % capacity;
            p++;
        }
    }
}

void MapHash::erase(const string &key)
{
    int p = 0;
    int i = hashfunction(key);
    int k = d(key);

    if (size() == 0)
    {
        cout << "Error, mapa vacío" << endl;
        return;
    }

    for (int j = 0; j < capacity; j++)
    {
        if (hashtable[i].first.empty())
        {
            cout << "DH ERASE key not found: " << key << endl;
            return;
        }
        else if (hashtable[i].first == key)
        {
            hashtable[i] = {"NULL", 0};
            mapSize--;
            return;
        }
        else
        {
            i = (i + p * k) % capacity;
            p++;
        }
    }
}

int MapHash::at(const string &key)
{
    int p = 0;
    int i = hashfunction(key);
    int k = d(key);

    for (int j = 0; j < capacity; j++)
    {
        if (hashtable[i].first.empty())
        {
            cout << "DH AT key not found  : " << key << endl;
            return -1;
        }
        else if (hashtable[i].first == key)
        {
            return hashtable[i].second;
        }
        else
        {
            i = (i + p * k) % capacity;
            p++;
        }
    }
    cout << "key not found: " << key << endl;
    return -1;
}

int MapHash::size()
{
    return mapSize;
}

bool MapHash::empty()
{
    return mapSize;
}

void MapHash::duplicate()
{
    int oldCapacity = capacity;
    capacity = smallestPrime(capacity * 2);
    pair<string, int> *temp = new pair<string, int>[capacity];
    for (int i = 0; i < oldCapacity; i++)
    {
        if (!hashtable[i].first.empty() && hashtable[i].first != "NULL")
        {
            insert(hashtable[i], temp);
        }
    }
    delete[] hashtable;
    hashtable = temp;
}

void MapHash::print()
{
    cout << "MapHash:" << endl;
    for (int i = 0; i < capacity; i++)
    {
        if (true) //! hashtable[i].first.empty() && hashtable[i].first != "NULL"
        {
            cout << "     "
                 << "index " << i
                 << ": (" << hashtable[i].first << ", " << hashtable[i].second << ")"
                 << endl;
        }
    }
}