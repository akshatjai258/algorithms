// Day 06: Let's Review
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getNewString(string word) {
    string even_string = "";
    string odd_string = "";
    
    for(int i = 0; i < word.length(); i++){
        if(i % 2 == 0){
            even_string += word.at(i);
        }else {
            odd_string += word.at(i);
        }
    }
    
    cout << even_string << " " << odd_string << endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int words_count;
    string words_to_convert;
    
    cin >> words_count;
    
    for (int i = 0; i < words_count; i++){
        cin >> words_to_convert;
        getNewString(words_to_convert);
    }
    
    return 0;
}
