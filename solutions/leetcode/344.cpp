class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size()/2; i++) {
            char letter = s[i];
            int mirror_index = (s.size() - i) - 1; 
            s[i] = s[abs(mirror_index)];
            s[abs(mirror_index)] = letter;
        }     
    }
};