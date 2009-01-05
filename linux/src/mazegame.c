/*
 * Fucking wonderful maze game :)
 * Copyright (C) 2008-? Li Xiaolan
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
#include <time.h>
#include "type_define.h"
#include "function_prototype.h"
#include "getch.h"

/*
 * Level 1.
 */
Status MazeGameLev1(MazeType maze, PosType start, PosType end)
{
  maze.maze[start.y][start.x] = 6;
  MazePrint(maze);
  printf("\n游戏开始, 请使用方向键控制, 走到出口即为胜利, 按q键退出.\n\n");
  maze.maze[start.y][start.x] = 1;

  int i = start.y, j = start.x, step = 0;
  char c;

  while (1)
  {
    c = getch();
    if (c == 113)
      break;
    c = getch();
    c = getch();
    switch (c)
    {
      case 65 :                 // up
        {
          i--;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }

          break;
        }
      case 66 :                 // down
        {
          i++;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }

          break;
        }
      case 67 :                 // right
        {
          j++;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }

          break;
        }
      case 68 :                 // left
        {
          j--;

          if (j < 0)
          {
            ++j;
            break;
          }

          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }

          break;
        }
    }

    /*
     * If reach the end, then exit.
     */
    if (i == end.y && j == end.x)
    {
      printf("Congratulation!\n");
      break;
    }

    if (i < 0)                  // out of top range
    {
      i++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j < 0)             // out of left range
    {
      maze.maze[i][j] = 0;
      j++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (i >= ROW_NUM)      // out of bottom range
    {
      i--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j >= COL_NUM)      // out of right range
    {
      maze.maze[i][j] = 0;
      j--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else
      ;
  }

  printf("你走了 %d 步\n\n", step);

  return OK;
}

Status MazeGameLev2(MazeType maze, PosType start, PosType end)
{
  maze.maze[start.y][start.x] = 6;
  MazePrint(maze);
  printf("\n游戏开始, 请使用方向键控制, 走到出口即为胜利, 按q键退出.\n\n");
  maze.maze[start.y][start.x] = 1;

  int i = start.y, j = start.x, step = 0;
  char c;

  while (1)
  {
    c = getch();
    if (c == 113)
      break;
    c = getch();
    c = getch();
    switch (c)
    {
      case 65 :                 // up
        {
          i--;
          if (maze.maze[i][j] == 1)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else if (maze.maze[i][j] == 0)
          {
            i++;
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
          }

          break;
        }
      case 66 :                 // down
        {
          i++;
          if (maze.maze[i][j] == 1)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else if (maze.maze[i][j] == 0)
          {
            i--;
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
          }

          break;
        }
      case 67 :                 // right
        {
          j++;
          if (maze.maze[i][j] == 1)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else if (maze.maze[i][j] == 0)
          {
            j--;
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
          }

          break;
        }
      case 68 :                 // left
        {
          j--;
          if (maze.maze[i][j] == 1)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else if (maze.maze[i][j] == 0)
          {
            j++;
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
          }

          break;
        }
    }

    /*
     * If reach the end, then exit.
     */
    if (i == end.y && j == end.x)
    {
      printf("Congratulation!\n");
      break;
    }

    if (i < 0)                  // out of top range
    {
      i++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j < 0)             // out of left range
    {
      j++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (i >= ROW_NUM)      // out of bottom range
    {
      i--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j >= COL_NUM)      // out of right range
    {
      j--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else
      ;
  }

  printf("你走了 %d 步\n\n", step);

  return OK;
}

Status MazeGameLev3(MazeType maze, PosType start, PosType end)
{
  int i = start.y, j = start.x, step = 0, m, n;
  char c;

  /*
   * Make bombs.
   */
  srandom(time(NULL));
  for (m = 0; m != ROW_NUM; ++m)
    for (n = 0; n != COL_NUM; ++n)
      if ((m != i && n != j) || (m != end.y && n != end.x))
      {
        if ((random() % 10 + 1) <= 2)
          maze.maze[m][n] = 5;
      }

  maze.maze[i][j] = 6;
  MazePrint(maze);
  printf("\n游戏开始, 请使用方向键控制, 小心炸弹! 走到出口即为胜利, 按q键退出.\n\n");
  maze.maze[i][j] = 1;

  while (1)
  {
    c = getch();
    if (c == 113)
      break;
    c = getch();
    c = getch();
    switch (c)
    {
      case 65 :                 // up
        {
          i--;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else
            if (maze.maze[i][j] == 5)
            {
              printf("Game over! Thanks join!\n\n");
              return OK;
            }

          break;
        }
      case 66 :                 // down
        {
          i++;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else
            if (maze.maze[i][j] == 5)
            {
              printf("Game over! Thanks join!\n\n");
              return OK;
            }

          break;
        }
      case 67 :                 // right
        {
          j++;
          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else
            if (maze.maze[i][j] == 5)
            {
              printf("Game over! Thanks join!\n\n");
              return OK;
            }

          break;
        }
      case 68 :                 // left
        {
          j--;

          if (j < 0)
          {
            ++j;
            break;
          }

          if (maze.maze[i][j] == 1 || maze.maze[i][j] == 0)
          {
            maze.maze[i][j] = 6;
            MazePrint(maze);
            maze.maze[i][j] = 1;
            ++step;
          }
          else
            if (maze.maze[i][j] == 5)
            {
              printf("Game over! Thanks join!\n\n");
              return OK;
            }

          break;
        }
    }

    /*
     * If reach the end, then exit.
     */
    if (i == end.y && j == end.x)
    {
      printf("Congratulation!\n");
      break;
    }

    if (i < 0)                  // out of top range
    {
      i++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j < 0)             // out of left range
    {
      maze.maze[i][j] = 0;
      j++;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (i >= ROW_NUM)      // out of bottom range
    {
      i--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else if (j >= COL_NUM)      // out of right range
    {
      maze.maze[i][j] = 0;
      j--;
      maze.maze[i][j] = 6;
      MazePrint(maze);
      maze.maze[i][j] = 1;
    }
    else
      ;
  }

  printf("你走了 %d 步\n\n", step);

  return OK;
}
