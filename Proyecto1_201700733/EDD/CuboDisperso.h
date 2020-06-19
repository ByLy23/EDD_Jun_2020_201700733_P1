#ifndef CUBODISPERSO_H_INCLUDED
#define CUBODISPERSO_H_INCLUDED
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;
//arreglos matriz
class Nodo
    {
        Nodo *siguiente;
        Nodo *anterior;
        Nodo *arriba;
        Nodo *abajo;
        Nodo *frente;
        Nodo *detras;
        string departamento;
        string empresa;
        Usuario *miUser;
        int tamanio;
    public:
        //crear cabeceras de departamentos y empresas
        Usuario *getUser()
        {
            return miUser;
        }
        void setUser(Usuario *user)
        {
            this->miUser=user;
        }

        Nodo(Usuario *user, string departamento, string empresa)
        {//anio es departamentos, mes es empresas
            this->departamento=departamento;
            this->empresa=empresa;
            this->miUser= user;
            siguiente=anterior=arriba=abajo=detras=frente=0;
        }
         Nodo(string dato, bool esdepartamento)
        {
            if(esdepartamento)
            {
            this->departamento="";
            this->empresa=dato;
            this->miUser=0;
            siguiente=anterior=arriba=abajo=detras=frente=0;
            }else{
            this->departamento=dato;
            this->empresa="";
            this->miUser=0;
            siguiente=anterior=arriba=abajo=detras=frente=0;
            }
        }
        string getEmpresa()
        {
            return empresa;
        }
        string getDepartamento()
        {
            return departamento;
        }
        void setEmpresa(string f)
        {
            empresa=f;
        }void setDepartamento(string f)
        {
            departamento=f;
        }
        Nodo *getSiguiente()
        {
            return siguiente;
        }
        Nodo *getAnterior()
        {
            return anterior;
        }
        Nodo *getArriba()
        {
            return arriba;
        }
        Nodo *getAbajo()
        {
            return abajo;
        }
        Nodo *getFrente()
        {
            return frente;
        }
        Nodo *getDetras()
        {
            return detras;
        }
        void setSiguiente(Nodo *siguiente)
        {
            this->siguiente=siguiente;
        }
        void setFrente(Nodo *frente)
        {
            this->frente=frente;
        }
         void setDetras(Nodo *detras)
        {
            this->detras=detras;
        }
        void setAnterior(Nodo *anterior)
        {
            this->anterior=anterior;
        }
        void setArriba(Nodo *arriba)
        {
            this->arriba=arriba;
        }
        void setAbajo(Nodo *abajo)
        {

            this->abajo=abajo;
        }
    };
class CuboDisperso
{

