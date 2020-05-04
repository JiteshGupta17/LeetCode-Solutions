class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        if(!n) return 0;
        
        int m = matrix[0].size();
        
        // Start from top right most corner
        int vertical = m-1;
        int horizontal = 0;
        
        while(vertical >=0 && horizontal < n)
        {
            int cur_ele = matrix[horizontal][vertical];
            if(cur_ele == target) return true;
            
            if(cur_ele > target) vertical--;
            else horizontal++;
        }
        
        return false;
    }
};
