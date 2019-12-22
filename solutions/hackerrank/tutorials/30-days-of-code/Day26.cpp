// Day 26: Nested Logic
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int fine = 0;
  int actualDay, actualMonth, actualYear, expectedDay, expectedMonth,
      expectedYear;

  cin >> actualDay;
  cin >> actualMonth;
  cin >> actualYear;
  cin >> expectedDay;
  cin >> expectedMonth;
  cin >> expectedYear;

  if(actualYear > expectedYear) {
      fine = 10000;
  } else if (actualYear == expectedYear) {
      if((expectedMonth == actualMonth) && (actualDay > expectedDay)) {
        fine = (actualDay - expectedDay) * 15;
      } else if (expectedMonth < actualMonth) {
        fine = (actualMonth - expectedMonth) * 500;
      }
  }

  cout << fine;

  return 0;
}
