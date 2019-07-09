#include<bits/stdc++.h>
using namespace std;

vector<int>v[100];

int main()
{
    int x,y;

    for(int i=0;i<5;i++){
            cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    return 0;
}
