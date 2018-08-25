#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include <fstream>

using namespace std;

class venta
{
protected:

    string idAgencia;
    string codigoV;
    string apellidos;
    string nombres;
    string fecha;
    string fechaVenta;
    unsigned int horaVenta;
    double cedula;

public:

    venta();
    virtual ~venta();
    void SetIdAgencia(string idA);
    void SetCodigoV (string codv);
    void SetApellidos(string ap);
    void SetNombres (string noms);
    void SetFecha (string fech);
    void SetFechaVenta(string fechaV);
    void SetHoraVenta (unsigned int horaV);
    void SetCedula(double ced);

    string GetIdAgencia();
    string GetCodigoV();
    string GetApellidos();
    string GetNombres();
    string GetFecha();
    string GetFechaVenta();
    unsigned int GetHoraVenta();
    double GetCedula();





};



#endif // VENTA_H_INCLUDED

