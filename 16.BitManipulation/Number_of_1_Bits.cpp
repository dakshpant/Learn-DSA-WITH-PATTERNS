#include <iostream>
using namespace std;
int hammingWeight(int n)
{
    int res = 0;
    // method 1
    // while (n > 0)
    // {
    //     int bit = n % 2;
    //     if (bit == 1)
    //         res++;

    //     n = n / 2;
    // }

    // Method 2 :  Using Kerninighan's Algo

    while (n > 0)
    {
        res++;
        n = n & (n - 1);
    }

    return res;
}
int main()
{
    int n = 11;
    cout << hammingWeight(n);
    return 0;
}