    Nodo *raiz;
        string cuerpo="";
        string enlaces="";
        string grupo="";
        string wolrd="";
    public:
        string getWor()
        {
            return wolrd;
        }
        void setWords(string grupo)
        {
            this->wolrd=grupo;
        }
        string getGrupo()
        {
            return grupo;
        }
        void setGrupo(string grupo)
        {
            this->grupo=grupo;
        }
        string getEnlaces()
        {
            return enlaces;
        }
        string getCuerpo()
        {
            return cuerpo;
        }
        void setCuerpo(string cuerpo)
        {
            this->cuerpo=cuerpo;
        }
        void setEnlaces(string enlaces)
        {
            this->enlaces=enlaces;
        }
    CuboDisperso()
    {
        Usuario *us= new Usuario("admin","admin","admin","admin","admin","admin");
        raiz= new Nodo(us,"a","a");
    }
    Nodo *busquedaNodo(string empresa, string departamento,string nombre, string contra)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            Nodo *aux3= aux2;
            while(aux3!=0)
            {
                if(aux3->getEmpresa().compare(empresa)==0 && aux3->getDepartamento().compare(departamento)==0)
                {
                    retorno=aux3;
                    bandera=true;
                    if(aux3->getUser()!=0)
                    {
                        if(aux3->getUser()->Getusername().compare(nombre)==0 && aux3->getUser()->Getpass().compare(contra)==0)
                            break;
                    }
                }
            aux3=aux3->getFrente();
        }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
    return retorno;
}
Nodo *crearempresa(string empresa)
{
    Nodo *cabeza_col= raiz;
    Nodo *col_insertada= insertarempresa(new Nodo(empresa,false), cabeza_col);
    return col_insertada;
}
Nodo *creardepartamento(string departamento)
{
    Nodo *cabezadepartamento= raiz;
    Nodo *departamentoInsertada= insertardepartamento(new Nodo(departamento,true),cabezadepartamento);
    return departamentoInsertada;
}
void imprimir()
{
    Nodo *aux= raiz;
    while(aux!=0){

            string fil="C"+aux->getDepartamento();
            string col="F"+aux->getEmpresa();
           /* if(aux->getAnterior()!=0){
                string departamentonterior="C"+to_string(aux->getAnterior()->getDepartamento());
            string colanterior="F"+to_string(aux->getAnterior()->getEmpresa());
            enlaces+="\""+fil+col+"\" -> \""+departamentonterior+colanterior+"\"\n";
            }
            if(aux->getSiguiente()!=0){
                string filsiguiente="C"+to_string(aux->getSiguiente()->getDepartamento());
            string colsiguiente="F"+to_string(aux->getSiguiente()->getEmpresa());
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
            }*/
            //cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\"];\n";

        Nodo *aux2=aux;
        string ranki="";
        while(aux2!=0)
        {
  string fil="C"+aux2->getDepartamento();
            string col="F"+aux2->getEmpresa();
            if(aux2->getArriba()!=0){
                string departamentonterior="C"+aux2->getArriba()->getDepartamento();
            string colanterior="F"+aux2->getArriba()->getEmpresa();
            enlaces+="\""+fil+col+"\" -> \""+departamentonterior+colanterior+"\"\n";
            }
            if(aux2->getAbajo()!=0){
                string filsiguiente="C"+aux2->getAbajo()->getDepartamento();
            string colsiguiente="F"+aux2->getAbajo()->getEmpresa();
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
            }
            if(aux2->getAnterior()!=0){
                string departamentonterior="C"+aux2->getAnterior()->getDepartamento();
            string colanterior="F"+aux2->getAnterior()->getEmpresa();
            enlaces+="\""+fil+col+"\" -> \""+departamentonterior+colanterior+"\"\n";
            }
            if(aux2->getSiguiente()!=0){
                string filsiguiente="C"+aux2->getSiguiente()->getDepartamento();
            string colsiguiente="F"+aux2->getSiguiente()->getEmpresa();
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
           // cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=yellow group="+aux2->getEmpresa()+"];\n";
            cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getDepartamento()+"\" style=filled fillcolor=blue group="+aux2->getEmpresa()+"];\n";
            }else{
                if(aux2->getDepartamento()=="" && aux2->getEmpresa()==""){
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\"Raiz\" style=filled fillcolor=gray group=1];\n";
                }else{
                    if(aux2->getDepartamento()=="")
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\" style=filled fillcolor=gray group="+aux2->getEmpresa()+"];\n";
                    else
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\" style=filled fillcolor=gray group= 1];\n";
                   // cout<<fil<<endl;
                }
                }
                ranki+=fil+col+";";
                //cout<<fil+col<<endl;
            aux2=aux2->getAbajo();
        }
        wolrd+="{rank= same; "+ranki+"}\n";
       // cout<<ranki<<endl;
        //grupo+= fil+col+"; ";
    aux=aux->getSiguiente();
        }
    }
void crearNodo(Usuario *user,string departamento, string empresa)
{
    Nodo *nuevo= new Nodo(user,departamento,empresa);
    Nodo *Nodoempresa= buscarempresa(empresa);
    Nodo *Nododepartamento= buscardepartamento(departamento);
    if(Nodoempresa==0 && Nododepartamento==0){
        //ninguno esta creado
        Nodoempresa= crearempresa(empresa);
        Nododepartamento= creardepartamento(departamento);
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
        cout<<"Crea uno areherheehehewherhsefher"<<endl;
    }
    else if(Nodoempresa==0 && Nododepartamento!=0)
    {
        Nodoempresa= crearempresa(empresa);
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
        //solo esta creada la departamento
    }
    else if(Nodoempresa!=0 && Nododepartamento==0)
    {
        //solo esta creada la empresa
        Nododepartamento= creardepartamento(departamento);
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
    }
    else if(Nodoempresa!=0 && Nododepartamento!=0)
    {
        //estan creados los dos
        Nodo *busqueda= busquedaNodo(user->Getempresa(),user->Getdepartamento(),user->Getusername(),user->Getpass());
        if(user->Getusername().compare(busqueda->getUser()->Getusername())==0)
        {
            string a;
            cout<<"No se puede Registrar por nombre igual"<<endl;
            cin>>a;
        }else if(busqueda==0){
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
        }else{
            busqueda->setFrente(nuevo);
            nuevo->setDetras(busqueda);
            busqueda=nuevo;
        }
    }
}
Nodo *insertarempresa(Nodo *nuevo,Nodo *nododepartamento)
{
    Nodo *aux= nododepartamento;
    bool Flag= false;
     while(true)
    {
        if(aux->getEmpresa().compare(nuevo->getEmpresa())==0)
        {
            aux->setDepartamento(nuevo->getDepartamento());
            aux->setUser(nuevo->getUser());
            Flag= true;
            return aux;
            break;
        }
        /*else if(aux->getEmpresa().compare(nuevo->getEmpresa())<0)
        {
        }*/
        if(aux->getAbajo()!=0)
        {
            aux=aux->getAbajo();
        }
        else{break;}
    }
    if(Flag)
        {
            nuevo->setAbajo(aux);
            aux->getArriba()->setAbajo(nuevo);
            nuevo->setArriba(aux->getArriba());
            aux->setArriba(nuevo);
        }
        else{
            aux->setAbajo(nuevo);
            nuevo->setArriba(aux);
        }
    return nuevo;

}
Nodo *insertardepartamento(Nodo *nuevo,Nodo *nodoempresa)
{
    Nodo *aux= nodoempresa;
    bool Flag= false;
    while(true)
    {
        if(aux->getDepartamento().compare(nuevo->getDepartamento())==0)
        {
            aux->setEmpresa(nuevo->getEmpresa());
            aux->setUser(nuevo->getUser());
            Flag= true;
            return aux;
            break;
        }
        /*else if(aux->getDepartamento().compare(nuevo->getDepartamento())<0)
        {
        }*/
        if(aux->getSiguiente()!=0)
        {
            aux=aux->getSiguiente();
        }
        else{break;}
    }
    if(Flag)
        {
            nuevo->setSiguiente(aux);
            aux->getAnterior()->setSiguiente(nuevo);
            nuevo->setAnterior(aux->getAnterior());
            aux->setAnterior(nuevo);
        }
        else{
            aux->setSiguiente(nuevo);
            nuevo->setAnterior(aux);
        }
    return nuevo;

}
Nodo *buscarempresa(string departamento)
{
    Nodo *aux= raiz;
    if(aux->getAbajo()!=0)
    {
        while(aux!=0)
        {
            if(aux->getDepartamento().compare(departamento)==0)
                return aux;
            aux=aux->getAbajo();
        }
    }
    return 0;
}
Nodo *buscardepartamento(string empresa)
{
    Nodo *aux= raiz;
    if(aux->getSiguiente()!=0)
    {
        while(aux!=0)
        {
            if(empresa.compare(aux->getEmpresa())==0)
                return aux;
            aux= aux->getSiguiente();
        }
    }
    return 0;
}


