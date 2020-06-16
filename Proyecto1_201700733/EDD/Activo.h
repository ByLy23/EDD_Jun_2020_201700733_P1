#ifndef ACTIVO_H
#define ACTIVO_H
#include <iostream>
#include <time.h>
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
            this->ID= metodoRandom();
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
        string metodoRandom()
        {
            string dato="";
            srand(time(0));
            for(int i=0; i<15; i++)
            {
            int random= rand() % 3;
            int num;
            char nums;
            char may;
            char mins;
            int mayus;
            int minuc;
            string b;
            switch(random)
            {
            case 0:
                num= 48+rand()%(58-48);
                nums=num;
                b= (char) nums;
                dato+=b;
                break;
            case 1:
                mayus= 65+rand()%(91-65);
                may=mayus;
                b= (char) may;
                dato+=b;
                break;
            case 2:
                minuc= 97+rand()%(123-97);
                mins=minuc;
                b= (char) mins;
                dato+=b;
                break;
            }
            }
            cout<<dato<<endl;
                        //48 - 57 numeros
            //65 - 90 letras mayusculas
            //97 - 122 letras minusculas
            return dato;
        }
        string Descripcion="";
        string Nombre="";
        string ID="";
};

#endif // ACTIVO_H
