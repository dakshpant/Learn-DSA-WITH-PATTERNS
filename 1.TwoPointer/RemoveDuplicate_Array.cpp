#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // Edge case
        if (nums.size() == 0) return 0;

        int i = 0; // pointer for unique elements

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j]; // overwrite instead of swap
            }
        }
        return i + 1; // count of unique elements
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 1, 2};

    int k = obj.removeDuplicates(nums);

    cout << "Unique elements count: " << k << endl;

    cout << "Modified array: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return 0;
}