#include <vector>
#include <numeric>

std::vector<int> between(int start, int end) 
{
  std::vector<int> vec(end - start + 1);
  std::iota(vec.begin(), vec.end(), start);
  return vec;
}
