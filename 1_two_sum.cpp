class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp_nums = nums;
        sort(temp_nums.begin(), temp_nums.end());
        int ptr1 = 0;
        int ptr2 = temp_nums.size() - 1;
        while(temp_nums[ptr1] + temp_nums[ptr2] != target && ptr1 != ptr2){
            if(temp_nums[ptr1] + temp_nums[ptr2] > target){
                ptr2--;
            }
            else{
                ptr1++;
            }
        }
        int first = temp_nums[ptr1];
        int second = temp_nums[ptr2];
        int first_index = -1, second_index = -1;
        for(int i = 0; i < temp_nums.size(); i++){
            if(nums[i] == first && first_index == -1){
                first_index = i;
            }
            else if(nums[i] == second && second_index == -1){
                second_index = i;
            }
            else if(first_index != -1 && second_index != -1){
                break;
            }
        }
        vector<int> ans;
        ans.push_back(first_index);
        ans.push_back(second_index);
        return ans;
    }
};