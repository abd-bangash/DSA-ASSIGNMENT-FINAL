#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int *readFile(string a, int *size_of_arr)
{
    int size;
    int value;
    int *ptr;

    ifstream inputFile(a);

    // reading the size of array

    inputFile >> size;
    *size_of_arr = size;
    inputFile.ignore(); // Consume the newline character left in the stream

    // reading the array

    string valuesLine;
    getline(inputFile, valuesLine);
    stringstream ss(valuesLine);
    ptr = (int *)malloc(size * sizeof(int));
    int i = 0;
    while (ss >> value)
    {
        *(ptr + i) = value;
        i++;
        if (ss.peek() == ',')
            ss.ignore();
    }
    inputFile.close();
    return ptr;
}
int goingOffCharts(int array[], int size)
{
    int workingHours = 6;
    int maxWorkingHours = 0;
    int currentWorkingHours = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > workingHours)
        {
            currentWorkingHours++;
            maxWorkingHours = max(maxWorkingHours, currentWorkingHours);
        }
        else
        {
            currentWorkingHours = 0;
        }
    }
    return maxWorkingHours;
}

int main()
{
    int *myArray; // to store the address of array returned by read file function
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray;                                                                                             // to store size of array through function
    string listOfTestCases[5] = {"TestCase2.1.txt", "TestCase2.2.txt", "TestCase2.3.txt", "TestCase2.4.txt", "TestCase2.5.txt"}; // all test cases files
    // testing all test cases:
    for (int i = 0; i < 5; i++)
    {
        myArray = readFile(listOfTestCases[i], sizeAddress); // readFile returns the pointer to the listOfTestCases read from txt file
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            arr[i] = *(myArray + i);
        }
        int result = goingOffCharts(arr, sizeOfArray); // calling the bribedQue function
        cout << "in " << listOfTestCases[i] << " bob consecutively worked overtime for " << result << " days" << endl;
        cout << endl;
        delete[] myArray;
    }
    // int arr[12] = {6, 6, 7, 8, 7, 6, 6, 8, 12, 11, 12, 10};
    // int result = goingOffCharts(arr, 12);
    // cout << result;
    return 0;
}