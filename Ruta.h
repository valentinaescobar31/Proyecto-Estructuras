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
    void CargarArchivoRuta (string nomarchivo)
    {
        ifstream myfile(nomarchivo.c_str());
        //string



    }

};


#endif // RUTA_H_INCLUDED
