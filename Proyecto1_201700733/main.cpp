#include <iostream>
#include "EDD/Cola.h"
#include "EDD/ArbolAVL.h"
#include "EDD/CuboDisperso.h"
using namespace std;



CuboDisperso* cubito=new CuboDisperso();
Usuario *persona;
 void moduloMostrarMisRentados()
 {

 }
 void moduloDevolverActivos()
 {

 }
 void moduloMostrarRentados()
 {

 }
 void moduloTransaccion()
 {

 }
  void moduloRentar()
  {
      string num="";
      cubito->mostrarActivosMenosLosMios(persona);
      cout<<endl;
      cout<<"Si desea rentar activos presiones 2, de lo contrario presione cualquier tecla"<<endl<<">>";
      cin>>num;
      if(num=="2")
      {
          cout<<"Ingrese ID de activo que quiere rentar e ingrese los datos correspondientes"<<endl;
          moduloTransaccion();

      }
  }
void moduloAgregaActivo()
{
    string nombreActivo;
    string nombreDesc;
    system("cls");
    cout<<"Agregar Activo"<<endl;
    cout<<"Ingrese el nombre"<<endl<<">>";
    cin>>nombreActivo;
    cout<<"ingrese Descripcion"<<endl<<">>";
    cin>>nombreDesc;
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
        cout<<"6. Devolver Activos"<<endl;
        cout<<"7. Mis Activos Rentados"<<endl;//lo que yo tengo a la renta
        cout<<"8. Cerrar Sesion"<<endl<<">>";
        cin>>opcion;
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
            moduloMostrarRentados();
            break;
        case 6:
            moduloDevolverActivos();
            break;
        case 7:
            moduloMostrarMisRentados();
            break;
        }
    }while(opcion!=8);
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
