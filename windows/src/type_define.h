/*
 * User-defined type and macro.
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

#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

#define OK 0
#define ERROR 1
#define TRUE 0
#define FALSE 1
#define OVERFLOW -2
#define ROW_NUM 39              // the row of maze
#define COL_NUM 39              // the column of maze
#define MAX_WAY 1000            // maximum number of pathway

typedef int Status;

/*
 * 定义坐标类型
 */
typedef struct
{
  int x;
  int y;
}PosType;

/*
 * 定义迷宫类型
 */
typedef struct
{
  int m, n;
  int maze[ROW_NUM][COL_NUM];   // 迷宫的最大范围
}MazeType;

/*
 * Link list.
 */
typedef PosType ElemType;
typedef struct LNode
{
  ElemType data;
  struct LNode* next;
}LNode, *LinkList;

#endif
