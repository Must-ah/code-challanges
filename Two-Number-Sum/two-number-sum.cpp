#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    unordered_set<int> look_up_table;
    for (const auto &elem : array)
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
