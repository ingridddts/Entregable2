// Clase para la tabla hash con hashing cerrado usando Linear Probing
class LinearProbingHashTable {
private:
    static const int hashGroups = 10007; // Tama�o de la tabla hash
    UserData table[hashGroups]; // Tabla hash representada como un arreglo de UserData
    bool filled[hashGroups]; // Bandera para indicar si una posici�n est� ocupada o no

    // Funci�n hash para User ID
    int hashFunction(int key) {
        return key % hashGroups;
    }

    // Funci�n hash para User Name
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % hashGroups;
        }
        return hash;
    }

public:
    // Constructor para inicializar las banderas filled
    LinearProbingHashTable() {
        for (int i = 0; i < hashGroups; ++i) {
            filled[i] = false;
        }
    }

    // M�todo para insertar un usuario en la tabla hash usando Linear Probing
    void insert(int userID, const UserData& data) {
        int hashValue = hashFunction(userID);
        while (filled[hashValue]) {
            hashValue = (hashValue + 1) % hashGroups; // Linear Probing
        }
        table[hashValue] = data;
        filled[hashValue] = true;
    }

    // M�todo para buscar un usuario por User ID
    UserData getUserByID(int userID) {
        int hashValue = hashFunction(userID);
        int initialHash = hashValue;
        while (filled[hashValue]) {
            if (table[hashValue].userID == userID) {
                return table[hashValue];
            }
            hashValue = (hashValue + 1) % hashGroups; // Linear Probing
            if (hashValue == initialHash) {
                break;
            }
        }
        throw runtime_error("User ID not found");
    }

    // M�todo para buscar un usuario por User Name
    UserData getUserByName(const string& userName) {
        int hashValue = hashFunction(userName);
        int initialHash = hashValue;
        while (filled[hashValue]) {
            if (table[hashValue].userName == userName) {
                return table[hashValue];
            }
            hashValue = (hashValue + 1) % hashGroups; // Linear Probing
            if (hashValue == initialHash) {
                break;
            }
        }
        throw runtime_error("User Name not found");
    }
};

