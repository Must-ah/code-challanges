#include <string>
#include <algorithm>
#include <unordered_map>
using std::unordered_map;

std::string DNAStrand(const std::string& dna)
{
  unordered_map<char,char> DNA_symbols {
    {'T','A'},
    {'A','T'},
    {'C','G'},
    {'G','C'}
  };
  std::string dna_copy = dna;
  if (dna.empty())
  {return dna;}
  std::transform(dna_copy.begin(),dna_copy.end(), dna_copy.begin(),
              [&DNA_symbols](unsigned char c) -> unsigned char 
              {
                auto search = DNA_symbols.find(c);
                if (search != DNA_symbols.end()){return search->second;}                  
              }
          );
  return dna_copy;
}