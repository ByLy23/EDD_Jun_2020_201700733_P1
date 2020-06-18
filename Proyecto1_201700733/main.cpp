#include <iostream>
#include <string>
#include "EDD/Cola.h"
#include "EDD/ListaDoble.h"
#include "EDD/ArbolAVL.h"
#include "EDD/Trans.h"
#include "EDD/CuboDisperso.h"
using namespace std;



CuboDisperso* cubito=new CuboDisperso();
ListaDoble<Trans*> *transacciones= new ListaDoble<Trans*>();
ListaDoble<Trans*> *ActivosRentados= new ListaDoble<Trans*>();
Usuario *persona;
 void moduloDevolverActivos()
 {
     string nombr;
     for(int i=0; i< ActivosRentados->getSize(); i++)
     {
         if(ActivosRentados->obtener_at(i)->GetUsername().compare(persona->Getusername())==0 && ActivosRentados->obtener_at(i)->Getdepartamento().compare(persona->Getdepartamento())==0 && ActivosRentados->obtener_at(i)->Getempresa().compare(persona->Getempresa())==0)
         {
             cout<<"ID: "<<ActivosRentados->obtener_at(i)->GetidActivo()<<" Dias: "<<ActivosRentados->obtener_at(i)->Gettiempo()<<" Dias"<<endl;
             cout<<ActivosRentados->obtener_at(i)->Gettiempo()<<endl;
             cout<<ActivosRentados->obtener_at(i)->Getfecha()<<endl;
         }
     }
     cout<<"Si desea devolver algun activo presione 2 de lo contrario presione cualquier otra tecla"<<endl<<">>";
     getline(cin, nombr);
     if(nombr=="2")
     {
         string act;
         cout<<"Ingrese ID de activo que quiere devolver"<<endl;
         getline(cin,act);
         cubito->apagarActivo(act,2);
         for(int i=0; i<ActivosRentados->getSize();i++)
         {
             if(ActivosRentados->obtener_at(i)->GetidActivo().compare(act)==0)
             {
                ActivosRentados->eliminar(i);
             }
         }
     }
 }
 void moduloMostrarMisRentados()
 {

 }
 void moduloTransaccion()
 {time_t tiempo= time(0);
     struct tm *tlocal= localtime(&tiempo);
     char salida[11];
     strftime(salida,11,"%d/%m/%y",tlocal);
     string fecha= salida;
     string id;
     string dias;
     getline(cin,id);
     cout<<"Ingrese dias para su renta"<<endl<<">>";
     cin>>dias;
     cin.ignore();
     transacciones->agregar_fin(new Trans(id, persona->Getusername(), persona->Getdepartamento(), persona->Getempresa(), dias, fecha));
     ActivosRentados->agregar_fin(new Trans(id, persona->Getusername(), persona->Getdepartamento(), persona->Getempresa(), dias, fecha));
     cubito->apagarActivo(id,1);
 }
  void moduloRentar()
  {
      string num="";
      cubito->mostrarActivosMenosLosMios(persona);
      cout<<endl;
      cout<<"Si desea rentar activos presiones 2, de lo contrario presione cualquier tecla"<<endl<<">>";

      cin>>num;
      cin.ignore();
      if(num=="2")
      {
          cout<<"Ingrese ID de activo que quiere rentar e ingrese los datos correspondientes"<<endl<<">>";
          moduloTransaccion();
          //aregar a historial de transacciones
      }
  }
void moduloAgregaActivo()
{
    string nombreActivo;
    string nombreDesc;
    system("cls");
    cout<<"Agregar Activo"<<endl;
    cout<<"Ingrese el nombre"<<endl<<">>";
    getline(cin,nombreActivo);
    cout<<"ingrese Descripcion"<<endl<<">>";
    getline(cin,nombreDesc);
    cubito->ingresarAVL(new Activo(nombreDesc,nombreActivo),persona);

}
void moduloEliminaActivo()
{
    string nombreActivo;
    system("cls");
    cout<<"Elimina Activo"<<endl;
    cout<<endl;
    cubito->mostrarActivos(persona);
    cout<<"Ingrese el ID del activo a eliminar"<<endl<<">>";

    cin>>nombreActivo;
    cin.ignore();
    cubito->eliminarAVL(nombreActivo,persona);

}
void moduloModificaActivo()
{
    string nombreActivo;
    string nomb;
    string act;
    system("cls");
    cout<<"Modifica Activo"<<endl;
    cout<<endl;
    cubito->mostrarActivos(persona);
    cout<<"Ingrese el ID del activo a Modificar"<<endl<<">>";

    cin>>nombreActivo;
    cin.ignore();
    cubito->modificarAVL(nombreActivo,persona);

}
void moduloUsuario()
{
int opcion=0;
    do{
            system("cls");
        cout<<"Bienvenido: "<<persona->Getusername()<<" DEP: "<<persona->Getdepartamento()<<" EMP: "<< persona->Getempresa()<<endl;
        cout<<"1. Agregar Activo"<<endl;
        cout<<"2. Eliminar Activo"<<endl;
        cout<<"3. Modificar Activo"<<endl;
        cout<<"4. Rentar Activo"<<endl;//catalogo de activos
        cout<<"5. Activos Rentados"<<endl;//los que yo rente
        cout<<"6. Mis Activos Rentados"<<endl;//lo que yo tengo a la renta
        cout<<"7. Cerrar Sesion"<<endl<<">>";

        cin>>opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            moduloAgregaActivo();
            break;
        case 2:
            moduloEliminaActivo();
            //reportes
            break;
        case 3:
            moduloModificaActivo();
            break;
        case 4:
            moduloRentar();
            break;
        case 5:
            moduloDevolverActivos();
            break;
        case 6:
            moduloMostrarMisRentados();
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

    getline(cin,nombre);
    cout<<"Apellido"<<endl<<">>";
    getline(cin,apellido);
    cout<<"Usuario"<<endl<<">>";
    getline(cin,usuario);
    cout<<"Contrasenia"<<endl<<">>";
    getline(cin,contrasenia);
    cout<<"Departamento"<<endl<<">>";
    getline(cin,departamento);
    cout<<"Empresa"<<endl<<">>";
    getline(cin,empresa);
    cubito->crearNodo(new Usuario(nombre,apellido,usuario, contrasenia, departamento, empresa),departamento,empresa);
    cout<<"Registrado"<<endl;
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
        cin.ignore();
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

    getline(cin,usuario);
    cout<<"Contrasenia"<<endl<<">>";
    getline(cin,contrasenia);
    cout<<"Departamento"<<endl<<">>";
    getline(cin,departamento);
    cout<<"Empresa"<<endl<<">>";
    getline(cin,empresa);
    Nodo *aux= cubito->busquedaNodo(departamento,empresa,usuario,contrasenia);
    if(aux!=0)
    {
        if(usuario.compare("admin")==0 && contrasenia.compare("admin")==0){
        moduloAdmin();}
        else if(aux->getUser()->Getusername().compare(usuario)==0 && aux->getUser()->Getpass().compare(contrasenia)==0){
           persona=aux->getUser();
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
    cin.ignore();
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
