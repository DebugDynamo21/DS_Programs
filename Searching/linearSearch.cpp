#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Array: " << endl;
    display(arr, n);

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, n, target);
    
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0; 
}