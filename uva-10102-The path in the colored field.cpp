#include<bits/stdc++.h>
using namespace std;
#define M 200

int cell[M][M];
int visit[M][M];
int dist[M][M];
int row=0,col=0;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int dx=0,dy=0;

void initiat(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            visit[i][j]=0;
            dist[i][j]=0;
        }
    }
}

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col){
        return true;
    }
    return false;
}

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

void bfs(int sx,int sy){
    queue<pr>q;
    visit[sx][sy]=1;
    dist[sx][sy]=0;
    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && visit[tx][ty]==0){
                visit[tx][ty]=1;
                dist[tx][ty]=dist[top.x][top.y]+1;
                if(cell[tx][ty]==3){
                    dx=tx;dy=ty;
                    return;
                }
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int sx=0,sy=0;
        row=col=n;
        int mx=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<n;j++){
                cell[i][j]=s[j]-'0';
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cell[i][j]==1){
                    initiat();
                    bfs(i,j);
                    mx=max(mx,dist[dx][dy]);
                    dx=0;
                    dy=0;
                }
            }
        }

        cout<<mx<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cell[i][j]=0;
                visit[i][j]=0;
                dist[i][j]=0;
            }
        }
    }
    return 0;
}
