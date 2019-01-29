#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  int l1 = str1.length();
  int l2 = str2.length();

  std::vector<std::vector<int>> D(l2+1, std::vector<int>(l1+1));

  for(int j = 0; j <= l2; j++)
    {
      D[0][j] = j;
    }
  for(int i = 0; i <= l1; i++)
    {
      D[i][0] = i;
    }


  for(int j = 1; j <=l2 ; j++)
    {
      int ins_score = INT_MAX;
      int del_score = INT_MAX;
      int match_score = INT_MAX;
      int mismatch_score = INT_MAX;
	
	for(int i = 1; i <= l1; i++)
	{
	  ins_score = D[i][j - 1] + 1;
	  del_score = D[i - 1][j] + 1;
	  match_score = D[i - 1][j - 1];
	  mismatch_score = D[i - 1][j - 1] + 1;

	  if(str1[i - 1] == str2[j - 1])
	    D[i][j] = std::min(ins_score, std::min(del_score, match_score));
	  else
	    D[i][j] = std::min(ins_score, std::min(del_score, mismatch_score));
	}
      
    }
  return D[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
