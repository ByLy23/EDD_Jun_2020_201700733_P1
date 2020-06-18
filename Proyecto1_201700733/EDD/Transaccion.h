#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <iostream>
using namespace std;

class Transaccion
{
    public:
        Transaccion();
        virtual ~Transaccion();
        Transaccion(string idActivo, string username, string dep, string emp, string tie, string fech)
        {

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
        string id;
        string idActivo;
        string Username;
        string departamento;
        string empresa;
        string tiempo;
        string fecha;
};

#endif // TRANSACCION_H
