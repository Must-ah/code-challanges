
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

