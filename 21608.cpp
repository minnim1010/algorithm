#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct SEATINFO{
    int x, y, empty=0, prfCnt = 0;
    bool operator <(const SEATINFO& i) const {
        if (prfCnt == i.prfCnt) {
            if (empty == i.empty) {
                if (x == i.x) return y > i.y;
                else return x > i.x;
            }
            else return empty < i.empty;
        }
        else return prfCnt < i.prfCnt;
    }
};

struct STUINFO{
    int num;
    int prf[4];
    int x, y;
};

int N, ans = 0;
STUINFO stu[400] = {0};
int seat[20][20] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int stsf[5] = {0, 1, 10, 100, 1000};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N*N; ++i) {
        cin >> stu[i].num;
        for (int j = 0; j < 4; ++j) {
            cin >> stu[i].prf[j];
        }
    }

    for (int s = 0; s < N*N; ++s) {
        priority_queue<SEATINFO> pq;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if(seat[i][j] == 0){
                    int empty, prf;
                    empty = prf = 0;

                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(x < 0 || y < 0 || x > N-1 || y > N-1) continue;
                        if(seat[x][y] == 0) empty++;
                        else{
                            for (int l = 0; l < 4; ++l) {
                                if(seat[x][y] == stu[s].prf[l]){
                                    prf++;
                                    break;
                                }
                            }
                        }
                    }
                    pq.push({i, j, empty, prf});
                }
            }
        }

        if(!pq.empty()){
            int x = pq.top().x;
            int y = pq.top().y;

            seat[x][y] = stu[s].num;
            stu[s].x = x;
            stu[s].y = y;
        }
    }

    for (int i = 0; i < N*N; ++i) {
        int x = stu[i].x;
        int y = stu[i].y;
        int cnt = 0;

        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
            for (int k = 0; k < 4; ++k) {
                if(seat[nx][ny] == stu[i].prf[k]){
                    cnt++;
                    break;
                }
            }
        }
        ans += stsf[cnt];
    }

    cout << ans;

    return 0;
}
