#define N 9

#include <bits/stdc++.h>

using namespace std;


class Solver {
public:
    void Init() {
        int i, j, j_;
        // 0 ways to place j (j > 0) bishops on board 0x0 for black positions
        // 1 way to place 0 bishop on board ixi black positions
        for (i = 0; i < N; ++i) {
            black_[i][0] = white_[i][0] = 1;
        }
        // from board (i-1)x(i-1) to ixi, the number of new black / white
        // positions
        for (i = 1; i < N; ++i) {
            if (i % 2) {
                n_new_black_[i] = i;
                n_new_white_[i] = n_new_white_[i - 1];
            } else {
                n_new_black_[i] = n_new_black_[i - 1];
                n_new_white_[i] = i;
            }
        }
        // transition, the number of ways of placing j bishops on ixi black
        // board =
        //      number of ways to place j bishops on the (i-1)x(i-1) black
        //      board
        //        +
        //      number of ways to place (j - 1) bishops on (i-1)x(i-1) board
        //      and last bishop on the new black positions
        for (i = 1; i < N; ++i) {
            for (j = 1; j <= i; ++j) {
                // As there are i new black or white positions maximum
                // for a board ixi, we can stop our search at i
                j_ = j - 1;
                black_[i][j] = black_[i - 1][j] +
                        black_[i - 1][j_] * (n_new_black_[i] - j_);
                white_[i][j] = white_[i - 1][j] +
                               white_[i - 1][j_] * (n_new_white_[i] - j_);
            }
        }


    }

    long Run(int n, int k) {
        if (k > 2 * n - 1) {
            return 0;
        }
        long n_ways = 0;
        for (int j = 0; j <= k; ++j) {
            if (j <= n && k - j <= n) {
                n_ways += black_[n][j] * white_[n][k - j];
            }
        }
        return n_ways;
    }

    void Print() {
        cout << "Black & White:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << i << ": ";
            for (int j = 0; j < N; ++j) {
                cout << "[" << black_[i][j] << " " << white_[i][j] << "] ";
            }
            cout << endl;
        }
    }

private:
    long black_[N][N] = {0};
    long white_[N][N] = {0};

    int n_new_black_[N] = {0};
    int n_new_white_[N] = {0};

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    auto solver = Solver();
    solver.Init();
    // solver.Print();
    while (n) {
        cout << solver.Run(n, k) << endl;
        cin >> n >> k;
    }
    return 0;
}
