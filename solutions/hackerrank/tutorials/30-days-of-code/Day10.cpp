// Day 10: Binary Numbers
#include <bits/stdc++.h>

using namespace std;

int consecutive_count(int decimal_n) {
    int count = 0;
    int temp = 0;
    while(decimal_n > 0) {
        int remainder = decimal_n % 2;
        decimal_n = decimal_n/2;

        if(remainder == 1) {
            temp += 1;
            if(temp > count) {
                count = temp;
            }
        } else {
            temp = 0;
        }

    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << consecutive_count(n) << endl;

    return 0;
}

