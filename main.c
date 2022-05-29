#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char mesg[] = "Habit Chain";
  int row, col;

  initscr();
  getmaxyx(stdscr, row, col);
  mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
  
  refresh();
  getch();
  endwin();

  return 0;
}
