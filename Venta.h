#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include <fstream>

using namespace std;

class venta
{
protected:

    string idAgencia;
    //string identificador;
    string codigoV;
    string apellidos;
    string nombres;
    string fecha;
    string fechaVenta;
    unsigned int horaVenta;
    string cedula;

public:

    //venta();
    // virtual ~venta();
    void SetIdAgencia(string idA)
    {

        idAgencia = idA;

    }

    void SetCodigoV (string codv)
    {

        codigoV = codv;

    }
    void SetApellidos(string ap)
    {

        apellidos = ap;

    }
    void SetNombres (string noms)
    {

        nombres = noms;

    }
    void SetFecha (string fech)
    {

        fecha = fech;
    }
    void SetFechaVenta(string fechaV)
    {

        fechaVenta = fechaV;

    }
    void SetHoraVenta (unsigned int horaV)
    {

        horaVenta = horaV;

    }
    void SetCedula(string ced)
    {

        cedula = ced;

    }

    string GetIdAgencia()
    {
        return idAgencia;

    }


    string GetCodigoV()
    {

       return codigoV;

    }
    string GetApellidos()
    {

       return apellidos;

    }
    string GetNombres()
    {

       return nombres;

    }
    string GetFecha()
    {

       return fecha;

    }
    string GetFechaVenta()
    {
       return fechaVenta;

    }
    unsigned int GetHoraVenta()
    {
       return horaVenta;


    }
    string GetCedula()
    {

      return cedula;

    }





};



#endif // VENTA_H_INCLUDED
