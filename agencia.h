#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class agencia
{

protected:

    string idAgencia;
    string contrasena;
    string nombre;
    list <ruta> rutas;
    list <venta> ventas;

public:

    agencia();
    virtual ~agencia();

    void SetIdAgencia(string idA);
    void SetContrasena (string cont);
    void SetNombre (string nom);
    void SetRutas (list <ruta> rut);
    void SetVentas (list <venta> ven);

    string GetIdAgencia();
    string GetContrasena();
    string GetNombre();
    list <venta> GetVentas();
    list <ruta> GetRutas();



    string verificarAgencia(string nomArchivo);





};

#endif // AGENCIA_H_INCLUDED
