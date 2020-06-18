#ifndef ARBOLBINBUSQUEDA_H_INCLUDED
#define ARBOLBINBUSQUEDA_H_INCLUDED
#include <iostream>
#include "Activo.h"
using namespace std;
class NodoAVL
    {
        Activo *nombreNodoAVL;
        int altura;
        public:
        NodoAVL *derecho;
        NodoAVL *izquierdo;
        NodoAVL()
        {
            nombreNodoAVL=0;
            izquierdo=derecho=0;
            altura=0;
        }
        NodoAVL(Activo *nombre)
        {
            nombreNodoAVL=nombre;
            altura=0;
            izquierdo=derecho=0;
        }
        void setNombre(Activo *nombre)
        {
            nombreNodoAVL= nombre;
        }
        Activo *getNombre()
        {
            return nombreNodoAVL;
        }
        void setIzquierdo(NodoAVL *izq)
        {
            this->izquierdo=izq;
        }
        void setDerecho(NodoAVL *der)
        {
            this->derecho=der;
        }
        NodoAVL *getIzquierdo()
        {
            return izquierdo;
        }
        NodoAVL *getDerecho()
        {
            return derecho;
        }
        int getAltura()
        {
            return altura;
        }
        void setAltura(int altura)
        {
            this->altura=altura;
        }
    };
