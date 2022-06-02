# Tournament Winner

There's an algorithms tournament taking place in which teams of programmers compete against each other to solve algorithmic problems as fast as possible. Teams compete in a round robin, where each team faces off against all other teams. Only two teams compete against each other at a time, and for each competition, one team is designated the home team, while the other team is the away team. In each competition there's always one winner and one loser; there are no ties. A team receives 3 points if it wins and 0 points if it loses. The winner of the tournament is the team that receives the most amount of points.
Given an array of pairs representing the teams that have competed against each other and an array containing the results of each competition, write a function that returns the winner of the tournament. The input arrays are named competitions and results, respectively. The competitions array has elements in the form of **[homeTeam, awayTeam]**, where each team is a string of at most 30 characters representing the name of the team. The results  array contains information about the winner of each corresponding competition in the competitions  array. Specifically, results[i] denotes the winner of competitions[i], where a 1 in the results array means that the home team in the corresponding competition won and a 0 means that the away team won.

It's guaranteed that exactly one team will win the tournament and that each
team will compete against all other teams exactly once. It's also guaranteed
that the tournament will always have at least two teams.

**Sample input**

```C++
competitions = [
  ["HTML", "C#"],
  ["C#", "Python"],
  ["Python", "HTML"],
]

results = [0, 0, 1]
```

**Sample output**

```C++
"Python"
```

## Solution

```C++
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <unordered_map>
using std::unordered_map;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string, int> teams;
  size_t idx = 0;
  int win_score = 3;
  string higest_score_team;
  int higest_score = 0;
  bool first_time = true;
  
  for (auto const& comp : competitions)
    {
      int win_team_idx = results.at(idx) == 0 ? 1 : 0;      
      string win_team = comp.at(win_team_idx);
      auto search = teams.find(win_team);
      if (search != teams.end())
      {
        search->second +=win_score;
        if (search->second > higest_score)
        {
          higest_score_team = search->first;
          higest_score = search->second;
        }
      }
      else
      {
        teams.insert({win_team, win_score});
        if (first_time)
        {
          first_time = false;
          higest_score_team = win_team;
          higest_score = win_score;          
        }
       }     
      
      ++idx;      
    }
  
  /*
  for (auto const& [current_team, score] : teams)
    {
      cout<< current_team
        << " | "
        << score
        <<endl;
      
    }
  */
   
  return higest_score_team;
}

```
