//
//  main.cpp
//  Individual Assignment-1
//
//  Created by Avijit Roy Kabyo on 8/28/19.
//  Copyright © 2019 Avijit Roy Kabyo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ofstream outFile("output.txt");

class customer{
public:
    string first;
    string last;
    string state;
    double sHistory[3];
    double totalSales;
    int purchaseUnits;
};

// Print Function to perform array printing in Terminal
void printcust(customer data[],int numb){
    cout << setw(15) << "First";
    cout << setw(15) << "Last";
    cout << setw(15) << "State";
    cout << setw(30) << "Sales History";
    cout << setw(20) << "Total Sales";
    cout << setw(15) << "Units" << endl;
    cout << setw(75) << "1      2      3" << endl;
    cout << "     --------------------------------------------------------------------------------------------------------------\n";
    
    for(int i=0; i<numb; i++){
        cout << setw(15) << data[i].first;
        cout << setw(15) << data[i].last;
        cout << setw(15) << data[i].state;
        cout << setw(16) << data[i].sHistory[0];
        cout << setw(7) << data[i].sHistory[1];
        cout << setw(7) << data[i].sHistory[2];
        cout << setw(20) << data[i].totalSales;
        cout << setw(15) << data[i].purchaseUnits << endl;
        cout << "     --------------------------------------------------------------------------------------------------------------\n";
    }
};

//SAVE PRINTED DATA IN OUTPUT FILE
void saveFile(customer data[],int numb){
    //Print Table Head
    outFile << setw(15) << "First";
    outFile << setw(15) << "Last";
    outFile << setw(15) << "State";
    outFile << setw(30) << "Sales History";
    outFile << setw(20) << "Total Sales";
    outFile << setw(15) << "Units" << endl;
    outFile << setw(75) << "1      2      3" << endl;
    outFile << "     --------------------------------------------------------------------------------------------------------------\n";
    
    for(int i=0; i<numb; i++){
        //Print Array Data
        outFile << setw(15) << data[i].first;
        outFile << setw(15) << data[i].last;
        outFile << setw(15) << data[i].state;
        outFile << setw(16) << data[i].sHistory[0];
        outFile << setw(7) << data[i].sHistory[1];
        outFile << setw(7) << data[i].sHistory[2];
        outFile << setw(20) << data[i].totalSales;
        outFile << setw(15) << data[i].purchaseUnits << endl;
        outFile << "     --------------------------------------------------------------------------------------------------------------\n";
    }
};

//Sort by Last Name in Alphabetically Order
void sortname(customer data[],int numb){
    customer temp;
    for(int pass=0; pass < numb; pass++){
        for(int i=0; i < numb-1; i++){
            if(data[i].last > data[i+1].last){
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    }
    return;
};

//Sort by Ttotal Sales, Descendig Order
void sortsales(customer data[],int numb){
    customer temp;
    for(int pass=0; pass<numb; pass++){
        for(int i=0; i<numb-1; i++){
            if(data[i].totalSales < data[i+1].totalSales){
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    }
    return;
};

int main () {
    ifstream inFile ("data.txt");
    
    //Check if Data Input file is there and can be opened
    if(!inFile.is_open()){
        cout << "Input file could not be opened." << endl;
        return 1;
    }
    //Check if output file can be opened or not.
    if(!outFile.is_open()){
        cout << "Output file could not be opened! Terminating" << endl;
        return 1;
    }
    
    int i=0;
    customer data[10];
    
    while(inFile){
        inFile >> data[i].first;
        inFile >> data[i].last;
        inFile >> data[i].state;
        
        inFile >> data[i].sHistory[0];
        inFile >> data[i].sHistory[1];
        inFile >> data[i].sHistory[2];
        inFile >> data[i].purchaseUnits;
        
        data[i].totalSales = data[i].sHistory[0]+data[i].sHistory[1]+data[i].sHistory[2];
        if(inFile.eof())
            break;
        i++;
    }
    cout << "\n\tTotal number of customers' value imported: [" << i << "]\n";
    outFile << "\n\tTotal number of customers' value imported: [" << i << "]\n";
    
    cout << endl << setw(60) << "Populated Data from Array, Unsorted";
    outFile << endl << setw(60) << "Populated Data from Array, Unsorted";
    cout << endl << setw(60) << "___________________________________" << "\n\n";
    outFile << endl << setw(60) << "___________________________________" << "\n\n";

    printcust(data, i);
    saveFile(data, i);
    
    sortname(data, i);
    
    cout << endl << setw(60) << "Sorted by Last Name, Alphabetically";
    outFile << endl << setw(60) << "Sorted by Last Name, Alphabetically";
    cout << endl << setw(60) << "___________________________________" << "\n\n";
    outFile << endl << setw(60) << "___________________________________" << "\n\n";
    
    printcust(data, i);
    saveFile(data, i);
    
    sortsales(data, i);
    
    cout << endl << setw(60) << "Sorted by Total Sales, Descending";
    outFile << endl << setw(60) << "Sorted by Total Sales, Descending";
    cout << endl << setw(60) << "__________________________________" << "\n\n";
    outFile << endl << setw(60) << "__________________________________" << "\n\n";
    
    printcust(data, i);
    saveFile(data, i);
    
    cout << endl;
}
