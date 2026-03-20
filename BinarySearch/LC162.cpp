#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid + 1]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}