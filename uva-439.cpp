#include<bits/stdc++.h>
using namespace std;

#define M 10
int row=8;
int col=8;
int cell[M][M];
int dist[M][M];
int fx[]={1,2,-1,-2,1,2,-1,-2};
int fy[]={2,1,2,1,-2,-1,-2,-1};

void initiat(int a[M][M],int c){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            a[i][j]=c;
        }
    }
}

int valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col){
        return 1;
    }
    return 0;
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
    initiat(dist,INT_MAX);
    dist[sx][sy]=0;

    queue<pr>q;
    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<8;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && (dist[top.x][top.y]+1)<dist[tx][ty]){
                dist[tx][ty]=dist[top.x][top.y]+1;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    char s1[5],s2[5];
    while(scanf("%s%s",&s1,&s2)!=EOF){
        //cout<<s1[0]-'a'<<" "<<(s1[1]-'0')-1<<" "<<s2[0]-'a'<<" "<<(s2[1]-'0')-1<<endl;
        bfs((s1[0]-'a'),(s1[1]-'0')-1);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dist[s2[0]-'a'][(s2[1]-'0')-1]<<" knight moves."<<endl;
    }
    return 0;
}
