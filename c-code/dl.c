#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <stdlib.h>
WINDOW *logwin;
#define RUNLOG(str)  runlog(logwin, str)
 void runlog(WINDOW *win, char *str);
 void cleanline(WINDOW *win, int y, int x);  
 WINDOW* logw();

int main(){
    WINDOW *win = initscr();
    //cbreak;
    box(win,'-','-');
    refresh();

    logwin = logw();

    RUNLOG("a");
    RUNLOG("b");
    
/*
    RUNLOG("c");
    RUNLOG("d");
    RUNLOG("e");
    RUNLOG("f");*/
    refresh();
    getchar();

    endwin();

    return 0;
}

WINDOW* logw(){
    WINDOW *logwin = newwin(5,5,10,10);
    //box(logwin, '#', '#');
   // mvwprintw(logwin, 0, 0, " LOG ");
    wrefresh(logwin);

    return logwin;
}

void runlog(WINDOW *win, char *str){
    static char logbuf[5][20] = {0};
    static int  index = 0;

    strcpy(logbuf[index], str);

    int i = 0;

    for (; i < 5; ++i) {
        cleanline(win, i+1, 1); 
        mvwprintw(win, i+1, 1, logbuf[(index+i) % 5]);
        wrefresh(win);
    }

    printf("%s",logbuf[4]);

    index = (index + 5 - 1) % 5;
}

void cleanline(WINDOW *win, int y, int x){
    char EMPTYLINE[20] = {0}; 

    memset(EMPTYLINE, ' ', 19);

    mvwprintw(win, y, x, EMPTYLINE);

    wrefresh(win);
}
