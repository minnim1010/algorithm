#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef struct{
    int x, y;
} POSITION;

int N, M;
int ar[8][8] = {0};
int ans = 0;
vector<POSITION> virus;
vector<POSITION> blank;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int simul[8][8]){
    queue<POSITION> q;
    for (int i = 0; i < virus.size(); ++i) {
        q.push(virus[i]);
    }

    while(!q.empty()){
        POSITION cur = q.front();
        q.pop();
        simul[cur.x][cur.y] = 2;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx < 0 || ny < 0 || nx > N-1 || ny > M-1) continue;
            if (simul[nx][ny] == 0){
                simul[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

void solution(int idx, int start){
    if(idx == 3){
        int simul[8][8];
        memcpy(simul, ar, sizeof(ar));
        bfs(simul);

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if(!simul[i][j]) cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i = start; i < blank.size(); ++i) {
        if(ar[blank[i].x][blank[i].y] == 0){
            ar[blank[i].x][blank[i].y] = 1;
            solution(idx+1, start+1);
            ar[blank[i].x][blank[i].y] = 0;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ar[i][j];
            if(!ar[i][j])
                blank.push_back({i, j});
            else if(ar[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    solution(0, 0);

    cout << ans;

    return 0;
}
