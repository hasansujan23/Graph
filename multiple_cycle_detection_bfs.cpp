#include<bits/stdc++.h>
using namespace std;
#define M 100

vector<int>v[M];
vector<int>path[M];
int visit[M];
int parent[M];
int color[M];

void cycle(int _start,int _end,int pos)
{
    path[pos].push_back(_start);
    path[pos].push_back(_end);
    int now=_start;
    int now1=_end;

    while(now!=now1){
        now=parent[now];
        now1=parent[now1];
        if(now!=now1){
            path[pos].push_back(now);
            path[pos].push_back(now1);
        }else{
            path[pos].push_back(now);
        }
    }
    //cout<<_start<<" "<<parent[_start]<<endl;
    //cout<<_end<<" "<<parent[_end]<<endl;
}

void print(int n){
    for(int i=0;i<n;i++){
        cout<<"Cycle "<<i+1<<" : ";
        for(int j=0;j<path[i].size();j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}

int bfs(int s){
    queue<int>q;
    int ck=0;
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
                if(parent[u]!=p && color[u]==0 && color[p]==0)
                    {
                        //_start=p;
                        //_end=u;
                        color[u]=1;
                        color[p]=1;
                        cycle(p,u,ck);
                        ck++;
                        //return 1;
                    }
            }
        }
    }
    return ck;
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

    int n=bfs(1);
    cout<<"number of cycle: "<<n<<endl;

    if(n){
        cout<<"Cycle Detected!"<<endl;
        print(n);
    }else{
        cout<<"No cycle founded"<<endl;
    }
    return 0;
}

