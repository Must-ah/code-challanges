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
