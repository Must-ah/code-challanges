# Basic Roman Numerals

Have the function BasicRomanNumerals(str) read str which will be a string of Roman numerals. The numerals being used are: I for 1, V for 5, X for 10, L for 50, C for 100, D for 500 and M for 1000. In Roman numerals, to create a number like 11 you simply add a 1 after the 10, so you get XI. But to create a number like 19, you use the subtraction notation which is to add an I before an X or V (or add an X before an L or C). So 19 in Roman numerals is XIX.

The goal of your program is to return the decimal equivalent of the Roman numeral given. For example: if str is "XXIV" your program should return 24

```C++

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string BasicRomanNumerals(string str) {
  // code goes here

  unordered_map<char,int> roman_numerals = {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
  };
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

int main(void) { 
   
  // keep this function call here
  string twenty_four = "XXIV";
  cout << BasicRomanNumerals(twenty_four);
  return 0;
    
}

´´´
