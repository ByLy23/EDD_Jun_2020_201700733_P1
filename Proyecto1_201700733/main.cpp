#include <iostream>
#include "EDD/Cola.h"
#include "EDD/ArbolAVL.h"
#include "EDD/CuboDisperso.h"
using namespace std;
void moduloEliminarActivo()
{
//desplegar lista de activos de mi usuario
string idActivo;
cout<<"Ingrese Activo a Eliminar"<<endl<<">>";
cin>>idActivo;
//mostrar Activo eliminado
}
void moduloAdmin()
{
    int opcion=0;
    do{
            system("cls");
        cout<<"1. Registrar Usuario"<<endl;
        cout<<"2. Reporte Matriz Dispersa"<<endl;
        cout<<"3. Reporte de Activos Disponibles por Departamento"<<endl;
        cout<<"4. Reporte de Activos Disponibles por Empresa"<<endl;
        cout<<"5. Reporte de Transacciones"<<endl;
        cout<<"6. Reporte de Activos de un Usuario"<<endl;
        cout<<"7. Reporte de Activos rentados por un Usuario"<<endl;
        cout<<"8. Ordenar Transacciones"<<endl;
        cout<<"9. Cerrar Sesion"<<endl<<">>";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            //moduloRegistro();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
    }while(opcion!=9);
}
void moduloSesion(){
    string usuario;
    string contrasenia;
    string empresa;
    string departamento;
    cout<<"Usuario"<<endl<<">>";
    cin>> usuario;
    cout<<"Contrasenia"<<endl<<">>";
    cin>>contrasenia;
    cout<<"Departamento"<<endl<<">>";
    cin>>departamento;
    cout<<"Empresa"<<endl<<">>";
    cin>>empresa;
    if(usuario=="admin" && contrasenia=="admin" && departamento=="defecto" && empresa=="defecto"){
        cout<<"Efectivamente"<<endl;
        moduloAdmin();
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
            system("cls");
    cout<<"1. Inicio Sesion"<<endl;
    cout<<"2. Finalizar"<<endl<<">>";
    cin>>sesion;
    if(sesion==1)
        moduloSesion();
    }while(sesion!=2);
}
