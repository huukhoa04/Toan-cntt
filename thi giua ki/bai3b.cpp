#include <bits/stdc++.h>
// #include "CubicEquation.cpp"
using namespace std;
#define MAX 100
void sort(double arr[], int n)
{
    int i, j;
    double temp;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {

                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no two elements were
        // swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}
void Init(double a[][MAX], int *n)
{
    fstream File("matrix.txt", ios::in);
    File >> *n;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
        {
            File >> a[i][j];
        }
}
void Identify(double a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j] = 1.0;
            else
                a[i][j] = 0.0;
        }
    }
}
void Zerotify(double a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0.0;
        }
    }
}
void Assign(double a[][MAX], double b[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void print(double a[][MAX], int n)
{
    cout << "matrix: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n";
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t\t";
        }
    }
    cout << "\n";
}
void multiple(double a[][MAX], double b[][MAX], int n, double result[][MAX])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void non_squared_multiple(double a[][MAX], double b[][MAX], int row_1, int column_1, int row_2, int column_2, double result[][MAX])
{
    if (column_1 != row_2)
        return;
    for (int i = 0; i < row_1; i++)
    {
        for (int j = 0; j < column_2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < row_2; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void FormMatrix(double numb, double M[][MAX], double output[][MAX], int row, int column)
{
    cout << "m: \n";
    print(M, row);
    double temp[MAX][MAX];
    Zerotify(temp, row);
    // tinh vector y
    double temp1[MAX][MAX];
    Zerotify(temp1, row);
    for (int i = 0; i < row; i++)
    {
        temp[i][0] = pow(numb, (double)((row - 1) - i));
    }
    multiple(M, temp, row, temp1);
    print(temp1, row);
    for (int i = 0; i < row; i++)
    {
        output[i][column] = temp1[i][0];
    }
}

void Eigendecomposite(double a[][MAX], int n)
{
    double M[MAX][MAX], M1[MAX][MAX];
    double temp[MAX][MAX];
    double C[MAX][MAX];
    double P[MAX][MAX];
    Identify(C, n);
    for (int k = n - 2; k >= 0; k--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != k)
                {
                    if (i == j)
                    {
                        M[i][j] = 1;
                        M1[i][j] = 1;
                    }
                    else
                    {
                        M[i][j] = 0;
                        M1[i][j] = 0;
                    }
                }
                else
                {
                    M1[i][j] = a[k + 1][j];
                    if (j == k)
                        M[i][j] = 1 / a[k + 1][k];
                    else
                        M[i][j] = -a[k + 1][j] / a[k + 1][k];
                }
            }
        }

        multiple(a, M, n, temp);
        multiple(M1, temp, n, a);
        multiple(C, M, n, temp);
        Assign(C, temp, n);
    }
    cout << "\n";
    print(a, n);
    Zerotify(temp, n);
    // print(C, n);
    double output[n];
    // Solve(1, -a[0][0], -a[0][1], -a[0][2], output);
    sort(output, n); // sap xep gia tri rieng theo thu tu
    for (int i = 0; i < n; i++)
    {

        FormMatrix(output[i], C, temp, n, i);
    }
    print(temp, n);
}

int main(int argc, char const *argv[])
{
    double matrix[MAX][MAX];
    int n;
    Init(matrix, &n);
    // cout << "Enter Matrix's size: "; cin >> n;
    // for (int i = 0; i < n; i++)
    // for (int j = 0; j < n; j++)
    // {
    //     cout << "matrix[" << i << "][" << j << "] = "; cin >> matrix[i][j];
    // }
    Eigendecomposite(matrix, n);
    return 0;
}
