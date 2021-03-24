#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<vector<int>> graph(101);

void dfs(int now);

int visit[101] ={0, };
int cnt = 0;

int main(){
  int node;
  int edge;
  scanf("%d\n%d", &node, &edge);
  for(int i=0; i<edge; i++)
  {
    int left, right;
    scanf("%d %d", &left, &right);
    graph[left].push_back(right); //0부터 n-1까지
    graph[right].push_back(left);
  }
  dfs(1);
  if(cnt-1 <0) printf("0");
  else printf("%d", cnt-1);
}

void dfs(int now)
{
  visit[now] =1;
  cnt+=1;
  for(int i=0; i<graph[now].size(); i++)
  {
    if(visit[graph[now][i]] == 0)
    {
      dfs(graph[now][i]);
    }
  }
}
