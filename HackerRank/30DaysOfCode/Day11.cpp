// Day 11: 2D Array
#include <bits/stdc++.h>

using namespace std;

int hourglassIt(int i, int j, vector<vector<int>> arr) 
{
    int hourglassSum = 0;

    hourglassSum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                   arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] +
                   arr[i + 2][j + 2];

    return hourglassSum;
}

void largestHourglass(vector<vector<int>> arr)
{
    int sum;
    int temp;

    for(int i = 0; i < arr.size() - 2; i++) {
        for(int j = 0; j < arr.size() - 2; j++) {
            temp = hourglassIt(i, j, arr);
            if( i == 0 && j == 0) {
                sum = temp;
            }
            if(temp > sum) {
                sum = temp;
            }
        }
    }

    cout << sum << endl;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }



    largestHourglass(arr);

    return 0;
}
