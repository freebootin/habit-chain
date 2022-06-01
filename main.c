#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct {
  char *name;
  int days;
} Habit;

void display_habit(int row, int col, Habit *habit);
void print_bar(int row, int col, int days);
void get_habit_entry(FILE *fp);


int main(int argc, char *argv[])
{
  char header[] = "Habit Chain";
  int row, col;

  FILE *fp;
  char *buffer;
  int buffer_size = 64;


  Habit *my_habit;

  fp = fopen("lines", "r");

  get_habit_entry(fp);

  fclose(fp);
  
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

/*
void get_habit_entry(FILE *fp)
{
  char *buffer;
  int buffer_size = 64;
  char *s;
  Habit *habit = malloc(sizeof(Habit));
  
  if (fp == NULL) {
    perror("Error opening file");
    exit(-1);
  }

  buffer = (char *)malloc(buffer_size * sizeof(char));
  if (fgets(buffer, buffer_size, fp) != NULL) {
    printf("%s", buffer);

    // cannot rely on s = NULL to "increment"
    for (s = buffer; (s = strtok(s, " ")) != NULL; s = NULL) {
      printf("Token: %s\n", s);
      if (s == NULL) {
        printf("NULL\n");
      }
      else {
        printf("not NULL\n");
      }
    }

  }
}
*/
