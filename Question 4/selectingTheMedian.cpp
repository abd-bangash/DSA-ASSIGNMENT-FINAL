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
int selectingTheMedian(int array[], int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    int medianIndex = size / 2;
    return array[medianIndex];
}

int main()
{
    int *myArray; // to store the address of array returned by read file function
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray;                                                                                             // to store size of array through function
    string listOfTestCases[5] = {"TestCase4.1.txt", "TestCase4.2.txt", "TestCase4.3.txt", "TestCase4.4.txt", "TestCase4.5.txt"}; // all test cases files
    // testing all test cases:
    for (int i = 0; i < 5; i++)
    {
        myArray = readFile(listOfTestCases[i], sizeAddress); // readFile returns the pointer to the listOfTestCases read from txt file
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            arr[i] = *(myArray + i);
        }
        int result = selectingTheMedian(arr, sizeOfArray); // calling the bribedQue function
        cout << "In " << listOfTestCases[i] << " Median is: " << result << endl;
        cout << endl;
        delete[] myArray;
    }
    // int arr[9] = {98, 88, 67, 82, 76, 80, 64, 55, 76};
    // int result = selectingTheMedian(arr, 9);
    // cout << result;
    return 0;
}