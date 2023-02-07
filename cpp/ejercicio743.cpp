// Ejemplo 07.05:
// Array con muchos struct y menu para manejarla
#include <iostream>
#include <string>
using namespace std;
struct tipoDatos
{
    string nombreFich; // Nombre del fichero
    long tamanyo;      // El tamaño en bytes
};
//variables generales
int numeroFichas = 0; // Número de fichas que ya tenemos
int i;                // Para bucles
int opcion;           // La opcion del menu que elija el usuario
string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;
//main
int main();
{
    tipoDatos *fichas = new tipoDatos[1000];
    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo fichero" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl;
        cin >> opcion;
        // Hacemos una cosa u otra según la opción escogida
        switch (opcion)
        {
        case 1:                      // Añadir un dato nuevo
            if (numeroFichas < 1000) // Si queda hueco
            {
                cout << "Introduce el nombre del fichero: ";
                cin >> fichas[numeroFichas].nombreFich;
                cout << "Introduce el tamaño en KB: ";
		getline(cin,fichas[numeroFichas].tamanyo);
                while (fichas[numeroFichas].tamanyo<0){
			getline(cin,fichas[numeroFichas].tamanyo);
		}
                numeroFichas++; // Y tenemos una ficha más
            }
            else // Si no hay hueco para más fichas, avisamos
                cout << "Máximo de fichas alcanzado (1000)!" << endl;
            break;
        case 2: // Mostrar todos
            for (i = 0; i < numeroFichas; i++)
                cout << "Nombre: " << fichas[i].nombreFich
                    << "; Tamaño: " << fichas[i].tamanyo
                    << "Kb" << endl;
            break;
        case 3: // Mostrar según el tamaño
            cout << "¿A partir de que tamaño quieres que te muestre? ";
            cin >> numeroTemporal;
            for (i = 0; i < numeroFichas; i++)
                if (fichas[i].tamanyo >= numeroTemporal)
                    cout << "Nombre: " << fichas[i].nombreFich
                        << "; Tamaño: " << fichas[i].tamanyo
                        << " Kb" << endl;
            break;
        case 4: // Ver todos los datos (pocos) de un fichero
            cout << "¿De qué fichero quieres ver todos los datos?";
            cin >> textoTemporal;
            for (i = 0; i < numeroFichas; i++)
                if (fichas[i].nombreFich == textoTemporal)
                    cout<< "Nombre: " << fichas[i].nombreFich
                        << "; Tamaño: " << fichas[i].tamanyo
                        << " Kb" << endl;
            break;
        case 5: // Salir: avisamos de que salimos
            cout << "Fin del programa" << endl;
            break;
        default: // Otra opcion: no válida
            cout << "Opción desconocida!" << endl;
            break;
        }
    } while (opcion != 5); // Si la opcion es 5, terminamos
    return 0;
}
