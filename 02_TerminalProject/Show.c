#include <ncurses.h>

int main(const int argc, const char **argv)
{
    initscr();
    noecho();
    FILE *file = fopen(argv[1], "r");
    printw("NameFile: %s", argv[1]);
    refresh();
    
    WINDOW *win = newwin(LINES - 1, COLS, 1, 0);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    
    char *string;
    size_t buf;
    for (int i = 0; i < LINES; ++i) { 
        if (getline(&string, &buf, file) == -1) {
            break;
        }
        wprintw(win, "%s", string);
    }
    
    int key;
    key = wgetch(win);
    while (key != 27) {
        if (getline(&string, &buf, file) != -1 && key == 32 ) {
            wprintw(win, "%s", string);
        }
        key = wgetch(win);
    }
    
    fclose(file);
    delwin(win);
    endwin();

    return 0;
}
