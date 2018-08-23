#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED

#include <list>

using namespace std;

class agencia
{

protected:

    string idAgencia;
    string nombre;
    list <ruta> rutas;
    list <venta> ventas;
    list <contrasena> contrasenas;

public:

    string verificarAgencia (string id)
    {

        string idVer;

        return idVer;


    }


};

#endif // AGENCIA_H_INCLUDED
