#ifndef ACTIVO_H
#define ACTIVO_H
#include <iostream>
using namespace std;
class Activo
{
    public:
        Activo(){
            Descripcion="";
            Nombre="";
            ID="";
        }
        Activo(string desc, string nombre)
        {
            //crear MetodoRandom para ai di

            this->Descripcion=desc;
            this->Nombre=nombre;
        }
        string GetDescripcion() { return Descripcion; }
        void SetDescripcion(string val) { Descripcion = val; }
        string GetNombre() { return Nombre; }
        void SetNombre(string val) { Nombre = val; }
        string GetID() { return ID; }
        void SetID(string val) { ID = val; }

    protected:

    private:
        string Descripcion="";
        string Nombre="";
        string ID="";
};

#endif // ACTIVO_H