class ArbolBusqueda{
private:
    string cuerpo= "";
    string enlaces="";
    void graficar(NodoAVL *nodo){
        if(nodo!=0){
            graficar(nodo->getIzquierdo());
            string alti= to_string(nodo->getAltura()-1);
            string nod;

            cuerpo+= "nodo [label= \" "+nodo->getNombre()->GetNombre()+"\n Altura: "+alti+"\"];";
            graficar(nodo->getDerecho());
        }
    }
    /*void graficar2(NodoAVL *nodo){
        if(nodo!=0){
     if(nodo.getIzquierdo()!=0){
            enlaces+="nodo"+nodo.hashCode()+"->"+"nodo"+nodo.getIzquierdo().hashCode()+"\n";
        }
        if(nodo.getDerecho()!=0){
            enlaces+="nodo"+nodo.hashCode()+"->"+"nodo"+nodo.getDerecho().hashCode()+"\n";
        }
        graficar2(nodo.getIzquierdo());
        graficar2(nodo.getDerecho());
        }
    }*/
    int alturaMaxima(int a, int b){return (a>b) ? a:b;}
    int obtieneAltura(NodoAVL *nuevo){return (nuevo==0) ? 0: nuevo->getAltura();}
    int getBalance(NodoAVL *nuevo){return (nuevo==0)? 0: (obtieneAltura(nuevo->getIzquierdo())-obtieneAltura(nuevo->getDerecho()));}
    NodoAVL *rotacionDD(NodoAVL *n){
        NodoAVL *n1= n->getIzquierdo();
        n->setIzquierdo(n1->getDerecho());
        n1->setDerecho(n);
        n->setAltura(alturaMaxima(obtieneAltura(n->getIzquierdo()), obtieneAltura(n->getDerecho()))+1);
        n1->setAltura(alturaMaxima(obtieneAltura(n1->getIzquierdo()), obtieneAltura(n1->getDerecho()))+1);
        return n1;
    }
    NodoAVL *rotacionII(NodoAVL *n)
    {
        NodoAVL *n1= n->getDerecho();
        n->setDerecho(n1->getIzquierdo());
        n1->setIzquierdo(n);
        n->setAltura(alturaMaxima(obtieneAltura(n->getIzquierdo()), obtieneAltura(n->getDerecho()))+1);
        n1->setAltura(alturaMaxima(obtieneAltura(n1->getIzquierdo()), obtieneAltura(n1->getDerecho()))+1);
        return n1;
    }
    NodoAVL *rotacionID(NodoAVL *n)
    {
         NodoAVL *n2;
        n->setIzquierdo(rotacionII(n->getIzquierdo()));
        n2= rotacionDD(n);
        return n2;
    }
    NodoAVL *rotacionDI(NodoAVL *n)
    {
        NodoAVL *n2;
        n->setDerecho(rotacionDD(n->getDerecho()));
        n2= rotacionII(n);
        return n2;
    }
    NodoAVL *raizGeneral=0;
     NodoAVL *crearNodoAVL(Activo *nombre)
    {
        NodoAVL *nuevo= new NodoAVL(nombre);
        nuevo->setNombre(nombre);
        nuevo->setIzquierdo(0);
        nuevo->setDerecho(0);
        return nuevo;
    }
    NodoAVL *aiuda=0;
    NodoAVL *verificaNombre(NodoAVL *arbol, string nombre)
    {
         if(arbol!=0){
                string nombreComparar= arbol->getNombre()->GetID();
                if(nombre.compare(nombreComparar)==0)
                {
                    aiuda=arbol;
                }
                else if(nombre.compare(nombreComparar)>0)
                {
                    verificaNombre(arbol->derecho,nombre);
                }
                else{
                    verificaNombre(arbol->izquierdo,nombre);
                }
        }
        return arbol;
    }
    void cambiarDatos(string nombres, string desc,string identificador)
    {
        cambiarDatosNodo(raizGeneral,nombres,desc,identificador);
    }
    void cambiarDatosNodo(NodoAVL *arbol, string nombres, string desc,string identificador)
    {
         if(arbol!=0){
                string nombreComparar= arbol->getNombre()->GetID();
                if(identificador.compare(nombreComparar)==0)
                {
                    arbol->getNombre()->SetDescripcion(desc);
                    arbol->getNombre()->SetNombre(nombres);
                }
                else if(identificador.compare(nombreComparar)<0)
                {
                    cambiarDatosNodo(arbol->izquierdo,nombres,desc,identificador);
                }
                else{
                    cambiarDatosNodo(arbol->derecho,nombres,desc,identificador);
                }
         }
    }
    NodoAVL *insertarNodoAVL(NodoAVL *&arbol, Activo *nombre)
    {
        if(arbol==0)
        {
            NodoAVL *nuevo= crearNodoAVL(nombre);
            arbol=nuevo;
        }
        else{
            string nombreComparar= arbol->getNombre()->GetID();
            if(nombre->GetID().compare(nombreComparar)==0)
            {
                cout<<"Nombre Repetido"<<endl;
                return arbol;
            }
            else if(nombre->GetID().compare(nombreComparar)<0)
            {
                NodoAVL *izquierdo;
                izquierdo= insertarNodoAVL(arbol->izquierdo,nombre);
                arbol->setIzquierdo(izquierdo);
            }
            else if(nombre->GetID().compare(nombreComparar)>0){
                    NodoAVL *derecho;
                derecho= insertarNodoAVL(arbol->derecho,nombre);
                arbol->setDerecho(derecho);
            }
            else{
                return arbol;
            }
        }
        arbol->setAltura(1+alturaMaxima(obtieneAltura(arbol->getIzquierdo()),obtieneAltura(arbol->getDerecho())));
        int balance= getBalance(arbol);
        if(balance>1){
            int balance2= getBalance(arbol->getIzquierdo());
            if(balance2==-1)
                return rotacionID(arbol);//este si es izquierda derecha xD
            else
                return rotacionDD(arbol);//es izquierda izquierda, pero como en otros metodos los tengo al reves que se quede asi xD
        }
        else if(balance<-1)
        {
            int balance2= getBalance(arbol->getDerecho());
            if(balance2==1)
                return rotacionDI(arbol);//esta si esta guena
            else
                return rotacionII(arbol);//esta es derecha derecha xD
        }
        return arbol;
    }
    NodoAVL *borrarNodo(NodoAVL *raiz, string nombre){

        if(raiz==0)
        {
            return raiz;
        }
        else if(nombre.compare(raiz->getNombre()->GetID())<0){
            NodoAVL *izquierdo;
            izquierdo= borrarNodo(raiz->izquierdo,nombre);
            raiz->setIzquierdo(izquierdo);
            //insertar izquierdo
        }
        else if(nombre.compare(raiz->getNombre()->GetID())>0){
            NodoAVL *derecho;
            derecho=borrarNodo(raiz->derecho,nombre);
            raiz->setDerecho(derecho);
            //insertarDerecho
        }
        else{
              if ((raiz->getIzquierdo() == 0) || (raiz->getDerecho() == 0)) {
                NodoAVL *temp =0;
                if (temp == raiz->getIzquierdo()) {
                    temp = raiz->getDerecho();
                } else {
                    temp = raiz->getIzquierdo();
                }
                if (temp == 0) {
                    raiz = 0;
                } else {
                    raiz = temp;
                }
              }
               else {
                NodoAVL *temp = nodoMaximo(raiz->izquierdo);
                actualizarNodo(raiz, temp);
                if (raiz->getIzquierdo() == temp) {
                    raiz->setIzquierdo(0);
                }
              }

        return raiz;
            }

        raiz->setAltura(1+alturaMaxima(obtieneAltura(raiz->getIzquierdo()),obtieneAltura(raiz->getDerecho())));
            int balance= getBalance(raiz);
            if (balance>1) {
                int balance2= getBalance(raiz->getIzquierdo());
                if(balance2<0 )
                   // rotacion izquierda derecha
                   return rotacionID(raiz);
                else if (balance2>=0)
                    //rotacion izquierda izquierda
                 return  rotacionDD(raiz);
        }
            else if(balance<-1){
                int balance2= getBalance(raiz->getDerecho());
                if(balance2>0)
                    //rotacion derecha izquierda
                    return rotacionDI(raiz);
                else if(balance2<=0)
                    //rotacion derecha derecha
                   return  rotacionII(raiz);
            }
        return raiz;
    }

