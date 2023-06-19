#include <iostream>
#include "constants.h"
#include "selectionsort.cpp"
#include "printarray.cpp"


// Function for Selection sort


// Function to print an array


int main()
{
    std::cout << "Enter integers (enter 0 to finish):" << std::endl;

    int* arr = nullptr; // Declare a pointer to an integer (initialize to nullptr)
    int num;
    int count = 0;
    const int chunkSize = 10;

    while (true) {
        std::cin >> num;

        if (num == 0) {
            break;
        }

        if (count % chunkSize == 0) {
            // If the current count is a multiple of chunkSize, allocate a new chunk of memory

            int* newNumbers = new int[count + chunkSize]; // Allocate memory for a larger array

            for (int i = 0; i < count; ++i) {
                newNumbers[i] = arr[i]; // Copy the elements from the old array to the new array
            }

            delete[] arr; // Free the memory occupied by the old array
            arr = newNumbers; // Update the pointer to point to the new array
        }

        arr[count] = num; // Store the input number in the array
        count++;
    }

    std::cout << "Entered numbers:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(arr, count); // Sort the array using the selection sort algorithm
    std::cout << "Sorted array: " << std::endl;
    printArray(arr, count); // Print the sorted array

    delete[] arr; // Free the memory occupied by the array

    return 0;
}