//****************************************
// problem3.cpp
// Transforms a sequence of numbers from the set {1, 2, 3},
// until the entire sequence has all terms equal.
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_2
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-02-14

#include<iostream>

/**Initializes the program and prompts user input.
*/
int main(){
  int current = 0; //stores current value of user input.
  int prev = 0; //stores previous value of user input.
  int first = 0; //stores value of the first value of user input.
  int counter = 0; //stores value of how many numbers are in the sequence.

  //Prompts user to create sequence
  std::cout << "Create a sequence from the set {1, 2, 3}. To indicate the end of the sequence, input -1 after n-th number of the sequence." << std::endl;
  std::cin >> current;
  first = current;

  //Allows input until the user has indicated the n-th number of the sequence.
  while (current != -1){;
    std::cin >> current;
    //Checks if the last number the user inputted is -1.
    if(current != -1){
      if(current != prev){
        //Checks if 1 is followed by 2, or vice versa in the sequence.
        if(current + prev == 3){
          first = 3;
          counter += 1;
        }
        //Checks if 1 is followed by 3, or vice versa in the sequence.
        if(current + prev == 4){
          first = 2;
          counter += 1;
        }
        //Checks if 2 is followed by 3, or vice versa in the sequence.
        if(current + prev == 5){
          first = 1;
          counter += 1;
        }
      }
    }
  }

  //Outputs the transformed sequence.
  std::cout << "Transformed sequence: ";
  for(int i = 0; i < counter - 1; i++){
    std::cout << first << " ";
  }
  std::cout << std::endl;

  return 0;
}
