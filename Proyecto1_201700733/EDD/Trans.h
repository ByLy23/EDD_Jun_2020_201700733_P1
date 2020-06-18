#ifndef TRANS_H
#define TRANS_H

#include <iostream>
using namespace std;
class Trans
{
   public:
        Trans();
        Trans(string idActivo, string username, string dep, string emp, string tie, string fech)
        {
            this->idActivo=idActivo;
            this->Username=username;
            this->departamento=dep;
            this->empresa=emp;
            this->tiempo=tie;
            this->fecha=fech;
            this->id=metodoRandom();
        }
        string Getid() { return id; }
        void Setid(string val) { id = val; }
        string GetidActivo() { return idActivo; }
        void SetidActivo(string val) { idActivo = val; }
        string GetUsername() { return Username; }
        void SetUsername(string val) { Username = val; }
        string Getdepartamento() { return departamento; }
        void Setdepartamento(string val) { departamento = val; }
        string Getempresa() { return empresa; }
        void Setempresa(string val) { empresa = val; }
        string Gettiempo() { return tiempo; }
        void Settiempo(string val) { tiempo = val; }
        string Getfecha() { return fecha; }
        void Setfecha(string val) { fecha = val; }

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
        string id;
        string idActivo;
        string Username;
        string departamento;
        string empresa;
        string tiempo;
        string fecha;
};

#endif // TRANS_H
