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