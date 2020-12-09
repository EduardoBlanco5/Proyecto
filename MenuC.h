#include "Civilizacion.h"
#include <list>

list<Aldeano> Aldeanos;

Aldeano Capturar()
{
    string Nombre;
    string Genero;
    size_t Edad;
    size_t Salud;
    Aldeano Al;
                    

    cout <<"";
    getline(cin, Nombre);
    Al.setNombre(Nombre);

    cout <<"Nombre: ";
    getline(cin, Nombre);
    Al.setNombre(Nombre);

    cout <<"Genero: ";
    getline(cin, Genero);
    Al.setGenero(Genero);
                    
    cout <<"Edad: ";
    cin>> Edad;
    Al.setEdad(Edad);
                    
    cout <<"Salud: ";
    cin>> Salud; cin.ignore();
    Al.setSalud(Salud);

    return Al;
}

void MenuC(Civilizacion &A)
{
    string op;
    while (true)
    {
        //system("cls");
        cout << "1.- Agregar Aldeano" << endl;
        cout << "2.- Eliminar Aldeano" << endl;
        cout << "3.- Clasificar Aldeano" << endl;
        cout << "4.- Buscar Aldeano" << endl;
        cout << "5.- Modificar Aldeano" << endl;
        cout << "6.- Mostrar Aldeano" << endl;
        cout << "0.- Salir" << endl;
        cout << "Ingresa una opcion: ";
        getline(cin, op);
    
        if (op == "1")
        {
            size_t ops;
            while (true)
            {
                //system("cls");
                cout << "1.- Agregar aldeano al inicio"<< endl;
                cout << "2.- Agregar aldeano al final"<< endl;
                cout << "0.- Salir"<< endl;
                cout << "Ingresa una opcion: ";
                cin >> ops;

                if (ops == 1)
                { 
                    //system("cls");
                    cout<< "\t\tAldeano\n"<< endl;
                     
                    A.AgregarInicio(Capturar());

                    system("pause");
                }
                else if (ops ==2)
                {
                    //system("cls");
                    A.AgregarFinal(Capturar());
                    system("pause");
                }
                else if (ops == 0)
                {
                    cout<< "gracias..."<< endl;
                    system("pause");
                    break;
                }        
            };
                
        }
        else if (op == "2")
        {
            int ops;
            while (true)
            {
                //system("cls");
                cout << "1.- Eliminar aldeano por Nombre"<< endl;
                cout << "2.- Eliminar aldeano por Salud"<< endl;
                cout << "3.- Eliminar aldeano por Edad"<< endl;
                cout << "0.- Salir"<< endl;
                cout << "Ingresa una opcion: ";
                cin >> ops;
                if (ops == 1)
                {
                    //system("cls");
                    string n;
                    cout << "Nombre: ";
                    getline(cin, n);
                    cin.ignore();                 
                    A.EliminarN(n);
                    system("pause");
                }
                else if (ops == 2)
                {
                    //system("cls");
                    float Salud;
                    cout << "Salud: ";
                    cin >> Salud;
                    cin.ignore();                    
                    A.EliminarS(Salud);
                    system("pause");
                }
                else if (ops == 3)
                {
                    //system("cls");
                    cout << "Eliminados mayores de 60..."<< endl;                   
                    A.EliminarE();
                    system("pause");
                }
                else if (ops == 0)
                {
                    cout<< "gracias..."<< endl;
                    system("pause");
                    break;
                }

            };
        } 
        else if (op == "3")
        {
            int ops;
            while (true)
            {
                //system("cls");
                cout << "1.- Clasificar aldeano por Nombre"<< endl;
                cout << "2.- Clasificar aldeano por Salud"<< endl;
                cout << "3.- Clasificar aldeano por Edad"<< endl;
                cout << "0.- Salir"<< endl;
                cout << "Ingresa una opcion: ";
                cin >> ops;
                if (ops == 1)
                {
                    A.ClasificarN();
                    system("pause");
                }
                else if (ops == 2)
                {
                    A.ClasificarS();
                    system("pause");
                }
                else if (ops == 3)
                {
                    
                    A.ClasificarE();
                    system("pause");
                }
                else if (ops == 0)
                {
                    cout<< "gracias..."<< endl;
                    system("pause");
                    break;
                }

            };
        } 
        else if (op == "4")
        {
            //system("cls");
            Aldeano L = Capturar();
            Aldeano *ptr = A.Buscar(L);

            if (ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << *ptr << endl;
            }
            system("pause");
        } 
        else if (op == "5")
        {
            break;
        } 
        else if (op == "6")
        {
            //system("cls");
            A.Mostrar();
            system("pause");
        } 
        else if (op == "0")
        {
            cout<<"Gracias..."<<endl;
            system("pause");
            break;
        } 
            
    };
        
};