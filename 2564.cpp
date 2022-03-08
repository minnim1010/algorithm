#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int r, c, num, x, y, shopIdx = 0, ans = 0;
int shop[101][2], dong[2];

void saveCoordFromCard(int card, int dis){
    int dim[4] = {0, r, 0, c};

    card -= 1;
    if(card/2 == 0){
        shop[shopIdx][0] = dim[card%2];
        shop[shopIdx][1] = dis;
    }
    else{
        shop[shopIdx][0] = dis;
        shop[shopIdx][1] = dim[2+card%2];
    }
    ++shopIdx;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> r >> num;

    for (int i = 0; i < num+1; ++i) {
        cin >> x >> y;
        saveCoordFromCard(x, y);
    }

    dong[0] = shop[num][0];
    dong[1] = shop[num][1];

    int disx, disy, dis, flagx, flagy;
    int maxDis = (r+c)*2;
    for (int i = 0; i < num; ++i) {
        flagx = flagy = 0;
        disx = abs(dong[0]-shop[i][0]);
        disy = abs(dong[1]-shop[i][1]);

        if(disx == r)
            dis = dong[1] + shop[i][1] + disx;
        else if(disy == c)
            dis = dong[0] + shop[i][0] + disy;
        else
            dis = disx + disy;
        dis = min(dis, maxDis-dis);
        ans += dis;
    }

    cout << ans;

    return 0;
}
