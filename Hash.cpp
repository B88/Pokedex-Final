#include "Hash.h"
#include <iostream>
#include <string>
#include "PokeList.h"

Hash::Hash(){                       //Constructor initializes all the
    for(int i = 0; i< 18; i++){     //pointers in the hash table to null
        for(int j = 0; j < 18; j++){
            hashTable[i][j] = nullptr;
        }
    }
}

int Hash::hashFunc(string key){     //The hashFunc function returns an
    int index;                      //index of the hash table where
    if(key == "Grass" || key == "grass")    //pokemon of a particular
        index = 1;                  //type are stored
    else if(key == "Poison" || key == "poison")
        index = 2;
    else if(key == "Fire" || key == "fire")
        index = 3;
    else if(key == "Electric" || key == "electric")
        index = 4;
    else if(key == "Rock" || key == "rock")
        index = 5;
    else if(key == "Ghost" || key == "ghost")
        index = 6;
    else if(key == "Ice" || key == "ice")
        index = 7;
    else if(key == "Flying" || key == "flying")
        index = 8;
    else if(key == "Steel" || key == "steel")
        index = 9;
    else if(key == "Fighting" || key == "fighting")
        index = 10;
    else if(key == "Normal" || key == "normal")
        index = 11;
    else if(key == "Ground" || key == "ground")
        index = 12;
    else if(key == "Dragon" || key == "dragon")
        index = 13;
    else if(key == "Bug" || key == "bug")
        index = 14;
    else if(key == "Fairy" || key == "fairy")
        index = 15;
    else if(key == "Psychic" || key == "psychic")
        index = 16;
    else if(key == "Water" || key == "water")
        index = 17;
    else
        index = 0;

    return index;
}

void Hash::addPokes(int num, string pokeName, string pokeType1, string pokeType2){

    int indexI = hashFunc(pokeType1);   //Pokemon are added to the hash table based
    int indexJ = hashFunc(pokeType2);   //on their types (indexes).

    if(hashTable[indexI][indexJ] == nullptr){   //Either the index to be used has no
        hashTable[indexI][indexJ] = new Pokes;  //pokemon stored in it's chain, and
        hashTable[indexI][indexJ]->number = num;//has to create a chain.
        hashTable[indexI][indexJ]->next = nullptr;
        hashTable[indexI][indexJ]->name = pokeName;
        hashTable[indexI][indexJ]->type1 = pokeType1;
        hashTable[indexI][indexJ]->type2 = pokeType2;
    } else {
        Pokes* p = hashTable[indexI][indexJ];   //Or the chain that exists is
        while(p->next) { p = p->next; }         //traversed and the new pokemon is
                                                //added to the end.
        Pokes* t = new Pokes;
        t->number = num;
        t->next = nullptr;
        t->name = pokeName;
        t->type1 = pokeType1;
        t->type2 = pokeType2;

        p->next = t;
    }
}

void Hash::get(string type){
    for(int i = 0; i < 18; i++){                //get function finds each chain for a
        Pokes* p = hashTable[hashFunc(type)][i];//user specified type and displays each
        while(!(p == nullptr)){                 //pokemon in each chain in that type's
            display(p);                         //row.
            p = p->next;
        }
    }

    for(int i = 0; i < 18; i++){                //it then displays each chain for the user's
        Pokes* p = hashTable[i][hashFunc(type)];//specified type in that type's column.
        while(!(p == nullptr)){
            display(p);
            p = p->next;
        }
    }
}

void Hash::display(Pokes* pokePtr){                     //display function for showing the data
    cout << "Number:     Name:          Type(s):\n";    //for a pokemon node
    cout << setw(7) << right << pokePtr -> number << "     " << setw(10) << left << pokePtr -> name;
    cout << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl << endl;
}
