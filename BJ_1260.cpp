#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<vector<int>> graph(1001);

bool compare(int left, int right)
{
  if(left < right) return true;
  else return false;
}

void dfs(int now);
void bfs(int start);

int visit[1000] ={0, };

int main(){
  int node;
  int edge;
  int start;
  scanf("%d %d %d", &node, &edge, &start);
  for(int i=1; i<=edge; i++)
  {
    int left, right;
    scanf("%d %d", &left, &right);
    graph[left].push_back(right); //0부터 n-1까지
    graph[right].push_back(left);
  }

  for(int i=1; i<=node; i++)
  {
    sort(graph[i].begin(), graph[i].end(), compare);
  }
  dfs(start);
  printf("\n");
  memset(visit, 0, sizeof(visit));
  bfs(start);
}

void dfs(int now)
{
  printf("%d ", now);
  visit[now] =1;
  for(int i=0; i<graph[now].size(); i++)
  {
    if(visit[graph[now][i]] == 0)
    {
      dfs(graph[now][i]);
    }
  }
}

void bfs(int start)
{
  queue<int> q;
  q.push(start);
  while(!q.empty())
  {
    int now = q.front();
    q.pop();
    printf("%d ", now);
    visit[now] = 1;

    for(int i=0; i<graph[now].size(); i++)
    {
      if(visit[graph[now][i]] == 0)
      {
        visit[graph[now][i]] =1;
        q.push(graph[now][i]);
      }
    }
  }
}