
#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1000010;
int n;

int uf[N];

void init( void ) {
    for(int i = 0; i < N; i++)
        uf[i] = -1;
}

/* Find root of set containing x */
int root( int x ) {
    int r = x;

    /* Find root */
    while(uf[r] >= 0)
        r = uf[r];

    /* Compress path to root */
    while(uf[x] >= 0) {
        int tmp = uf[x];
        uf[x] = r;
        x = tmp;
    }

    return r;
}

/* Union of sets containing x and y */
void join( int x, int y ) {
    x = root(x);
    y = root(y);

    if(x != y) {
        if(uf[x] < uf[y]) {
            uf[x] += uf[y];
            uf[y] = x;
        }
        else {
            uf[y] += uf[x];
            uf[x] = y;
        }
    }
}

int main( void ) {

    init();

    assert(root(1) != root(2));
    join(1, 2);
    assert(root(1) == root(2));

    join(3, 4);
    join(2, 3);
    assert(root(1) == root(4));

    return 0;
}
