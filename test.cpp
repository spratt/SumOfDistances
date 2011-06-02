#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "SumOfDifferences.h"

using namespace std;

const int MAX_RAND = 3;

int main(int argv, char** argc) {
  time_t before, after;
  int result;
  // Seed the random number generator
  srand( time(0) );
  /////////////////////////////////////////////////////////////////////////////
  // Build a sorted vector of points                                         //
  /////////////////////////////////////////////////////////////////////////////
  int n = 1000;
  if(argv > 1)
    n = atoi(argc[1]);
  vector<int> v;
  int last = 0;
  for(int i = 0; i < n; i++) {
    int num = last + (rand() % (1+MAX_RAND));
    if(n < 10) {
      if(i == 0)
	cout << num;
      else
	cout << "," << num;
    }
    v.push_back(num);
    last = num;
  }
  cout << endl;
  /////////////////////////////////////////////////////////////////////////////
  // Neat algorithm O(n)                                                     //
  /////////////////////////////////////////////////////////////////////////////
  before = time(0);
  result = SumOfDifferences::neatSum<int>(v);
  after = time(0);
  cout << "Neat:  " << result << endl
       << "Took:  " << (before-after) << endl;
  /////////////////////////////////////////////////////////////////////////////
  // Naiive algorithm O(n^2)                                                 //
  /////////////////////////////////////////////////////////////////////////////
  before = time(0);
  result = SumOfDifferences::naiveSum<int>(v);
  after = time(0);
  cout << "Naive: " << result << endl
       << "Took:  " << (before-after) << endl;
  return 0;
}
