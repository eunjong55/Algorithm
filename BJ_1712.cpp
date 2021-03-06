//problem link : https://www.acmicpc.net/problem/1712

#include <cstdio>

using namespace std;

int main(){
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);
  if(B >= C) printf("%d", -1);
  else printf("%d", A/(C-B)+1);
}