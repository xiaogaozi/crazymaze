/*
 * A crazy maze demo.
 * Copyright (C) 2008-? Crazy Maze Group
 */

/*
 * This file is part of Crazy Maze.
 
 * crazy maze is free software: you can redistribute it and/or modify
 * it under the terms of the gnu general public license as published by
 * the free software foundation, either version 3 of the license, or
 * (at your option) any later version.

 * this program is distributed in the hope that it will be useful,
 * but without any warranty; without even the implied warranty of
 * merchantability or fitness for a particular purpose.  see the
 * gnu general public license for more details.

 * you should have received a copy of the gnu general public license
 * along with this program.  if not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "function_prototype.h"
#include "type_define.h"

int stepset[10];
int alist;
LinkList Temp;
LinkList LinkListArray[10];

int main()
{
  MazeType maze;
  PosType start;
  PosType end;

  char* main_menu[] = {
                        "迷宫求解",
                        "迷宫游戏",
                        "  退出  "
                      };
  char* game_menu[] = {
                        " 迷宫新手 ",
                        " 进阶冒险 ",
                        " 终极挑战 ",
                        "回到主菜单"
                      };

  while (1)
  {
    switch (ShowMenu(main_menu, 3))
    {
      case 1 :
        {
          /*
           * Create the maze from map file.
           */
          CreateMaze(&maze, &start, &end);

          MazePrint(maze);
          printf("请按任意键开始自动演示...");
          getch();

          /*
           * Use backtrace algorithm to find the pathway.
           */
          InitList_L(&Temp);
          int i;
          for (i = 0; i != MAX_WAY; ++i)
          {
            InitList_L(&LinkListArray[i]);
            stepset[i] = 0;
          }
          alist = 0;
          MazePath(maze, start, end);

          /*
           * Dynamic print the maze.
           */
          if (Compare(&i))
            printf("\n没有通路!\n");
          else
            Dynamic_Show(maze, i, end);

          printf("演示结束, 按任意键回到主菜单...");
          getch();

          /*
           * Destroy the linked list.
           */
          DestroyList_L(Temp);
          for (i = 1; i <= stepset[0]; ++i)
            DestroyList_L(LinkListArray[i]);

          break;
        }
      case 2 :
        {
          /*
           * Create the maze from map file.
           */
          CreateMaze(&maze, &start, &end);

          switch (ShowMenu(game_menu, 4))
          {
            case 1 :
              MazeGameLev1(maze, start, end);
              printf("按任意键回到主菜单...");
              getch();
              break;
            case 2 :
              MazeGameLev2(maze, start, end);
              printf("按任意键回到主菜单...");
              getch();
              break;
            case 3 :
              MazeGameLev3(maze, start, end);
              printf("按任意键回到主菜单...");
              getch();
              break;
            case 4 :
              break;
          }

          break;
        }
      case 3 :
        {
          exit(EXIT_SUCCESS);
        }
    }
  }
}
