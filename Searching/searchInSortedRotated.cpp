#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findpivot(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        if (nums.size() <= 1) return -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && nums[mid] > nums[mid + 1]) return mid;
            if (mid > start && nums[mid - 1] > nums[mid]) return mid - 1;

            if (nums[start] >= nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findpivot(nums);

        if (pivot == -1) return binarySearch(nums, 0, nums.size() - 1, target);
        if (nums[pivot] == target) return pivot;

        if (target >= nums[0])
            return binarySearch(nums, 0, pivot - 1, target);
        else
            return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }
};

int main() {


    vector<int> nums{4,5,6,0,1,2,3,4,5};
    int target;
    cin >> target;

    Solution ob;

    int pivot = ob.findpivot(nums);
    cout << "Pivot index: " << pivot << endl;
    if (pivot != -1) {
        cout << "Pivot element: " << nums[pivot] << endl;
    }

    int result = ob.search(nums, target);
    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl;
    } else {
        cout << "Target " << target << " not found" << endl;
    }

    return 0;
}
