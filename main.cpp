#include <iostream>
#include "string.h"
#include "Ruta.h"
#include "Venta.h"
#include "contrasena.h"
#include "agencia.h"

using namespace std;

int main()
{
    string archRuta,archVenta,archCont,comando;
    string idA,ver;
    agencia a;
    ruta r;
    venta v;
    contrasena c;
    int opcion;
    do
    {
        cout << "\n";
        cout << "\n ------------ PROGRAMA DE AGENCIA DE VIAJES ----------------- \n";
        cout << "\n $ ";

        getline(cin,comando);

        if (comando.length() == 10)
            opcion = 1;



       // Cargan los archivos de rutas, vuelos y contrasenas //
        r.CargarArchivoRuta(archRuta);
        v.CargarArchivoVenta(archVenta);
        c.CargarArchivoContrasena(archCont);


        switch(opcion)
        {
        case 1:
            ver = a.verificarAgencia(idA);
            cout << "\n Sesion iniciada ";

            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            cout << "\n Ha salido del programa. " <<endl;
            break;

        case 7:
            cout << "\n Menu de Ayuda ";
            cout << "\n 1. login: Validar la sesion de trabajo de una agencia de viajes";
            cout << "\n 2. logout: Terminar la sesion de una agencia de viajes ";
            cout << "\n 3. report flights: Generar reportes de vuelos disponibles ";
            cout << "\n 4. Generar inventario de ventas ";
            cout << "\n 5. Vender un vuelo sencillo (de unica ruta) ";
            cout << "\n 6. exit: Salir de la aplicacion ";
            break;

        default:
            cout<<"\n Opcion invalida"<<endl;
            break;
        }

    }
    while(opcion!=6);



    return 0;
}
