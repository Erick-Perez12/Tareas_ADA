#include <cmath>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

Point p[10001];
int tmp[10001];

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int cmpx(const Point& a, const Point& b) {
    return a.x < b.x;
}

int cmpy(int x, int y) {
    return p[x].y < p[y].y;
}

double solu(int l, int r) {
    if (r == l + 1) {return dist(p[l], p[r]);}
    if (l == r) { return numeric_limits<double>::max(); }
    int mid = (l + r) / 2;
    double resp = min(solu(l, mid), solu(mid + 1, r));
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (fabs(p[i].x - p[mid].x) <= resp) { tmp[cnt++] = i; }
    }
    sort(tmp, tmp + cnt, cmpy);
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (p[tmp[j]].y - p[tmp[i]].y >= resp) {
                break;
            }
            resp = min(resp, dist(p[tmp[i]], p[tmp[j]]));
        }
    }
    return resp;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cout << "INSERTAR PUNTOS \n";
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        sort(p + 1, p + 1 + n, cmpx);
        double resp = solu(1, n);
        if (resp >= 10000) {
            cout << "INFINITY" << endl;
        }
        else {
            cout << fixed << setprecision(4) << resp << endl;
        }
    }
    return 0;
}
