#include<bits/stdc++.h>
using namespace std;
#define M 100010

int parent[M];
int ranks[M];
int node[M];

void initialize(){
    for(int i=0;i<M;i++){
        parent[i]=i;
        ranks[i]=0;
        node[i]=1;
    }
}

int findParent(int x){
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    return x;
}

int unionSet(int x,int y){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py){
        return node[px];
    }

    if(ranks[px]>ranks[py]){
        parent[py]=px;
        node[px]+=node[py];
        return node[px];
    }
    else if(ranks[py]>ranks[px]){
        parent[px]=py;
        node[py]+=node[px];
        return node[py];
    }
    else{
        parent[py]=px;
        ranks[px]++;
        node[px]+=node[py];
        return node[px];
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        map<string,int>mp;
        initialize();

        int n;
        cin>>n;
        int ck=1;
        for(int i=1;i<=n;i++){
            string s,s1;
            cin>>s>>s1;

            if(!mp[s]){
                mp[s]=ck;
                ck++;
            }
            if(!mp[s1]){
                mp[s1]=ck;
                ck++;
            }

            cout<<unionSet(mp[s],mp[s1])<<endl;
        }
    }
    return 0;
}

