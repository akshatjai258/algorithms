class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int number_of_even_digits_number = 0;
        
        for(int i = 0; i < nums.size(); i++) {        
            int number_of_digits = 0;
            
            while(nums[i] > 0) {
                nums[i] /= 10;
                number_of_digits++;
                
            }
            
            if(number_of_digits % 2 == 0) {
                number_of_even_digits_number++;
            }
        }
        return number_of_even_digits_number;
    }
};