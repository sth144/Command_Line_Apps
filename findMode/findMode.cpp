/*
Author: Sean T Hinds
Date: 11/04/16
Description: Takes an array of values and returns a vector containing the mode(s in
              ascending order). Compile command: g++ findMode.cpp*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function body for findMode, which accepts an array and the size of that array
vector<int> findMode(int array[], int size) {

  // sort the input array. Sorting makes finding consecutive occurrences of ints
  // in array easier
  std::sort(array, array + size);

  // this block determines the maximum occurrence of any int in the array
  int counter = 1; // counts consecutive occurrences of a number
  int max = 1; // stores max consecutive occurrences of any number in array
  // for loop iterates through each element in array
  for (int iterator = 0; iterator < size - 1; iterator++) {
    // if-else statement uses counter to track consecutive occurrences of int value stored
    // in a given element of the array
    if (array[iterator] == array[iterator + 1]) {
      counter++;
      // nested if statement handles case where number of consecutive occurrences
      // of current int value being evaluated surpasses previous max consecutive value
      if (counter > max) {
        max = counter;
      }
    }
    // if int value stored in next array element differs from current int being
    // evaluated, this else statement resets counter to 1
    else {
      counter = 1; // reset counter
    }
  }

  // this block uses the max value from the previous block to determine which
  // numbers occur max times
  vector<int> modeVector; // vector to store mode values
  int consec = 1; // tracks consecutive occurrences. Analogues to 'counter' above
  // for loop iterates through array a second time
  for (int position = 0; position < size; position++) {
    // if-else statement uses consec to track consecutive occurrences of int value stored
    // in a given element of the array. Starts by handling case where each element in
    // array holds a unique int value
    if (max == 1) {
      modeVector.push_back(array[position]);
    }
    else if (array[position] == array[position + 1]) {
      consec++;
      // nested if statement adds value to modeVector if it occurs max number of times
      // in the array
      if (consec == max) {
        modeVector.push_back(array[position]);
      }
    }
    // if value occurs less than max number of times, reset consec
    else {
      consec = 1;
    }
  }

  // This if statement alerts the user if the above loops didn't function
  // correctly, and modeVector remains empty
  if (modeVector.empty()) {
    std::cout << "error: modeVector is empty" << endl;
  }

  return modeVector;
}

 // main method for testing
int main() {
  int SIZE = 8;
  int value;
  int testArray[SIZE];
  std::cout << "enter 8 ints" << endl;
  for (int i = 0; i < SIZE; i++) {
    std::cin >> value;
    testArray[i] = value;
  }
  vector<int> testMode(findMode(testArray, SIZE));
  std::cout << "the modes are: " << endl;
  for (int n = 0; n < testMode.size(); n++) {
    std::cout << testMode[n] << " " << endl;
  }
  return 0;
}
