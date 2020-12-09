#include <iostream>
#include <stdio.h>
#include <vector>
#include "Videogame.h"
#include "MenuC.h"

using namespace std;

int main()
{
    Videogame vg;
    vector<Civilizacion> Civilizacionez;
    vector<Videogame> Civilizacione;
    string op;

    while (true)
    {
        //system("cls");
        cout << "1.- Agregar Civilizacion " << endl;
        cout << "2.- Elegir Civilizacion" << endl;
        cout << "3.- Insertar " << endl;
        cout << "4.- Inicializar " << endl;
        cout << "5.- Primera Civilizacion " << endl;
        cout << "6.- Ultima Civilizacion " << endl;
        cout << "7.- Ordenar " << endl;
        cout << "8.- Eliminar " << endl;
        cout << "9.- Buscar " << endl;
        cout << "10.- Resumen " << endl;
        cout << "11.- Total " << endl;
        cout << "12.- Respaldar " << endl;
        cout << "13.- Recuperar " << endl;
        cout << "0.- Salir " << endl;
        cout << "Ingresa una opcion: ";
        getline(cin, op);

        if (op == "1")
        {
            system("cls");
            cout<< "\t\t*Captura de civilizaciones*\n"<<endl;
            string Nombre;
            string X;
            int Y;
            float Puntuacion;
            Civilizacion civilizacion;

            cout << "Nombre: ";
            getline(cin, Nombre);
            civilizacion.setNombre(Nombre);

            cout << "Ubicacion en X: ";
            getline(cin, X);
            civilizacion.setX(X);

            cout << "Ubicacion en Y: ";
            cin >> Y;
            civilizacion.setY(Y);

            cout << "Puntuacion: ";
            cin >> Puntuacion;
            civilizacion.setPuntuacion(Puntuacion);

            vg.AgregarCivilizacion(civilizacion);
            Civilizacionez.push_back(civilizacion);

            cout << "\nGuardado con exito..."<<endl;
            system("pause");
        }
        else if (op == "2")
        {
            if(Civilizacionez.empty())
            {
                cout << "No hay civilizaciones."<< endl;
                system("pause");
            }
            else
            {
                for (size_t i = 0; i < Civilizacionez.size(); i++)
                {
                    Civilizacion &civilizacion = Civilizacionez[i];

                    cout << i + 1<<".- "; 
                    cout << civilizacion.getNombre() << endl;
                }
                cout << "0.- Salir "<< endl;
                cout << "Ingresa una opcion: ";
                size_t ops;
                cin >> ops; cin.ignore();

                if(ops > Civilizacionez.size())
                {
                    cout<< "Opcion Incorrecta."<< endl;
                }
                else if (ops != 0)
                {
                    Civilizacion &civilizacion = Civilizacionez[ops-1];
                    MenuC(civilizacion);

                }
                
            }
            
        }  
        else if (op == "3")
        {
            //system("cls");
            cout<< "\t\t*Insertar civilizaciones por posicion*\n"<<endl;
            Civilizacion C;

            cin >> C;
            size_t pos;
            cout << "posicion: ";
            cin >> pos; 

            if (pos >= vg.size())
            {
                cout << "posicion no valida" << endl;
            }
            else
            {
                vg.Inicializar(C, pos);
            
                cout<<"\nInsertado con exito..."<<endl;
                system("pause");
            }
    
        }
        else if(op == "4")
        {
            //system("cls");
            cout<<"\t\t*Insertar 'n' veces*\n"<<endl;
            Civilizacion C;
            cin >> C;
            
            size_t n;
            cout << "Cuantas veces lo insertas?: ";
            cin >> n; 

            vg.Inicializar(C, n);
            system("pause");
        }
        else if (op == "5")
        {
            //system("cls");
            cout <<"\t\t*Primera Civilizacion*\n"<<endl;
            vg.Primera();
            system("pause");
        }
        else if (op == "6")
        {
            system("cls");
            cout<<"\t\t*Ultima Civilizacion*\n"<<endl;
            vg.Ultima();
            system("pause");
        }
        else if (op == "7")
        {
            //system("cls");
            string opc;
            while (true)
            {
                //system("cls");
                cout<<"\t\t*Ordenar Por:*\n"<<endl;
                cout << "1.- Ordenar por Nombre" << endl;
                cout << "2.- Ordenar por Ubicaion en X" << endl;
                cout << "3.- Ordenar por Ubicaion en Y" << endl;
                cout << "4.- Ordenar por Puntuacion" << endl;
                cout << "0.- Salir al menu" << endl;
                cout << "Ingrese una opcion: ";
                getline(cin, opc);

                if(opc == "1")
                {
                    vg.OrdenarNombre();
                    cout<<"\nOrdenado con exito..."<<endl;
                    system("pause");
                }
                else if(opc == "2")
                {
                    vg.OrdenarX();
                    cout<<"\nOrdenado con exito..."<<endl;
                    system("pause");
                }
                else if(opc == "3")
                {
                    vg.OrdenarY();
                    cout<<"\nOrdenado con exito..."<<endl;
                    system("pause");
                }
                else if(opc == "4")
                {
                    vg.OrdenarPuntuacion();
                    cout<<"\nOrdenado con exito..."<<endl;
                    system("pause");
                }
                else if (opc == "0")
                {
                    break;
                }
            };
                            
        }
        else if (op == "8")
        {
            //system("cls");
            cout<<"\t\t*Eliminar por nombre*\n"<<endl;
            string Nombre;

            cout << "Nombre: ";
            getline(cin, Nombre);

            vg.Eliminar(Nombre);
            cout<< "\nEliminado con exito"<<endl;
            system("pause");
        }
        else if (op == "9")
        {
           // system("cls");
            cout<<"\t\t*Buscar Civilizacion*\n"<<endl;
            Civilizacion C;
            cin >> C; 
            
            Civilizacion *ptr = vg.Buscar(C);

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
        else if (op == "10")
        {
            //system("cls");
            cout<<"\t\t*Resumen*\n"<<endl;
            vg.Resumen();
            system("pause");
        }
                        
        else if (op == "11")
        {
            //system("cls");
            cout<<"\t\t*Total*\n"<<endl;
            vg.Total();
            system("pause");
        }  
        else if (op == "12")
        {
            vg.respaldar();
            cout<<"\nRespaldado con exito..."<<endl;
            system("pause");
        }  
        else if (op == "13")
        {
            vg.recuperar();
            cout<<"\nRecuperado con exito..."<<endl;
            system("pause");
        }  
        else if (op == "0")
        {
            cout<<"Regresando al menu..."<<endl;
            break;
            system("pause");
        }  
        
    };

    system("pause");
}

