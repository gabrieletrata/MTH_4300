//****************************************
// problem1.cpp
// Solves a system of equations of 2 variables.
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_2
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-02-11

#include<iostream>;

/**Returns factor to eliminate pivot.
  @param double a coefficient of pivot
  @param double b coefficient above pivot
 */
double getFactor(double a, double b){
  double factor = a / b;
  return factor;
}

/**Initializes the program and prompts user input.
 */
int main(){
  //Assumes a 2 x 3 matrix.
  int rowSize = 2;
  int colSize = 3;

  //Initializes 2 x 3 matrix.
  double matrix [rowSize][colSize];

  std::cout << "Input the 6 coefficients for the first and second linear equation, respectively." << std::endl;
  //Stores coefficients into matrix.
  for(int i = 0; i < rowSize; i++){
    for(int j = 0; j < colSize; j++){
      std::cin >> matrix[i][j];
    }
  }

  //Executes elimination and back substitution.
  double factor = getFactor(matrix[1][0], matrix[0][0]);
  matrix[1][1] = matrix[1][1] - matrix[0][1] * factor;
  matrix[1][2] = matrix[1][2] - matrix[0][2] * factor;
  double y = matrix[1][2] / matrix[1][1];
  double x = (matrix [0][2] - matrix[0][1] * y) / matrix [0][0];
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;

  return 0;
}
