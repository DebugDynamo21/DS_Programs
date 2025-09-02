// Program for reversal of an array.

#include <iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int end = n - 1;

    cout << "Given Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    for(int start = 0; start < n/2; start++){
        swap(arr[start], arr[end]); //function to swap the array.
        end--;
    }

    cout << "\nReversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0; 
}