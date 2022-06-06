# Counting Duplicates

Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

**Example**

```go

"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice

```

## Solution

```go

import "strings"
var m map[string]int 

func duplicate_count(s1 string) int {
  m = make(map[string]int)  
  slicedStr := strings.Split(s1,"")
  sum :=0
    for idx, s := range slicedStr {
      _, ok := m[s]
      if !ok {
        number:= strings.Count(s1[idx+1:], s) + strings.Count(s1[idx+1:], strings.ToUpper(s))
        if number > 0 {
          sum++
          m[s] = 0
        }
      }
    }
  return sum 
}

```
