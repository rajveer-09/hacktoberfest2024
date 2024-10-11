#include <iostream>
#include <vector>
using namespace std;

int countRotations(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    int rotations = countRotations(nums);
    cout << "Array has been rotated " << rotations << " times." << endl;
    return 0;
}
