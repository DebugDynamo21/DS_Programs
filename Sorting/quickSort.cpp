// Write a cpp Program to implement quick sorting.

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];

    int i = low - 1;
    
    //Traverse arr[low..high] and move all smaller elements on left side.
    // Elements from low to i are smaller after every iteration.
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Move pivot after the smaller elements and return its position.
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int q = partition(arr, low, high);
        quickSort(arr, low, q - 1);
        quickSort(arr, q + 1, high);
    }
}

void display(vector<int>& arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    
    cout << "Array: ";
    display(arr, n);
    
    quickSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    display(arr, n);

    return 0; 
}