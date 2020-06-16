#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include "ArbolAVL.h"
using namespace std;

class Usuario
{
    public:
Usuario()
{
    this->nombre="";
    this->apellido="";
    this->pass="";
    this->empresa="";
    this->departamento="";
    this->username="";
    this->arbolito= 0;
    //ctor
}
Usuario(string nombre,string apellido,string username, string pass, string departamento, string empresa)
{
    this->nombre=nombre;
   this->apellido=apellido;
    this->pass=pass;
    this->empresa=empresa;
    this->username=username;
    this->departamento=departamento;
    this->arbolito= new ArbolBusqueda();
}
        virtual ~Usuario();
        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string Getapellido() { return apellido; }
        void Setapellido(string val) { apellido = val; }
        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getpass() { return pass; }
        void Setpass(string val) { pass = val; }
        string Getdepartamento() { return departamento; }
        void Setdepartamento(string val) { departamento = val; }
        string Getempresa() { return empresa; }
        void Setempresa(string val) { empresa = val; }
        ArbolBusqueda *Getarbolito() { return arbolito; }
        void Setarbolito(ArbolBusqueda *val) { arbolito = val; }

    protected:

    private:
        string nombre;
        string apellido;
        string username;
        string pass;
        string departamento;
        string empresa;
        ArbolBusqueda *arbolito;
};

#endif // USUARIO_H
