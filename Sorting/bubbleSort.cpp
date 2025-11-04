// Write a cpp program to implement bubble sorting.

#include <iostream>
using namespace std;

void bubbleSort(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
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
    cout << "Enter the elements of array: "; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr);

    bubbleSort(arr);

    cout << "Sorted array: ";
    display(arr);

    return 0; 
}