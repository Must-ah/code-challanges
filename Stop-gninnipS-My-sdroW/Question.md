# Stop gninnipS My sdroW!

Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

Examples: spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" spinWords( "This is a test") => returns "This is a test" spinWords( "This is another test" )=> returns "This is rehtona test"

## Solution

```C++
#include <regex>
#include <iterator>
#include <iostream>
#include <string>
 
std::string spinWords(const std::string &str)
{
  std::regex words_regex("[^\\s]+");
    auto words_begin = 
      std::sregex_iterator(str.begin(), str.end(), words_regex);
    auto words_end = std::sregex_iterator();
  std::string temp = "";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;                                                 
        std::string match_str = match.str();
      if (match_str.size()>4)
        {std::reverse(std::begin(match_str), std::end(match_str));}
      temp.append(match_str);
      temp.append(" ");
  }
  temp.pop_back();
  return temp;
}
```
