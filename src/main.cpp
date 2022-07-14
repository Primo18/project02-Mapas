#include "MapAVL.h"
#include "MapSV.h"
#include "MapHash.h"

int main(int argc, char const *argv[])
{
    int N = 40;
    MapAVL *mapAVL = new MapAVL();
    MapHash *mapHash = new MapHash(N);
    MapSV *mapSV = new MapSV();

    // Read dic
    ifstream ifile;
    ifile.open("dic/dic.txt");
    string s;
    clock_t start;
    clock_t end;
    vector<string> listString;
    int randNum;

    if (ifile.is_open())
    {
        while (listString.size() != N)
        {
            ifile >> s;
            // Obtener solo palabras con longitud igual a 6
            if (s.size() == 6)
            {
                listString.push_back(s);
            }
        }
        // Mezclar aleatoriamente la lista de strings
        random_shuffle(listString.begin(), listString.end());
        ifile.close();
    }
    else
    {
        cout << "No se pudo abrir el diccionario" << endl;
    }

    // Tiempo total métodos MapAVL
    double insert_MapAVL = 0; // Tiempo total de insertar un par llave-valor N veces
    double at_MapAVL = 0;     // Tiempo total de encontrar el valor asociado a una llave k, N veces
    double erase_MapAVL = 0;  // Tiempo total de eliminar el valor asociado a una llave k, N veces

    // Tiempo total métodos MapHash
    double insert_MapHash = 0; // Tiempo total de insertar un par llave-valor N veces
    double at_MapHash = 0;     // Tiempo total de encontrar el valor asociado a una llave k, N veces
    double erase_MapHash = 0;  // Tiempo total de eliminar el valor asociado a una llave k, N veces

    // Tiempo total métodos MapSV
    double insert_MapSV = 0; // Tiempo total de insertar un par llave-valor N veces
    double at_MapSV = 0;     // Tiempo total de encontrar el valor asociado a una llave k, N veces
    double erase_MapSV = 0;  // Tiempo total de eliminar el valor asociado a una llave k, N veces

    // /*******************************   MapAVL   *******************************/
    // insert()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        randNum = rand() % 1000 + 1;
        mapAVL->insert(make_pair(listString.at(i), randNum));
    }
    end = clock();
    insert_MapAVL += (double)(end - start) / CLOCKS_PER_SEC;

    // at()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapAVL->at(listString.at(i));
    }
    end = clock();
    at_MapAVL += (double)(end - start) / CLOCKS_PER_SEC;

    // erase()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapAVL->erase(listString.at(i));
    }
    end = clock();
    erase_MapAVL += (double)(end - start) / CLOCKS_PER_SEC;

    /*******************************   MapHash   *******************************/
    // insert()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        randNum = rand() % 1000 + 1;
        mapHash->insert(make_pair(listString.at(i), randNum));
    }
    end = clock();
    insert_MapHash += (double)(end - start) / CLOCKS_PER_SEC;

    mapHash->print();

    // at()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapHash->at(listString.at(i));
    }
    end = clock();
    at_MapHash += (double)(end - start) / CLOCKS_PER_SEC;

    // erase()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapHash->erase(listString.at(i));
    }
    end = clock();
    erase_MapHash += (double)(end - start) / CLOCKS_PER_SEC;

    mapHash->print();

    /*******************************   MapSV   *******************************/
    // insert()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        randNum = rand() % 1000 + 1;
        mapSV->insert(make_pair(listString.at(i), randNum));
    }
    end = clock();
    insert_MapSV += (double)(end - start) / CLOCKS_PER_SEC;

    mapSV->print();

    // at()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapSV->at(listString.at(i));
    }
    end = clock();
    at_MapSV += (double)(end - start) / CLOCKS_PER_SEC;

    // erase()
    start = clock();
    for (int i = 0; i < N; i++)
    {
        mapSV->erase(listString.at(i));
    }
    end = clock();
    erase_MapSV += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n***** Tiempo total con %d pares <string, int> *****\n\n", N);
    // MapAVL
    printf("MapAVL: Insert %d elements = %.10f seconds.\n", N, insert_MapAVL);
    printf("MapAVL: At %d elements   = %.10f seconds.\n", N, at_MapAVL);
    printf("MapAVL: Erase %d elements   = %.10f seconds.\n\n", N, erase_MapAVL);

    // MapHash
    printf("MapHash: Insert %d elements = %.10f seconds.\n", N, insert_MapHash);
    printf("MapHash: At %d elements   = %.10f seconds.\n", N, at_MapHash);
    printf("MapHash: Erase %d elements   = %.10f seconds.\n\n", N, erase_MapHash);

    // MapSV
    printf("MapSV: Insert %d elements = %.10f seconds.\n", N, insert_MapSV);
    printf("MapSV: At %d elements   = %.10f seconds.\n", N, at_MapSV);
    printf("MapSV: Erase %d elements   = %.10f seconds.\n\n", N, erase_MapSV);

    delete mapAVL;
    delete mapHash;
    delete mapSV;
    return 0;
}
