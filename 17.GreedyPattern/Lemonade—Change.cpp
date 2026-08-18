#include <iostream>
#include <vector>
using namespace std;
bool leamonade(vector<int> &bills)
{
    int n = bills.size();
    int five = 0;
    int ten = 0;
    for (int i = 0; i < n; i++)
    {
        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
        {
            if (five == 0)
                return false;
            else
            {
                five--;
                ten++;
            }
        }
        else
        {
            if (ten > 0)
            {
                ten--;
                if (five == 0)
                    return false;
                five--;
            }
            else
            {
                if (five < 3)
                    return false;

                five = five - 3;
            }
        }
    }
    return true;
}
int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    cout << leamonade(bills);
    return 0;
}