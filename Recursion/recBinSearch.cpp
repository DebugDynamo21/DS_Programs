#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& vec, int n, int low, int high, int target){
    int mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(vec[mid] == target){
            return mid;
        }else if(vec[mid] < target){
            binarySearch(vec, n, low, mid - 1, target);
        }else{
            binarySearch(vec, n, mid + 1, high, target);
        }
    }
    return 1;
}

void display(vector<int>& vec, int n){
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> vec;
    cout << "Enter the elements in array: ";
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int res = binarySearch(vec, n, 0, n-1, target);
    
    cout << "Target element " << target << "found at index: " << res << endl;
    return 0; 
}