#ifndef RUTA_H_INCLUDED
#define RUTA_H_INCLUDED
#include <fstream>
using namespace std;

class ruta
{
protected:

    string codigoVuelo;
    string dia;
    string ciudadO;
    string ciudadD;
    unsigned int horaSalida;
    unsigned int tiempoVuelo;
    unsigned int cantSillas;
    double costoSilla;

public:

    ruta();
    virtual ~ruta();
    void SetCodigoVuelo(string cod);
    void SetDia (string d);
    void SetCiudadO(string origen);
    void SetCiudadD(string destino);
    void SetHoraSalida (unsigned int horaS);
    void SetTiempoVuelo (unsigned int temp);
    void SetCostoSilla (double costo);

    string GetCodigoVuelo();
    string GetDia();
    string GetCiudadO();
    string GetCiudadD();
    unsigned int GetHoraSalida();
    unsigned int GetTiempoVuelo();
    double GetCostoSilla();


};


#endif // RUTA_H_INCLUDED
