#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std; 
struct User {
    string university;
    long long user_id;
    string user_name;
    int number_tweets;
    int friends_count;
    int followers_count;
    string created_at;
};

 int a = 31;
 int b = 7;
 int N = 101;

//función de hash para el ID del usuario
int FuncionhashUserID(long long user_id) {
    return (a * user_id + b) % N;
}

//función de hash para el nombre de usuario
char hashUserName(const string& user_name) {
    int hash_value = 0;
    for (char ch : user_name) {
        hash_value += static_cast<unsigned int>(ch);
    }
    return hash_value ; 
}

// Segunda función de hash para el ID del usuario
int Funcion2HashUserID(long long user_id) {
    return 1 + (user_id % 97);
}

// Segunda función de hash para el nombre de usuario
char Funcion2HashUserName(const string& user_name) {
    int hash = 0;
    for (char c : user_name) {
        hash = hash * 31 + c;
    }
    return 1 + (hash % 97);
}

#endif 




