#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void Solve(double a ,double b, double c, double d, double output[]) 
{
    
    b /= a;
    c /= a;
    d /= a;
    
    double disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    term1 = (b/3.0);
    
    double x1_real, x2_real, x3_real;
    double x2_imag, x3_imag;
    string x2_imag_s, x3_imag_s;
    if (disc > 0)   // One root real, two are complex
    {
        s = r + sqrt(disc);
        s = s<0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t<0 ? -cbrt(-t) : cbrt(t);
        x1_real = -term1 + s + t;
        term1 += (s + t)/2.0;
        x3_real = x2_real = -term1;
        term1 = sqrt(3.0)*(-t + s)/2;
        x2_imag = term1;
        x3_imag = -term1;
        x2_imag_s =  " + "+ to_string(x2_imag) + "i";
        x3_imag_s =  " - "+ to_string(x2_imag) + "i";
    } 
    // The remaining options are all real
    else if (disc == 0)  // All roots real, at least two are equal.
    { 
        x3_imag = x2_imag = 0;
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1_real = -term1 + 2.0*r13;
        x3_real = x2_real = -(r13 + term1);
    }
    // Only option left is that all roots are real and unequal (to get here, q < 0)
    else
    {
        x3_imag = x2_imag = 0;
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1_real = -term1 + r13*cos(dum1/3.0);
        x2_real = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
        x3_real = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
    }
    
    cout << "\nRoots:" << endl <<
            "  x = " << x1_real << endl <<
            "  x = " << x2_real << x2_imag_s << endl <<
            "  x = " << x3_real << x3_imag_s << endl;
    output[0] = x1_real;
    output[1] = x2_real;
    output[2] = x3_real;

}
void sort(double arr[], int n)
{
    int i, j;
    double temp;
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                     
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
void Identify(double a[][MAX] ,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) a[i][j] = 1.0;
            else a[i][j] = 0.0;
        }
    }
}
void Zerotify(double a[][MAX] ,int n)
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
            cout  << setprecision(5) << a[i][j] << "\t\t";
        }
    }
    cout << "\n";
}
void multiple(double a[][MAX], double b[][MAX], int n, double result[][MAX])
{
    
    for (int i =0 ; i< n; i++)
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
void FormMatrix(double numb, double M[][MAX], double output[][MAX], int row, int column)
{
    
    double temp[MAX][MAX];
    Zerotify(temp, row);
    // tinh vector y
    double temp1[MAX][MAX];
    Zerotify(temp1, row);
    for (int i = 0; i<row; i++)
    {
        temp[i][0] = pow(numb, (double)((row-1)-i));
    }
    multiple(M, temp, row, temp1);
    for (int i = 0; i< row; i++)
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
    for (int k = n-2; k>=0; k--)
    {
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
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
                    M1[i][j] = a[k+1][j];
                    if (j == k) M[i][j] = 1/a[k+1][k];
                    else M[i][j] = -a[k+1][j]/a[k+1][k];
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
    Solve(1, -a[0][0], -a[0][1], -a[0][2], output);
    sort(output, n); // sap xep gia tri rieng theo thu tu
    for (int i = 0; i<n; i++)
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
