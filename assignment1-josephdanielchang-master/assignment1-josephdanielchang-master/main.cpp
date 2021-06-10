//
//  main.cpp
//  cards
//
//  Created by rick gessner on 9/21/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include <iostream>
#include <fstream>  // stream class to read and write from/to files.
#include <string>
#include <cstring>
#include <cstdlib> // rand
#include <ctime>   // time
#include <fcntl.h>

#define SPADE	"\u2660"
#define CLUB    "\u2663"
#define HEART   "\u2665"
#define DIAMOND "\u2666"

using namespace std;

const char* getPath() {
  const char *thePath= "../cards.json"; // You can modify this path, but be sure to change it back for testing
  return thePath;
}

void shuffle(int deck[], int len) {
    int temp = 0;
    int randomIndex = 0;

    for (int i=0; i<len; i++) {     // swap every index with random index
        randomIndex = rand() % len;
        temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

string numToSuit(int num) {
    string suit;

    if (num >= 0 && num <= 13)
        suit = "diamond";
    else if (num >= 14 && num <= 26)
        suit = "heart";
    else if (num >= 27 && num <= 39)
        suit = "spade";
    else if (num >= 40 && num <= 52)
        suit = "club";
    else
        suit = "Could not find matching suit";
    return suit;
}

string numToFace(int num) {
    string face;
    int remainder = num % 13;

    switch (remainder) {
        case 0: // code to be executed if n = 1;
            face = "A";
            break;
        case 1: // code to be executed if n = 2;
            face = "2";
            break;
        case 2:
            face = "3";
            break;
        case 3:
            face = "4";
            break;
        case 4:
            face = "5";
            break;
        case 5:
            face = "6";
            break;
        case 6:
            face = "7";
            break;
        case 7:
            face = "8";
            break;
        case 8:
            face = "9";
            break;
        case 9:
            face = "10";
            break;
        case 10:
            face = "J";
            break;
        case 11:
            face = "Q";
            break;
        case 12:
            face = "K";
            break;
        default:
            face = "Could not find matching face";
    }
    return face;
}

void sortPrintCards(string face[], string suit[]) {
    // Sort and print cards in the order: diamond, heart, spade, club
    for (int i=0;i<52;i++) {
        if (suit[i] == "diamond") {
            cout << "┌─────┐" << endl;
            cout << "|" << face[i] << "    |" << endl;
            cout << "|  " << DIAMOND << "  |" << endl;
            cout << "|    " << face[i] << "|" << endl;
            cout << "└─────┘" << endl;
        }
    }

    for (int i=0;i<52;i++) {
        if (suit[i] == "heart") {
            cout << "┌─────┐" << endl;
            cout << "|" << face[i] << "    |" << endl;
            cout << "|  " << HEART << "  |" << endl;
            cout << "|    " << face[i] << "|" << endl;
            cout << "└─────┘" << endl;
        }
    }
    for (int i=0;i<52;i++) {
        if (suit[i] == "spade") {
            cout << "┌─────┐" << endl;
            cout << "|" << face[i] << "    |" << endl;
            cout << "|  " << SPADE << "  |" << endl;
            cout << "|    " << face[i] << "|" << endl;
            cout << "└─────┘" << endl;
        }
    }
    for (int i=0;i<52;i++) {
        if (suit[i] == "club") {
            cout << "┌─────┐" << endl;
            cout << "|" << face[i] << "    |" << endl;
            cout << "|  " << CLUB << "  |" << endl;
            cout << "|    " << face[i] << "|" << endl;
            cout << "└─────┘" << endl;
        }
    }
}
void createCardFile(const char *aPath) {
    int deck[52];
    string suit;
    string face;

    // Initialize deck in order
    for  (int i=0; i<52; i++) {
        deck[i] = i + 1;
    }

    // Shuffle deck order
    shuffle(deck, 52);

    // Open JSON file
    ofstream file(aPath);
    if (file.is_open())
    {
        // Fill out JSON file with cards
        file << "[\n";
        for (int i=0; i<52; i++) {
            suit = numToSuit(deck[i]);
            face = numToFace(deck[i]);
            if (i<51)
                file << "\t{ \"face\" : \"" << face << R"(", "suit" : ")" << suit << "\"},\n"; // quotes written as raw string literals
            else
                file << "\t{ \"face\" : \"" << face << R"(", "suit" : ")" << suit << "\"}\n"; // no comma at final line
        }
        file << "]\n";
        file.close();
    }
    else cout << "Unable to open file to write" << endl;
}

void readJSONCards(const char *aPath) {
    string input;
    string suit[52];
    string face[52];
    int counter1 = 0;    // increments between 0-7
    int counter2 = 0;

    // Open JSON file
    ifstream file(aPath);
    if (file.is_open()) {
        // Read JSON file
        for (int i = 0; i < 417; i++) { // 417 quotation delimited sections

            getline(file, input, '\"');

            // Get faces - delimited indices: 3, 11, 19, ... - ignore 0 and 6
            if (counter1 % 3 == 0 && counter1 != 0 && counter1 != 6) {
                face[counter2] = input;
            }
            // Get suits - delimited indices: 7, 15, 23, ... - ignore 0
            if (counter1 % 7 == 0 && counter1 != 0) {
                suit[counter2] = input;
            }
            // Reset counter from 7 to 0 - ignore 0
            if (counter1 % 7 == 0 && counter1 != 0) {
                counter1 = 0;
                counter2++;
            }
            else
                counter1++;
        }
        file.close();

        // Sort cards by suit and print
        sortPrintCards(face, suit);
    }
    else cout << "Unable to open file to read" << endl;
}

int main(int argc, const char * argv[]) {

    createCardFile(getPath());  // Generate cards.json file
    readJSONCards(getPath());   // Read cards.json, display cards on command line ordered by suit
    return 0;
}


