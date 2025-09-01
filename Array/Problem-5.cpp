// Program to find the missing number from the array which has the number in the range 1 to n.

#include <iostream>
using namespace std;

int missingNum(int *arr, int n){
    int total = 10; // Total number of elements from 1 to n.
    int sum = (total * (total + 1)) / 2; // Sum of first n natural numbers.
    int arrSum = 0;
    for(int i = 0; i < n; i++){
        arrSum += arr[i];   //Sum of elements in the array.
    }
    return sum - arrSum;
}

int main(){
    int arr[] = {1, 2, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int missingNumber = missingNum(arr, n);
    cout << "The missing number is: " << missingNumber << endl;
    return 0; 
}