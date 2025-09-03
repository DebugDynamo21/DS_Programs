// Program for Matrix Addition.

#include <iostream>
using namespace std;

int main(){
    int m, n;
    cout << "Enter the order of matrix A(m x n): ";
    cin >> m >> n;

    int p, q;
    cout << "Enter the order of matrix B(p x q): ";
    cin >> p >> q;

    if(m != p || n != q){
        cout << "Invalid order! Please enter a valid order such that (m x n) = (p x q)." << endl;
    }else{

        //First matrix A
        int A[m][n];
        cout << "Enter values in matrix A: ";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }

        cout << "\nMatrix A [" << m << "x" << n << "]: " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

    //Second Matrix B
        int B[p][q];
        cout << "Enter values in matrix B: ";
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                cin >> B[i][j];
            }
        }

        cout << "\nMatrix B [" << p << "x" << q << "]: " << endl;
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        //Sum of the matrix A and B
        cout << "\nSum of matrix A & B [" << m << "x" << n << "]: \n";
        int c[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                c[i][j] = A[i][j] + B[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << c[i][j] << " "; 
            }
            cout << endl;
        }

    }

    return 0; 
}