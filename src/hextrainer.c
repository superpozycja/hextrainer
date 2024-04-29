#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
//    FILE* fp;
//    fp = fopen(argv[1], "r");

    initscr();

    /*
    while(!feof(fp)) {
        addch(fgetc(fp));
        refresh();
        napms(16);
    }
    */

    char* welcome = "h   e   x   t   r   a   i   n   e   r   ";
    char* wel_hex = "68  65  78  74  72  61  69  6e  65  72";
    while(1) {
        for(int i = 0; i < strlen(welcome); i++) {     
            for(int j = 0; j < strlen(welcome); j++) {
                if(welcome[j] == ' ') {
                    continue;
                }
                if (i==j) {
                    attron(A_BOLD);
                }
                mvaddch(30-(i<=j+3 && i >= j), 30+j, welcome[j]);
                attroff(A_BOLD);
            }
            mvprintw(32, 30, wel_hex);
            refresh();
            napms(32+8);
            clear();
        }
    }
//    fclose(fp);
    return 0;
}
