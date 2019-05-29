// $ sudo apt-get install ncurses-dev
// $ sudo apt-get install gcc

// $ gcc -lncurses kawakudari.c -o kawakudari.exe
// $ ./kawakudari.exe

#include <stdlib.h>  // rand()
#include <unistd.h>  // usleep()
#include <ncurses.h>

int main(int argc, char ** argv){
	// omajinai
	initscr();
	noecho();
	curs_set(0);
	WINDOW * win = newwin(24,32,0,0);
	nodelay(win,TRUE);
	scrollok(win,TRUE);
	keypad(win,TRUE);

	// kawakudari
	wclear(win);int x = 15;
	while(1) {
		mvwprintw(win,5,x,"0");
		mvwprintw(win,23,rand()%32,"*");

		int c = wgetch(win);
		if(c == KEY_LEFT ){ x -= 1;}
		if(c == KEY_RIGHT){ x += 1;}
		if (mvwinch(win,6,x) == '*') break;

		scroll(win);
		wrefresh(win);
		usleep(80 * 1000);
	}

	// omajinai
	nodelay(win,FALSE);
	while('q' != wgetch(win));
	delwin(win);
	endwin();
}

