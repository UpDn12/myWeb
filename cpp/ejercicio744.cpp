#include <iostream>
using namespace std;

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
int AniadirDatos(tipoDatos datos[],int numeroFicha){
    int numeroFichas=numeroFicha;
    if(numeroFichas<1000){
        cout<<"Introduce el nombre del fichero: ";
        cin>>datos[numeroFichas].nombreFichero;
        cout << "Introduce el tamaño en KB: ";
        cin>>datos[numeroFichas].tamanio;
        while(stoi(datos[numeroFichas].tamanio)<0){
            cin>>datos[numeroFichas].tamanio;
        }
        cout<<numeroFichas;
        numeroFichas++;
    }else{
        cout << "Máximo de fichas alcanzado (1000)!\n";
    }
    return numeroFichas;
}
//segunda opcion
int MostrarTodo(tipoDatos datos[],int numeroFicha){
    int numeroFichas=numeroFicha;
    for(int i=0; i<numeroFichas+1; i++){
        cout<<"\nNombre: "<<datos[i].nombreFichero
            <<"\nTamanio: "<<datos[i].tamanio<<" kb";
    }
    return numeroFichas;
}
//tercera opcion
int MostarSegunTamanio(tipoDatos datos[],int numeroFicha, int tamanioAMostrar){
    int numeroFichas=numeroFicha;
    for(int i=0;i<numeroFichas+1;i++){
        if(stoi(datos[i].tamanio)>=tamanioAMostrar){
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
    return numeroFichas;
}
//cuarta opcion
int DatosDeFichero(tipoDatos datos[],int numeroFicha, string ficheroAMostrar){
    int numeroFichas=numeroFicha;
    for(int i=0;i<numeroFichas+1;i++){
        if(datos[i].nombreFichero==ficheroAMostrar){
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
    return numeroFichas;
}
//quianta opcion
int BuscaPorNombre(tipoDatos datos[],int numeroFicha, string ficheroAMostrar){
    string nombre;
    int length;
    int numeroFichas=numeroFicha;
    length=ficheroAMostrar.length();

    for(int i=0;i<numeroFichas+1;i++){
        nombre=datos[i].nombreFichero;
        if(nombre.substr(0,length)==ficheroAMostrar){// es un char solo devuelve un caracter
            cout<<"\nNombre: "<<datos[i].nombreFichero
                <<"\nTamanio: "<<datos[i].tamanio<<" kb";
        }
    }
    return numeroFichas;
}
//sexta opcion
int EliminarDatos(tipoDatos datos[],int numeroFicha,int EliminarDato){
    int numeroFichas=numeroFicha;
    if(EliminarDato<numeroFichas){
        for(int i=0;i<numeroFichas+1;i++){
            if(i==EliminarDato){
                for(int j=i;j<numeroFichas;j++){
                    datos[j].nombreFichero=datos[j+1].nombreFichero;
                    datos[j].tamanio=datos[j+1].tamanio;
                }
                break;
            }
        }
    }else{
        cout << "ese dato no existe!!\n";
    }
    numeroFichas--;
    return numeroFichas;
}
main(){
    int i=0, tamanioAMostrar=0,EliminarDato=0;
    int numeroFichas=0;
    tipoDatos datos[numeroFichas];
    int salir=0;
    string textoAMostrar;
    //menu y pociones
    do
    {
        switch (Menu())
        {
        case 1:
            //o Mostrar la lista de todos los nombres.
            numeroFichas=AniadirDatos(datos,numeroFichas);
            break;
        case 2:
            //o Mostrar las personas de una cierta edad.
            numeroFichas=MostrarTodo(datos,numeroFichas);
            break;
        case 3:
            //Mostrar las personas cuya inicial sea la que el usuario indique.
            cout << "¿A partir de que tamaño quieres que te muestre? ";
            cin >> tamanioAMostrar;
            numeroFichas=MostarSegunTamanio(datos,numeroFichas,tamanioAMostrar);
            break;
        case 4:
            //o Mostrar la lista de todos los nombres.
            cout << "¿De qué fichero quieres ver todos los datos?";
            cin >> textoAMostrar;
            numeroFichas=DatosDeFichero(datos,numeroFichas,textoAMostrar);
            break;
        case 5:
            //o Mostrar las personas de una cierta edad.
            cout << "¿De qué nombre quieres ver todos los datos?";
            cin >> textoAMostrar;
            numeroFichas=BuscaPorNombre(datos,numeroFichas,textoAMostrar);
            break;
        case 6:
            //Mostrar las personas cuya inicial sea la que el usuario indique.
            cout << "¿que posicion del dato quiere elimar (desde el 1)?";
            cin >> EliminarDato;
            numeroFichas=EliminarDatos(datos,numeroFichas,EliminarDato);
            break;
        case 7:
            cout << "saliendo";
            salir=7;
            break;
        default:
        //salir del programa
            cout << "opcion no valida";
            break;
        }
    } while (salir!=7);
}
