#include <stdio.h>
#include <stdlib.h>

long gcd(long long a, long long b);

int main()
{
    long long a, b, ans = 0;
    scanf("%lli %lli", &a, &b);
    ans = gcd(a, b);
    printf("%lli", ans);
}

long gcd(long long a, long long b)
{
    int r = 1, ans;
    int q;
    while(r != 0){
        if(b == 0)  break;
        r = a%b;
        q = a/b;
        a = b;
        b = r;
    }
    return a;
}
