# Sorted Squared Array

Write a function that takes in a non-empty array of integers that are sorted
in ascending order and returns a new array of the same length with the squares
of the original integers also sorted in ascending order.

**Sample input**

```C++
array  = [1, 2, 3, 5, 6, 8, 9]
```

**Sample output**

```C++
array  = [1, 4, 9, 25, 36, 64, 81]
```

## Solution

```C++
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
 vector<int> square;
 square.reserve(array.size());
 for_each(begin(array),end(array),[&square](const int& elem){int sq = elem*elem;
                               square.push_back(sq);
                               }
     );
 sort(begin(square),end(square));
 square.shrink_to_fit();
  return square;
}

```