    void actualizarNodo(NodoAVL *&raiz, NodoAVL *&temp)
    {
        raiz->setNombre(temp->getNombre());
    }
     NodoAVL *nodoMaximo(NodoAVL *&raiz){
        NodoAVL *actual= raiz;
        NodoAVL *temporal = raiz;
        while (actual->getDerecho() != 0) {
            temporal = actual;
            actual = actual->getDerecho();
        }
        temporal->setDerecho(0);

        return actual;
    }
        bool bandera=false;
    public:
    ArbolBusqueda(){
    }
    void insertar(Activo *nombre){
        raizGeneral=insertarNodoAVL(raizGeneral,nombre);
    }
    void eliminar(string identificacion)
    {
        raizGeneral=borrarNodo(raizGeneral,identificacion);
       // cout<<"Eliminado: "<<nombre<<endl;
    }
    void buscar(string id,int num)
    {
        buscarActivo(raizGeneral,id,num);
    }
    void buscarActivo(NodoAVL *arbol,string nombre, int num)
    {
         if(arbol!=0){
                string nombreComparar= arbol->getNombre()->GetID();
                if(nombre.compare(nombreComparar)==0)
                {
                    if(num==1)
                    {
                    arbol->getNombre()->setRentado(true);
                    }else{
                    arbol->getNombre()->setRentado(false);
                    }
                }
                else if(nombre.compare(nombreComparar)<0)
                {
                    buscarActivo(arbol->izquierdo,nombre,num);
                }
                else{
                    buscarActivo(arbol->derecho,nombre,num);
                }
        }

    }
    void actualizar(string identificador){
        string nombres;
        string nuevaDesc;
        cout<<"Modificar Datos, sino va a modificar nada escriba de nuevo los datos"<<endl;
        cout<<"Nombre"<<endl<<">>";
        getline(cin,nombres);
        cout<<"Descripcion"<<endl<<">>";
        getline(cin,nuevaDesc);
        cambiarDatos(nombres, nuevaDesc,identificador);
    }
    void preOrden()
    {
        recorridoPre(raizGeneral);
    }

    void recorridoPre(NodoAVL *raiz)
    {
        if(raiz!=0){
        cout<<raiz->getNombre()<<", ";
        recorridoPre(raiz->getIzquierdo());
        recorridoPre(raiz->getDerecho());
        }
    }
    void inordenMuestra()
    {
        recorrerInorden(raizGeneral);
    }
    void recorrerInorden(NodoAVL *raiz)
    {
        if(raiz!=0)
        {
            recorrerInorden(raiz->getIzquierdo());
            cout<<"ID= "<<raiz->getNombre()->GetID()<<" ; Nombre= "<<raiz->getNombre()->GetNombre()<<" Descripcion= "<<raiz->getNombre()->GetDescripcion()<<endl;
            recorrerInorden(raiz->getDerecho());
        }
    }
    void activosSinRentar()
    {
        recorrerSinRentar(raizGeneral);
    }
    void recorrerSinRentar(NodoAVL *raiz)
    {
        if(raiz!=0)
        {
            recorrerSinRentar(raiz->getIzquierdo());
            if(!raiz->getNombre()->getRentado())
                cout<<"ID= "<<raiz->getNombre()->GetID()<<" ; Nombre= "<<raiz->getNombre()->GetNombre()<<" Descripcion= "<<raiz->getNombre()->GetDescripcion()<<endl;
            recorrerSinRentar(raiz->getDerecho());
        }
    }
    void misActivosRentados()
    {
        recorrerMisRentados(raizGeneral);

    }

    void recorrerMisRentados(NodoAVL *raiz)
    {
        if(raiz!=0)
        {
            recorrerMisRentados(raiz->getIzquierdo());
            if(raiz->getNombre()->getRentado())
                cout<<"ID= "<<raiz->getNombre()->GetID()<<" ; Nombre= "<<raiz->getNombre()->GetNombre()<<" ; Descripcion= "<<raiz->getNombre()->GetDescripcion()<<endl;
            recorrerMisRentados(raiz->getDerecho());
        }
    }

};

#endif // ARBOLBINBUSQUEDA_H_INCLUDED
