#include<bits/stdc++.h>
using namespace std;
#define M 25

int cell[M][M];
int vis[M][M];
int fx[]={1,-1,0,0,};
int fy[]={0,0,1,-1,};

int row=0,col=0;

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]!=0){
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

int bfs(int sx,int sy){
    queue<pr>q;
    vis[sx][sy]=1;
    q.push(pr(sx,sy));
    int ck=0;

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && vis[tx][ty]==0){
                ck++;
                vis[tx][ty]=1;
                q.push(pr(tx,ty));
            }
        }
    }

    return ck+1;
}

int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int w,h;
        int sx=0,sy=0;

        cin>>w>>h;
        row=h;col=w;
        for(int i=0;i<h;i++){
            string s;
            cin>>s;
            for(int j=0;j<w;j++){
                if(s[j]=='.' || s[j]=='@'){
                    cell[i][j]=1;
                }
                if(s[j]=='@'){
                    sx=i;
                    sy=j;
                }
            }
        }

        cout<<"Case "<<k+1<<": "<<bfs(sx,sy)<<endl;

        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                cell[i][j]=0;
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
