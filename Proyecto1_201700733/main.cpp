#include <iostream>
#include <string>
#include <fstream>
#include "EDD/Cola.h"
#include "EDD/ListaDobleCircular.h"
#include "EDD/ListaDoble.h"
#include "EDD/ArbolAVL.h"
#include "EDD/Trans.h"
#include "EDD/CuboDisperso.h"
using namespace std;



CuboDisperso* cubito=new CuboDisperso();
ListaDobleCircular<Trans*> *transacciones= new ListaDobleCircular<Trans*>();
ListaDoble<Trans*> *ActivosRentados= new ListaDoble<Trans*>();
Usuario *persona;
void graficarReportes(string, string);
void imprimirTransacciones(ListaDobleCircular<Trans*>);
string cuerpoLista="";
string enlaceLista="";
string todoArbolito="";
 void moduloDevolverActivos()
 {
     string nombr;
     for(int i=0; i< ActivosRentados->getSize(); i++)
     {
         if(ActivosRentados->obtener_at(i)->GetUsername().compare(persona->Getusername())==0 && ActivosRentados->obtener_at(i)->Getdepartamento().compare(persona->Getdepartamento())==0 && ActivosRentados->obtener_at(i)->Getempresa().compare(persona->Getempresa())==0)
         {
             cout<<"ID: "<<ActivosRentados->obtener_at(i)->GetidActivo()<<" Tiempo Rentado: "<<ActivosRentados->obtener_at(i)->Gettiempo()<<" Dias"<<endl;
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
     cout<<"Estos son los activos que rentaron de usted"<<endl;
    cubito->mostrarActivosRentados(persona);
    system("pause");
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

void imprimirTransacciones(ListaDobleCircular<Trans*> *lista)
{
    for(int i=0; i<lista->getSize(); i++)
    {
        int j=i+1;
        int k=i-1;
        cuerpoLista+="nodo"+to_string(i)+"[shape= record label=\""+lista->obtener_at(i)->Getid()+"\\nID del Activo: "+ lista->obtener_at(i)->GetidActivo()+"\\nLo alquilo: "+lista->obtener_at(i)->GetUsername()+"\\nLo alquilo para: "+lista->obtener_at(i)->Gettiempo()+"\\nFecha de alquiler: "+lista->obtener_at(i)->Getfecha()+"\"];\n";
        if(i==0)
        {
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(lista->getSize()-1)+"\n";
        }
        if(j==lista->getSize()-1)
        {
            enlaceLista+="nodo"+to_string(j)+" -> nodo"+ to_string(0)+"\n";
        }
        if(j<lista->getSize())
        {
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(j)+"\n";
        }
        if(k>=0){
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(k)+"\n";
        }
    }
}
void imprimirP(ListaDoble<Trans*> *lista)
{
    for(int i=0; i<lista->getSize(); i++)
    {
        int j=i+1;
        int k=i-1;
        cuerpoLista+="nodo"+to_string(i)+"[shape= record label=\""+lista->obtener_at(i)->Getid()+"\\nID del Activo: "+ lista->obtener_at(i)->GetidActivo()+"\\nLo alquilo: "+lista->obtener_at(i)->GetUsername()+"\\nLo alquilo para: "+lista->obtener_at(i)->Gettiempo()+"\\nFecha de alquiler: "+lista->obtener_at(i)->Getfecha()+"\"];\n";
        if(j<lista->getSize())
        {
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(j)+"\n";
        }
        if(k>=0){
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(k)+"\n";
        }
    }
}
void moduloImprimirAVL()
{
    string us;
    cout<<"Ingrese nombre Usuario"<<endl<<">>";
    getline(cin,us);
    cubito->imprimirPorUsuario(us);
}
void moduloAdmin()
{
    int opcion=0;
    do{
            system("cls");
            string dep;
            string emp;
        cout<<"1. Registrar Usuario"<<endl;
        cout<<"2. Reporte Matriz Dispersa"<<endl;//este toca
        cout<<"3. Reporte de Activos Disponibles por Departamento"<<endl;//por cada usuario del departamento
        cout<<"4. Reporte de Activos Disponibles por Empresa"<<endl;// por cada usuario de la empresa xD
        cout<<"5. Reporte de Transacciones"<<endl;//listo
        cout<<"6. Reporte de Activos de un Usuario"<<endl;//listo
        cout<<"7. Reporte de Activos rentados por un Usuario"<<endl;//lista simple
        cout<<"8. Ordenar Transacciones"<<endl;// si me da tiempo la hago sino F
        cout<<"9. Cerrar Sesion"<<endl<<">>";
        cin>>opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            moduloRegistro();
            break;
        case 2:
            cubito->imprimir();
            todoArbolito="digraph Matriz{ \n "+cubito->getCuerpo()+"\n"+cubito->getEnlaces()+cubito->getWor()+"{rank= same; "+cubito->getGrupo()+"}\n"+"}";
            graficarReportes(todoArbolito,"matriz");
            cubito->setCuerpo("");
            cubito->setEnlaces("");
            cubito->setGrupo("");
            todoArbolito="";
            //reportes
            break;
        case 3:
            cout<<"que departamento"<<endl;
            cin>>dep;
            cin.ignore();
            cubito->graficarporDep(dep);
            break;
        case 4:
            cout<<"que Empresa"<<endl;
            cin>>emp;
            cin.ignore();
            cubito->graficarporEmp(dep);
            break;
        case 5:
            imprimirTransacciones(transacciones);
            todoArbolito="digraph ListaCircular{ \n linkdir=LR \n"+cuerpoLista+"\n"+enlaceLista+"}";
            graficarReportes(todoArbolito,"ListaTransacciones");
            cuerpoLista="";
            enlaceLista="";
            todoArbolito="";
            break;
        case 6:
            moduloImprimirAVL();
            break;
        case 7:
            imprimirP(ActivosRentados);
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
    Nodo *aux= cubito->busquedaNodo(empresa,departamento,usuario,contrasenia);
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

void graficarReportes(string archivo,string nombre)
{
    string nombreArchivo=nombre+".dot";
    ofstream datos(nombreArchivo);
    datos<<archivo<<endl;
    datos.close();
    string inicio="start dot -Tjpg "+nombre+".dot -o "+nombre+".jpg";
    string ejecucion= "start "+nombre+".jpg";
    system((inicio).c_str());
    system((ejecucion).c_str());
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
