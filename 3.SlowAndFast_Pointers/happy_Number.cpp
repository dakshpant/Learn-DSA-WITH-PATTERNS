#include <iostream>
using namespace std;
int digiSum(int n){
int sum = 0;
while(n > 0){
    int d = n%10;
    n = n/10;
    sum += d*d;//sum+d*d
}
return sum;
}
bool isHappy(int n){
    int slow = n;
    int fast = n;
    while(fast != 1){
        slow = digiSum(slow);
        fast = digiSum(digiSum(fast));
        if(slow == fast && slow != 1){
             //slow == fast = cycle and != 1 means cycle to hae but koi 1 nhi bana hae
             return false;
        }
    }
    return true;
}
int main(){
    int n =2;//19 will give true
    bool ans = isHappy(n);
    if(ans == false){
        cout<<n << "is not a happy number"<< ans << endl;
        return 0;
    }else cout<<n << "is a happy number"<<ans<<endl;
    return 0;
}