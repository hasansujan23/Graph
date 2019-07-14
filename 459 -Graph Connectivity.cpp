#include<bits/stdc++.h>
using namespace std;
#define M 100

vector<int>v[M];
int visit[M];

void initiat()
{
    for(int i=0;i<M;i++){
        visit[i]=0;
    }
}

void dfs(int s){
    if(visit[s]==1)
        return;
    visit[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        string s,s1;

        cin>>s;
        int node=s[0]-'A';
        cin.ignore();
        while(1){
            getline(cin,s1);
            //cin.ignore();
            if(s1.empty())
                break;
            v[s1[0]-'A'].push_back(s1[1]-'A');
            v[s1[1]-'A'].push_back(s1[0]-'A');
        }

        initiat();
        int ck=0;
        for(int i=0;i<=node;i++){
            if(visit[i]==0){
                dfs(i);
                ck++;
            }
        }

        cout<<ck<<endl;
        if(k<t-1)
            cout<<endl;
        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
