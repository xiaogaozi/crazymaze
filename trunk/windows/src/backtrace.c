/*
 * Backtrace Algorithm
 * Copyright (C) 2008-? Yang Jin & Ding Rui
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
#include "type_define.h"
#include "function_prototype.h"

int curstep = 0;                // 记录路径长度
extern int alist;               // record the times of recursion
extern int stepset[MAX_WAY]; // 构造一个一维数组来存储多条路径的长度, 0下标用来记录找到的总的路径数.
extern LinkList Temp;        // 构造一个暂存链表来跟踪路径
extern LinkList LinkListArray[MAX_WAY]; // 构造一个链表数组来存储多条路径

/*
 * 当坐标上的值为1时, 可以通过, 返回OK, 否则返回ERROR.
 */
Status Pass(MazeType maze, PosType p)
{
  if (maze.maze[p.y][p.x] == 1)	// x是列，y是行
    return OK;
  else
    return ERROR;
}

/*
 * 寻找下一位置.
 */
void NextPos(PosType e, PosType* next, int di)
{
  (*next).x = e.x;
  (*next).y = e.y;

  switch (di)
  {
    case 1:
      ++(*next).x;
      break;                    // 右移
    case 2:
      ++(*next).y;
      break;                    // 下移
    case 3:
      --(*next).x;
      break;                    // 左移
    case 4:
      --(*next).y;
      break;                    // 上移
  }
}

/*
 * 将暂存链表复制到链表数组中的链表.
 */
void copyLinkList(LinkList Temp, LinkList* L)
{
  int k;
  ElemType e;

  for (k = 1; k <= curstep; k++)
  {
    GetElem_L(Temp, k, &e);
    ListInsert_L(*L, k, e);
  }
}

/*
 * 保存路径到链表数组中.
 */
void Savepath()
{
  copyLinkList(Temp, &LinkListArray[stepset[0] + 1]);
  stepset[0]++;                  // the sum of pathway
  stepset[stepset[0]] = curstep; // store the steps in this pathway
}

/*
 * 当位置可以通过时, 把地图标记为2, 留下痕迹.
 */
void FootPrint(MazeType* maze, PosType p)
{
  (*maze).maze[p.y][p.x] = 2;
}

/*
 * Backtrace algorithm.
 */
void MazePath(MazeType maze, PosType curpos, PosType end)
{
  int di, tag = 0;
  PosType next;

  /*
   * Control the times of recursion.
   */
  if (alist > 8001)
    return;

  if (curpos.x == end.x && curpos.y == end.y)
  {
    Savepath();                 // store this pathway
  }
  else
  {
    for (di = 1; di <= 4; di++)
    {
      NextPos(curpos, &next, di);

      /*
       * tag等于1代表这个点紧挨着出口.
       */
      if (next.x == end.x && next.y == end.y)
        tag = 1;

      if (!Pass(maze, next))    // 判断是否为通路且未走过
      {
        /*
         * 如果这个点曾经没有被标记过, 就执行以下过程.
         */
        if (!Pass(maze, curpos))
        {
          curstep++;
          FootPrint(&maze, curpos);
          ListInsert_L(Temp, curstep, curpos); // insert current point to linked list
        }

        ++alist;                   // record the times of recursion
        MazePath(maze, next, end); // 在下一个路径点上再次判断

        if (di == 4)            // 判断四个方向都无法走通
        {
          ListDelete_L(Temp, curstep); // delete current point from linked list
          curstep--;            // 回溯
        }
        else if (di == 4 && tag == 1)
          curstep--;            // 回溯
        else
          ;
      }
      else
      {
        if (di == 4)            // 判断四个方向都无法走通
        {
          /*
           * 如果这个点曾经被标记过, 就执行以下过程.
           */
          if (Pass(maze, curpos))
          {
            ListDelete_L(Temp, curstep); // delete current point from linked list
            curstep--;          // 回溯
          }
        }
      }
    }
  }
}

/*
 * Seek the shortest pathway through compare the elements of array.
 */
Status Compare(int* index)
{
  int i;
  int shorteststep;

  /*
   * If there aren't pathway, then return error.
   */
  if (!stepset[0])
    return ERROR;

  *index = 1;
  shorteststep = stepset[1];

  for (i = 2; i <= stepset[0]; i++)
  {
    if (shorteststep > stepset[i])
    {
      shorteststep = stepset[i];
      *index = i;
    }
  }

  return OK;
}
