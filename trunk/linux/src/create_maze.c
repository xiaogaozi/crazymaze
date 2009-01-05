/*
 * Create the maze.
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

#include "type_define.h"
#include "function_prototype.h"

Status CreateMaze(MazeType* maze, PosType* start, PosType* end)
{
  if (LoadMaze(maze, start, end))
    return ERROR;

  (*maze).m = ROW_NUM;          // 行
  (*maze).n = COL_NUM;          // 列

  return OK;
}
