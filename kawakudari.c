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
	wresize(stdscr,24,32);
	nodelay(stdscr,TRUE);
	scrollok(stdscr,TRUE);
	keypad(stdscr,TRUE);

	// kawakudari
	clear();int x = 15;
	while(1) {
		mvprintw(5,x,"0");
		mvprintw(23,rand()%32,"*");

		int c = getch();
		if(c == KEY_LEFT ){ x -= 1;}
		if(c == KEY_RIGHT){ x += 1;}
		if (mvinch(6,x) == '*') break;

		scroll(stdscr);
		refresh();
		usleep(80 * 1000);
	}

	// omajinai
	nodelay(stdscr,FALSE);
	while('q' != getch());
	endwin();
}

