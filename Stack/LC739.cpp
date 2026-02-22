#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int>warmerDays(vector<int>temperatures){
    int n = temperatures.size();
    vector<int>result(n);
    stack<int>st;
    //Initialize these result and stack with intial values
    result[n-1]=0;
    st.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
            st.pop();
        }
        if(st.empty()){
            result[i]=0;
        }else{
            result[i]=st.top()-i;
        }
        st.push(i);
    }
    return result;
}

int main(){
    vector<int>temperatures={73, 74, 75, 71, 69, 72, 76, 73};
    vector<int>solution = warmerDays(temperatures);
    for(int i=0;i<solution.size();i++){
        cout<<solution[i] << " " ;
    }
    return 0;
}

// DONE