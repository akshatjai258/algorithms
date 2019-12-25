class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> array_sorted;
        for(int i = 0; i < A.size(); i++){
            if(A[i] % 2 == 0) {
                array_sorted.insert(array_sorted.begin(), A[i]);
            } else {
                array_sorted.push_back(A[i]);
            }
        }
        return array_sorted;
    }
};