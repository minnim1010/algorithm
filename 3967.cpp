#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char tmp;
vector<int> star;
vector<int> ans;
bool remainNum[13] = {0};

bool isMagicStar(vector<int> star) {
    if (star[0] + star[2] + star[5] + star[7] != 26) return false;
    if (star[0] + star[3] + star[6] + star[10] != 26) return false;
    if (star[1] + star[2] + star[3] + star[4] != 26) return false;
    if (star[1] + star[5] + star[8] + star[11] != 26) return false;
    if (star[4] + star[6] + star[9] + star[11] != 26) return false;
    if (star[7] + star[8] + star[9] + star[10] != 26) return false;
    return true;
}

void printMagicStar(vector<int> star) {
    printf("....%c....\n", star[0] + 'A' - 1);
    printf(".%c.%c.%c.%c.\n", star[1] + 'A' - 1, star[2] + 'A' - 1, star[3] + 'A' - 1, star[4] + 'A' - 1);
    printf("..%c...%c..\n", star[5] + 'A' - 1, star[6] + 'A' - 1);
    printf(".%c.%c.%c.%c.\n", star[7] + 'A' - 1, star[8] + 'A' - 1, star[9] + 'A' - 1, star[10] + 'A' - 1);
    printf("....%c....\n", star[11] + 'A' - 1);
}

bool solution(vector<int> star, int idx) {
    while (idx <= 11 && star[idx] != 0) {
        ++idx;
    }

    if (idx == 12){
        if(isMagicStar(star)){
            ans.assign(star.begin(), star.end());
            return true;
        }
        return false;
    }


    for (int i = 1; i < 13; ++i) {
        if (remainNum[i]) {
            star[idx] = i;
            remainNum[i] = false;
            if (solution(star, idx + 1))
                return true;
            remainNum[i] = true;
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(remainNum, 1, sizeof(remainNum));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> tmp;
            if (tmp == '.')
                continue;
            else if (tmp == 'x')
                star.push_back(0);
            else {
                star.push_back(tmp - 'A' + 1);
                remainNum[tmp - 'A' + 1] = false;
            }
        }
    }

    solution(star, 0);

    printMagicStar(ans);

    return 0;
}
