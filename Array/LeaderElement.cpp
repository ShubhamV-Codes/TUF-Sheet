#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> findLeader(int arr[], int n){
    stack<int>s;
    int prev = arr[n-1];
    s.push(prev);

    for(int i=n-2;i>=0;i--){
        if(arr[i]>prev){
            s.push(arr[i]);
            prev = arr[i];
        }
    }
    return s;

}

int main(){
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> leaders = findLeader(arr, n);

    while(leaders.size()>0){
        cout << leaders.top() << " ";
        leaders.pop();
    }

    return 0;


    

    
}