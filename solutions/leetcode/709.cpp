class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.length(); i++) {
            if(isupper(str[i])) {
                str[i] = tolower(str[i]);
            }
        }
        
        return str;
    }
};