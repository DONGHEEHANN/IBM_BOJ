// https://www.acmicpc.net/source/81345630
#include <bits/stdc++.h>
#define ibm514 ios_base::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
using namespace std;
int n, m, one=3, brd[8][8];
int dx[4]={0,1,-1,0}, dy[4]={1,0,0,-1};
vector<pair<int,int>> brs,bin;

int bfs(){
    bool us[8][8]={}; int sol=0;
    queue<pair<int,int>> q;
    for(auto e:brs) {q.push(e); us[e.ff][e.ss]=true;}
    while(!q.empty()){
        auto cur=q.front(); q.pop(); sol++;
        for(int d=0;d<4;d++){
            int nx=cur.ff+dx[d], ny=cur.ss+dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=m || us[nx][ny] || brd[nx][ny]==1) continue;
            q.emplace(nx,ny); us[nx][ny]=true;
        }
    }
    return sol;
}

int main() {
    ibm514;
    cin>>n>>m;

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>brd[i][j];
            if(brd[i][j]==0) bin.emplace_back(i,j);
            else if(brd[i][j]==2) brs.emplace_back(i,j);
            else one++;
        }

    int sz=(int)bin.size(), ans=1e9;
    for(int k=0;k<sz;++k){
        for(int i=k+1;i<sz;++i){
            for(int j=i+1;j<sz;++j){
                brd[bin[i].ff][bin[i].ss]=1;
                brd[bin[j].ff][bin[j].ss]=1;
                brd[bin[k].ff][bin[k].ss]=1;
                ans=min(ans,bfs());
                brd[bin[i].ff][bin[i].ss]=0;
                brd[bin[j].ff][bin[j].ss]=0;
                brd[bin[k].ff][bin[k].ss]=0;
            }
        }
    }
    cout<<n*m-one-ans;
    return 0;
}