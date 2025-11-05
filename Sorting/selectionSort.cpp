#include <iostream>
using namespace std;

void selectionSort(vector<int>& arr){
    
    for(int i = 0; i < arr.size() - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
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
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr);

    selectionSort(arr);

    cout << "Array after Sorting: ";
    display(arr);
    return 0; 
}