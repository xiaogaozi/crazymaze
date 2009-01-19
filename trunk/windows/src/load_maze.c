/*
 * Loading the maze data from random map file.
 * Copyright (C) 2008-? Gao Changjian
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

// -1156203886

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "type_define.h"

#define MAX_MAP_NUM 7             // maximum numbers of map file
#define FILENAME_SUFFIX_LEN 2     // length of map filename's suffix
#define FILENAME_PREFIX "mazemap" // map filename's prefix
#define MAP_FILE_PATH "map\\"     // the directory where store the map
#define FILENAME_LEN strlen(MAP_FILE_PATH) + strlen(FILENAME_PREFIX) + FILENAME_SUFFIX_LEN // length of map filename

int LoadMaze(MazeType* maze, PosType* entry, PosType* exit)
{
  srand(time(NULL));            // random seed

  int mapnumInt = rand() % MAX_MAP_NUM + 1; // 1 <= mapnum <= MAX_MAP_NUM
  char* mapfile = (char*) malloc(sizeof(char) * (FILENAME_LEN + 1)); // store the map filename
  char* mapnumStr = (char*) malloc(sizeof(char) * (FILENAME_SUFFIX_LEN + 1)); // store character type map number
  mapfile[0] = '\0';

  /*
   * Convert the integer type map number to character,
   * and store as a string.
   */
  if (mapnumInt < 10)
  {
    mapnumStr[0] = '0';
    mapnumStr[1] = (char) (mapnumInt + '0');
  }
  else
  {
    mapnumStr[0] = (char) (mapnumInt / 10 + '0');
    mapnumStr[1] = (char) (mapnumInt % 10 + '0');
  }
  mapnumStr[FILENAME_SUFFIX_LEN] = '\0';

  /*
   * Store the filename.
   */
  mapfile = strcat(mapfile, MAP_FILE_PATH);
  mapfile = strcat(mapfile, FILENAME_PREFIX);
  mapfile = strcat(mapfile, mapnumStr);

  /*
   * Open the map file.
   */
  FILE* fp = fopen(mapfile, "r");
  if (!fp)
    return ERROR;

  /*
   * Store the data to 'maze' array.
   */
  int i, j;
  for (i = 0; i != ROW_NUM; ++i)
  {
    for (j = 0; j != COL_NUM; ++j)
    {
      fscanf(fp, "%d", &(*maze).maze[i][j]);
      fseek(fp, 1, SEEK_CUR); // the offset is relative to the current position indicator
    }
  }

  /*
   * Get the coordinate of entry and exit.
   */
  fscanf(fp, "%d", &(*entry).x);
  fseek(fp, 1, SEEK_CUR); // the offset is relative to the current position indicator
  fscanf(fp, "%d", &(*entry).y);
  fseek(fp, 1, SEEK_CUR); // the offset is relative to the current position indicator
  fscanf(fp, "%d", &(*exit).x);
  fseek(fp, 1, SEEK_CUR); // the offset is relative to the current position indicator
  fscanf(fp, "%d", &(*exit).y);

  /*
   * Release the space.
   */
  if (!mapfile)
    free(mapfile);
  if (!mapnumStr)
    free(mapnumStr);
  mapfile = NULL;
  mapnumStr = NULL;

  fclose(fp);

  return OK;
}
