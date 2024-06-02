#include <unordered_map>

// Uso de unordered_map de la STL de C++
unordered_map<int, UserData> userIDMap;
unordered_map<string, UserData> userNameMap;

// Insertar usuarios en los unordered_map
userIDMap[userID] = userData;
userNameMap[userName] = userData;

// Obtener usuarios por User ID y User Name
UserData userDataByID = userIDMap[userID];
UserData userDataByName = userNameMap[userName];
