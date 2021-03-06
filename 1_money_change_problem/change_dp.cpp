#include <iostream>
#include <climits>
#include <vector>

int get_change(int money) {
  std::vector<int> minNumCoins ;
  minNumCoins.push_back(0);
  int coins[3] = {1,3,4};
  int numCoins;
  for(int m = 1; m <= money ; m++)
    {
      minNumCoins.push_back(INT_MAX);
      for(int i = 0; i < 3; i++)
	{
	  if(m >= coins[i])
	    {
	      numCoins = minNumCoins[m - coins[i]] + 1;
	      if(numCoins < minNumCoins[m])
		{
		  minNumCoins[m] = numCoins;
		}
	      
	    }
	}
    }
  return minNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
