#include<iostream>
#include<algorithm>
#include<vector>
#include <iterator>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0 ;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0 ){
                candidate = nums[i];
            }
            count += (candidate==nums[i]) ? 1:-1;
        }
        return candidate;   
    }

};

int main(){
    Solution S ;
    vector<int> nums = {2,2,1,1,1,2,2,1,2,2,2,22,1,2,1};
    cout<<S.majorityElement(nums)<<endl;    
    return 0;
}