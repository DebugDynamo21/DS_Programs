// Write a cpp program to implement binary search.

#include <iostream>
using namespace std;

void binarySearch(vector<int>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int pos = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] < target){
            low = mid + 1;
        }else if(arr[mid] > target){
            high = mid - 1;
        }else{
            pos = mid;
            break;
        }
    }

    if(pos == -1){
        cout << target << " is not Found in the array!" << endl;
    }else{
        cout << target << " is found at index " << pos << endl;
    }
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

    int target;
    cout << "Enter value to search for: ";
    cin >> target;

    binarySearch(arr, target);

    return 0; 
}