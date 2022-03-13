#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n, l, r;
int A[50][50] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
bool flagMigration = true;
bool visit[50][50] = {0};

bool migration(int x, int y) {
    queue<pair<int, int>> v;
    queue<pair<int, int>> uni;
    int totalPopul = 0;
    int numUni = 0;
    pair<int, int> f;
    pair<int, int> elem;

    elem = make_pair(x, y);
    v.push(elem);
    uni.push(elem);
    visit[x][y] = true;

    while (!v.empty()) {
        f = v.front();
        v.pop();
        totalPopul += A[f.first][f.second];
        numUni++;

        for (int k = 0; k < 4; ++k) {
            int nx = f.first + dx[k];
            int ny = f.second + dy[k];

            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
            if(visit[nx][ny]) continue;

            int gap = abs(A[f.first][f.second] - A[nx][ny]);
            if (l <= gap && gap <= r) {
                elem = make_pair(nx, ny);
                v.push(elem);
                uni.push(elem);
                visit[nx][ny] = true;
            }
        }
    }

    if(numUni != 1){
        int nPopul = totalPopul/numUni;

        while(!uni.empty()){
            f = uni.front();
            uni.pop();
            A[f.first][f.second] = nPopul;
        }
        return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    while (flagMigration) {
        memset(visit, 0, sizeof(bool)*50*50);

        flagMigration = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j]) continue;
                if(migration(i, j))
                    flagMigration = true;
            }
        }

        ans++;
    }

    cout << ans-1;

    return 0;
}
