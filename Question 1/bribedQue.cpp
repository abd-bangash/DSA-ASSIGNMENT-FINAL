#include <iostream>
#include <array>
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
int bribedQue(int array[], int size)
{
    int key, j;
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
            count++;
        }
        array[j + 1] = key;
    }
    return count;
}
int main()
{
    int *myArray; // to store the address of array returned by read file function
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray; // to store size of array through function
    // creating a list of all test cases
    string listOfTestCases[5] = {"TestCase1.1.txt", "TestCase1.2.txt", "TestCase1.3.txt", "TestCase1.4.txt", "TestCase1.5.txt"}; // all test cases files
    // testing all test cases:
    for (int i = 0; i < 5; i++)
    {
        myArray = readFile(listOfTestCases[i], sizeAddress); // readFile returns the pointer to the list read from txt file
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            arr[i] = *(myArray + i);
        }
        int result = bribedQue(arr, sizeOfArray); // calling the bribedQue function
        cout << "In " << listOfTestCases[i] << " the number of bribes were : " << result << endl;
        cout << endl;
        delete[] myArray;
    }
    return 0;
}