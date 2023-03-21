/*Code written by: Julian Sahagun*/
#include <iostream>
#include <chrono>
#include <math.h>

// The Fibonacci Sequence is 0,1,1,2,3,5,8...
// F0 = 0, F1 = 1, and Fn = Fn-1 + Fn-2

using namespace std;

int main(){
  int maxFib(int upperBound);
  int indexOfFib(int fibNum);
  int fibRecursion(int index);
  double fibUsingFormula(int index);
  auto start = chrono::steady_clock::now();
  auto end = chrono::steady_clock::now();
  chrono::duration<double> timeUsingMaxFib = start - start; //initializing the value to 0

  //1. What is the max Fibonacci number that is less than the max integer that can be represented in C++? (call maxFib)
  
  int largestFib = maxFib(INT_MAX);
  cout << "1) The maximum Fibonacci number less than the max integer is: " << largestFib << "\n";

  //2. What is the index of the above number? (call indexOfFib)

  int indexLargest = indexOfFib(largestFib);
  cout << "2) The index of the largest Fibonacci number less than the max integer is: " << indexLargest << "\n";
  
  //3. How much time does it take to find the number in 1) ? use the appropriate methods from the library

  for(int i = 0; i < 10; i++){
    // run 10 times and average the time taken per run
    start = chrono::steady_clock::now();
    largestFib = maxFib(INT_MAX);
    end = chrono::steady_clock::now();
    timeUsingMaxFib += end - start;
  }
  timeUsingMaxFib /= 10;
  printf("3) Time to find the max fib in 1): %0.8f s\n",timeUsingMaxFib.count());
  
  //4. How much time does it take to find the number by calling fibRecursion and using the index found in 2) as the parameter?

  start = chrono::steady_clock::now();
  fibRecursion(indexLargest);
  end = chrono::steady_clock::now();
  chrono::duration<double> timeUsingFibRecursion = end - start;
  cout << "4) Time to find the max fib in 1) using recursion: " << timeUsingFibRecursion.count() << "s\n";

  //5. What is the value if you call fibUsingFormula with the index found in 2)?

  double largestWithFormula = fibUsingFormula(indexLargest);
  printf("5) Value using Binet's formula with the index found in 2) : %.0f\n",largestWithFormula);
}

int maxFib(int upperBound){
  // Returns the largest Fibonacci number that is less than or equal to the upperBound. For this use loops
  if(upperBound <= 0){
    return 0;
  }
  int fib = 1;         // Fn
  int fibPrev = 1;     // Fn-1
  int fibPrevPrev = 0; // Fn-2
  // Currently goes past max integer and into negatives
  while(fib < upperBound && fib > 0){
    fibPrev = fib;
    fib = fibPrev + fibPrevPrev;
    fibPrevPrev = fibPrev; 
  }
  if(fib <= upperBound && fib != INT_MAX && fib >= 0){
    return fib;
  }
  return fibPrev;
}

int indexOfFib(int fibNum){
  // Returns the index of fibNum which is a number in the Fibonacci sequence. The index starts with 0, so the index of 2 is 3.
  int index = 0;
  if(fibNum == 0){
    return 0;
  }
  index++;
  int fib = 1;          //Fn
  int fibPrev = 1;      //Fn-1
  int fibPrevPrev = 0;  //Fn-2
  while(fib < fibNum && fib > 0){
    fibPrev = fib;
    fib = fibPrev + fibPrevPrev;
    fibPrevPrev = fibPrev;
    index++;
  }
  if(fib == fibNum){
    return index;
  }
  cout << "The number given, " << fibNum << ", is not a number in the Fibonacci sequence.\n";
  return -1;
}

int fibRecursion(int index){
  // Returns the number in the Fibonacci sequence with the given index. The function should be written using recursion
  if(index == 0){
    return 0;
  }
  return index <= 2? 1 : fibRecursion(index - 1) + fibRecursion(index - 2);
}

double fibUsingFormula(int index){
  // Returns the number in the Fibonacci sequence with the given index, using Binet's formula
  return (pow((1+sqrt(5))/2,index) - pow((1-sqrt(5))/2,index)) / sqrt(5);
}
