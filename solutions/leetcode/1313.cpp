class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        std::vector<int> new_array;
        

        for (int i = 0; i <= (nums.size() - 2); i+=2) {
            int frequency = nums[i];
            int value = nums[i+1];
            
            for (int j = 0; j < frequency; j++) {
                new_array.push_back(value);
            }            
        }
        
        
        
        return new_array;
        
    }
};