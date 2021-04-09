#include <cstdio>

int parent[1000000];


int find(int cur)
{
  if(cur == parent[cur]) return cur;
  else 
  {
    int root = find(parent[cur]);
    parent[cur] = root;
    return root;
  }
}

void merge(int a, int b)
{
  int x= find(a);
  int y = find(b);
  if(x!=y) parent[x] = y;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n+1; i++) parent[i] = i;

  for(int i=0; i<m; i++)
  {
    int func, a, b;
    scanf("%d %d %d", &func, &a, &b);
    if(func == 0)
    {
      merge(a, b);
    }
    if(func == 1)
    {
      int x= find(a);
      int y= find(b);

      if(x==y) printf("YES\n");
      else printf("NO\n");
    }
  }
  
}