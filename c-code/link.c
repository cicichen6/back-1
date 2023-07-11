#include <stdio.h>
#include <stdlib.h>

struct Student {
    char Name[20];
    int Number;
    struct Student* pNext;

};

typedef struct Student* pStu;


int Count = 0;

pStu Creat()
{
    pStu pHead = NULL;
    pStu pNew,pEnd;
    pEnd = pNew = (pStu)malloc(sizeof(struct Student));
    printf("input Name,Number\n");
    scanf("%s",pNew->Name);
    scanf("%d",&pNew->Number); 
    while(pNew->Number != 0)
    {
        Count++;
	if(Count == 1){
	    pNew->pNext = NULL;
	    pEnd = pNew;
	    pHead = pNew;
	}
	else{
	    pNew->pNext = NULL;
	    pEnd->pNext = pNew;
	    pEnd = pNew;
         
	}
        pNew = (pStu)malloc(sizeof(struct Student));
	scanf("%s",pNew->Name);
	scanf("%d",&pNew->Number);
    }  
    free(pNew);

    return pHead;
}

void Print(pStu pHead)
{
    pStu pCurrent;
    pCurrent = pHead;

    while(pCurrent != NULL)
    {
  //      printf("%p", pCurrent);
        printf("%s",pCurrent->Name);
	      pCurrent = pCurrent->pNext;
    }
}

pStu insert(pStu pHead)
{
    pStu pNew = (pStu)malloc(sizeof(struct Student));
    printf("input new student name,number");
    scanf("%s",pNew->Name);
    scanf("%d",&pNew->Number);
    
    Count++;

    pNew->pNext = pHead;
    pHead = pNew;

    return pHead;
}


void delete(pStu *pHead)
{
    int index;
    pStu pCurrent,pPre;
    
    pPre = pCurrent = *pHead;
    
    printf("input one student's number to delete");
    scanf("%d",&index);
 
    if(index >= Count && index < 0){
        printf("wrong");
    }
    
    for(int ii = 1; ii <= index; ii++){
        pPre = pCurrent;
        pCurrent = pPre->pNext;
    }
    pPre->pNext = pCurrent->pNext;

    if(index == 0){
        *pHead = pCurrent->pNext;
        printf("%p\n-3-",*pHead);
    }

    free(pCurrent);
    pCurrent = NULL;
    Count--;
}


int main()
{
    pStu pHead;
    pHead = Creat();
    printf("%p-1-",pHead);
    pHead = insert(pHead);
    printf("%p-2-",pHead);
    Print(pHead);
    pStu *pp = &pHead; 
    delete(pp);
    printf("%p-4-",*pp);
    Print(*pp);

    return 0;    
}

	
