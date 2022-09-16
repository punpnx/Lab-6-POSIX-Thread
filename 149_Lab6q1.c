#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum;
void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid; //thread id
    pthread_attr_t attr; //set of attr
    pthread_attr_init(&attr); //get default attr
    pthread_create(&tid, &attr, runner, argv[1]);

    int upperM = atoi(argv[1]);
    int m;
    int msum = 0;
    if(upperM > 0) {
        for(m = 0; m <= upperM; m++)
            msum += m;
    }
    //printf("msum = %d\n", msum);
    pthread_join(tid, NULL);
    printf("csum - msum = %d\n",csum - msum);
    return 0;
}

void *runner(void *param) {
    int upper = atoi(param);
    int i;
    csum = 0;
    if(upper > 0) {
        for(i = 0; i <= 2*upper; i++)
            csum += i;
    }
    //printf("csum = %d\n", csum);
    pthread_exit(0);
}
