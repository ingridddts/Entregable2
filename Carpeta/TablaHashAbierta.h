#include <iostream>
#include <string>

using namespace std;
 struct Usuario {
        string university;
        string user_name;
        int number_tweets;
        int friends_count;
        int followers_count;
        string created_at;
    };

    struct Node {
        long long user_id;
        string user_name;
        Usuario dato;
        Node* next;
    };
    


// clase para el id
class UserIDTablaHashOpen {
private:

    Node** tabla;
    size_t size_= 21089;

public:
    UserIDTablaHashOpen(size_t size) : size_(size) {
        tabla = new Node*[size_];
        for (size_t i = 0; i < size_; i++) {
            tabla[i] = nullptr;
        }
    }

    ~UserIDTablaHashOpen() {
        for (size_t i = 0; i < size_; i++) {
            Node* actual = tabla[i];
            while (actual!= nullptr) {
                Node* next = actual->next;
                delete actual;
                actual = next;
            }
        }
        delete[] tabla;
    }

    void insert(long long user_id, const Usuario& dato) {
        size_t i = fhashID(user_id);
        Node* actual = tabla[i];
        while (actual!= nullptr) {
            if (actual->user_id == user_id) {
                // Actualizar datos si la clave ya existe
                actual->dato = dato;
                return;
            }
            actual = actual->next;
        }
        // Insertar nuevo nodo al principio de la lista
        Node* newNode = new Node;
        newNode->user_id = user_id;
        newNode->dato = dato;
        newNode->next = tabla[i];
        tabla[i] = newNode;
    }

    Usuario* find(long long user_id) {
        size_t i = fhashID(user_id);
        Node* actual = tabla[i];
        while (actual!= nullptr) {
            if (actual->user_id == user_id) {
                return &actual->dato;
            }
            actual = actual->next;
        }
        return nullptr;
    }

private:
    size_t fhashID(long long user_id) {
        return user_id % size_;
    }
};
// clase para el nombre
class UserNameTablaHashOpen {
private:

    Node** tabla;
    size_t size_= 21089;

public:
    UserNameTablaHashOpen(size_t size) : size_(size) {
        tabla = new Node*[size_];
        for (size_t i = 0; i < size_; i++) {
            tabla[i] = nullptr;
        }
    }

    ~UserNameTablaHashOpen() {
        for (size_t i = 0; i < size_; i++) {
            Node* actual = tabla[i];
            while (actual != nullptr) {
                Node* next = actual->next;
                delete actual;
                actual = next;
            }
        }
        delete[] tabla;
    }

    void insert(const string& user_name, const Usuario& dato) {
        size_t i = fhashNAME(user_name);
        Node* actual = tabla[i];
        while (actual != nullptr) {
            if (actual->user_name == user_name) {
                // Actualizar datos si la clave ya existe
                actual->dato = dato;
                return;
            }
            actual = actual->next;
        }
        // Insertar nuevo nodo al principio de la lista
        Node* newNode = new Node;
        newNode->user_name = user_name;
        newNode->dato = dato;
        newNode->next = tabla[i];
        tabla[i] = newNode;
    }

    Usuario* find(const string& user_name) {
        size_t i = fhashNAME(user_name);
        Node* actual = tabla[i];
        while (actual != nullptr) {
            if (actual->user_name == user_name) {
                return &actual->dato;
            }
            actual = actual->next;
        }
        return nullptr;
    }

private:
    size_t fhashNAME(const string& user_name) {
        size_t fhashNAME = 0;
        for (char c : user_name) {
            fhashNAME = (fhashNAME << 5) + c;
        }
        return fhashNAME % size_;
    }
};
