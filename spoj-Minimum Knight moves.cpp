#include<bits/stdc++.h>
using namespace std;
#define M 15

int cell[M][M];
int dist[M][M];

int fx[]={-2,-2,2,2,-1,-1,1,1};
int fy[]={-1,1,-1,1,-2,2,-2,2};

int row=9,col=9;

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
};

void init(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            dist[i][j]=INT_MAX;
        }
    }
}

bool valid(int x,int y){
    if(x>0 && x<row && y>0 && y<col){
        return true;
    }
    return false;
}

void bfs(int sx,int sy){
    dist[sx][sy]=0;

    queue<pr>q;

    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<8;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && dist[top.x][top.y]+1<dist[tx][ty]){
                dist[tx][ty]=dist[top.x][top.y]+1;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        string s,s1;
        cin>>s>>s1;
        //cout<<s[0]-'a'+1<<s[1]-'0'<<" "<<s1[0]-'a'+1<<s1[1]-'0'<<endl;
        init();
        bfs((s[0]-'a')+1,(s[1]-'0'));
        cout<<dist[(s1[0]-'a')+1][s1[1]-'0']<<endl;
    }

    return 0;
}
