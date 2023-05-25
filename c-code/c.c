#include <stdio.h>

int main(){
    char str1[30], str2[20];
    printf("please input a string:\n");
    fgets(str1, sizeof(str1), stdin);
    printf("please input another string:\n");
    fgets(str2, sizeof(str2), stdin);

    char *pStr1, *pStr2;
    pStr1 = str1;
    pStr2 = str2;
    
    int len = 0;
   
    do {
	len++;
    }
    while(str2[len] != '\n');

    int *index = NULL;

    for(int ii = 0; ii < sizeof(str1); ii++){
        if(*pStr2 == *(pStr1 + ii)) {
            for(int jj = 1; jj < len; jj++){
	        if (*(pStr2 + jj) != *(pStr1 + ii + jj) ){
		    break;
		}

		if(jj == len - 1) {
                    index = &ii;
		}
	    }	

	    if(index != NULL){
	        printf("Index is: %d", *index);
		break;
	    }
	}      

        if(ii == sizeof(str1) - 1){
            printf("No string mathed!");
	}		
    }

    return 0;
}
