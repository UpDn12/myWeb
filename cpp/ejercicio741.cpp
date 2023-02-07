/**Un programa que pida el nombre, el apellido y la edad de una persona, los almacene en un “struct” y luego muestre los tres datos en una misma línea, separados por comas. */
#include <iostream>
using namespace std;
//struct persona
struct Persona
{
    string name;
    string lastname;
    int age;
};
//clase main
int main(int argc, char const *argv[])
{
    Persona person[3];
    //pedir datos de las 3 personas
    for (int i = 0; i < 3; i++)
    {
        cout<<"nombre de la persona "<<i+1<<": ";
        cin>>person[i].name;
        cout<<"apellido de la persona "<<i+1<<": ";
        cin>>person[i].lastname;
        cout<<"edad de la persona "<<i+1<<": ";
        cin>>person[i].age;
    }
    //imprimir datos
    for (int i = 0; i < 3; i++)
    {
        cout<<"Persona "<<i+1<<": >Nombre "<<person[i].name<<",\tApellido "<<person[i].lastname<<",\tEdad: "<<person[i].age<<"\n";
    }
    
    
    return 0;
}

