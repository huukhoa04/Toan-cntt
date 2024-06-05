#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
#define COL int
#define ROW int
MatrixXd powOfMatrix(MatrixXd matrix, int power, ROW m, COL n)
{
    EigenSolver<MatrixXd> eig(matrix);

  // Extract eigenvalues and eigenvectors
  MatrixXd eigenvalues = eig.eigenvalues();
  MatrixXd eigenvectors = eig.eigenvectors();

  // Calculate matrix power using eigenvalues
  MatrixXd powerMatrix = MatrixXd::Identity(m, n);
  for (int i = 0; i < m; ++i) {
    powerMatrix(i, i) = std::pow(eigenvalues(i), power);
  }

  // Calculate the result matrix
  MatrixXd result = eigenvectors * powerMatrix * eigenvectors.inverse();

  // Display the result matrix
//   cout << "\nResultant matrix:\n";
//   cout << result << endl;
  return result;
}
int main() {
  // Define the matrix and its dimensions
  int m, n;
  std::cout << "Enter the number of rows (m): ";
  std::cin >> m;
  std::cout << "Enter the number of columns (n): ";
  std::cin >> n;

  MatrixXd matrix(m, n);
  std::cout << "Enter the matrix elements row by row: \n";
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix(i, j);
    }
  }

  // Get the power to raise the matrix to
  int power;
  std::cout << "Enter the power (x): ";
  std::cin >> power;

  // Perform Eigen decomposition
  EigenSolver<MatrixXd> eig(matrix);

  // Extract eigenvalues and eigenvectors
  MatrixXd eigenvalues = eig.eigenvalues();
  MatrixXd eigenvectors = eig.eigenvectors();

  // Calculate matrix power using eigenvalues
  MatrixXd powerMatrix = MatrixXd::Identity(m, n);
  for (int i = 0; i < m; ++i) {
    powerMatrix(i, i) = std::pow(eigenvalues(i), power);
  }

  // Calculate the result matrix
  MatrixXd result = eigenvectors * powerMatrix * eigenvectors.inverse();

  // Display the result matrix
  std::cout << "\nResultant matrix:\n";
  std::cout << result << std::endl;

  return 0;
}