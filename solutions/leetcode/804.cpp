class Solution {
public:
    map<char, string> morse_alphabet = {
        {'a', ".-"},
        {'b', "-..."},
        {'c', "-.-."},
        {'d', "-.."},
        {'e', "."},
        {'f', "..-."},
        {'g', "--."},
        {'h', "...."},
        {'i', ".."},
        {'j', ".---"},
        {'k', "-.-"},
        {'l', ".-.."},
        {'m', "--"},
        {'n', "-."},
        {'o', "---"},
        {'p', ".--."},
        {'q', "--.-"},
        {'r', ".-."},
        {'s', "..."},
        {'t', "-"},
        {'u', "..-"},
        {'v', "...-"},        
        {'w', ".--"},
        {'x', "-..-"},        
        {'y', "-.--"},        
        {'z', "--.."}
    };

    int uniqueMorseRepresentations(vector<string>& words) {
                
        set<string> different_transformations;
        
        for(int i = 0; i < words.size(); i++) {
            string morse_code = "";
            for(int j = 0; j < words[i].length(); j++) {
                morse_code += morse_alphabet[words[i][j]];
            }
            different_transformations.insert(morse_code);
        }

        return different_transformations.size(); 
    }
};