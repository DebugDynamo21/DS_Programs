// Program for delete the given elements into an array.

#include <iostream>
using namespace std;
int main(){
    int arr[] = {10, 16, 14, 12, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    int position;
    cout << "Enter the position to delete the element: ";
    cin >> position;

    if(position < 1 || position > n + 1){
        cout << "Invalid position!! Please enter a valid position." << endl; 
    }else{
        for(int i = position - 1; i < n - 1; i++){
            arr[i] = arr[i + 1];    // Shifting elements to the left.
        }

        n--;
        for(int i = 0;i < n; i++){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0; 
}