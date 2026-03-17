#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int guess)
{
    int n = stalls.size();
    int cows = 1;
    int prevPos = stalls[0];
    for(int i=1; i<n;i++){
        int dist = stalls[i]-prevPos;
        if(dist<guess)continue;
        cows++;
        prevPos = stalls[i];
    }
    if(cows>=k){
        return true;
    }else{
        return false;
    }
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9, 3, 5, 22};
    int k = 3;
    int low = 1;
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int high = stalls[n - 1] - stalls[0];
    int res = -1;;

    while (low <= high)
    {
        int guess = low + (high - low) / 2;
        if (isPossible(stalls, k, guess)){
            res = guess;
            low = guess+1;

            }
        else{
            high = guess-1;
        }
    }
    cout<< res;
    return 0;

}