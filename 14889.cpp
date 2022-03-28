#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int N;
int power[20][20], ans = 40000;

void solution(int max, vector<int> power1, vector<int> power2, int idx){
    int size1 = power1.size();
    int size2 = power2.size();

    if(size1 > max || size2 > max)
        return;

    if(size1 == max && size2 == max){
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < max; ++i) {
            for (int j = 0; j < max; ++j) {
                sum1 += power[power1[i]][power1[j]];
                sum2 += power[power2[i]][power2[j]];
            }
        }

        int gap = abs(sum2-sum1);
        if(gap < ans)
            ans = gap;

        return;
    }

    vector<int> npower1, npower2;
    npower1.assign(power1.begin(), power1.end());
    npower1.push_back(idx);
    npower2.assign(power2.begin(), power2.end());
    npower2.push_back(idx);

    solution(max, npower1, power2, idx+1);
    solution(max, power1, npower2, idx+1);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> power[i][j];
        }
    }

    vector<int> power1, power2;
    solution(N/2, power1, power2, 0);

    cout << ans;

    return 0;
}
