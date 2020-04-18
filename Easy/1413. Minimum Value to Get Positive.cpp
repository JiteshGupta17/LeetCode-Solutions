class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum = 0;
        int mini = INT_MAX;
        for(int ele : nums){
            sum += ele;
            mini = min(mini,sum);
        }
        
        return mini > 0 ? 1 : -mini + 1;
    }
};
