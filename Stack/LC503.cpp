#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>nextGreaterCircular(vector<int>nums){
    int n=nums.size();
    vector<int>result(n);
    stack<int>st;

    for(int i=n-2;i>=0;i--){
        st.push(nums[i]);
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            result[i]=-1;
        }else{
            result[i]=st.top();
        }
        st.push(nums[i]);
    }
    return result;
}

int main(){
    vector<int>nums={1, 2, 3, 4, 3};
    vector<int>solution = nextGreaterCircular(nums);
    for(int i=0; i<solution.size();i++){
        cout<< solution[i]<<" ";
    }
    return 0;
}