#include <iostream>
#include <stdlib.h>
#include <limits>
#include "string.h"
#include "central.h"
#include "Ruta.h"
#include "Venta.h"
#include "agencia.h"

using namespace std;

central c;
agencia a;
vector<string> cadenas;

string SepararCadena (string cadena);
void OpcionesMenu (int opcion2, string idA);
void ayuda();


int main()
{
    string archRuta,archVenta,archCont,comando,contra;
    string idA;
    bool ver=false;
    archCont="passwords01.txt";
    archRuta="flights01.txt";
    archVenta="tickets01.txt";

    int opcion=0,opcion2=0;
    do
    {
        cout << "\n";
        cout << "\n -------------------------- PROGRAMA DE AGENCIA DE VIAJES -------------------- \n";
        cout << "\n $ ";


        getline(cin,comando);

        idA = SepararCadena(comando);

        if (comando.length() == 10 && comando[0] == 'l')
            opcion = 1;

        if (comando.length() == 4 && comando == "exit")
            opcion = 2;

        if (comando.length() == 4 && comando == "help")
            opcion = 3;

        if (comando.length() == 6)
            opcion = 4;

        if (comando.length() == 16 && comando == "report inventory" && comando == "report flights")
            opcion = 5;


        // Cargan los archivos de rutas, vuelos y contrasenas //
        a.CargarArchivoRuta(archRuta);
        a.CargarArchivoVenta(archVenta);
        c.CargarArchivoContrasena(archCont);

        switch(opcion)
        {
        case 1:
            system("cls");
            cout << "\n Ingrese la contrasena: ";
            cin >> contra;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ver = c.verificarAgencia(idA,contra);
            if(ver)
            {
                cout << "\n Sesion iniciada ";
                OpcionesMenu(opcion2,idA);

            }
            else
            {
                cout << "\n El ID o contraseña ingresados no son validos. Intente nuevamente. ";
            }
            break;

        case 2:
            system("cls");
            cout << "\n Ha salido del programa. " <<endl;
            break;

        case 3:
            system("cls");
            ayuda();
            break;

        case 4:
            system("cls");
            cout << "\n No ha iniciado sesion.";
            break;

        case 5:
            system("cls");
            cout << "\n Debe iniciar sesion para acceder a esta funcionalidad. Intente nuevamente. ";
            break;

        default:
            cout<<"\n Al comando le hace falta informacion o es invalido. Ingrese help para saber mas."<<endl;
            break;
        }

    }
    while(opcion!=2);

    return 0;
}

string SepararCadena (string cadena)
{
    string cadenaAux;

    for(unsigned int i=0; i<cadena.length(); i++)
    {
        if (i>=6)
        {
            cadenaAux = cadenaAux+cadena[i];
        }
    }

    return cadenaAux;

}

void OpcionesMenu (int opcion2, string idA)
{
    string comando,comandoaux,origen,dia;
    do
    {

        cout << "\n";
        cout << "\n -------------------------- PROGRAMA DE AGENCIA DE VIAJES -------------------- \n";
        cout << "\n $ ";


        getline(cin,comando);

        comandoaux = comando;

        if (comandoaux.length() > 14)
        {
            cadenas = c.split(comandoaux,' ');
            origen = cadenas[2];
            dia = cadenas[3];
            cout << origen <<endl;
            cout << dia <<endl;
        }

        if (comando[13] == 's')
            opcion2=1;

        if (comando.length() == 16)
            opcion2 = 2;


        if (comando.length() == 6 && comando == "logout")
            opcion2 = 4;

        if (comando.length() == 4 && comando == "exit")
            opcion2 = 5;

        if (comando.length() == 4 && comando == "help")
            ayuda();




        switch (opcion2)
        {

        case 1:
            system("cls");
            cout << "\n Reporte de Vuelos Disponibles:  \n";
            if (comando == "report flights")
            {
                a.generarReportesVuelosDisponibles();
            }
            else {

                a.generarReporteOrigenFecha(idA,origen,dia);

            }
            break;

        case 2:
            cout << "\n ------------------------ Inventario de ventas ------------------------------- ";

            break;

        case 3:
            cout << "\n ------------------------ Venta de Vuelos ------------------------------------- ";
            break;

        case 4:
            cout << "\n Sesion finalizada. ";
            break;

        case 5:
            exit(0);
            cout << "\n Ha salido del programa.";
            break;

        default:
            cout << "\n Opcion invalida. ";
            break;

        }

    }
    while (opcion2!=4);

}

void ayuda ()
{

    cout << "\n ------------------------------ MENU DE AYUDA -----------------------------------\n";
    cout << "\n La informacion solicitada entre < > es obligatoria.";
    cout << "\n La informacion solicitada entre [ ] es opcional.";
    cout << "\n Lista de Comandos: ";
    cout << "\n 1. login <id_agencia>: Validar la sesion de trabajo de una agencia de viajes";
    cout << "\n 2. logout: Terminar la sesion de una agencia de viajes ";
    cout << "\n 3. report flights [origen] [fecha]: Generar reportes de vuelos disponibles ";
    cout << "\n 4. report inventory: Generar inventario de ventas ";
    cout << "\n 5. sell <id_vuelo> <fecha>: Vender un vuelo sencillo (de unica ruta) ";
    cout << "\n 6. exit: Salir de la aplicacion ";



}
