#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& arr, int size, int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int largest = index;
    
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != index){
        swap(arr[index], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void heapSort(vector<int>& arr){
    for(int i = arr.size()/2 - 1; i >= 0; i--){
        maxHeapify(arr, arr.size(), i);
    }
    for(int i = arr.size() - 1; i > 0; i--){
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
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
    cout << "Enter elements in array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Array: " << endl;
    display(arr);

    heapSort(arr);

    cout << "Array after sorting: " << endl;
    display(arr);
    return 0; 
}