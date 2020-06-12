#ifndef CUBODISPERSO_H_INCLUDED
#define CUBODISPERSO_H_INCLUDED
#include <iostream>

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
        int multiplicador;
        string letra;
        int tamanio;
    public:
        //crear cabeceras de departamentos y empresas

        Nodo(string letra, string departamento, string empresa, int multi)
        {//anio es departamentos, mes es empresas
            this->departamento=departamento;
            this->empresa=empresa;
            this->letra=letra;
            this->multiplicador=multi;
            siguiente=anterior=arriba=abajo=detras=frente=0;
        }
         Nodo(string dato, bool esdepartamento)
        {
            if(esdepartamento)
            {
            this->departamento=dato;
            this->empresa="";
            this->letra="";
            this->multiplicador=0;
            siguiente=anterior=arriba=abajo=detras=frente=0;
            }else{
            this->departamento="";
            this->empresa=dato;
            this->letra="";
            this->multiplicador=0;
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
        int getMuti()
        {
            return multiplicador;
        }
        string getLetra()
        {
            return letra;
        }
        void setEmpresa(string f)
        {
            empresa=f;
        }void setDepartamento(string f)
        {
            departamento=f;
        }void setMulti(int f)
        {
           multiplicador=f;
        }
        void setLetra(string letra)
        {
            this->letra=letra;
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
        raiz= new Nodo("raiz",0,0,0);
    }
    Nodo *busquedaNodo(string empresa, string departamento)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            if(aux2->getEmpresa()==empresa && aux2->getDepartamento()==departamento)
                {
                    retorno=aux2;
                    bandera=true;
                    break;
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
            }
            if(aux2->getMuti()==2)
            {
            cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=yellow group="+aux2->getEmpresa()+"];\n";
            }
            else if(aux2->getMuti()==3)
            {
               cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=green group="+aux2->getEmpresa()+"];\n";
            }
            else if(aux2->getMuti()==1){
                cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=blue group="+aux2->getEmpresa()+"];\n";
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
void crearNodo(string nombre, int multi, string departamento, string empresa)
{
    Nodo *nuevo= new Nodo(nombre,departamento,empresa,multi);
    Nodo *Nodoempresa= buscarempresa(empresa);
    Nodo *Nododepartamento= buscardepartamento(departamento);
    if(Nodoempresa==0 && Nododepartamento==0){
        //ninguno esta creado
        Nodoempresa= crearempresa(empresa);
        Nododepartamento= creardepartamento(departamento);
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
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
        nuevo= insertarempresa(nuevo,Nododepartamento);
        nuevo= insertardepartamento(nuevo,Nodoempresa);
    }
}
Nodo *insertarempresa(Nodo *nuevo,Nodo *nododepartamento)
{
    Nodo *aux= nododepartamento;
    bool Flag= false;
     while(true)
    {
        if(aux->getEmpresa() ==nuevo->getEmpresa())
        {
            aux->setDepartamento(nuevo->getDepartamento());
            aux->setLetra(nuevo->getLetra());
            aux->setMulti(nuevo->getMuti());
            return aux;
        }
        else if(aux->getEmpresa()>nuevo->getEmpresa())
        {
            Flag= true;
            break;
        }
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
        if(aux->getDepartamento() ==nuevo->getDepartamento())
        {
            aux->setEmpresa(nuevo->getEmpresa());
            aux->setLetra(nuevo->getLetra());
            aux->setMulti(nuevo->getMuti());
            return aux;
        }
        else if(aux->getDepartamento()>nuevo->getDepartamento())
        {
            Flag= true;
            break;
        }
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
    if(raiz->getAbajo()!=0)
    {
        while(aux!=0)
        {
            if(departamento==aux->getDepartamento())
                return aux;
            aux=aux->getAbajo();
        }
    }
    return aux;
}
Nodo *buscardepartamento(string empresa)
{
    Nodo *aux= raiz;
    if(aux->getSiguiente()!=0)
    {
        while(aux!=0)
        {
            if(empresa==aux->getEmpresa())
                return aux;
            aux= aux->getSiguiente();
        }
    }
    return aux;
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
