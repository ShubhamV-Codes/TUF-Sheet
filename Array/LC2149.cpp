#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int>ans(nums.size());
        int even = 0;
        int odd = 1;

        for(int i =0;i<nums.size();i++){
            if(nums[i]>0){
                ans[even]=nums[i];
                even += 2;
            }else{
                ans[odd]=nums[i];
                odd += 2;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,1,-2,-5,2,-4};
    vector<int>ans = s.rearrangeArray(nums);    
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}