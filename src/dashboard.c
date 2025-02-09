// dashboard.c
#include "dashboard.h"

char* banner[] = 
{ 
  "╔-------───────────────-----────────---────────╗",
  "│                                              │",
  "│  ____  _____ __________ ___   ____   __ __   │",
  "│ /    \\ |    \\\\---  ---/ \\ /  /    \\ |  \\\\ \\  │",
  "│ | () | | :--/    | |    | |  | () | \\ |\\\\| | │",
  "│ \\____/ \\_|      /___\\  /___\\ \\____/ /_| \\_/  |",
  "│                                              |",  
  "|                                              │",
  "╚──-────────────--------───────────────────────╝"
};

char slogan[] = "Your vim-like editor, but better!";

char* init_dashboard(int row, int col)
{
  curs_set(0);

  int start_row = (row - BANNER_HEIGHT) / 2;

  for(int i=0; i<BANNER_HEIGHT; i++)
    mvprintw( (start_row + i),  (col-BANNER_WIDTH) / 2, "%s", banner[i]);
  mvprintw(start_row + BANNER_HEIGHT + 2, (col - strlen(slogan)) / 2, "%s", slogan);

  mvprintw(row - 1, 1, "no files open");
  move(row-1, col-1);

  mvprintw(row - 3, 1, "press N for create a new file");
  
  short key;
  static char new_flname[257];  // 255 + 1 for \0 + 1 for test
  while(1)
  {
    key = getch();
    if(key == 'N' || key == 'n')
      break;
  }
  echo();
  curs_set(1);
  if(key == 'N' || key == 'n')
  do
  {
    move(row - 3, 1);
    clrtoeol();
    printw("Enter the name for new file: ");
    move(row - 3, 30);
    getstr(new_flname);

    if(strlen(new_flname) > 255)
    {
      move(row - 3, 1);
      clrtoeol();
      mvprintw(0, 1, "The name must be less than 256 characters long");
      refresh();
    }
  } while(strlen(new_flname) == 0 || strlen(new_flname) == 256);
  return new_flname;
}
