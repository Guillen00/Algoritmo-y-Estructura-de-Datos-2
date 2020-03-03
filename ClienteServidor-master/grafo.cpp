/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la especificación de las funciones que se declararon en el documento grafo.h
  */

#include "grafo.h"

/**
 * @brief Grafo::Inicializa , crea el grafo y lo pone null
 */
void Grafo::Inicializa(){
    h = NULL;

/** @brief Grafo::Vacio , devuelve si el grafo esta vacio o no .
  */

}
bool Grafo::Vacio(){
    if(h == NULL){return true;}
    else{return false;}
}

/** @brief Grafo::getvertice , obtiene el vertice con el nombre ingresado .
  */


vertice *Grafo::getvertice(string nombre){
    vertice *aux;
    aux= h ;
    while(aux != NULL){
        if(aux->nombre == nombre){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

/** @brief Grafo::insertarvertice , inserta un vertice al grafo y le da el nombre que se ingreso .
  */


void Grafo::insertarvertice(string nombre){
    vertice *nuevo =  new vertice;
    nuevo->nombre = nombre;
    nuevo->sig= NULL;
    nuevo->ady= NULL;
    if(Vacio()){h=nuevo;}
    else{vertice *aux;
    aux=h;
    while(aux->sig !=NULL){aux = aux->sig;}
    aux->sig = nuevo;
    }


}


/** @brief Grafo::insertararista , inserta una arista que conecta a los dos vertices que se ingresan y se le da un peso que también se ingresa.
  */

void Grafo::insertararista(vertice *origen, vertice *destino, int peso){
    arista *nueva = new arista;
    nueva->peso=peso;
    nueva->sig=NULL;
    nueva->ady= NULL;

    arista *aux;
    aux = origen->ady;

    if(aux==NULL){
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else{
        while(aux->sig != NULL)
        {aux = aux->sig;}
        aux->sig = nueva;
        nueva->ady = destino;
    }

}

/** @brief Grafo::listaadyacencia , devuelve una lista de todas las aristas con sus respectivos vertices concetados  .
  */


void Grafo::listaadyacencia(){
    vertice *vertaux;
    arista *aristaaux;
    vertaux = h;
    while(vertaux != NULL){
        cout<<vertaux->nombre<<"->";
        aristaaux= vertaux->ady;
        while(aristaaux != NULL){
            cout<<aristaaux->ady->nombre<<"->";
            aristaaux = aristaaux->sig;

        }
        vertaux= vertaux->sig;
        cout<<endl;    //salto de linea
    }
 }

/** @brief Grafo::Dijkstra , Es un algoritmo para buscar el camino más corto de un vertice a otro , en este caso retorna la tuta más corta entre los vertices ingresados .
  */

string Grafo::Dijkstra(vertice *origen, vertice *destino){
    string ruta=" ";
    int band,band2, band3=0;
    arista *aux;
    vertice *verticeactual;
    vertice *destinoactual;
    typedef pair<vertice*,vertice*> verticevertice;
    queue<vertice*> cola;
    stack<verticevertice> pila;
    list<vertice*> lista;
    list<vertice*>::iterator i;
    cola.push(origen);

    cout<<"primero"<<endl;
    while(!cola.empty()){
        band =0;
        verticeactual = cola.front();
        cola.pop();
        cout<<"segundo"<<endl;
        for(i=lista.begin();i!=lista.end();i++){
            if(verticeactual == *i){
                band = 1;

            }

        }
        if(band ==0){
            cout<<"tercero"<<endl;
            if(verticeactual == destino){//
                cout<<"CUARTO"<<endl;
                band3 =1;
                destinoactual = destino;
                while(!pila.empty()){
                    cout<<"CUATRO.UNO"<<endl;
                    //cout<<destinoactual->nombre<<"<-";
                    ruta=ruta+destinoactual->nombre+" <-- ";
                    while(!pila.empty() && pila.top().second != destinoactual){
                        pila.pop();
                        cout<<"POP"<<endl;
                    }
                    if(!pila.empty()){
                        destinoactual = pila.top().first;

                    }
                }
                //cout<<endl;
            }
            lista.push_back(verticeactual);
            aux = verticeactual->ady;
            cout<<"QUINTO"<<endl;
            while(aux!= NULL){
                band2 =0;
                for(i=lista.begin();i!=lista.end();i++){
                    if(aux->ady == *i){
                        band2 =1;

                    }
                }
                if(band2==0){
                    cola.push(aux->ady);
                    pila.push(verticevertice(verticeactual,aux->ady));
                }
                aux =aux->sig;
            }
        }

    }
    if(band3 ==0){
        cout<<"no hay ruta"<<endl;
    }
    return "completado";
}
