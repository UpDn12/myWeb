/**Un programa que sea capaz de almacenar los datos de 50 personas: nombre, dirección, teléfono, edad (usando una tabla de      
structs). Deberá ir pidiendo los datos uno por uno, hasta que un nombre se introduzca vacío (se pulse Intro sin teclear nada). Entonces deberá aparecer un menú que permita:
o Mostrar la lista de todos los nombres.
o Mostrar las personas de una cierta edad.
o Mostrar las personas cuya inicial sea la que el usuario indique.
o Salir del programa (lógicamente, este menú debe repetirse hasta que se escoja la opción de “salir”). */
#include <iostream>
using namespace std;
//menu del programa
int Menu(){
    int option;
    cout<<"1.) Mostrar la lista de todos los nombres\n"
        <<"2.) Mostrar las personas de una cierta edad\n"
        <<"3.) Mostrar las personas cuya inicial sea la que el usuario indique\n"
        <<"4.) Salir del programa\n";
    cin>>option;
    return option;
};
//struct persona
struct Persona
{
    string nombre;
    string direcion;
    string telefono;
    string edad;
};
//o Mostrar la lista de todos los nombres.
void ListNombres(Persona person[],int tamanioArray){
    for (int i = 0; i < tamanioArray; i++)
    {
        cout<<"Persona "<<i+1<<": "<<person[i].nombre<<"\n";
    }
}
//o Mostrar las personas de una cierta edad.
void ListEdad(Persona person[],int tamanioArray,int edad){
    for (int i = 0; i < tamanioArray; i++)
    {
        //verifica si la edad es la misma a la de buscar
        if (stoi(person[i].edad)==edad)
        {
            cout<<"Persona "<<i+1<<":\n"
                <<"\tNombre: "<<person[i].nombre
                <<"\tEdad: "<<person[i].edad
                <<"\tTelefono: "<<person[i].telefono
                <<"\n";
        }

    }
}
//Mostrar las personas cuya inicial sea la que el usuario indique.
void ListInicial(Persona person[],int tamanioArray,char inicial){
    string nombre;
    for (int i = 0; i < tamanioArray; i++)
    {
        nombre=person[i].nombre;
        //verifica si la inicial es igual a la de buscar
        if (nombre[0]==inicial)
        {
            cout<<"Persona "<<i+1<<":\n"
                <<"\tNombre: "<<person[i].nombre
                <<"\tEdad: "<<person[i].edad
                <<"\tTelefono: "<<person[i].telefono
                <<"\n";
        }
    }
}
//main
int main(int argc, char const *argv[])
{
    Persona person[2];
    int edad=0,i=0;
    bool salir;
    char inicial;
    //pedir datos
    while (i<2){
        cout<<"nombre de la persona "<<i+1<<":\n";
        getline(cin,person[i].nombre);
        if (person[i].nombre.empty())
        {
            break;
        }
        cout<<"direcion de la persona "<<i+1<<":\n";
        getline(cin,person[i].direcion);
        cout<<"telefono de la persona "<<i+1<<":\n";
        getline(cin,person[i].telefono);
        cout<<"edad de la persona "<<i+1<<":\n";
        getline(cin,person[i].edad);
        i++;
    }
    //menu y pociones
    do
    {
        switch (Menu())
        {
        case 1:
            //o Mostrar la lista de todos los nombres.
            ListNombres(person,i);
            break;
        case 2:
            //o Mostrar las personas de una cierta edad.
            cout<<"edades a buscar: ";
            cin>>edad;
            ListEdad(person,i,edad);
            break;
        case 3:
            //Mostrar las personas cuya inicial sea la que el usuario indique.
            cout<<"inicial a buscar: ";
            cin>>inicial;
            ListInicial(person,i,inicial);
            break;
        default:
        //salir del programa
            salir=false;
            break;
        }
    } while (salir);




    return 0;
}
