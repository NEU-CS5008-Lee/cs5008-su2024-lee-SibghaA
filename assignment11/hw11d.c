// name: Sibgha Ahmad
// email: ahmad.si@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(d[n] != 0) return d[n];
    d[n] = 3 * dp(n - 2) + 2 * dp(n - 1);
    for(int i = n - 3; i >= 0; i--){
      d[n] += 2 * dp(i);
    }
    return d[n];

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
