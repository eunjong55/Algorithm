#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[50];

int min_depth = 50;

bool isOneDiff(string left, string right)
{
    int count = 0;
    for(int i=0; i<left.length(); i++)
    {
        if(left.at(i) != right.at(i)) count +=1;
    }
    return (count == 1) ? true:false;
}

void dfs(int idx, int targetIdx, int depth, vector<string> words)
{
    if(words[idx].compare(words[targetIdx]) == 0)
    {   
        min_depth = (depth<min_depth)? depth:min_depth;
        return;
    }
    
    visited[idx] = true;
    
    for(int i=0; i<words.size(); i++)
    {
        if(visited[i] == false && isOneDiff(words[idx], words[i]) == true) 
        {
            dfs(i, targetIdx, depth+1, words);
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int target_idx=-1;
    for(int i=0; i<words.size(); i++)
    {
        if(target.compare(words[i])==0){
            target_idx = i;
            break;
        }
    }
    if(target_idx == -1) return 0;
    
    else
    {
        for(int i=0; i<words.size(); i++)
        {
            if(visited[i]==false && isOneDiff(begin, words[i]) == true) dfs(i, target_idx, 1, words);
        }
    }
    
    return (min_depth==50)?0:min_depth;
}