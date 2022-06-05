# What is Between?

Complete the function that takes two integers (a, b, where a < b) and return an array of all integers between the input parameters, including them.

For example:

```C++
a = 1
b = 4
answer --> [1, 2, 3, 4]

```


## Solution

```C++
#include <vector>
#include <numeric>
std::vector<int> between(int start, int end) 
{
  std::vector<int> vec(end - start + 1);
  std::iota(vec.begin(), vec.end(), start);
  return vec;
}

```
