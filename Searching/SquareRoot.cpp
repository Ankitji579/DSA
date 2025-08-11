#include <iostream>
#include <iomanip>
using namespace std;

int findSquare(int n) {
    int s = 0;
    int e = n;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (1LL * mid * mid == n)
            return mid;
        else if (1LL * mid * mid > n)
            e = mid - 1;
        else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int precision;
    cin >> precision;

    int intPart = findSquare(n);
    double step = 0.1;
    double finalAns = intPart;

    for (int i = 0; i < precision; i++) {
        for (double j = finalAns; j * j <= n; j += step) {
            finalAns = j;
        }
        step /= 10;
    }

    cout << fixed << setprecision(precision) << finalAns << endl;
    return 0;
}
