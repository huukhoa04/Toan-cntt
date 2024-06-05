// // 0.5 1/3
// #include <iostream>
// #include <Eigen/Dense>

// using namespace Eigen;
// using namespace std;
// int main() {
//   // Define the transition matrix
//   MatrixXd transition_matrix;
//   int num_states;

//   // Get the number of states from user
//   std::cout << "Enter the number of states in the Markov chain: ";
//   std::cin >> num_states;

//   // Initialize the transition matrix with zeros
//   transition_matrix = MatrixXd::Zero(num_states, num_states);

//   // Get the transition matrix elements from user
//   std::cout << "Enter the transition matrix elements row by row (separated by spaces):\n";
//   for (int i = 0; i < num_states; ++i) {
//     for (int j = 0; j < num_states; ++j) {
//       double value;
//       std::cin >> value;
//       transition_matrix(i, j) = value;
//     }
//   }

//   // Get the initial state from user
//   int initial_state;
//   std::cout << "Enter the initial state (0 to " << num_states - 1 << "): ";
//   std::cin >> initial_state;

//   // Get the number of steps from user
//   int num_steps;
//   std::cout << "Enter the number of steps to simulate: ";
//   std::cin >> num_steps;

//   // Validate initial state
//   if (initial_state < 0 || initial_state >= num_states) {
//     std::cerr << "Error: Invalid initial state.\n";
//     return 1;
//   }

//   // Create a column vector to represent the initial state distribution
//   VectorXd state_distribution(num_states);
//   state_distribution.setZero();
//   state_distribution(initial_state) = 1.0; // Set probability 1 for the initial state

//   // Simulate the Markov chain for the specified number of steps
//   for (int step = 0; step < num_steps; ++step) {
//     state_distribution = transition_matrix * state_distribution;
//   }

//   // Print the state distribution after the specified number of steps
//   std::cout << "\nState distribution after " << num_steps << " steps:\n";
//   std::cout << state_distribution << std::endl;

//   return 0;
// }
#include <bits/stdc++.h>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
  // Define the transition matrix
  MatrixXd transition_matrix;
  int num_states;

  // Get the number of states from user
  std::cout << "Enter the number of states in the Markov chain: ";
  std::cin >> num_states;

  // Initialize the transition matrix with zeros
  transition_matrix = MatrixXd::Zero(num_states, num_states);

  // Get the transition matrix elements from user
  std::cout << "Enter the transition matrix elements row by row (separated by spaces):\n";
  for (int i = 0; i < num_states; ++i) {
    for (int j = 0; j < num_states; ++j) {
      double value;
      std::cin >> value;
      transition_matrix(i, j) = value;
    }
  }

  // Get the initial state probability distribution
  VectorXd state_distribution(num_states);
  state_distribution.setZero();

  // Get probabilities for each state from user
  std::cout << "Enter the initial state probability for each state (separated by spaces):\n";
  for (int i = 0; i < num_states; ++i) {
    double probability;
    std::cin >> probability;
    // Validate probability (between 0 and 1)
    if (probability < 0 || probability > 1) {
      std::cerr << "Error: Invalid probability entered. Please enter values between 0 and 1.\n";
      return 1;
    }
    state_distribution(i) = probability;
  }

  // Get the number of steps from user
  int num_steps;
  std::cout << "Enter the number of steps to simulate: ";
  std::cin >> num_steps;

  // Simulate the Markov chain for the specified number of steps
  for (int step = 0; step < num_steps; ++step) {
    state_distribution = transition_matrix * state_distribution;
  }

  // Print the state distribution after the specified number of steps
  std::cout << "\nState distribution after " << num_steps << " steps:\n";
  std::cout << state_distribution << std::endl;

  return 0;
}