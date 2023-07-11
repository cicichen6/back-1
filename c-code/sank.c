#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <stdlib.h>
int main(){

    WINDOW *wim = initscr();
    
    box(wim,'%','%');
    
    int titleCOL = COLS/2 - 20;
    int titleLINE = LINES/2 - 3;

    attron(A_BOLD);
    // mvaddstr(y,x,str): 在(x,y) 上显示一串字串. 相当於呼叫move(y,x);addstr(str); printw(format,str)
    mvaddstr(titleLINE,titleCOL,"User Name:");
    char strPwd[20]; 
    sprintf(strPwd,"%10s","pwd");
    mvaddstr(titleLINE + 2,titleCOL, strPwd);
    attroff(A_BOLD);
  
    int strIndex = titleCOL + strlen("User Name:");
    
    move(titleLINE,strIndex);

    refresh();

    char userName[20];
    char password[20];

    memset(userName,0,sizeof(userName));
    getstr(userName);

    move(titleLINE + 2,strIndex);

    refresh();

    memset(password,'\0',sizeof(password));

    cbreak();
    noecho();

    int ii = 0;

    while(ii < sizeof(password)){
        password[ii] = getch();
        if(password[ii] == '\n'){
          password[ii] = '\0';
            break;
        }
    move(titleLINE + 2,strIndex + ii);
    addch('*');
    refresh();
    ii++;
    }

    echo();
    nocbreak();

    move(titleLINE + 4,titleCOL);
    char iname[] = "think8848";
    //char innerpassword = "111111";
    int a = 111111;
    char num[20]={'\0'};

    sprintf(num, "%d", a); 

    if(strncmp(userName,iname,strlen(iname)) == 0 && strncmp(password,num,strlen(num)) == 0){
        printw("%s","SUCCESS!");
    }else{
        printw("%s","INVALID!");
    }
    refresh();

    getchar();

    endwin();
}
