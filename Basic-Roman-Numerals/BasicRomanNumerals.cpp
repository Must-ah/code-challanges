#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string BasicRomanNumerals(string str)
{
    // code goes here

    unordered_map<char, int> roman_numerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    reverse(begin(str), end(str));
    int old_value = -1;
    int value = 0;
    bool first_time = true;
    for (auto elem : str)
    {
        auto search = roman_numerals.find(elem);
        auto found = search != roman_numerals.end();

        if (found)
        {
            if (first_time)
            {
                value = search->second;
                first_time = false;
            }
            else if (search->second < old_value)
            {
                value -= search->second;
            }
            else
            {
                value += search->second;
            }

            old_value = search->second;
        }
    }

    return to_string(value);
}

int main(void)
{

    string twenty_four = "XXIV";
    cout << BasicRomanNumerals(twenty_four);
    return 0;
}