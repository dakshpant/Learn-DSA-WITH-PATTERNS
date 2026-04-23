#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Using Dutch National Algo and 2 Pointes
// void sortedColors(vector<int>& nums){
// int low = 0;
// int mid = 0;
// int high = nums.size() - 1;
// while (mid <= high)
// {
//     if(nums[mid] == 0){
//         swap(nums[mid], nums[low]);
//         mid ++;
//         low ++;
//     }else if(nums[mid] == 1){
//         mid ++;
//     }else{
//         swap(nums[mid], nums[high]);
//         high --;
//     }
// }
// }
//Optimal Solution

void sortedColors(vector<int>& nums){
    int size = nums.size();
    int ones = 0; int twos = 0; int zeros = 0;
    for(int i = 0; i < size; i++){
        if(nums[i]==0) zeros++;
        else if(nums[i]==1) ones++;
        else twos++;
    }
    int index = 0;
    for(int i = 0; i < zeros; i++){
        nums[index] = 0;
        index++;
    }
    while(ones--){
        nums[index] = 1;
        index++;
    }
    while(twos--){
        nums[index] = 2;
        index++;
    }

}
int main(){
vector<int> nums = {2,0,2,1,1,0};
sortedColors(nums);
for(int x : nums){
    cout<< x << " ";
}
}