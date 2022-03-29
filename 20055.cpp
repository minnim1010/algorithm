#include <iostream>
#include <cmath>
//20055 컨베이어 벨트 위의 로봇
using namespace std;

struct CONTAINER{
    int duration;
    bool robot;
};

int N, K, ans = 0, crash = 0;
struct CONTAINER cont[201];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= 2*N; ++i) {
        cin >> cont[i].duration;
    }

    cont[0].duration = cont[0].robot = 0;
    while(crash < K){
        struct CONTAINER tmp = cont[2*N];
        for (int i = 2*N; i > 1; --i) {
            cont[i] = cont[i-1];
            if(i == N && cont[i].robot)
                cont[i].robot = false;
        }
        cont[1] = tmp;

        for (int i = N; i >= 1; --i) {
            if(cont[i].duration > 0 && !cont[i].robot){
                cont[i].robot = cont[i-1].robot;
                if(cont[i].robot) --cont[i].duration;
                if(cont[i].duration == 0) ++crash;
                cont[i-1].robot = false;
            }
            if(i == N && cont[i].robot)
                cont[i].robot = false;
        }

        if(cont[1].duration > 0){
            cont[1].robot = true;
            --cont[1].duration;
            if(cont[1].duration == 0) ++crash;
        }

        ans++;
    }

    cout << ans;

    return 0;
}
