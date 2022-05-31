#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct {
  char name[30];
  int days;
} Habit;

void display_habit(int row, int col, Habit *habit);
void print_bar(int row, int col, int days);

int main(int argc, char *argv[])
{
  char header[] = "Habit Chain";
  int row, col;
  Habit my_habit = {
    .name = "Drinking Coffee",
    .days = 11
  };

  initscr();
  cbreak();
  noecho();
  curs_set(0);

  getmaxyx(stdscr, row, col);
  
  mvprintw(5, (col - strlen(header)) / 2, "%s", header);
  refresh();

  display_habit(7, 0, &my_habit);

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

void display_habit(int row, int col, Habit *habit)
{
  mvprintw(row, col, "Habit: %s", habit->name);
  print_bar(row + 1, col, habit->days);
}
