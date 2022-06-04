# Complementary DNA

Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.

If you want to know more: http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You function receives one side of the DNA (string, except for Haskell); you need to return the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

**Example: (input --> output)**

```C++

"ATTGC" --> "TAACG"
"GTAT" --> "CATA"

```

## Solution

```C++
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

```
