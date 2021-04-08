#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> edges;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int visited[10000] = {0, };
int weight_sum = 0;

void prim(int cur)
{
  visited[cur] = 1;
  for(int i=0; i<edges[cur].size(); i++)
  {
    if(visited[edges[cur][i].second] == 0)
    {
      pq.push({edges[cur][i].first, edges[cur][i].second});
    }
  }

  while(!pq.empty())
  {
    int weight = pq.top().first;
    int next = pq.top().second;
    pq.pop();
    if(visited[next]==0)
    {
      weight_sum += weight;
      prim(next);
      return;
    }
  }

}

int main(){
  int v, e;
  scanf("%d %d", &v, &e);
  edges.resize(v);

  for(int i=0; i<e; i++)
  {
    int first, second, weight;
    scanf("%d %d %d", &first, &second, &weight);
    edges[first-1].push_back({weight, second-1});
    edges[second-1].push_back({weight, first-1});
  }

  prim(0);
  printf("%d", weight_sum);
  return 0;
}