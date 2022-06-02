# Two Number Sum

Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. If any two numbers in the input array sum
up to the target sum, the function should return them in an array, in any
order. If no two numbers sum up to the target sum, the function should return
an empty array.

Note that the target sum has to be obtained by summing two different integers
in the array; you can't add a single integer to itself in order to obtain the
target sum.

You can assume that there will be at most one pair of numbers summing up to
the target sum.

**Sample input**

```C++
array =  = [3, 5, -4, 8, 11, 1, -1, 6]
target_sum = 10
```

**Sample output**

```C++
[-1, 10]
```

## Solution

```C++
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
 
 unordered_set<int> look_up_table;
 for (const auto& elem : array)
 {
  int rest = targetSum - elem;
  auto search = look_up_table.find(rest);
  if (search != look_up_table.end())
  {
   return {elem, rest};
  }
  else
  {
   look_up_table.insert(elem);
  }
  
 }
  return {};
}

```
