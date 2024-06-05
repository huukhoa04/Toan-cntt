// g++ -I C:\eigen-3.4.0 tenfile.cpp -o tenfile.exe
// tinh toan 3 ma tran U, sigma, V
#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
MatrixXf Transpose_1(MatrixXf A, int row, int column)
{
    MatrixXf A_trans(column, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            A_trans(j, i) = A(i, j);
        }
    }
    return A_trans;
}
MatrixXf Multiple(MatrixXf A, int A_row, int A_col, MatrixXf B, int B_row, int B_col)
{
    MatrixXf result(A_col, B_row);
    for (int i = 0; i < A_col; i++)
    {
        for (int j = 0; j < B_row; j++)
        {
            result(i, j) = 0;
            for (int k = 0; k < B_col; k++)
            {
                result(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    return result;
}
MatrixXf MatrixDacTrung(MatrixXf A, int row, int column)
{
    MatrixXf At = Transpose_1(A, row, column);
    MatrixXf mtdt = Multiple(At, row, column, A, column, row);
    return mtdt;
    // MatrixXf At = A.transpose();
    // MatrixXf mtdt =  At*A;
    // return mtdt;
}
MatrixXf vtCal(MatrixXf A, int row, int column)
{
    MatrixXf mtdt = MatrixDacTrung(A, row, column);
    EigenSolver<MatrixXf> es(mtdt);
    EigenSolver<MatrixXf>::EigenvectorsType eigenVectors = es.eigenvectors();

    MatrixXf V = eigenVectors.real().matrix();
    return V;
}
MatrixXf sigmaCal(MatrixXf A, int row, int column)
{
    MatrixXf mtdt = MatrixDacTrung(A, row, column);
    EigenSolver<MatrixXf> es(mtdt);
    EigenSolver<MatrixXf>::EigenvalueType eigenValues = es.eigenvalues();
    EigenSolver<MatrixXf>::EigenvectorsType eigenVectors = es.eigenvectors();
    MatrixXf sigma = MatrixXf::Zero(eigenValues.rows(), eigenValues.rows());
    // cout << "\n";
    for (int i = 0; i < eigenValues.rows(); i++)
    {
        sigma(i, i) = sqrt((eigenValues[i].real()));
    }
    // sigma(eigenValues.rows() - 1, eigenValues.rows() - 1) = 0.000001;
    // cout << sigma;
    return sigma;
    // có được ma trận đường chéo lambda
}
MatrixXf uCal(MatrixXf A, int row, int column) // sửa uCal tùy bài
{
    // MatrixXf mtdt = MatrixDacTrung(A, row, column);
    // EigenSolver<MatrixXf> es(A);
    // EigenSolver<MatrixXf>::EigenvalueType eigenValues = es.eigenvalues();
    // EigenSolver<MatrixXf>::EigenvectorsType eigenVectors = es.eigenvectors();

    MatrixXf V = vtCal(A, row, column);
    // int row1 = V.rows();
    // int col1 = V.cols();

    MatrixXf U = A * V;
    // MatrixXf U = Multiple(A, row, column , V, column, column);
    for (int i = 0; i < U.cols(); ++i)
        U.col(i).normalize();
    return U;
}
void check(MatrixXf U, MatrixXf sigma, MatrixXf Vt)
{
    cout << "\n"
         << (U * sigma * Vt.transpose()).real() << "\n";
}
int main(int argc, char const *argv[])
{
    int row = 3;
    int column = 3;

    MatrixXf A = MatrixXf(row, column);

    A << 4, 8, 6,
        8, 8, 6,
        9, 8, 6;
    // A <<    -3,  1,
    //         6,  -2,
    //         6,  -2;
    //  A << -18, 13,  -4,  4,
    //       2,   19,  -4,  12,
    //       -14, 11,  -12, 8,
    //       -2,  21,  4,   8;
    // A << 1, 0,  1,
    //     -2,  1,  0;
    MatrixXf ATA = MatrixDacTrung(A, row, column);
    cout << ATA << "\n";
    MatrixXf U = uCal(A, row, column);
    cout << "U: " << "\n";
    cout << U << "\n";
    MatrixXf sigma = sigmaCal(A, row, column);
    cout << "sigma: " << "\n";

    cout << sigma << "\n";
    MatrixXf Vt = vtCal(A, row, column);
    cout << "Vt: " << "\n";

    cout << Vt << "\n";
    check(U, sigma, Vt);
    return 0;
}
