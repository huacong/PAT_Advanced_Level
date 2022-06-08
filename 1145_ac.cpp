#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false; 
    }
    return true;
}

int H(int key, int TSize){
    return key % TSize;
}

int msize, n, m, a, table[10010];
int main() {
    memset(table, -1, sizeof(table));
    scanf("%d%d%d", &msize, &n, &m);

    while (isPrime(msize) == false) msize++;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);

        bool founded = false;
        for (int j = 0; j < msize; j++) {
            int d = j * j;
            int tid = (H(a, msize) + d) % msize;
            if (table[tid] == -1) {
                founded = true;
                table[tid] = a;
                break;
            } 
        }
        if (founded == false) {
            printf("%d cannot be inserted.\n", a);
        }
    }
    int tot = 0;
    for(int i=0;i<msize;i++) printf("%d:%d \n",i,table[i]);
    printf("\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        int t = 0;
        bool founded = false;
        for (int j = 0; j < msize; j++) {
            tot++;
            int d = j * j;
            int tid = (H(a, msize) + d) % msize;
            if (table[tid] == a || table[tid] == -1) { // 找到或者不存在
                founded = true;
                break;
            }
        }
        if(founded ==false) {
            tot++;
        }
        printf("%d:%d\n",a,tot);
    }

    printf("%.1f\n", tot*1.0/m);

    return 0;
}
