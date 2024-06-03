#include "todohash.h"
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include <cmath>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

 int main(){
    unordered_map<long long, Usuario> um_userID;
    unordered_map<string, Usuario> um_userName;
    UserIDTablaHashOpen hashOpenID(21089);
    UserNameTablaHashOpen hashOpenName(21089);
    LinealProbing linealProbing(21089);
    QuadraticProbing quadraticProbing(21089);
    DoubleHashing doubleHashing(21089);
    

    ifstream file("universities_followers.csv");
    if (!file.is_open()) {
        cerr << "no se pudo abrir" << endl;
        return 1;
    }

    string line, word;
    getline(file, line);  

    vector<Usuario> usuarios;
    while (getline(file, line)) {
        stringstream s(line);
        Usuario usuario;

        getline(s, usuario.university, ',');
        getline(s, word, ',');
        usuario.user_id = stoll(word);
        getline(s, usuario.user_name, ',');
        getline(s, word, ',');
        usuario.number_tweets = stoi(word);
        getline(s, word, ',');
        usuario.friends_count = stoi(word);
        getline(s, word, ',');
        usuario.followers_count = stoi(word);
        getline(s, usuario.created_at, ',');

        usuarios.push_back(usuario);
    }
    file.close();

    vector<long long> inserciones = {1000, 5000, 10000, 15000, 20000};
    for (long long inserciones_size : inserciones) {
        auto start = chrono::high_resolution_clock::now();
        for (long long i = 0; i < inserciones_size && i < usuarios.size(); ++i) {
            hashOpenID.insert(usuarios[i].user_id, usuarios[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Tiempo para insertar " << inserciones_size << " usuarios en hashOpenID: " << duration.count() << " segundos" << endl;

        start = chrono::high_resolution_clock::now();
        for (long long i = 0; i < inserciones_size && i < usuarios.size(); ++i) {
            hashOpenName.insert(usuarios[i].user_name, usuarios[i]);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo para insertar " << inserciones_size << " usuarios en hashOpenName: " << duration.count() << " segundos" << endl;

        start = chrono::high_resolution_clock::now();
        for (long long i = 0; i < inserciones_size && i < usuarios.size(); ++i) {
            linealProbing.insert(usuarios[i].user_id, usuarios[i]);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo para insertar " << inserciones_size << " usuarios en linealProbing: " << duration.count() << " segundos" << endl;

        start = chrono::high_resolution_clock::now();
        for (long long i = 0; i < inserciones_size && i < usuarios.size(); ++i) {
            quadraticProbing.insert(usuarios[i].user_id, usuarios[i]);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo para insertar " << inserciones_size << " usuarios en quadraticProbing: " << duration.count() << " segundos" << endl;

        start = chrono::high_resolution_clock::now();
        for (long long i = 0; i < inserciones_size && i < usuarios.size(); ++i) {
            doubleHashing.insert(usuarios[i].user_id, usuarios[i]);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo para insertar " << inserciones_size << " usuarios en doubleHashing: " << duration.count() << " segundos" << endl;
        
    }
    
    //Busquedas
	int N = 21089;

  	// Random number generator
  	random_device rd; //Número aleatorio verdadero
  	mt19937 gen(rd()); //Número aleatorio pseudoaleatorio	con distribución uniforme llamado con número aleatorio verdadero
  	uniform_int_distribution<> dis(1, N*2); //Distribución uniforme de 1 a N*2

	// Search linealProbing
	//para guardar en aarchivo se usa ofstream
	ofstream archivo("linear_search.csv", ios::app);
	for (int i = 10; i <= 15; i++) {
    	for (int j = pow(2, i); j < pow(2, i+1); j++) {
        	auto start = chrono::high_resolution_clock::now();
        	linealProbing.search(j);
        	auto end = chrono::high_resolution_clock::now();
        	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        	archivo << j << ", " << duration << "\n";
    	}
	}
	archivo.close();
	std::cout << "Busqueda Lineal" << std::endl;

	// Search quadraticProbing
	archivo.open("quadratic_search.csv");
	for (int i = 10; i <= 15; i++) {
    	for (int j = pow(2, i); j < pow(2, i+1); j++) {
        	auto start = chrono::high_resolution_clock::now();
        	quadraticProbing.search(j);
        	auto end = chrono::high_resolution_clock::now();
        	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        	archivo << j << ", " << duration << "\n";
    	}
	}
	archivo.close();
	std::cout << "quadratic busqueda listo" << std::endl;

	// Search doubleHashing
	archivo.open("double_search.csv");
	for (int i = 10; i <= 15; i++) {
    	for (int j = pow(2, i); j < pow(2, i+1); j++) {
        	auto start = chrono::high_resolution_clock::now();
        	doubleHashing.search(j);
        	auto end = chrono::high_resolution_clock::now();
        	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        	archivo << j << ", " << duration << "\n";
    	}
	}
	archivo.close();
	std::cout << "double busqueda listo" << std::endl;

	// Search in um
/*
file.open("unordered_map_search.csv");
for (int i = 10; i <= 15; i++) {
    for (int j = pow(2, i); j < pow(2, i+1); j++) {
        auto start = chrono::high_resolution_clock::now();
        um.find(j);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        file << j << ", " << duration << "\n";
    }
}
file.close();

std::cout << "unordered_map busqueda listo" << std::endl;
*/

    

    return 0;
}
