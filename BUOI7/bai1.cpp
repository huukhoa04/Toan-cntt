#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;


int main()
{
//     Eigen::Matrix3d m;
//     m << 50, 0, 40,
//          0, 0, 0,
//          40, 0, 50;
     Matrix2d m;
     m << 74, 32, 
          32, 26;
    cout << m << "\n";
    Eigen::EigenSolver<Eigen::MatrixXd> es(m);
    cout << "The eigenvalues of the 2x2 matrix of ones are:" 
     << endl << es.eigenvalues() << "\n";
     cout << es.eigenvectors();
     cout << "\n";
     cout << es.eigenvectors().transpose();
}