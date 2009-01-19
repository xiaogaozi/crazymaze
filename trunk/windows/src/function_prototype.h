/*
 * All prototypes of functions.
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

#ifndef FUNCTION_PROTOTYPE_H
#define FUNCTION_PROTOTYPE_H

#include "type_define.h"

Status CreateMaze(MazeType*, PosType*, PosType*);
int LoadMaze(MazeType*, PosType*, PosType*);
Status MazePrint(MazeType);
void MazePath(MazeType, PosType, PosType);
Status Compare(int*);
void Dynamic_Show(MazeType, int, PosType);
Status MazeGameLev1(MazeType, PosType, PosType);
Status MazeGameLev2(MazeType, PosType, PosType);
Status MazeGameLev3(MazeType, PosType, PosType);
int ShowMenu(char* [], int);

/*
 * Link list.
 */
Status InitList_L(LinkList*);
Status ListInsert_L(LinkList, int, ElemType);
Status ListDelete_L(LinkList, int);
Status GetElem_L(LinkList, int, ElemType*);
Status PrintList_L(LinkList);
Status DestroyList_L(LinkList);

#endif
