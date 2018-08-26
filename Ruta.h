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

    //ruta();
    //virtual ~ruta();
    void SetCodigoVuelo(string cod)
    {
        codigoVuelo=cod;
    }
    void SetDia (string d)
    {

        dia=d;
    }
    void SetCiudadO(string origen)
    {

        ciudadO=origen;
    }
    void SetCiudadD(string destino)
    {

        ciudadD=destino;
    }
    void SetHoraSalida (unsigned int horaS)
    {
        horaSalida=horaS;

    }
    void SetTiempoVuelo (unsigned int temp)
    {

        tiempoVuelo=temp;
    }
    void SetCostoSilla (double costo)
    {

        costoSilla=costo;
    }
    void SetCantSillas (unsigned int can)
    {

        cantSillas=can;
    }

    string GetCodigoVuelo()
    {

        return codigoVuelo;
    }
    string GetDia()
    {

        return dia;
    }
    string GetCiudadO()
    {

        return ciudadO;
    }
    string GetCiudadD()
    {
        return ciudadD;

    }
    unsigned int GetHoraSalida()
    {

        return horaSalida;
    }
    unsigned int GetTiempoVuelo()
    {
        return tiempoVuelo;

    }
    unsigned int GetCantSillas()
    {

        return cantSillas;
    }
    double GetCostoSilla()
    {
        return costoSilla;

    }


};


#endif // RUTA_H_INCLUDED

