#include "editor_ui.h"

void init_editor(FILE* file, int row, int col, const char* filename)
{
  mvprintw(row-1, 1, "\"%s\"", filename);
  
  int pos_y = 1;

  char buffer[250];
  while(fgets(buffer, sizeof(buffer), file))
  {
    mvaddstr(pos_y++, 1, buffer);
  }
  refresh();

  move(1,1);
  raw();
  echo();
  keypad(stdscr, true);
  
  short key;
  while(1)
  {
    int key = getch();
    if(key == KEY_UP)
      if(getcury(stdscr) != 1) move( getcury(stdscr)-1, getcurx(stdscr) );
    if(key == KEY_RIGHT)
      if(getcurx(stdscr) != col - 1) move( getcury(stdscr), getcurx(stdscr)+1 );
    if(key == KEY_DOWN)
      if(getcury(stdscr) != row - 1) move( getcury(stdscr)+1, getcurx(stdscr) );
    if(key == KEY_LEFT)
      if(getcurx(stdscr) != 1) move( getcury(stdscr), getcurx(stdscr)-1 );
    if(key == 3) keyboard_interruption_handler();
  }

}
