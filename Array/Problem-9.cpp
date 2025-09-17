// Program for Set union

#include <iostream>
using namespace std;

void unionOfArrays(int arr1[], int size1, int arr2[], int size2) {
    int unionArr[size1 + size2];
    int k = 0;

    // Add all elements of the first array to the union array
    for (int i = 0; i < size1; i++) {
        unionArr[k++] = arr1[i];
    }

    // Add elements of the second array to the union array if they are not already present
    for (int j = 0; j < size2; j++) {
        bool found = false;
        for (int i = 0; i < size1; i++) {
            if (arr2[j] == arr1[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unionArr[k++] = arr2[j];
        }
    }

    // Print the union array
    cout << "Union of the two arrays is: ";
    for (int i = 0; i < k; i++) {
        cout << unionArr[i] << " ";
    }
    cout << endl;
}