#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Venta.h"
#include "Ruta.h"
#include <fstream>
#include <sstream>
#include<iostream>

using namespace std;

class agencia
{

public:

    string idAgencia;
    string contrasena;
    string nombre;
    vector <ruta> rutas;
    vector <venta> ventas;

public:

    vector <string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
            result.push_back(item);
        return result;
    }

    void SetIdAgencia(string idA)
    {
        idAgencia = idA;

    }
    void SetContrasena (string cont)
    {

        contrasena = cont;

    }
    void SetNombre (string nom)
    {

        nombre=nom;

    }

    void SetRutas (vector <ruta> rut)
    {

        rutas=rut;

    }

    void SetVentas (vector <venta> ven)
    {

        ventas=ven;


    }

    string GetIdAgencia()
    {

        return idAgencia;

    }

    string GetContrasena()
    {

        return contrasena;


    }
    string GetNombre()
    {

        return nombre;

    }
    vector <venta> GetVentas()
    {

        return ventas;

    }
    vector <ruta> GetRutas()
    {

        return rutas;

    }

    void CargarArchivoRuta (string archivo)
    {

        ifstream input(archivo.c_str());// Open text file
        if( !input )
        {
            cout << "Error opening \"" << archivo << "\"" << std::endl;
        } // fi
        string input_line;
        while(getline(input,input_line))
        {
            ruta r;
            vector<string>tokens = split(input_line,';');
            r.SetCodigoVuelo(tokens[0]);
            r.SetDia(tokens[1]);
            r.SetCiudadO(tokens[2]);
            r.SetCiudadD(tokens[3]);
            r.SetHoraSalida(stoul(tokens[4]));
            r.SetTiempoVuelo(stoul(tokens[5]));
            r.SetCantSillas(stoul(tokens[6]));
            r.SetCostoSilla(stod(tokens[7]));
            rutas.push_back(r);
        }
        input.close( ); // Close text fileCodigo



    }

    void CargarArchivoVenta (string archivo)
    {

        ifstream input(archivo.c_str());// Open text file
        if( !input )
        {
            cout << "Error opening \"" << archivo << "\"" << std::endl;
        } // fi
        string input_line;
        while(getline(input,input_line))
        {
            venta vnt;
            vector<string>tokens=split(input_line,';');
            vnt.SetIdAgencia(tokens[0]);
            vnt.SetCodigoV(tokens[1]);
            vnt.SetCedula(tokens[2]);
            vector<string>tk=split(tokens[3],',');
            vnt.SetApellidos(tk[0]);
            vnt.SetNombres(tk[1]);
            vnt.SetFecha(tokens[4]);
            vnt.SetFechaVenta(tokens[5]);
            vnt.SetHoraVenta(stoi(tokens[6]));

            ventas.push_back(vnt);
        }
        input.close( ); // Close text file



    }

    void generarReportesVuelosDisponibles ()
    {

        cout << "\n | id  |      Dia      | Ciudad Origen |  Ciudad Destino  |   Hora de Salida   | Tiempo Vuelo | Cantidad Sillas |   Costo Silla   | " << endl;
        vector<ruta>::iterator it;
        for (it=rutas.begin(); it!=rutas.end(); it++)
        {

            ruta r = *it;
            cout << "  " << r.GetCodigoVuelo() << "\t   " << r.GetDia() << "\t  " << r.GetCiudadO() << "      " << "\t  " << r.GetCiudadD() <<
                 " " << "\t  " << "     " << r.GetHoraSalida() << "\t         " << r.GetTiempoVuelo() << "\t         " <<r.GetCantSillas() << "\t           " << r.GetCostoSilla() <<endl;

        }


    }


    void generarReporteOrigenFecha (string idA, string origen, string dia)
    {   
        int cont=0;
        vector <string> aux2;
        bool b=false;
        cout << "\n | id  |      Dia      | Ciudad Origen |  Ciudad Destino  |   Hora de Salida   | Tiempo Vuelo | Cantidad Sillas |   Costo Silla   | " << endl;
        vector<ruta>::iterator it;
        vector<venta>::iterator it2;
        for (it=rutas.begin(); it!=rutas.end(); it++)
        {
            ruta r = *it;
            for (it2=ventas.begin(); it2!=ventas.end(); it2++ )
            {

                venta v = *it2;
                string aux = v.GetIdAgencia();
                aux2 = split(aux,'_');

                if (idA == aux2[0])
                {
                    if (v.GetCodigoV() == r.GetCodigoVuelo())
                    {
                        if (r.GetCiudadO()== origen && r.GetDia() == dia)
                        {
                            if (r.cantSillas > 0)
                            {
                                b = true;
                                cout << "  " << r.GetCodigoVuelo() << "\t   " << r.GetDia() << "\t  " << r.GetCiudadO() << "      " << "\t  " << r.GetCiudadD() <<
                                     " " << "\t  " << "     " << r.GetHoraSalida() << "\t         " << r.GetTiempoVuelo() << "\t         " <<r.GetCantSillas() << "\t           " << r.GetCostoSilla() <<endl;
                            }
                        }

                    }

                }
            }

        }

        if (b == false)
        {

            cout << "\n No hay un vuelo con esas caracteristicas. ";
        }
    }


};



#endif // AGENCIA_H_INCLUDED
