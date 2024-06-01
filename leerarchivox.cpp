#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//declaracion de metodos
void insertar();
void listado_general();
void menu();

//implementacion metodos
void insertar(){
    ofstream archivo("pruebas1.csv", ios::app);
    if(!archivo){
        cout << "ERROR" << endl;
    }
    else {
        string university; //uni a la que sigue el usuario - string
        long long user_ID; //num identificador usuario - num
        string user_name; //nom usuario - dtring
        int numbertweets; // num tweets - num
        int friendsCount; //num de cuentas que sigue el usuario - num
        int followersCount; //num de seguidores - num
        string createdAt; // fecha creacion cuenta - fechs

        cout << "Universidad: "; 
        cin >> university;
        //getline(cin, university);
        cout << "UserId:";
        cin >> user_ID;
        //getline(cin, user_ID);
        cout << "Nombre usuario: ";
        //getline(cin, user_name);
        cin >> user_name;
        cout << "Nro tweets: ";
        cin >> numbertweets;
        cout << "Seguidos: ";
        cin >> friendsCount;
        cout << "Seguidores: ";
        cin >> followersCount;
        /*
        cout << "Fecha ingreso: ";
        //getline(cin, createdAt);
        cin >> createdAt;
        */

		//se guarda en el archivo variable separada por una coma
        archivo << university << ',' << user_ID << "," << user_name << "," << numbertweets << "," << friendsCount << "," << followersCount << "," << createdAt << endl;

        archivo.close();
        cout << "Se insertó correctamente" << endl << endl;
    }
}

//se lee el archivo y se imprime por pantalla
void listado_general(){
    //ifstream archivo("pruebas.csv", ios :: in);
    ifstream archivo("pruebas1.csv", ios :: in);
    if(!archivo){
        cout << "ERROR" << endl;
    }
    else{
        string registro;
        string university, user_ID, user_name, numbertweets, friendsCount, createdAt ;

        cout<< "university" << " " <<  "user_ID" << " " << "user_name" << " " << "numbertweets" << " " <<  "friendsCount" << " " <<  "createdAt" << endl;
        while(getline(archivo, registro)){
            //cout<< registro << endl;
            stringstream token(registro);
            getline(token, university, ',');
            getline(token, user_ID , ',');
            getline(token, user_name, ',');
            getline(token, numbertweets, ','); 
			getline(token, friendsCount, ','); 
			getline(token, createdAt, ','); 

            //imprimir
            cout<< university << " " <<  user_ID << " " << user_name << " " << numbertweets << " " <<  friendsCount << " " <<  createdAt << endl;
        }
        archivo.close();
    }
}

void menu(){
    int opc;
    do{
        cout << "Menú" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Listado general" << endl;
        cout << "0. Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1: insertar() ; break;
            case 2: listado_general() ; break;
            case 0: break;
            default : cout << "opcion incorrecta"<< endl;
        } 
    } while (opc != 0);
}

int main(){
    menu();
    return 0;
}
