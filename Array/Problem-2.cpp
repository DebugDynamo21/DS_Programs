// Program to insert the given elements into an array.

#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 16, 14, 12, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;

    cout << "Enter the position to insert the element: ";
    cin >> position;

    if(position < 1 || position > n + 1){
        cout << "Invalid posiiton!! Please enter a valid position." << endl;
    }else{
        for(int i = n - 1; i >= position - 1; i--){
            arr[i + 1] = arr[i];    // Shifting elements to the right.
        }

        arr[position - 1] = element; // Inserting the element at the given position.
        n++;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}