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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int ShowMenu(char* menu[], int item_sum)
{
  char c;
  int i = 1, j;

  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\t\t\t========= Crazy Maze =========\n\n");
  for (j = 1; j != item_sum + 1; ++j)
  {
    if (j == i)
      printf("\t\t\t\t> %s <\n", menu[j - 1]);
    else
      printf("\t\t\t\t  %s\n", menu[j - 1]);
  }
  printf("\n\t\t\t==============================\n\n");

  while (1)
  {
    c = getch();
    if (c == 13)
      break;
    c = getch();
    switch (c)
    {
      case 72 :                 // up
        if (i > 1)
          --i;
        break;
      case 80 :                 // down
        if (i < item_sum)
          ++i;
        break;
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t========= Crazy Maze =========\n\n");
    for (j = 1; j != item_sum + 1; ++j)
    {
      if (j == i)
        printf("\t\t\t\t> %s <\n", menu[j - 1]);
      else
        printf("\t\t\t\t  %s\n", menu[j - 1]);
    }
    printf("\n\t\t\t==============================\n\n");
  }

  return i;
}
