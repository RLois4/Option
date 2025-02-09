// dashboard.h

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <locale.h>
#include <string.h>

#define BANNER_WIDTH 48
#define BANNER_HEIGHT 9

extern char* banner[];
extern char slogan[];

char* init_dashboard(int row, int col);

#endif