void ingresarAVL(Activo *activo,Usuario *user)
{
    Nodo *busqueda=busquedaNodo(user->Getempresa(),user->Getdepartamento(),user->Getusername(),user->Getpass());
    busqueda->getUser()->Getarbolito()->insertar(activo);
}
void eliminarAVL(string nombre,Usuario *user)
{
    Nodo *busqueda=busquedaNodo(user->Getempresa(),user->Getdepartamento(),user->Getusername(),user->Getpass());
    cout<<"Si busca"<<endl;
    busqueda->getUser()->Getarbolito()->eliminar(nombre);
}
void modificarAVL(string identificar,Usuario *user)
{
    Nodo *busqueda=busquedaNodo(user->Getempresa(),user->Getdepartamento(),user->Getusername(),user->Getpass());
    busqueda->getUser()->Getarbolito()->actualizar(identificar);
}
void mostrarActivos(Usuario *user)
{
     Nodo *busqueda=busquedaNodo(user->Getempresa(),user->Getdepartamento(),user->Getusername(),user->Getpass());
     busqueda->getUser()->Getarbolito()->inordenMuestra();
}
void imprimirPorUsuario(string usuario)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            Nodo *aux3= aux2;
            while(aux3!=0)
            {
                bandera=true;
                if(aux3->getUser()!=0)
                {
                    if(aux3->getUser()->Getusername().compare(usuario)==0)
                    {
                        aux3->getUser()->Getarbolito()->imprimirNodos();
                    }
                }
            aux3=aux3->getFrente();
        }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
}
void apagarActivo(string id,int numero)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            Nodo *aux3= aux2;
            while(aux3!=0)
            {
                bandera=true;
                if(aux3->getUser()!=0)
                {
                    aux3->getUser()->Getarbolito()->buscar(id,numero);
                }
            aux3=aux3->getFrente();
        }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
}
void mostrarActivosMenosLosMios(Usuario *user)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            Nodo *aux3= aux2;
            while(aux3!=0)
            {
                bandera=true;
                if(aux3->getUser()!=0)
                {
                    if(aux3->getUser()->Getusername().compare(user->Getusername())==0 && aux3->getUser()->Getpass().compare(user->Getpass())==0)
                    {
                    }
                    else
                        aux3->getUser()->Getarbolito()->activosSinRentar();
                }
            aux3=aux3->getFrente();
        }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
}

void mostrarActivosRentados(Usuario *user)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            Nodo *aux3= aux2;
            while(aux3!=0)
            {
                bandera=true;
                if(aux3->getUser()!=0)
                {
                    if(aux3->getUser()->Getusername().compare(user->Getusername())==0 && aux3->getUser()->Getpass().compare(user->Getpass())==0)
                    {
                        aux3->getUser()->Getarbolito()->misActivosRentados();
                    }
                }
            aux3=aux3->getFrente();
        }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
}
    /*Nodo *insertardepartamento(Nodo *nuevo, Nodo *departamento);
    Nodo *insertarempresa(Nodo *nuevo, Nodo *nodoempresa);
    Nodo *creardepartamento(string departamento);
    Nodo *crearempresa(string empresa);
    Nodo *busquedaNodo(string empresa, string departamento);
    Nodo *buscarempresa(string empresa);//listo
    Nodo *buscardepartamento(string departamento);//listo
    void crearNodo(string nombre, int anio, string mes, ListaSimple<Cancion*> *canciones);*/
};


#endif // CUBODISPERSO_H_INCLUDED
