#include<bits/stdc++.h>
using namespace std;
#define M 100010

vector<int>v[M];
stack<int>st;
int vis[M];

void initiat()
{
    for(int i=0;i<M;i++){
        vis[i]=0;
    }
}

void topSort(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;

    for(int i=0;i<v[s].size();i++){
        topSort(v[s][i]);
    }

    st.push(s);
}

void dfs(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

int main()
{
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }

        initiat();

        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                topSort(i);
            }
        }

        initiat();

        int ck=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();

            if(vis[top]==0){
                dfs(top);
                ck++;
            }
        }

        cout<<ck<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
