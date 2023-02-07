/**· (7.4.2) Un programa que pida datos de 8 personas: nombre, dia de nacimiento, mes de nacimiento, y año de nacimiento (que se 
deben almacenar en una tabla de structs). Después deberá repetir lo siguiente: preguntar un número de mes y mostrar en 
pantalla los datos de las personas que cumplan los años durante ese mes. Terminará de repetirse cuando se teclee 0 como número de mes. */
#include <iostream>
using namespace std;
struct Persona
{
    string nombre;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
};
int main(int argc, char const *argv[])
{
    Persona person[8];
    int mes=1;
    //pedir datos
    for (int i = 0; i < 8; i++)
    {
        cout<<"nombre, dia/mes/anio de nacimiento de la persona "<<i+1<<": ";
        cin>>person[i].nombre;        
        cin>>person[i].diaNacimiento;
        cin>>person[i].mesNacimiento;
        cin>>person[i].anioNacimiento;
    }
    do
    {
        cout<<"dime un numero de mes: ";
        cin>>mes;
        cout<<"\nlos nacidos en ese mes son:\n";
        for (int i = 0; i < 8; i++)
        {
            if (person[i].mesNacimiento==mes)
            {
                cout<<"Persona "<<i+1<<":\n"
                    <<"\tNombre: "<<person[i].nombre
                    <<"\tDia de Nacimiento: "<<person[i].diaNacimiento
                    <<"\tMes de Nacimiento: "<<person[i].mesNacimiento
                    <<"\tAnio de Nacimiento: "<<person[i].anioNacimiento
                    <<"\n";
            }
            
        }
    } while (mes!=0);
    return 0;
}
