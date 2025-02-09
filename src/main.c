// main.c

#include <ncurses.h>
#include "dashboard.h"
#include "exit_window.h"
#include "editor_ui.h"


int main(int argc, char** argv)
{

  FILE* file;

  setlocale(LC_CTYPE, "en_US.UTF-8"); // setting utf-8

  signal(SIGINT, keyboard_interruption_handler); // for endwin if Ctrl C
  initscr();
  init_pair(1, COLOR_WHITE, 232); // main menu colors
  bkgd(COLOR_PAIR(1));
  refresh();
  cbreak();
  noecho();

  int row, col;
  getmaxyx(stdscr, row, col);

  char filename[255];

  if(argc == 1)
  {
    strcpy(filename, init_dashboard(row, col));

  } else 
  {
    strcpy(filename, argv[1]);
  }
  

  file = fopen(argv[1], "r+");
  if(file != NULL)
  init_editor(file, row, col, filename);  
  
  refresh();
  
  
  move(row, col);
  getch();
  endwin();
}
