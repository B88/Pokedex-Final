#ifndef __CS_252_Project__Badges__
#define __CS_252_Project__Badges__
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Items{    //Items class declaration
private:
    struct Slot{
        string name;        //Holds the name of the item
        int number;         //Holds the quantity of the item
    };

    Slot bag[10];
    int size;

public:
    Items();                //Constructor
    void addItem(string);   //Function to add each item
    void displayAll();      //Function to display all the items
    void sort();            //Function which sorts the items alphabetically
};

Items::Items(){
    size = 0;
};

//Add items to the bag
void Items::addItem(string thing){
    int spot = -1;
    for(int i = 0; i < size; i++) { if(bag[i].name == thing) { spot = i; } }
    if(spot > -1) { bag[spot].number++; }
    else if(size < 10){
        bag[size].name = thing;
        bag[size].number = 1;
        size++;
    } else { cout << "Bag is full\n"; }
}

//Display the items
void Items::displayAll(){
    cout << "\n\t\tItems:" << endl;
    for(int i = 0; i < size; i++) { cout << bag[i].name << "\n          x " << bag[i].number << endl; }
    cout << "\nPress enter to return to the menu.\n";
    cin.ignore();
}

//Bubble sort items alphabetically by name
void Items::sort(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(bag[j].name > bag[j+1].name){
                Slot temp  = bag[j + 1];
                bag[j + 1] = bag[j];
                bag[j]     = temp;
            }
        }
    }
}

void items()
{
    Items one;                          //Define an instance of Items
    
    one.addItem("Repel");               //Add items
    one.addItem("Super Potion");
    one.addItem("Rare Candy");
    one.addItem("Escape Rope");
    one.addItem("Moon Stone");
    one.addItem("Antidote");
    for(int i = 0; i < 3; i++) { one.addItem("Revive"); }           //Increase quantity of certain items
    for(int i = 0; i < 10; i++) { one.addItem("Poke Ball"); }
    for(int i = 0; i < 7; i++) { one.addItem("Potion"); }
    for(int i = 0; i < 5; i++) { one.addItem("Great Ball"); }

    one.sort();
    one.displayAll();
}
#endif
