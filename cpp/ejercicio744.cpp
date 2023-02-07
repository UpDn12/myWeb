#include <iostream>
using namespace std;
int numeroFichas=0;
//menu general
int Menu(){
    int option;
    cout<<"1.- Añadir datos de un nuevo fichero\n"
        <<"2.- Mostrar los nombres de todos los ficheros\n"
        <<"3.- Mostrar ficheros que sean de mas de un cierto tamaño\n"
        <<"4.- Ver datos de un fichero\n"
        <<"5.- busca de datos\n"
        <<"6.- eliminar datos de un nuevo fichero\n"
        <<"7.- Salir\n";
    cin>>option;
    return option;
};
//struct
struct tipoDatos{
    string nombreFichero; // Nombre del fichero
    string tamanio;      // El tamaño en bytes
};
//primera opcion
void AniadirDatos(tipoDatos datos[],int numeroFichas){
    if(numeroFichas<1000){
        cout<<"Introduce el nombre del fichero: ";
        cin>>datos[numeroFichas].nombreFichero;
        cout << "Introduce el tamaño en KB: ";
        cin>>datos[numeroFichas].tamanio;
        while(datos[numeroFichas].tamanio<0){
            cin>>datos[numeroFichas].tamanio;
        }
        numeroFichas++;
    }else{
        cout << "Máximo de fichas alcanzado (1000)!\n";
    }
}
//segunda opcion
void MostrarTodo(tipoDatos datos[],int numeroFichas){
    for(int i; i<numeroFichas; i++){
        cout<<"\nNombre: "<<datos[i].nombreFichero
            <<"\nTamanio: "<<datos[i].tamanio<<" kb";
    }
}
//tercera opcion
void MostarSegunTamanio(tipoDatos datos[],int numeroFichas, int tamanioAMostrar){
    for(int i;i<numeroFichas;i++){
        if(stoi(dato[i].tamanio>=tamanioAMostrar)){
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
}
//cuarta opcion
void DatosDeFichero(tipoDatos datos[],int numeroFichas, string ficheroAMostrar){
    for(int i;i<numeroFichas;i++){
        if(datos[i].nombreFichero==ficheroAMostrar){
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
}
//quianta opcion
void BuscaPorNombre(tipoDatos datos[],int numeroFichas, string ficheroAMostrar){
    string nombre;
    int length;
    length=ficheroAMostrar.length();
    nombre=datos[i].nombreFichero;

    for(int i;i<numeroFichas;i++){
        if(nombre[length]==ficheroAMostrar){
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
}
//sexta opcion
void EliminarDatos(tipoDatos datos[],int numeroFichas,int EliminarDato){
    if(EliminarDato<numeroFichas){
        for(int i;i<numeroFichas;i++){
            if(i==EliminarDato){
                for(int j=i;j<numeroFichas-1;j++){
                    datos[j].nombreFichero=datos[j+1].nombreFichero;
                    datos[j].tamanio=datos[j+1].tamanio;
                }
                break;
            }
        }
    }else{
        cout << "ese dato no existe!!\n";
    }
}
main(){
    int i=0, tamanioAMostrar=0,EliminarDato=0;
    tipoDatos datos[numeroFichas];
    bool salir;
    string textoAMostrar;
    //menu y pociones
    do
    {
        switch (Menu())
        {
        case 1:
            //o Mostrar la lista de todos los nombres.
            AniadirDatos(datos,numeroFichas);
            break;
        case 2:
            //o Mostrar las personas de una cierta edad.
            MostrarTodo(datos,numeroFichas);
            break;
        case 3:
            //Mostrar las personas cuya inicial sea la que el usuario indique.
            cout << "¿A partir de que tamaño quieres que te muestre? ";
            cin >> tamanioAMostrar;
            MostarSegunTamanio(datos,numeroFichas,tamanioAMostrar);
            break;
        case 4:
            //o Mostrar la lista de todos los nombres.
            cout << "¿De qué fichero quieres ver todos los datos?";
            cin >> textoAMostrar;
            DatosDeFichero(datos,numeroFichas,textoAMostrar);
            break;
        case 5:
            //o Mostrar las personas de una cierta edad.
            cout << "¿De qué nombre quieres ver todos los datos?";
            cin >> textoAMostrar;
            BuscaPorNombre(datos,numeroFichas,textoAMostrar);
            break;
        case 6:
            //Mostrar las personas cuya inicial sea la que el usuario indique.
            cout << "¿que posicion del dato quiere elimar (desde el 1)?";
            cin >> EliminarDato;
            EliminarDatos(datos,numeroFichas,EliminarDato);
            break;
        default:
        //salir del programa
            salir=false;
            break;
        }
    } while (salir);
}
