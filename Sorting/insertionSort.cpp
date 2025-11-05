// Write a cpp program to implement insertion sort.

#include <iostream>
using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void display(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);   
    cout << "Enter elements in array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr);

    insertionSort(arr);

    cout << "Array after sorting: ";
    display(arr);

    return 0; 
}