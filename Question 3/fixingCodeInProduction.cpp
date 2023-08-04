#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int *readFile(string a, int *to_search, int *size_of_arr)
{
    ifstream inputFile(a);
    int size;
    int search;
    // read and store the number to search

    inputFile >> search;
    *to_search = search;
    inputFile.ignore();
    // read and store the size of array

    inputFile >> size;
    *size_of_arr = size;
    inputFile.ignore(); // Consume the newline character left in the stream
    // read array

    string valuesLine;
    getline(inputFile, valuesLine);
    stringstream ss(valuesLine);
    int value;
    int *ptr = (int *)malloc(size * sizeof(int));
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
int fixingCodeInProduction(int search, int size, int array[])
{
    int flag = 0;
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == search)
        {
            return mid;
            flag = 1;
            break;
        }
        else if (array[mid] > search)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (flag == 0)
    {
        return -1;
    }
}
int main()
{
    int *myArray; // to store the address of array returned by read file function
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray; // to store size of array through function
    int searchNumber;
    int *searchNumberAddress = &searchNumber;
    string listOfTestCases[5] = {"TestCase3.1.txt", "TestCase3.2.txt", "TestCase3.3.txt", "TestCase3.4.txt", "TestCase3.5.txt"}; // all test cases files
    // testing all test cases:
    for (int i = 0; i < 5; i++)
    {
        myArray = readFile(listOfTestCases[i], searchNumberAddress, sizeAddress); // readFile returns the pointer to the listOfTestCases read from txt file
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            arr[i] = *(myArray + i);
        }
        int result = fixingCodeInProduction(searchNumber, sizeOfArray, arr); // calling the bribedQue function
        if (result != -1)
        {
            cout << "In " << listOfTestCases[i] << " element found at index : " << result << endl;
            cout << endl;
        }
        else
        {
            cout << "In " << listOfTestCases[i] << " Not Found" << endl;
            cout << endl;
        }
        delete[] myArray;
    }
    // int arr[9] = {2, 4, 8, 16, 32, 64, 128, 256, 512};
    // int result = fixingCodeInProduction(128, 9, arr);
    // cout << "element found at index : " << result;
    return 0;
}