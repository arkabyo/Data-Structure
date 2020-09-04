//
//  main.cpp
//  Assignment-1
//
//  Created by Avijit Roy Kabyo on 9/3/20.
//  Copyright © 2020 Avijit Roy Kabyo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

#include "header.h"

using namespace std;

int main() {
    //==== Variables for Time ====//
    clock_t start, end, beginM;
//    clock_t endM, loopStart, loopEnd, randStart, randStop; //for test

    beginM = clock(); //track total program time start

    //  Initializing Output File
    ofstream printFile;

    //  Opening Output File
    printFile.open ("100.csv");

    //  Printing Column Heads
    printFile << "Array Size,Insertion Sort Time,Merge Sort Time,\n";

    //==== random Reset ====//
    srand(int(time(0))); //to generate random at all time

    //initializing arrays to NULL;
    int* arr = NULL;
    int* insertionArray = NULL;
    int* mergeArray = NULL;
    int sizeOfArray;;

    //Loop
    for (int i=0; i<=100; i=i+1)
    {
//        loopStart = clock();
        sizeOfArray = i;
        cout << "Length of Array " << sizeOfArray << endl;
        arr = new int[sizeOfArray];
        insertionArray = new int[sizeOfArray];
        mergeArray = new int[sizeOfArray];

        //==== Random Number Generating ====//
        for (int count = 0; count < sizeOfArray; count++)
        {
            arr[count] = (rand() % (2000000-1))+1; //generating random numbers from 1 - 2000000
            insertionArray[count] = mergeArray[count] = arr[count];
        }

        //Calculating total time taken for each loop

        //  InsertionSort
        start = clock();        //save time to start variable
        insertionSort(insertionArray, sizeOfArray);
        end = clock();          //save time to end variable
        //  saving time duration in time_taken variable
        double insertionTime = float(end - start)/CLOCKS_PER_SEC;

        //  MergeSort
        start = clock();        //save time to start variable
        mergeSort(mergeArray, 0, sizeOfArray-1);
        end = clock();          //save time to end variable
        //  saving time duration in time_taken variable
        double mergeTime = float(end - start)/CLOCKS_PER_SEC;

        //  Printing the time data to the CSV file
        printFile << fixed << setprecision(9) << sizeOfArray << "," << insertionTime << "," << mergeTime  << ","  << endl;

        //  Delete arrays
        delete [] arr;
        delete [] insertionArray;
        delete [] mergeArray;
    }
    return 0;
}
