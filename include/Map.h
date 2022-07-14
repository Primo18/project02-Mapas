#if !defined(MAP_H_)
#define MAP_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Map
{
public:
    virtual void insert(pair<string, int>) = 0; // Insertar un par llave-valor, no admite claves repetidas
    virtual void erase(const string &) = 0;     // Eliminar el par clave-valor asociado a una clave
    virtual int at(const string &) = 0;         // Encontrar el valor asociado a una llave k, debe ser probado únicamente con claves en el Mapa
    virtual int size() = 0;                     // Obtener cantidad de elementos almacenados
    virtual bool empty() = 0;                   // Verificar si está vacía
};

#endif // MAP_H_
