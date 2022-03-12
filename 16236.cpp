#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct FISH {
    int x, y;
    int dis;

    bool operator<(const FISH &i) const {
        if (dis == i.dis) {
            if (x == i.x) {
                return y > i.y;
            } else return x > i.x;
        } else return dis > i.dis;
    }
};

struct SHARK {
    int x, y;
    int smsf;
    int size;
};

int n, ans = 0;
int map[20][20] = {0};
SHARK shark;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
FISH target;

void calcDis(int x, int y) {
    queue<pair<int, int>> v;
    int visit[20][20];

    target.x = 401;
    target.y = 401;
    target.dis = 160000;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visit[i][j] = -1;
        }
    }

    v.push(make_pair(x, y));
    visit[x][y] = 0;

    while (!v.empty()) {
        pair<int, int> f = v.front();
        v.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];

            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;

            if (visit[nx][ny] == -1 && map[nx][ny] <= shark.size) {
                visit[nx][ny] = visit[f.first][f.second] + 1;
                if (map[nx][ny] != 0 && map[nx][ny] < shark.size) {
                    FISH fish;
                    fish.x = nx;
                    fish.y = ny;
                    fish.dis = visit[nx][ny];

                    if (target.dis < fish.dis)
                        return;

                    if (target.dis > fish.dis) {
                        target = fish;
                    } else if (target.dis == fish.dis) {
                        if (target.x > fish.x) {
                            target = fish;
                        } else if (target.x == fish.x) {
                            if (target.y > fish.y) {
                                target = fish;
                            }
                        }
                    }
                }

                v.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                shark.smsf = 0;
                shark.size = 2;
                map[i][j] = 0;
            }
        }
    }

    while (1) {
        calcDis(shark.x, shark.y);

        if (target.x == 401)
            break;

        ans += target.dis;
        shark.x = target.x;
        shark.y = target.y;
        map[target.x][target.y] = 0;
        shark.smsf++;
        if (shark.smsf == shark.size) {
            shark.smsf = 0;
            shark.size++;
        }
    }

    cout << ans;

    return 0;
}
