#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int minElement = findMin(nums);
    cout << "Minimum element is " << minElement << endl;
    return 0;
}
