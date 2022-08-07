# Non-constructible-change


Given an array of positive integers representing the values of coins in your
possession, write a function that returns the minimum amount of change (the
minimum sum of money) that you **cannot** create. The given coins can have
any positive integer value and aren't necessarily unique (i.e., you can have
multiple coins of the same value).

For example, if you're given *coins = [1, 2, 5]* , the minimum amount of change that you can't create is **4**.

```C++
#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

int nonConstructibleChange(vector<int> coins) {  
  sort(coins.begin(), coins.end());

  int accumulated_sum = 0;
  int minimum_non_constructible_change = accumulated_sum +1;
  for (int coin : coins)
    {
      if (coin > minimum_non_constructible_change)
      {       
        return minimum_non_constructible_change;
      }
      accumulated_sum +=coin;
      minimum_non_constructible_change = accumulated_sum;
      minimum_non_constructible_change += 1;    
    }
  
  return minimum_non_constructible_change;
}

```