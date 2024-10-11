#include <iostream>
#include <vector>
using namespace std;

bool checkRotatedSorted(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) ++count;
    }
    if (nums[n - 1] > nums[0]) ++count;
    return count <= 1;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    bool isRotatedSorted = checkRotatedSorted(nums);
    cout << "Array is rotated and sorted: " << (isRotatedSorted ? "Yes" : "No") << endl;
    return 0;
}
