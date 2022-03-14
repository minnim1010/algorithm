#include <iostream>
#include <cmath>

using namespace std;

int N, M, x, y, K;
int nx, ny;
int map[20][20];
int cmd[1000];
int dice_col[4] = {0};
int dice_row[4] = {0};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void rollDice(int c){
    int mov;

    switch(c){
        case 1: //east
            mov = dice_row[3];
            for (int i = 3; i > 0; --i) {
                dice_row[i] = dice_row[i-1];
            }
            dice_row[0] = mov;
            dice_col[1] = dice_row[1];
            dice_col[3] = dice_row[3];
            break;
        case 2: //west
            mov = dice_row[0];
            for (int i = 1; i < 4; ++i) {
                dice_row[i-1] = dice_row[i];
            }
            dice_row[3] = mov;
            dice_col[1] = dice_row[1];
            dice_col[3] = dice_row[3];
            break;
        case 3: //North
            mov = dice_col[3];
            for (int i = 3; i > 0; --i) {
                dice_col[i] = dice_col[i-1];
            }
            dice_col[0] = mov;
            dice_row[1] = dice_col[1];
            dice_row[3] = dice_col[3];
            break;
        case 4: //South
            mov = dice_col[0];
            for (int i = 1; i < 4; ++i) {
                dice_col[i-1] = dice_col[i];
            }
            dice_col[3] = mov;
            dice_row[1] = dice_col[1];
            dice_row[3] = dice_col[3];
            break;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        cin >> cmd[i];

        nx = x + dx[cmd[i]];
        ny = y + dy[cmd[i]];

        if(nx < 0 || ny < 0 || nx > N-1 || ny > M-1) continue;

        x = nx;
        y = ny;

        rollDice(cmd[i]);

        if(map[x][y]){
            dice_row[3] = dice_col[3] = map[x][y];
            map[x][y] = 0;
        }

        else
            map[x][y] = dice_row[3];

        cout << dice_row[1] << '\n';
    }

    return 0;
}
