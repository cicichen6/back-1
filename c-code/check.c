#include <stdio.h>
#include <string.h>
#define NUM 5
 int runlog(char *str);
int main(){
    runlog("a01");
    runlog("b02");

    return 0;
}

int runlog(char// *str){
    //static char logbuf[NUM][20] = {0};
    static int index = 0;
    int ii = 0;
    strcpy(logbuf[index],str);
    printf("=============\n");
    for(;ii < NUM;ii++){
       int mod = ((ii + index) % NUM);
        printf("ii=%d,content=%s,number=%d\n",ii,logbuf[mod],mod);
    }
    
    printf("-----------------\n");
    index = (index + NUM - 1) % NUM;

    return 0;
}
