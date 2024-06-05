//g++ -I C:\eigen-3.4.0 tenfile.cpp -o tenfile.exe
//khong dung ham transpose trong thi
#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
// solving 3 var equations
double determinantOfMatrix(MatrixXf mat)
{
    double ans;
    ans = mat(0, 0) * (mat(1,1) * mat(2,2) - mat(2,1) * mat(1,2))
          - mat(0,1) * (mat(1, 0) * mat(2, 2) - mat(1, 2) * mat(2, 0))
          + mat(0, 2) * (mat(1, 0) * mat(2, 1) - mat(1, 1) * mat(2, 0));
    return ans;
}
 
// This function finds the solution of system of
// linear equations using cramer's rule
MatrixXf findSolution(MatrixXf coeff)
{
    // Matrix d using coeff as given in cramer's rule
    MatrixXf d(3, 3);
         d <<  coeff(0,0), coeff(0,1), coeff(0,2) ,
               coeff(1,0), coeff(1,1), coeff(1,2) ,
               coeff(2,0), coeff(2,1), coeff(2,2);
    
    // Matrix d1 using coeff as given in cramer's rule
    MatrixXf d1(3, 3);
         d1 << coeff(0,3), coeff(0,1), coeff(0,2) ,
               coeff(1,3), coeff(1,1), coeff(1,2) ,
               coeff(2,3), coeff(2,1), coeff(2,2);
    
    // Matrix d2 using coeff as given in cramer's rule
    MatrixXf d2(3, 3);
         d2 << coeff(0,0), coeff(0,3), coeff(0,2),
               coeff(1,0), coeff(1,3), coeff(1,2),
               coeff(2,0), coeff(2,3), coeff(2,2);
    
    // Matrix d3 using coeff as given in cramer's rule
    MatrixXf d3(3, 3);
     d3 <<     coeff(0,0), coeff(0,1), coeff(0,3) ,
               coeff(1,0), coeff(1,1), coeff(1,3) ,
               coeff(2,0), coeff(2,1), coeff(2,3);
    
 
    // Calculating Determinant of Matrices d, d1, d2, d3
    double D = determinantOfMatrix(d);
    double D1 = determinantOfMatrix(d1);
    double D2 = determinantOfMatrix(d2);
    double D3 = determinantOfMatrix(d3);
//     printf("D is : %lf \n", D);
//     printf("D1 is : %lf \n", D1);
//     printf("D2 is : %lf \n", D2);
//     printf("D3 is : %lf \n", D3);
     double x,y,z;
    // Case 1
    if (D != 0) {
        // Coeff have a unique solution. Apply Cramer's Rule
        x = D1 / D;
        y = D2 / D;
        z = D3 / D; // calculating z using cramer's rule
     }
     MatrixXf result(4,1);
     result(0, 0) = x;
     result(1, 0) = y;
     result(2, 0) = z;
     result(3, 0) = 1;     
// Case 2
//     else {
//         if (D1 == 0 && D2 == 0 && D3 == 0)
//             printf("Infinite solutions\n");
//         else if (D1 != 0 || D2 != 0 || D3 != 0)
//             printf("No solutions\n");
//     }

     return result;
}
MatrixXf Transpose_1(MatrixXf A, int row, int column)
{
     MatrixXf A_trans(column,row);
     for (int i = 0; i< column; i++)
     {
          for (int j = 0; j< row; j++)
          {
               A_trans(j, i) = A(i, j);
          }
     }
     return A_trans;
}
MatrixXf Zerotify(MatrixXf A, int row, int column)
{
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < column; j++)
          {
               A(i,j) = 0;
          }
     }
     return A;
}
MatrixXf Multiple(MatrixXf A, int A_row, int A_col, MatrixXf B,int B_row, int B_col)
{
     MatrixXf result(A_row, B_col);
     for (int i =0 ; i< A_row; i++)
     {
        for (int j = 0; j < B_col; j++)
        {
            result(i,j) = 0;
            for (int k = 0; k < B_col; k++)
            {
                result(i,j) += A(i,k)* B(k,j);
            }
        }
     }
     return result;
}
MatrixXf Multiple_SingleNumber(MatrixXf A, int A_row, int A_col, double a)
{
     MatrixXf result(A_row, A_col);
     for (int i =0 ; i< A_row; i++)
     {
        for (int j = 0; j < A_col; j++)
        {
            result(i, j) *= a;
        }
     }
     return result;
}
MatrixXf MatrixDacTrung(MatrixXf A, int row, int column)
{
     MatrixXf At = Transpose_1(A, row, column);
     MatrixXf mtdt = Multiple(At, row, column, A, column, row);
     return mtdt;
}
MatrixXf vtCal(MatrixXf A, int row, int column)
{
     MatrixXf mtdt = MatrixDacTrung(A, row, column);
     EigenSolver<MatrixXf> es(mtdt);
     MatrixXf Vt = es.eigenvectors().real().matrix();
     return Vt;

}
MatrixXf sigmaCal(MatrixXf A, int row, int column)
{
     MatrixXf mtdt = MatrixDacTrung(A, row, column);
     EigenSolver<MatrixXf> es(mtdt);
     MatrixXf sigma = MatrixXf(row,column);
     sigma.setZero();
     // cout << "\n";
     for (int i = 0; i< es.eigenvalues().size(); i++)
     {
          sigma(i,i) = sqrt(fabs(es.eigenvalues()[i].real()));
     }
     // cout << sigma;
     return sigma;
     //có được ma trận đường chéo lambda
}
MatrixXf GetCol(MatrixXf A, int row, int column, int selected_column)
{
     MatrixXf Result(row, 1);
     for (int i = 0; i < row; i++)
     {
          Result(i,0) = (double)A(i, selected_column);
     }
     return Result;
}
MatrixXf AddCol(MatrixXf U, int row, int column, MatrixXf Added, int column_to_add)
{
     MatrixXf Result(row, column);
     Result = U;
     for (int i =0; i < row; i++)
     {
          Result(i, column_to_add) = (double)Added(i, 0);
     }
     return Result;
}
MatrixXf AddRow(MatrixXf U, int row, int column, MatrixXf Added, int row_to_add)
{
     MatrixXf Result(row, column);
     Result = U;
     for (int i = 0; i < row; i++)
     {
          Result(row_to_add, i) = (double)Added(i, 0);
     }
     return Result;
}
void uCal (MatrixXf A, int row, int column)
{
     MatrixXf U(row, row);
     MatrixXf Sigma = sigmaCal(A, row, column);
     cout << Sigma << "\n";
     MatrixXf Vt = vtCal(A, row, column);
     cout << Vt << "\n";
     U.setZero();
     for (int i = 0; i < row-1; i++)
     {
          

          MatrixXf temp(row, 1);// 1 cột trong U
          MatrixXf temp_V(column, 1); //1 cột vector
          temp_V = GetCol(Vt, row, column, i); //lấy ra từng vector // set 0
          MatrixXf temp_A(row,column); // lấy ra số nhân ma trận
          temp_A = Multiple_SingleNumber(A, row, column, 1/Sigma(i,i)); //nhân 1/sigma với ma trận A
          temp = Multiple(temp_A, row, column, temp_V, column, 1); // nhân temp_A với vector đã lấy ra
          U = AddCol(U, row, row, temp, i);
          
     }    
     MatrixXf temp_equal(row-1,row);
     
}
void check(){}
int main()
{
     int row = 4;
     int column = 4;


     MatrixXf A = MatrixXf(row,column);
     
     A << -18, 13,  -4,  4,
          2,   19,  -4,  12,
          -14, 11,  -12, 8,
          -2,  21,  4,   8;
     // A << 6,   -8,  -4,   5,  -4,
     //      2,   7,   -5,  -6,  4,
     //      0,   -1,  -8,  2,   2,
     //      -1,  -2,  4,   4,   -8;
     MatrixXf mtdt = MatrixDacTrung(A, row, column);
     cout <<  mtdt << "\n";
     
     // MatrixXf Vt = vtCal(mtdt, row, column);
     // cout << Vt << "\n";
     // MatrixXf Sigma = sigmaCal(A, row, column);
     // cout << Sigma << "\n";
     uCal(A, row, column);
     // cout << U << "\n";
     // MatrixXf U = uCal(A, 2, 3);
     // cout << U << "\n";
     
     
}
