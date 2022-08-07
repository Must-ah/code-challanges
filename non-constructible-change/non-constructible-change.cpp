#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <iostream>
using std::cout;
using std::endl;

int nonConstructibleChange(vector<int> coins)
{
    sort(coins.begin(), coins.end());

    int accumulated_sum = 0;
    int minimum_non_constructible_change = accumulated_sum + 1;
    for (int coin : coins)
    {
        if (coin > minimum_non_constructible_change)
        {
            return minimum_non_constructible_change;
        }
        accumulated_sum += coin;
        minimum_non_constructible_change = accumulated_sum;
        minimum_non_constructible_change += 1;
    }

    return minimum_non_constructible_change;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int minimum_non_constructible_change = nonConstructibleChange(coins);
    cout << minimum_non_constructible_change << endl;
    coins = {1, 1, 2, 3, 5, 7, 22};
    minimum_non_constructible_change = nonConstructibleChange(coins);
    cout << minimum_non_constructible_change << endl;
    return 0;
}