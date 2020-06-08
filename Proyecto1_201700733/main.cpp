#include <iostream>
#include "EDD/Cola.h"
using namespace std;

void moduloSesion(){
    string usuario;
    string contrasenia;
    string empresa;
    string departamento;
    cout<<"Usuario"<<endl;
    cin>> usuario;
    cout<<"Contrasenia"<<endl;
    cin>>contrasenia;
    cout<<"Departamento"<<endl;
    cin>>departamento;
    cout<<"Empresa"<<endl;
    cin>>empresa;
    if(usuario=="admin" && contrasenia=="admin" && departamento=="defecto" && empresa=="empresa"){
        cout<<"Efectivamente"<<endl;
    }
    //aca va a ir un else-if para buscar el usuario en la matriz
    else{
        cout<<"Error al iniciar Sesion"<<endl;
    }
}





int main()
{
    int sesion=0;
    do{
    cout<<"1. Inicio Sesion"<<endl;
    cout<<"2. Finalizar"<<endl;
    cin>>sesion;
    if(sesion==1)
        moduloSesion();
    }while(sesion!=2);
}
