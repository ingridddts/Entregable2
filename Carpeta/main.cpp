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
    UserIDTablaHashOpen userIdTable(21089);
    UserNameTablaHashOpen userNameTable(21089);
    LinealProbing linealProbing(21089);
    QuadraticProbing quadraticProbing(21089);
    DoubleHashing doubleHashing(21089);

    std::ifstream file("universities_followers.csv");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        long long user_id;
        std::string user_name, university;
        int number_tweets, friends_count, followers_count;
        std::string created_at;

        iss >> user_id;
        iss >> user_name;
        iss >> university;
        iss >> number_tweets;
        iss >> friends_count;
        iss >> followers_count;
        iss >> created_at;

        Usuario usuario = {user_id, user_name, university, number_tweets, friends_count, followers_count, created_at};

        userIdTable.insert(user_id, usuario);
        userNameTable.insert(user_name, usuario);
        linealProbing.insert(user_id, usuario);
        linealProbing.insert(user_name, usuario);
        quadraticProbing.insert(user_id, usuario);
        quadraticProbing.insert(user_name, usuario);
        doubleHashing.insert(user_id, usuario);
        doubleHashing.insert(user_name, usuario);
    }

    file.close();
    Usuario* usuario = userIdTable.find(12345);
    if (usuario) {
        std::cout << "User ID 12345: " << usuario->user_name << std::endl;
    } else {
        std::cout << "User ID 12345 not found" << std::endl;
    }

    usuario = userNameTable.find("john_doe");
    if (usuario) {
        std::cout << "User Name john_doe: " << usuario->user_id << std::endl;
    } else {
        std::cout << "User Name john_doe not found" << std::endl;
    }












    return 0;
}