// Program for insertion in the sorted array.

#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element;
    cout << "Enter the element to insert: ";
    cin >> element;

    int i;
    for(i = n - 1; (i >= 0 && arr[i] > element); i--){
        arr[i + 1] = arr[i];    // Shifting elements to the right.
    }
    arr[i + 1] = element; // Inserting the element at the correct position.
    n++;

    cout << "Array after insertion: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}