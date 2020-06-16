#include <iostream>
#include "EDD/Cola.h"
#include "EDD/ArbolAVL.h"
#include "EDD/CuboDisperso.h"
using namespace std;



CuboDisperso* cubito=new CuboDisperso();

void moduloUsuario()
{
int opcion=0;
    do{
            system("cls");
        cout<<"1. Agregar Activo"<<endl;
        cout<<"2. Eliminar Activo"<<endl;
        cout<<"3. Modificar Activo"<<endl;
        cout<<"4. Rentar Activo"<<endl;
        cout<<"5. Activos Rentados"<<endl;
        cout<<"6. Mis Activos Rentados"<<endl;
        cout<<"7. Cerrar Sesion"<<endl<<">>";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            break;
        case 2:
            //reportes
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    }while(opcion!=7);
}

void moduloRegistro()
{
    cout<<"Registre al Usuario"<<endl;
            string usuario;
            string nombre;
            string apellido;
    string contrasenia;
    string empresa;
    string departamento;
    cout<<"Nombre"<<endl<<">>";
    cin>> nombre;
    cout<<"Apellido"<<endl<<">>";
    cin>> apellido;
    cout<<"Usuario"<<endl<<">>";
    cin>> usuario;
    cout<<"Contrasenia"<<endl<<">>";
    cin>>contrasenia;
    cout<<"Departamento"<<endl<<">>";
    cin>>departamento;
    cout<<"Empresa"<<endl<<">>";
    cin>>empresa;
    cubito->crearNodo(new Usuario(nombre,apellido,usuario, contrasenia, departamento, empresa),departamento,empresa);
    cout<<"Registrado"<<endl;
    system(0);
}
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
            moduloRegistro();
            break;
        case 2:
            //reportes
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
    Nodo *aux= cubito->busquedaNodo(departamento,empresa,usuario,contrasenia);
    if(aux!=0)
    {
        if(aux->getUser()->Getusername().compare(usuario)==0 && aux->getUser()->Getpass().compare(contrasenia)==0){
        moduloAdmin();}
        else if(aux->getUser()->Getusername().compare(usuario)==0 && aux->getUser()->Getpass().compare(contrasenia)==0){
           moduloUsuario();
        }
    }
    else
    {
        cout<<"No existe el men"<<endl;
        //moduloUsuario
    }

    //aca va a ir un else-if para buscar el usuario en la matriz

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
        if(sesion==90)
        {
            //48 - 57 numeros
            //65 - 90 letras mayusculas
            //97 - 122 letras minusculas
            Activo *holi= new Activo("uno","Uni");
            return(0);
        }
    }while(sesion!=2);
}
