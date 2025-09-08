// Program for merging two sorted arrays

#include <vector>
#include <iostream>
using namespace std;

int main(){
    int m, n;
    cout << "Enter the size of vector A and B: ";
    cin >> m >> n;

    vector<int>nums1(m + n);   // Assuming nums1 has enough space to hold elements of nums2
    vector<int>nums2(n);

    cout << "Enter values for vector A(sorted): ";
    for(int i = 0; i < m; i++){
        cin >> nums1[i];    //input for first m elements
    }

    cout << "Enter values for vector B(sorted): ";
    for(int i = 0; i < n; i++){
        cin >> nums2[i];    //input for n elements
    }

    int idx = m + n - 1, i = m - 1, j = n - 1;

    while(i >= 0 && j >= 0){    //merge in reverse order
        if(nums1[i] >= nums2[j]){   //greater element goes to the end
            nums1[idx] = nums1[i];  //place the greater element from nums1 at the end of nums1
            idx--, i--;
        }else{
            nums1[idx] = nums2[j];  //place the greater element from nums2 at the end of nums1
            idx--, j--;
        }
    }

    while(j >= 0){  //if any elements are left in nums2
        nums1[idx] = nums2[j];  //place the remaining elements from nums2 to nums1
        idx--, j--;
    }

    cout << "\nResult: ";   //print the merged array
    for(int i = 0; i < m + n; i++){
        cout << nums1[i] << " ";
    }

    cout << endl;
    return 0;
}