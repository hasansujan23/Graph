#include<bits/stdc++.h>
using namespace std;
#define M 100

vector<int>v[M];
stack<int>st;
int vis[M];

void dfs(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
    st.push(s);
}

int main()
{
    int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }

    for(int i=1;i<=node;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }

    cout<<"Topological Sort: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}
