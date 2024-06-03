//leer datos del archivo .csv e insertar en archivo de salida
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//declaracion de metodos
void insertar();
void listado_general();
void menu();

struct User {
    string university;
    string userName;
    string UserID;
    string numberTweets;
    string friendsCount;
    string followersCount;
    string createdAt;
};

//implementacion metodos
void insertar(){
	//modo ofstream para guardar en archivo
	//se leen los registros de archivo universities_followers.csv y se guardan en pruebas2.csv
	//ios:: app indica que esta en modo añadir
    ofstream archivo("pruebas2.csv", ios::app);
    ifstream archivolectura("pruebas1.csv", ios :: in);
    if(!archivo && !archivolectura){
        cout << "ERROR" << endl;
    }
    else {
        string registro;
        vector<User> usuario;
        string field;
        //ifstream archivo("pruebas1.csv");
        //leer archivo 
        
        string university, userID, user_name, numbertweets, friendsCount, followersCount, createdAt ;
        while(getline(archivolectura, registro)){
            //cout<< registro << endl;
            //lee una linea del archivo y lo guarda en una variable
            stringstream token(registro);
            User persona;
            getline(token, field, ',');
            persona.university = university;
            getline(token, field , ',');
            persona.UserID = userID;
            getline(token, field, ',');
            persona.userName = user_name;
            getline(token, field, ','); 
            //persona.numberTweets = stoi(numbertweets);
            persona.numberTweets = numbertweets;
			getline(token, field, ',');
			//persona.friendsCount = stoi(friendsCount);
			persona.friendsCount = friendsCount;
			getline(token, field, ','); 
			persona.followersCount = followersCount;
			getline(token, field, ','); 
			persona.createdAt = createdAt;
			usuario.push_back(persona);

        	//se guarda en el archivo variable separada por una coma
        	archivo << university << ',' << userID << "," << user_name << "," << numbertweets << "," << friendsCount << "," << followersCount << "," << createdAt << endl;
		}
        archivo.close();
        cout << "Se insertÃ³ correctamente" << endl << endl;
    
	}
}

//se lee el archivo y se imprime por pantalla
void listado_general(){
    //ifstream archivo("pruebas.csv", ios :: in);
    //aca se abre el archivo con los usuarios de twitter
    ifstream archivo("pruebas1.csv", ios :: in);
    if(!archivo){
        cout << "ERROR" << endl;
    }
    else{
        string registro;
        string university, user_ID, user_name, numbertweets, friendsCount, createdAt ;
		
		//orden variables mostradas
        cout<< "university" << " " <<  "user_ID" << " " << "user_name" << " " << "numbertweets" << " " <<  "friendsCount" << " " <<  "createdAt" << endl;
        //ciclo para leer cada linea del archivo entregado
        while(getline(archivo, registro)){
            //cout<< registro << endl;
            //lee una linea del archivo y lo guarda en una variable
            stringstream token(registro);
            getline(token, university, ',');
            getline(token, user_ID , ',');
            getline(token, user_name, ',');
            getline(token, numbertweets, ','); 
			getline(token, friendsCount, ','); 
			getline(token, createdAt, ','); 

            //imprimir datos
            cout<< university << " " <<  user_ID << " " << user_name << " " << numbertweets << " " <<  friendsCount << " " <<  createdAt << endl;
        }
        archivo.close();
    }
}

void menu(){
    int opc;
    do{
        cout << "Menu" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Listado general" << endl;
        cout << "3. Buscar" << endl;
        cout << "0. Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1: insertar() ; break;
            case 2: listado_general() ; break;
            //case 3: searh() ; break;
            case 0: break;
            default : cout << "opcion incorrecta"<< endl;
        } 
    } while (opc != 0);
}

int main(){
    menu();
    return 0;
}
