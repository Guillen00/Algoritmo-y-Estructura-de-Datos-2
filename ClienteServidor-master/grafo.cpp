#include "grafo.h"


void Grafo::Inicializa(){
    h = NULL;


}
bool Grafo::Vacio(){
    if(h == NULL){return true;}
    else{return false;}
}
int Grafo:: Tamano(){
    int cont =0;
    vertice *aux;
    aux =h;
    while(aux !=NULL){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

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
void Grafo::anular(){
    vertice *aux;
    while(h !=NULL){
        aux = h;
        h= h->sig;
        delete(aux);
    }
}

void Grafo::Dijkstra(vertice *origen, vertice *destino){

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


    while(!cola.empty()){
        band =0;
        verticeactual = cola.front();
        cola.pop();

        for(i=lista.begin();i!=lista.end();i++){
            if(verticeactual == *i){
                band = 1;

            }

        }
        if(band ==0){
            if(verticeactual == destino){//

                band3 =1;
                destinoactual = destino;
                while(!pila.empty()){
                    cout<<destinoactual->nombre<<"<-";
                    while(!pila.empty() && pila.top().second != destinoactual){
                        pila.pop();

                    }
                    if(!pila.empty()){
                        destinoactual = pila.top().first;

                    }
                }
                cout<<endl;
            }
            lista.push_back(verticeactual);
            aux = verticeactual->ady;
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
}
