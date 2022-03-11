#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, width, length;
char star[2050][2050] = {0};

void stars(int n, int start_w, int start_l) {
    if (n == 1) {
        star[start_l][start_w] = '*';
        return;
    } else {
        int width = pow(2, n + 1) - 3;
        int length = pow(2, n) - 1;
        for (int i = start_l; i < start_l + length; ++i) {
            if (n % 2 == 0) {
                int begin = start_w + (i - start_l);
                int end = start_w + width - (i - start_l);

                for (int j = begin; j < end; ++j) {
                    if (i == start_l)
                        star[i][j] = '*';
                    else {
                        if (j == begin || j == end - 1) {
                            star[i][j] = '*';
                        }
                    }
                }
            } else {
                int begin = start_w + (width - 1) / 2 - (i - start_l);
                int end = start_w + (width - 1) / 2 + (i - start_l);

                for (int j = begin; j <= end; ++j)
                    if (i == start_l + length - 1)
                        star[i][j] = '*';
                    else {
                        if (j == begin || j == end) {
                            star[i][j] = '*';
                        }
                    }
            }
        }
        if (n % 2 == 0)
            stars(n - 1, start_w + pow(2, n - 1), start_l + 1);
        else
            stars(n - 1, start_w + length / 2 + 1, start_l + length / 2);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    width = pow(2, N + 1) - 3;
    length = pow(2, N) - 1;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            star[i][j] = ' ';
        }
    }


    stars(N, 0, 0);

    if (N % 2 == 0) {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width - i; ++j) {
                cout << star[i][j];
            }
            cout << '\n';
        }
    } else {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < (width - 1) / 2 + i+1; ++j) {
                cout << star[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
