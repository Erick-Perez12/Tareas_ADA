#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100000;

struct Pairs {
    int l, r;
};

Pairs p[N], out[N];

int cmp(Pairs a, Pairs b) {
    return a.r > b.r;
}

int main() {
    int m, pi, po;
    cout << "Input \n";
    cin >> m;
    for (pi = 0;; pi++) {
        cin>>p[pi].l>>p[pi].r;
        if (p[pi].l == 0 && p[pi].r == 0) {
            break;
        }
    }
    sort(p, p + pi, cmp);
    int start = 0, end = m, i;
    po = 0;
    while (start < end) {
        for (i = 0; i < pi; i++) {
            if (p[i].l <= start && p[i].r > start) {
                start = p[i].r;
                out[po++] = p[i];
                break;
            }
        }
        if (i == pi) {
            break;
        }
    }
    cout<<"Output\n";
    if (start < end) {
        cout<<"No hay solucion\n";
    }
    else {
        cout << po << "\n";
        for (int i = 0; i < po; i++) {
            cout<<out[i].l<<" "<<out[i].r<<endl;
        }
    }

    return 0;
}
