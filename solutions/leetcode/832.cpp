class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        // Reverse
        for(int i = 0; i < A.size(); i++) { 
            for(int j = 0; j < A[i].size() / 2; j++){
                int current_binary_number = A[i][j];
                
                int index = (A[i].size() - j) - 1;
                A[i][j] = A[i][abs(index)];
                A[i][abs(index)] = current_binary_number;
            }
        }
        
        // Invert
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                switch(A[i][j]) {
                    case 0:
                        A[i][j] += 1;
                        break;
                    case 1:
                        A[i][j] -= 1;
                        break;
                }
            }
        }
        
        return A;
    }
};