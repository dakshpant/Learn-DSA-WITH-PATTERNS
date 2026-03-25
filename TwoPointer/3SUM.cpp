#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size() - 2; i++) {

            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets with sum 0:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    // Time Complexity: O(n^2)
    // Space Complexity: O(1) (excluding result storage)

    return 0;
}