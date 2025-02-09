// exit_window.c

#include "exit_window.h"

void keyboard_interruption_handler()
{
  endwin();
  exit(0);
}
