/*
 * Dynamic print the maze.
 * Copyright (C) 2008-? Ding Rui
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
#include <unistd.h>
#include "type_define.h"
#include "function_prototype.h"

#define SHOW_TIME 1000000       // 演示速度, 微秒

int stepset[MAX_WAY];
LinkList LinkListArray[MAX_WAY];

/*
 * 打印迷宫.
 */
Status MazePrint(MazeType maze)
{
  int i, j;

  system("cls");
  printf("迷宫图为: (空白表示通路, ■ 表示墙)\n");

  for (i = 0; i < maze.m; i++)
  {
    for (j = 0; j < maze.n; j++)
      if (maze.maze[i][j] == 0)
        printf("■");            // wall
      else if (maze.maze[i][j] == 1)
        printf("  ");           // road
      else if (maze.maze[i][j] == 2)
        printf(". ");           // pathway
      else if (maze.maze[i][j] == 3)
        printf("- ");           // dead way
      else if (maze.maze[i][j] == 5)
        printf("●");            // bomb
      else if (maze.maze[i][j] == 6)
        printf("囧");           // jiong
      else
        ;
    printf("\n");
  }

  return OK;
}

/*
 * 动态演示迷宫走法.
 */
void Dynamic_Show(MazeType Dynamic_Maze, int index, PosType end)
{
  ElemType e;
  int i;

  for (i = 1; i != stepset[index] + 1; ++i)
  {
    GetElem_L(LinkListArray[index], i, &e);
    Dynamic_Maze.maze[e.y][e.x] = 2; // mark this point as pathway
    MazePrint(Dynamic_Maze);         // print the maze
    usleep(SHOW_TIME);               // microsecond lag
  }
  Dynamic_Maze.maze[end.y][end.x] = 2; // mark the exit as pathway
  MazePrint(Dynamic_Maze);
  printf("共走了 %d 步\n\n", stepset[index]);
}
