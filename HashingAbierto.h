#ifndef HASHINGABIERTO_H
#define HASHINGABIERTO_H

#include "funcioneshash.h" // .h con las funciones hash
#include <vector>
#include <list>
using namespace std;

class HashingAbierto {
private:
    struct Usuarios {
        list<User> users; // struct para la lista de usuarios
    };
    vector<Usuarios> table; 
    int capacidad; //capacidad de la tabla hash
    
public:
    // resize a la tabla
    HashingAbierto(int size) : capacidad(size) {
        table.resize(capacidad);
    }

    //funcion para insertar
    void insert(const User& user) {
        int hash = FuncionhashUserID(user.user_id) % capacidad;
        table[hash].users.push_back(user);
    }

    //funcion para buscarr
    User* find(long long user_id) {
        //usa modulo de capacidad para asegurarse de que  el indice sirva
        int hash = FuncionhashUserID(user_id) % capacidad;
        //recorre la lista de usuarios en el índice hash buscando el usuario con el ID dado
        for (auto& user : table[hash].users) {
            //devuelve un puntero a ese usuario
            if (user.user_id == user_id) {
                return &user;
            }
        }
        //si no se encuentra el usuario devuelve nullptr
        return nullptr;
    }
};

#endif