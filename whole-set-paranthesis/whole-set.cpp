#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set;

#include <utility>
using std::pair;

#include <assert.h>

bool correct_set(string str_in)
{
    if (str_in.empty())
    {
        return false;
    }
    vector<char> characters_so_far;
    unordered_map<char, char> paired_parentheses{
        {')', '('},
        {']', '['},
        {'}', '{'}};
    unordered_set<char> allowed_characters{'{', '[', '('};
    for (auto const &elem : str_in)
    {
        if (allowed_characters.contains(elem))
        {
            characters_so_far.push_back(elem);
        }
        else
        {
            auto search = paired_parentheses.find(elem);
            if (search == paired_parentheses.end() || characters_so_far.size() == 0)
            {
                return false;
            }
            else
            {
                bool last_elem_is_closed = characters_so_far.back() == search->second;
                if (last_elem_is_closed)
                {
                    characters_so_far.pop_back();
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return characters_so_far.size() == 0;
}

int main(void)
{
    vector<pair<string, bool>> test_cases{
        {"((()))", true},
        {")()()()()()", false},
        {"((())))", false},
        {"()()()()()", true},
        {"hj", false},
        {"{}", true},
        {"()(())((()))(())()", true},
        {"}{", false},
        {")(", false},
        {"][", false},
        {"123", false},
        {"(])", false},
        {"[(]", false},
        {"{)}", false},
        {"", false},
        {"{}[]()", true}};
    for (auto const &[str_out, ground_truth] : test_cases)
    {
        bool is_correct = correct_set(str_out);
        cout << std::boolalpha
             << is_correct
             << endl;

        assert(ground_truth == is_correct);
    }
    return 0;
}