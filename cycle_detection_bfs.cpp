#include<bits/stdc++.h>
using namespace std;
#define M 100

vector<int>v[M];
int visit[M];
int parent[M];

int _start=0,_end=0;

void print()
{
    vector<int>path;
    path.push_back(_start);
    path.push_back(_end);
    int now=_start;
    int now1=_end;

    while(now!=now1){
        now=parent[now];
        now1=parent[now1];
        if(now!=now1){
            path.push_back(now);
            path.push_back(now1);
        }else{
            path.push_back(now);
        }
    }


    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }

    //cout<<_start<<" "<<parent[_start]<<endl;
    //cout<<_end<<" "<<parent[_end]<<endl;
}

int bfs(int s){
    queue<int>q;
    q.push(s);
    visit[s]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                parent[p]=u;
                q.push(p);
            }
            else{
                if(parent[u]!=p)
                    {
                        _start=p;
                        _end=u;
                        return 1;
                    }
            }
        }
    }
    return 0;
}


int main()
{
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    if(bfs(1)){
        cout<<"Cycle Detected!"<<endl;
        print();
    }else{
        cout<<"No cycle founded"<<endl;
    }
    return 0;
}
