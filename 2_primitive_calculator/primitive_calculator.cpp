#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

vector<int> calc_min(std::vector<int> calc_op)
{
  std::vector<int> result;
  int m = INT_MAX, op = 0;
  for(int i = 0; i < calc_op.size(); i++)
    {
     
      if( calc_op[i] < m)
	{
	  m = calc_op[i];
	  op = i;
	}
    }
  result.push_back(m);
  result.push_back(op+1);

  return result;

  
}


vector<int> optimal_sequence(int n) {
  std::vector<int> sequence, minNumOperations(n+1);
  std::vector<int> operations, result, calc_op(3);
  int current;
  minNumOperations[0] = 0;
  minNumOperations[1] = 0;
  operations.push_back(0);
  operations.push_back(0);
  for(int x = 2; x <= n; x++)
    {
      minNumOperations[x] = INT_MAX;
      current = x;
      calc_op[0] = INT_MAX;
      calc_op[1] = INT_MAX;
      calc_op[2] = INT_MAX;
      if(x > 1)
	{
	  
	  
	  if(x % 3 == 0)
	    {
	      
	      calc_op[2] = minNumOperations[x/3] + 1;
	    }
	  if(x % 2 == 0)
	    {
	      
	      calc_op[1] = minNumOperations[x/2] + 1;
	    }
	    
	  calc_op[0] = minNumOperations[x - 1] + 1;

	  result = calc_min(calc_op);
	  
	  minNumOperations[current] = result[0];
	  operations.push_back(result[1]);
	}
      
    }
  
  sequence.push_back(n);
  int i = n;
  while(n > 1)
    {
      if(operations[i] == 1)
	{
	  n = n - 1;
	  sequence.push_back(n);
	  i = n;
	}
      if(operations[i] == 2)
	{
	  n = n/2;
	  sequence.push_back(n);
	  i = n;
	}
      if(operations[i] == 3)
	{
	  n = n/3;
	  sequence.push_back(n);
	  i = n;
	}

      
    }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
