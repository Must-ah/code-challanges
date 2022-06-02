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
  // Write your code here.
  unordered_map<string, int> teams;
  size_t idx = 0;
  int win_score = 3;
  string highest_score_team;
  int highest_score = 0;
  bool first_time = true;
  
  for (auto const& comp : competitions)
    {
      int win_team_idx = results.at(idx) == 0 ? 1 : 0;      
      string win_team = comp.at(win_team_idx);
      auto search = teams.find(win_team);
      if (search != teams.end())
      {
        search->second +=win_score;
        if (search->second > highest_score)
        {
          highest_score_team = search->first;
          highest_score = search->second;
        }
      }
      else
      {
        teams.insert({win_team, win_score});
        if (first_time)
        {
          first_time = false;
          highest_score_team = win_team;
          highest_score = win_score;          
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
   
  return highest_score_team;
}
