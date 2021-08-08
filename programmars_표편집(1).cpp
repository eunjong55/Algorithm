#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

stack<Node*> st;

struct ll
{
    Node *head;
    Node *tail;
    ll() : head(NULL), tail(NULL){}
    void insert(int data);
    void restore();
    Node* erase(Node* node);
};

void ll::insert(int data)
{
    Node* node = new Node(data);
    if(head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}
void ll::restore()
{
    Node* node = st.top();
    st.pop();
    
    if(node->prev == NULL)
    {
        head = node;
        node->next->prev = node;
    }
    else if(node->next == NULL)
    {
        tail = node;
        node->prev->next = node;
    }
    else
    {
        node->next->prev = node;
        node->prev->next = node;
    }
}
Node* ll::erase(Node* node)
{
    st.push(node);
    if(node == head)
    {
        head = node->next;
        node->next->prev = NULL;
        return node->next;
    }
    else if(node == tail)
    {
        tail = node->prev;
        node->prev->next = NULL;
        return node->prev;
    }
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return node->next;
    }
}



string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    ll* list = new ll();
    for(int i=0; i<n; i++)
    {
        list->insert(i); 
    }
    
    Node* iter = list->head;
    for(int i=0; i<k; i++)
    {
        iter = iter->next;
    }

    for(int i=0; i<cmd.size(); i++)
    {
        if(cmd[i][0] == 'U')
        {
            cmd[i][0] = ' ';
            for(int j=0; j<stoi(cmd[i]); j++)
            {
                iter = iter->prev;
            }
        }
        if(cmd[i][0] == 'D')
        {
            cmd[i][0] = ' ';
            for(int j=0; j<stoi(cmd[i]); j++)
            {
                iter = iter->next;
            }
        }
        if(cmd[i][0] == 'C')
        {
            iter = list->erase(iter);
        }
        if(cmd[i][0] == 'Z')
        {
            list->restore();
        }

    }
    for(int i=0; i<n; i++) answer+='O';
    while(!st.empty())
    {
        Node* del = st.top();
        st.pop();
        answer.at(del->data) = 'X';
    }
    cout<<endl;
    return answer;
}