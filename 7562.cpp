#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef struct {
    int x, y;
} POSITION;

int T;
int l;
int chess[300][300];
POSITION src, dst;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


int bfs(POSITION src, POSITION dst){
    queue<POSITION> q;

    if(src.x == dst.x && src.y == dst.y)
        return 1;

    q.push(src);
    chess[src.x][src.y] = 1;

    while(!q.empty()){
        POSITION cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            int cnt = chess[cur.x][cur.y]+1;

            if(chess[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx > l-1 || ny > l-1) continue;

            if(nx == dst.x && ny == dst.y)
                return cnt;
            chess[nx][ny] = cnt;
            q.push({nx, ny});
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> l;
        cin >> src.x >> src.y;
        cin >> dst.x >> dst.y;

        memset(chess, 0, sizeof(chess));
        cout << bfs(src, dst)-1 << '\n';
    }

    return 0;
}
