#include "todohash.h"
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <random>
#include <sstream>


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

        auto start = chrono::high_resolution_clock::now();
        hashOpenID.insert(usuario.user_id, usuario);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Tiempo en hashOpenID: " << duration.count() << "segundos" << endl;

        start = chrono::high_resolution_clock::now();
        hashOpenName.insert(usuario.user_name, usuario);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo en hashOpenName: " << duration.count() << "segundos" << endl;

        start = chrono::high_resolution_clock::now();
        linealProbing.insert(usuario.user_id, usuario);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo en linealProbing: " << duration.count() << "segundos" << endl;

        start = chrono::high_resolution_clock::now();
        quadraticProbing.insert(usuario.user_id, usuario);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo en quadraticProbing: " << duration.count() << "segundos" << endl;

        start = chrono::high_resolution_clock::now();
        doubleHashing.insert(usuario.user_id, usuario);
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Tiempo en doubleHashing: " << duration.count() << "segundos" << endl;
    }

    file.close();


    return 0;
}
