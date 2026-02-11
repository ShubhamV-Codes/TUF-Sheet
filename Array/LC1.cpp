#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        if (arr.empty()) return {};

        vector<pair<int,int>> values;
        for (int i = 0; i < arr.size(); i++) {
            values.push_back({arr[i], i});
        }

        sort(values.begin(), values.end());

        int left = 0, right = values.size() - 1;

        while (left < right) {
            int sum = values[left].first + values[right].first;

            if (sum == target) {
                return {values[left].second, values[right].second};
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    Solution s;
    vector<int> arr = {2, 7, 9, 15};
    int target = 11;

    vector<int> result = s.twoSum(arr, target);

    for (int x : result) cout << x << " ";
    return 0;
}
