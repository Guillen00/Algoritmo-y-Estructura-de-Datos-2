/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se describe la clase Arista, Vertice y Grafo las cuales componen a lo que respecta un grafo, utilizando los vertices
  * conectados por aristas las cuales tienen un peso especifico
  */

#ifndef GRAFO_H
#define GRAFO_H


/**Se añaden librerias para hacer uso de algunas funciones especìficas que se necesitan para el desarrollo de las clases
  *
  */

#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class arista;

/**Se crea la clase vertice la cual almacena cada punto del grafo, el cual cuenta con un nombre ,un puntero que lo relaciona con una arista y otro puntero la cual
 * lo relaciona con los demas vertices.
  *
  */

class vertice{
   public:
   vertice *sig;
   arista *ady;
   string nombre;
   friend class Grafo;


};

/**Se crea la clase arista la cual hará una conección o relación entre dos vertices con un puntero y otro puntero que lo relaciona a las demás
 * aristas que se relacionan con el vertice posicionado.
  *
  */

class arista{
    public:
    arista *sig;
    vertice *ady;
    int peso;
    friend class Grafo;


};

/**Se crea la clase grafo que contiene los vertices y aristas para conformar el grafo además se tienen las funciones las cuales se utilizarán para crear el grafo
  *
  */

class Grafo
{
    vertice *h;
public:
    void Inicializa();
    bool Vacio();
    vertice *getvertice(string nombre);
    void insertararista(vertice *origen,vertice *destino ,int peso);
    void insertarvertice(string nombre);
    void listaadyacencia();
    string Dijkstra(vertice *origen,vertice *destino);

};

#endif // GRAFO_H
