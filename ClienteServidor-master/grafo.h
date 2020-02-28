#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class arista;

class vertice{
   public:
   vertice *sig;
   arista *ady;
   string nombre;
   friend class Grafo;


};

class arista{
    public:
    arista *sig;
    vertice *ady;
    int peso;
    friend class Grafo;


};

class Grafo
{
    vertice *h;
public:
    void Inicializa();
    bool Vacio();
    int Tamano();
    vertice *getvertice(string nombre);
    void insertararista(vertice *origen,vertice *destino ,int peso);
    void insertarvertice(string nombre);
    void listaadyacencia();
    void anular();
    void Dijkstra(vertice *origen,vertice *destino);

};

#endif // GRAFO_H
