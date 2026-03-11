#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int j = 1;
        int unique = 1;

        while (j < nums.size())
        {
            if (nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                swap(nums[i + 1], nums[j]);
                i++;
                j++;
                unique++;
            }
        }
        return unique;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 2};

    int k = obj.removeDuplicates(nums);   // store return value

    cout << "Unique elements count: " << k << endl;

    cout << "Modified array: ";
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
        //O(n)->Time Complexity
        //O(1)=>Space Complexity
    return 0;
}