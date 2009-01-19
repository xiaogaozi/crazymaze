/*
 * A crazy maze demo.
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
                        "�Թ����",
                        "�Թ���Ϸ",
                        "  �˳�  "
                      };
  char* game_menu[] = {
                        " �Թ����� ",
                        " ����ð�� ",
                        " �ռ���ս ",
                        "�ص����˵�"
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
          printf("�밴�������ʼ�Զ���ʾ...");
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
            printf("\nû��ͨ·!\n");
          else
            Dynamic_Show(maze, i, end);

          printf("��ʾ����, ��������ص����˵�...");
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
              printf("��������ص����˵�...");
              getch();
              break;
            case 2 :
              MazeGameLev2(maze, start, end);
              printf("��������ص����˵�...");
              getch();
              break;
            case 3 :
              MazeGameLev3(maze, start, end);
              printf("��������ص����˵�...");
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
