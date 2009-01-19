/*
 * Show menu.
 * Copyright (C) 2008-? Crazy Maze Group
 */

/*
 * This file is part of Crazy Maze.
 
 * Crazy Maze is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Crazy Maze is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include "getch.h"

int ShowMenu(char* menu[], int item_sum)
{
  char c;
  int i = 1, j;

  system("clear");
  printf("\n\n\n\t========= Crazy Maze =========\n\n");
  for (j = 1; j != item_sum + 1; ++j)
  {
    if (j == i)
      printf("\t\t> %s <\n", menu[j - 1]);
    else
      printf("\t\t  %s\n", menu[j - 1]);
  }
  printf("\n\t==============================\n\n");

  while (1)
  {
    c = getch();
    if (c == 10)
      break;
    c = getch();
    c = getch();
    switch (c)
    {
      case 65 :                 // up
        if (i > 1)
          --i;
        break;
      case 66 :                 // down
        if (i < item_sum)
          ++i;
        break;
    }
    system("clear");
    printf("\n\n\n\t========= Crazy Maze =========\n\n");
    for (j = 1; j != item_sum + 1; ++j)
    {
      if (j == i)
        printf("\t\t> %s <\n", menu[j - 1]);
      else
        printf("\t\t  %s\n", menu[j - 1]);
    }
    printf("\n\t==============================\n\n");
  }

  return i;
}
