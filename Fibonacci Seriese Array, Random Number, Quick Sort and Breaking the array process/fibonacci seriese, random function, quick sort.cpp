//
//  main.cpp
//  Group Assignment - 1
//
//  Created by Avijit Roy Kabyo on 9/2/19.
//  Copyright © 2019 Avijit Roy Kabyo. All rights reserved.
//
//
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream outFile("output.txt");

// Function for Fibonacci series
int fib(int n) {
    if (n <= 0) //handling negative input or 0
    {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2); //fibonacci sequece equation
    }
}

//Print function
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << "\t";
        outFile << arr[i] << "\t";
    }
    cout << endl;
    outFile << endl;
}

//Quick Sort Starts
//Swap
void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}

//Select last element as Pivot and partitioning the array
int partition(int arr[], int start, int end) {
    int pivot = arr[end]; // selecting pivot
    int i = (start - 1); // Finding the index of the smaller element
    
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) // checks if the current selection is smaller than pivot
        {
            i++;
            swap( & arr[i], & arr[j]);
        }
    }
    swap( & arr[i + 1], & arr[end]);
    return (i + 1);
}

//Sort low to high
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1); // before partition
        quickSort(arr, pi + 1, end); // after partition
    }
}
//end quicksort

// Main function starts
int main() {
    //Fibonacci
    //Taking user input for Fibonacci Seriese
    int length;
    cout << "Enter a positive number to display the Fibonacci series till that point: ";
    cin >> length;
    
    //Input Validation
    if (cin.fail()) {
        outFile << "\nENTRY IS NOT AN INTEGER. Please enter a positive integer.\n\n";
        cout << "\nENTRY IS NOT AN INTEGER. Please enter a positive integer.\n\n";
    } else if (length > 0) {
        cout << "\nThe first " << length << " number(s)1 in Fibonacci series are : \n";
        outFile << "\nThe first " << length << " number(s)1 in Fibonacci series are : \n";
        
        //loop to pring Fibonacci seriese according to user Length input
        for (int i = 0; i < length; i++) {
            cout << fib(i) << "\t";
            outFile << fib(i) << "\t";
        }
        cout << "\n\n";
        outFile << "\n\n";
    } else if (length == 0) //handling input ZERO
    {
        cout << "\nYou have entered ZERO\n\n";
        outFile << "\nYou have entered ZERO\n\n";
    } else //handling Negative number input
    {
        cout << "\nYou entered a negative number. \n";
        outFile << "\nYou entered a negative number. \n";
    }
    
    //Generate 10 Random Numbers 0-99 in an array
    srand(int(time(NULL))); //to generate random at all time
    
    const int sizeOfArray = 10; //constant of array size, change when you need a different number of sequence to store in the array
    int arr[sizeOfArray];
    int r; // counter
    for (r = 0; r < sizeOfArray; r++) {
        arr[r] = rand() % 100; //generating random numbers from 0 - 99 (100) numbers
    }
    
    cout << "10 Random numbers between 0 to 99 are : \n";
    outFile << "10 Random numbers between 0 to 99 are : \n";
    
    printArray(arr, r); //calling print function to print the Random numbers' Array
    cout << "\n";
    outFile << "\n";
    
    //implement QUICK SORT for the previous array
    int s = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, s - 1);
    cout << "Quick Sorted Array is: \n";
    outFile << "Quick Sorted Array is: \n";
    
    printArray(arr, s);
    cout << "\n";
    outFile << "\n";
    
    return 0;
    
}
