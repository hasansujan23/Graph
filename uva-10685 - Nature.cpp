#include<bits/stdc++.h>
using namespace std;
#define M 5010

int parent[M];
int ranks[M];
int node[M];
int mx=0;

void initialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        ranks[i]=0;
        node[i]=1;
    }
}

int findParent(int x){
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void unionSet(int x,int y){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)
        return;

    if(ranks[px]>ranks[py]){
        parent[py]=px;
        node[px]+=node[py];
        mx=max(mx,node[px]);
    }
    else if(ranks[py]>ranks[px]){
        parent[px]=py;
        node[py]+=node[px];
        mx=max(mx,node[py]);
    }
    else{
        parent[py]=px;
        ranks[px]++;
        node[px]+=node[py];
        mx=max(mx,node[px]);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(1){
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0){
        break;
    }

    map<string,int>mp;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]=i;
    }
    initialize(n);
    for(int i=0;i<m;i++){
        string s,s1;
        cin>>s>>s1;
        unionSet(mp[s],mp[s1]);
    }

    if(mx==0){
        cout<<1<<endl;
    }
    else{
        cout<<mx<<endl;
    }
    mx=0;
//    for(int i=0;i<n;i++){
//        cout<<parent[i]<<" "<<ranks[i]<<" "<<node[i]<<endl;
//    }
    }

    return 0;
}

