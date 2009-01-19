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

int curstep = 0;                // ��¼·������
extern int alist;               // record the times of recursion
extern int stepset[MAX_WAY]; // ����һ��һά�������洢����·���ĳ���, 0�±�������¼�ҵ����ܵ�·����.
extern LinkList Temp;        // ����һ���ݴ�����������·��
extern LinkList LinkListArray[MAX_WAY]; // ����һ�������������洢����·��

/*
 * �������ϵ�ֵΪ1ʱ, ����ͨ��, ����OK, ���򷵻�ERROR.
 */
Status Pass(MazeType maze, PosType p)
{
  if (maze.maze[p.y][p.x] == 1)	// x���У�y����
    return OK;
  else
    return ERROR;
}

/*
 * Ѱ����һλ��.
 */
void NextPos(PosType e, PosType* next, int di)
{
  (*next).x = e.x;
  (*next).y = e.y;

  switch (di)
  {
    case 1:
      ++(*next).x;
      break;                    // ����
    case 2:
      ++(*next).y;
      break;                    // ����
    case 3:
      --(*next).x;
      break;                    // ����
    case 4:
      --(*next).y;
      break;                    // ����
  }
}

/*
 * ���ݴ������Ƶ����������е�����.
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
 * ����·��������������.
 */
void Savepath()
{
  copyLinkList(Temp, &LinkListArray[stepset[0] + 1]);
  stepset[0]++;                  // the sum of pathway
  stepset[stepset[0]] = curstep; // store the steps in this pathway
}

/*
 * ��λ�ÿ���ͨ��ʱ, �ѵ�ͼ���Ϊ2, ���ºۼ�.
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
       * tag����1�������������ų���.
       */
      if (next.x == end.x && next.y == end.y)
        tag = 1;

      if (!Pass(maze, next))    // �ж��Ƿ�Ϊͨ·��δ�߹�
      {
        /*
         * ������������û�б���ǹ�, ��ִ�����¹���.
         */
        if (!Pass(maze, curpos))
        {
          curstep++;
          FootPrint(&maze, curpos);
          ListInsert_L(Temp, curstep, curpos); // insert current point to linked list
        }

        ++alist;                   // record the times of recursion
        MazePath(maze, next, end); // ����һ��·�������ٴ��ж�

        if (di == 4)            // �ж��ĸ������޷���ͨ
        {
          ListDelete_L(Temp, curstep); // delete current point from linked list
          curstep--;            // ����
        }
        else if (di == 4 && tag == 1)
          curstep--;            // ����
        else
          ;
      }
      else
      {
        if (di == 4)            // �ж��ĸ������޷���ͨ
        {
          /*
           * ����������������ǹ�, ��ִ�����¹���.
           */
          if (Pass(maze, curpos))
          {
            ListDelete_L(Temp, curstep); // delete current point from linked list
            curstep--;          // ����
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
