class Solution {
public:
    string defangIPaddr(string address) {
        string defangedAddress = "";
        
        for(int i = 0; i < address.length(); i++) {
            if(address[i] == '.') {
                defangedAddress += "[.]";
            } else {
                defangedAddress += address[i];
            }
        }
        
        return defangedAddress;
    }
};