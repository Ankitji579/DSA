#include <bits/stdc++.h>
using namespace std;

double findQuotientWithPrecision(int dvd, int dsr, int precision) {
    if (dsr == 0) {
        throw invalid_argument("Division by 0 is undefined");
    }
    if (dvd == 0) {
        return 0.0;
    }

    // clamp overflow case
    if (dvd == INT_MIN && dsr == -1) {
        return (double)INT_MAX;
    }

    bool isNegative = (dvd < 0) ^ (dsr < 0);

    long long p_dvd = abs((long long)dvd);
    long long p_dsr = abs((long long)dsr);

    // Integer part via binary search
    long long s = 0, e = p_dvd, intPart = 0;
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        if (mid * p_dsr == p_dvd) {
            intPart = mid;
            break;
        } else if (mid * p_dsr < p_dvd) {
            intPart = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    // Fractional part via step refinement
    double finalAns = intPart;
    double step = 0.1;
    for (int i = 0; i < precision; i++) {
        while ((finalAns + step) * p_dsr <= p_dvd) {
            finalAns += step;
        }
        step /= 10;
    }

    return isNegative ? -finalAns : finalAns;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int dvd, dsr;
    cin >> dvd >> dsr;

    try {
        int precision = 10;
        double quotient = findQuotientWithPrecision(dvd, dsr, precision);
        cout << fixed << setprecision(precision) << quotient << "\n";
    } catch (const exception &e) {
        cout << e.what() << "\n";
    }

    return 0;
}
