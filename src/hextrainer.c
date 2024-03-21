#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    fp = fopen(argv[1], "r");

    initscr();

    while(!feof(fp)) {
        addch(fgetc(fp));
        refresh();
        napms(16);
    }

    wgetch(stdscr);
    endwin();

    fclose(fp);
    return 0;
}
