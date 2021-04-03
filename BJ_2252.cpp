#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int prev_count[32001] = {0,}; // i번째 사람보다 키가 작은 사람들 수
vector<vector<int>> next_persons(32001); // i번째 사람보다 키가 큰 사람들
int res[32001];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++)
  {
    int first, second;
    scanf("%d %d", &first, &second);
    prev_count[second] +=1;
    next_persons[first].push_back(second);
  }
  queue<int> q;
  for(int i=1; i<=n; i++)
  {
    if(prev_count[i]==0)
    {
      q.push(i);
      prev_count[i] = -1;
    }
  }

  int idx=0;
  while(!q.empty())
  {
    int person = q.front();
    q.pop();
    res[idx] = person;
    idx++;

    //next_persons update
    for(int i=1; i<=next_persons[person].size(); i++)
    {
      prev_count[next_persons[person][i-1]] -=1;
      if(prev_count[next_persons[person][i-1]]==0) q.push(next_persons[person][i-1]);
    }
  }
  for(int i=0; i<n; i++) printf("%d ", res[i]);
}

