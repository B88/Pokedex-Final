#include <string>
using namespace std;

class Hash{             //Header for hash class
private:
    struct Pokes{       //Hashes pokemon
        int number;
        string name, type1, type2;
        Pokes *next;
    };

    Pokes* hashTable[18][18];   //Pokemon locations are stored in a hashTable

public:
    Hash();                     //Function names
    int hashFunc(string key);
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2);
    void get(string);
    void display(Pokes*);
};
