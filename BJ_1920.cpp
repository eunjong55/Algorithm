#include<cstdio>
#include<vector>
#include<algorithm>

bool b_search(int numbers[], int left, int right, int find);

using namespace std;

bool compare(int i, int j)
{
  if(i<j) return true;
  else return false;
}

int main()
{
  int n, m;
  scanf("%d", &n);
  int numbers[n];

  for(int i=0; i<n; i++)
  {
    int temp;
    scanf("%d", &temp);
    numbers[i] = temp;
  }
  sort(numbers, numbers+n, compare);

  scanf("%d", &m);
  for(int i=0; i<m; i++)
  {
    int target;
    scanf("%d", &target);
    if(b_search(numbers, 0, n-1, target))
    {
      printf("1\n");
    }
    else printf("0\n");
  }
}

bool b_search(int numbers[], int left, int right, int target)
{
  if(left > right) return false;
  int mid = left + (right-left)/2;
  if(numbers[mid] == target) return true;
  if(numbers[mid]<target) left = mid+1;
  else right = mid -1;
  if(b_search(numbers, left, right, target)) return true;
  else return false;
}