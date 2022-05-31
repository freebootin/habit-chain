#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct {
  char name[30];
  int days;
} Habit;

void print_bar(int row, int col, int days);

int main(int argc, char *argv[])
{
  char header[] = "Habit Chain";
  int row, col;

  initscr();
  cbreak();
  noecho();
  curs_set(0);

  getmaxyx(stdscr, row, col);
  
  mvprintw(5, (col - strlen(header)) / 2, "%s", header);
  refresh();
  print_bar(6, 0, 15);
  getch();
  endwin();

  return 0;
}

void print_bar(int row, int col, int days)
{
  move(row, col);
  for (int i = 0; i < days; i++) {
    mvaddch(row, col + i, '#');
    refresh();
  }
}

