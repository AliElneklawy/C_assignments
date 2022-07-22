#include <stdio.h>
#include <stdlib.h>

/*int car1(int d, int m, int n, int stops[])
{
    int rem_dist = m, fills = 0;

    for(int i = 0; i < n+1; i++){
        if( (stops[i+1] - stops[i]) > m ){
            fills = -1;
            break;
        }
        if((stops[i+1] - stops[i]) > rem_dist){
            ++fills;
            rem_dist = m;
        }
        rem_dist = rem_dist - (stops[i+1] - stops[i]);
    }
    //printf("%d\n", fills);
    return fills;
}*/



int main()
{
    int d, m, n, fills = 0, i;
    scanf("%d", &d);
    scanf("%d", &m);
    scanf("%d", &n);
    int stops[n+2], rem_dist = m;
    stops[0] = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &stops[i]);
    }
    stops[n+1] = d;

    for(int i = 0; i < n+1; i++){
        if( (stops[i+1] - stops[i]) > m ){
            fills = -1;
            break;
        }
        if((stops[i+1] - stops[i]) > rem_dist){
            ++fills;
            rem_dist = m;
        }
        rem_dist = rem_dist - (stops[i+1] - stops[i]);
    }
    printf("%d\n", fills);
}

        /**STRESS TEST**/

    /*while(1){
        int d;
        int m = rand() % 50;
        d = (rand()%100) + m;
        int n = (rand() % 10) + 3;
        int stops[n+2];
        int length = sizeof(stops)/sizeof(stops[0]);
        stops[0] = 0;
        stops[n+1] = d;
        for(int i = 1; i<=n; i++){
            stops[i]= (rand() % m) + 2;
        }
        for (int i = 0; i < length; i++) {
            for (int j = i+1; j < length; j++) {
               if(stops[i] > stops[j]) {
                   temp = stops[i];
                   stops[i] = stops[j];
                   stops[j] = temp;
               }
            }
        }
        for(int i = 0; i<=n+1; i++){
            printf("%d ", stops[i]);
        }

        printf("\nd: %d m: %d n: %d\n", d, m, n);
        val1 = car1(d, m, n, stops);
        //int *val2 = car2(d, m, n, stops);
        printf("ans: %d\n\n", val1);
        //sleep(10);
        if(val1 >= 3)    break;
    }*/
//    printf("%d", val1);

