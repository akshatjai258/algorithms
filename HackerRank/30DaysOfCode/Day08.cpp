// Day 08: Dictionaries and Maps

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    int pos;
    string input;
    string name;
    string phone_number;
    string names;
    map<string,string> phone_book;

    getline(cin, input);
    n = stoi(input);

    for(int i = 0; i < n; i++) {
        getline(cin, input);
        pos = input.find(" ");
        name = input.substr(0, pos);
        phone_number = input.substr(pos+1);
        phone_book.insert(pair<string,string>(name,phone_number));
    }


    while(cin >> names) {
        map<string,string>::const_iterator i = phone_book.find(names);
        if(i != phone_book.end())
        cout << i->first << "="  << i->second << endl;
        else
        cout << "Not found" << endl;
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

