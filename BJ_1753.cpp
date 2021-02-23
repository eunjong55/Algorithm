#include<cstdio>
#include<vector>
#include<limits.h>
#include<queue>

using namespace std;

int main()
{
  int v, e;
  int start;
  scanf("%d %d", &v, &e);
  scanf("%d", &start);

  int dist[v];
  vector <vector<pair<int, int>> > map(v);
  priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair <int, int>>> pq;

  for(int i=0; i<v; i++){
    if(i==start-1) dist[i] = 0;
    else dist[i] = INT_MAX;

    pq.push(make_pair(dist[i], i));
  }

  for(int i=0; i<e; i++)
  {
    int v1, v2, w;
    scanf("%d %d %d", &v1, &v2, &w);
    map[v1-1].push_back(make_pair(v2-1, w));
  }

  while(!pq.empty())
  {
    pair<int,int> now = pq.top();
    pq.pop();
    if (now.first == INT_MAX) break;
    if (now.first > dist[now.second]) continue;
    for(int i=0; i< map[now.second].size(); i++)
    {
      int start_to_now = dist[now.second];
      int now_to_next = map[now.second][i].second;
      int start_to_next = dist[map[now.second][i].first];
      if(start_to_now + now_to_next < start_to_next)
      {
        dist[map[now.second][i].first] =start_to_now + now_to_next;
        pq.push(make_pair(dist[map[now.second][i].first], map[now.second][i].first));
      }
    }
  }

  for(int i=0; i<v; i++)
  {
    if(dist[i] == INT_MAX)
    {
      printf("INF\n");
    }
    else printf("%d\n", dist[i]);
  }
  return 0;
}