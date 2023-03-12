#include <iostream>

// The Fibonacci Sequence is 0,1,1,2,3,5,8
// F0 = 0, F1 = 1, and Fn = Fn-1 + Fn-2

using namespace std;

int main(){
  int maxFib(int upperBound);
  int indexOfFib(int fibNum);
  int fibRecursion(int index);
  double fibUsingFormula(int index);
  
  //1. What is the max Fibonacci number that is less than the max integer that can be represented in C++? (call maxFib)
  int largestFib = maxFib(INT_MAX);
  cout << "The maximum Fibonacci number less than the max integer is: " << largestFib << "\n";
  //2. What is the index of the above number? (call indexOfFib)
  //int indexLargest = indexOfFib(largestFib);
  int index5 = indexOfFib(5);
  cout << "Index of 5: " << index5 << "\n";
  //3. How much time does it take to find the number in 1) ? use the appropriate methods from the library

  //4. How much time does it take to find the number by calling fibRecursion and using the index found in 2) as the parameter?
  cout << fibRecursion(11) << "\n";
  //5. What is the value if you call fibUsingFormula with the index found in 2)?

}

int maxFib(int upperBound){
  //returns the largest Fibonacci number that is less than or equal to the upperBound. For this use loops
  if(upperBound <= 0){
    return 0;
  }
  int fib = 1;     // Fn
  int fibPrev = 1;     // Fn-1
  int fibPrevPrev = 0; // Fn-2
  //currently goes past max integer and into negatives
  while(fib < upperBound && fib > 0){
    fibPrev = fib;
    fib = fibPrev + fibPrevPrev;
    cout << fib << "\t" << fibPrev << "\t" << fibPrevPrev << "\n";
    fibPrevPrev = fibPrev; 
    
  }
  if(fib <= upperBound && fib != INT_MAX && fib >= 0){
    return fib;
  }
  return fibPrev;
}

int indexOfFib(int fibNum){
  //returns the index of fibNum which is a number in the Fibonacci sequence. The index starts with 0, so the index of 2 is 3.

}

int fibRecursion(int index){
  //returns the number in the Fibonacci sequence with the given index. The function should be written using recursion
  if(index == 0)
    return 0;
  return index <= 2? 1 : fibRecursion(index - 1) + fibRecursion(index - 2);

}

double fibUsingFormula(int index){
  //returns the number in the Fibonacci sequence with the given index, the computation is using the following formula:
  // Fn = [(1+sqrt(5)^n / 2^n) - (1-sqrt(5))^n / 2^n] / sqrt(5)


}
