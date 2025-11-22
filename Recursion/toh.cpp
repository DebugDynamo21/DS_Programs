// TOWER OF HANOI ALGORITHM.

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char S, char M, char D){
    if(n == 1){
        cout << "Move disk from " << S << " to " << D << endl;
    }
    else{
        towerOfHanoi(n-1, S, D, M);
        cout << "Move disk from " << S << " to " << D << endl;
        towerOfHanoi(n-1, M, S, D);
    }
}

int main(){
    int n;
    cout << "Enter number of discs: ";
    cin >> n;

    towerOfHanoi(n, 'S', 'M', 'D');
    return 0; 
}