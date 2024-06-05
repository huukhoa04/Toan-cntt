#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void Identify(float a[][MAX] ,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}
void Reset(float a[][MAX] ,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            a[i][j] = 0;
        }
    }
}
void print(float a[][MAX], int n)
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
void transpose(float a[][MAX], int row, int column, float b[][MAX])
{
    // float b[column][row];
    for (int i = 0; i< row; i++)
    for (int j = 0; j< column; j++)
    {
        b[i][j] = a[j][i];
    }
}
void multiple(float a[][MAX], float b[][MAX], int row_1, int column_1, int row_2, int column_2, float result[][MAX])
{
    if (column_1 != row_2) return;
    for (int i =0 ; i< row_1; i++)
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
void LDLT_Decomposition(float matrix[][MAX], float output1[][MAX], float output2[][MAX], float output3[][MAX], int n)
{
    Identify(output1, n);
    Identify(output3, n);
    // output2[0][0] = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            float sum = 0;
 
            if (j == i) // summation for diagonals
            {
                for (int k = 0; k < j; k++)
                    sum += pow(output1[j][k], 2) * output2[k][k];
                output2[j][j] = matrix[j][j] -
                                        sum;
            } else {
 
                // Evaluating L(i, j) using L(j, j)
                for (int k = 0; k < j; k++)
                    sum += (output1[i][k] * output1[j][k] * output2[k][k]);
                output1[i][j] = (matrix[i][j] - sum) /
                                      output2[j][j];
            }
        }
    }
    transpose(output1, n, n, output3);
    cout << setw(15) << " L " 
         << setw(31) << "D"
          << setw(32) << "LT" << endl;
    for (int i = 0; i < n; i++) {
         
        // output1 Triangular
        for (int j = 0; j < n; j++)
            cout << setw(6) << output1[i][j] << "\t";
        cout << "\t";
         
        // Transpose of output1 Triangular
        for (int j = 0; j < n; j++)
            cout << setw(6) << output2[i][j] << "\t";
        cout << "\t";

        for (int j = 0; j < n; j++)
            cout << setw(6) << output3[i][j] << "\t";
        cout << endl;
    }

}
bool check(float input[][MAX], float L1[][MAX], float L2[][MAX], int n)
{
    float mul[MAX][MAX];
    
    multiple(L1, L2, n, n, n, n, mul);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        if (mul[i][j] != input[i][j]) return false;
    }
    return true;



}
int main()
{
    int n;
    cout << "Enter matrix's size: "; cin>> n;
    float matrix[MAX][MAX];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        cout << "matrix[" << i << "][" << j << "] = "; cin >> matrix[i][j];
    }
    float L1[MAX][MAX], L2[MAX][MAX], L3[MAX][MAX];
    
    float Transpose[MAX][MAX];
    
    cout << "LDLT DECOMPOSITION: \n";
    LDLT_Decomposition(matrix, L1, L2, L3, n);

}