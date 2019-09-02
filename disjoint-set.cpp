#include<bits/stdc++.h>
using namespace std;
#define M 100

int parent[M];
int ranks[M];

void initialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        ranks[i]=0;
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

    if(ranks[px]<ranks[py]){
        parent[px]=py;
    }
    else if(ranks[px]>ranks[py]){
        parent[py]=px;
    }
    else{
        parent[py]=px;
        ranks[px]++;
    }
}

void print(int n){
    for(int i=0;i<n;i++){
        cout<<"Node "<<i<<" parent : "<<parent[i]<<" ranks : "<<ranks[i]<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    initialize(n);

    unionSet(0,1);
    unionSet(4,2);
    unionSet(3,1);
    unionSet(0,3);
    unionSet(0,4);
    print(n);
    return 0;
}
