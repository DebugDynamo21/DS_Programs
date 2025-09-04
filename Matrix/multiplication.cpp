// Program for Matrix Multiplication

#include <iostream>
using namespace std;

void prodMatrix(int *A, int *B, int m, int q, int n)
{
    int C[m][q];
    int i, j, k;

    //Calculate product of matrix A and B using pointer arithmetic.
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                C[i][j] += *(A + i * n + k) * *(B + k * q + j);
                // Multiplication loop me ye offsets calculate karke values multiply aur sum ki ja rahi hain.
            }
        }
    }

    //Print product matrix C.
    cout << "\nMatrix C[" << m << "x" << q << "]: " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cout << "Enter the order of matrix A(m x n): ";
    cin >> m >> n;

    int p, q;
    cout << "Enter the order of matrix B(p x q): ";
    cin >> p >> q;

    if (n != p)
    {
        cout << "Invalid order! Please enter a valid order such that n = p." << endl;
    }
    else
    {
        // First matrix A
        int A[m][n];
        cout << "Enter values in matrix A: ";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> A[i][j];
            }
        }

        cout << "\nMatrix A [" << m << "x" << n << "]: " << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        // Second Matrix B
        int B[p][q];
        cout << "Enter values in matrix B: ";
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> B[i][j];
            }
        }

        cout << "\nMatrix B [" << p << "x" << q << "]: " << endl;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        //Calling prodMatrix Function
        prodMatrix((int *)A, (int *)B, m, q, n);
    }

    return 0;
}