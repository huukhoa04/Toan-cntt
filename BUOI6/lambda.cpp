#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    MatrixXf A(4,5);
    A << 
    6,   -8,  -4,   5,  -4,
    2,   7,   -5,  -6,  4,
    0,   -1,  -8,  2,   2,
    -1,  -2,  4,   4,   -8;
    MatrixXf At(5,4);
    At = A.transpose();
    MatrixXf ata = At*A;
    EigenSolver<MatrixXf> es(ata);
    cout << es.eigenvalues().real() << "\n";
    cout << es.eigenvectors().real();
}