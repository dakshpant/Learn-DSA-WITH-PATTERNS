#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
int fruitBasket(vector<int> &fruits){
    int low = 0;
    int high = 0;
    int res = INT_MIN;
    unordered_map<int, int> basket;
    while(high < fruits.size()){
        basket[fruits[high]]++;
        while (basket.size() > 2)
        {
            basket[fruits[low]]--;
            low++;
            if(basket[fruits[low-1]]==0){
                basket.erase(fruits[low-1]);
            }
        }
        /*since we want at most 2 baskets to be filled
        means can fill both or 1 baker 
        =>window size == 2 or < 2
        */
       int len = high - low + 1;
       res = max(res, len);
       high ++;
    }
    return res;
}
int main(){
    vector<int> fruits = {1,2,0,1,2,2};//ans is 3 think of it for later
    int ans = fruitBasket(fruits);
    cout<< ans << endl;
    return 0;
}