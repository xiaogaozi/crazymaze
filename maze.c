// -1156203886

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0
#define COLUMN 50

typedef struct
{
  int x;
  int y;
}Point;

int step;
int stepset[100];

void CreateMaze(SElemType (*maze)[COLUMN], int row, int col)
{
  int i, j;

  for (i = 0; i != row; ++i)
    for (j = 0; j != col; ++j)
    {
      if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
        maze[i][j].grid = 1;
      else if ((i == 1 && j == 1) || (i == row - 2 && j == col - 2))
      {
        maze[i][j].grid = 0;
        maze[i][j].direction = 0;
        maze[i][j].pass = 0;
        maze[i][j].i = i;
        maze[i][j].j = j;
      }
      else
      {
        /*
         * random create
         */
        if ((rand() % 10) < 5)
        {
          maze[i][j].grid = 0;
          maze[i][j].direction = 0;
          maze[i][j].pass = 0;
          maze[i][j].i = i;
          maze[i][j].j = j;
        }
        else
          maze[i][j].grid = 1;
      }
    }
}

void PrintMaze(SElemType (*maze)[COLUMN], int row, int col)
{
  int i, j;

  for (i = 0; i != row; ++i)
  {
    for (j = 0; j != col; ++j)
    {
      if (maze[i][j].pass == 2)
      {
        switch (maze[i][j].direction)
        {
          case 1 :
            printf("→ ");
            break;
          case 2 :
            printf("↓ ");
            break;
          case 3 :
            printf("← ");
            break;
          case 4 :
            printf("↑ ");
            break;
          default :
            printf("￥");
        }
      }
      else if (maze[i][j].grid)
        printf("▇ ");
      else
        printf("  ");
    }

    printf("\n");
  }
}

SElemType NextPosition(SElemType (*maze)[COLUMN], int i, int j)
{
  switch (maze[i][j].direction)
  {
    case 0 :
      if (!maze[i][j + 1].grid && !maze[i][j + 1].pass)
      {
        maze[i][j].direction = 1;
        return maze[i][j + 1];
      }
    case 1 :
      if (!maze[i + 1][j].grid && !maze[i + 1][j].pass)
      {
        maze[i][j].direction = 2;
        return maze[i + 1][j];
      }
    case 2 :
      if (!maze[i][j - 1].grid && !maze[i][j - 1].pass)
      {
        maze[i][j].direction = 3;
        return maze[i][j - 1];
      }
    case 3 :
      if (!maze[i - 1][j].grid && !maze[i - 1][j].pass)
      {
        maze[i][j].direction = 4;
        return maze[i - 1][j];
      }
    default :
      return maze[0][0];
  }
}

// Status Maze(SElemType (*maze)[COLUMN], SqStack* path, int row, int col)
// {
//   SElemType point, e;
//   int i, j;
// 
//   point = maze[1][1];
//   Push(path, maze[1][1]);
//   do
//   {
//     GetTop(*path, &point);
//     i = point.i;
//     j = point.j;
//     maze[i][j].pass = 1;
// 
//     point = NextPosition(maze, i, j);
//     if (!point.i && !point.j)
//       Pop(path, &e);
//     else if (point.i == row - 2 && point.j == col - 2)
//     {
//       Push(path, point);
//       return SUCCESS;
//     }
//     else
//       Push(path, point);
//   }
//   while (!StackEmpty(*path));
// 
//   return FAIL;
// }

Status CanMove(int direction, Point* p)
{
  switch (direction)
  {
    case 0 :
      if (!maze[i][j + 1].grid && !maze[i][j + 1].pass)
      {
        maze[i][j].direction = 1;
        return maze[i][j + 1];
      }
      break;
    case 1 :
      if (!maze[i + 1][j].grid && !maze[i + 1][j].pass)
      {
        maze[i][j].direction = 2;
        return maze[i + 1][j];
      }
      break;
    case 2 :
      if (!maze[i][j - 1].grid && !maze[i][j - 1].pass)
      {
        maze[i][j].direction = 3;
        return maze[i][j - 1];
      }
      break;
    case 3 :
      if (!maze[i - 1][j].grid && !maze[i - 1][j].pass)
      {
        maze[i][j].direction = 4;
        return maze[i - 1][j];
      }
      break;
    default :
      return maze[0][0];
  }
}

void Maze(Point p)
{
  int direction = 0;
  int i = 0;

  if (p == end)
  {
    while (stepset[i])
      ++i;
    stepset[i] = step;
    --step;
  }
  else
  {
    for (; direction != 4; ++direction)
      if (CanMove(direction, &p))
      {
        ++step;
        Maze(NextPosition(p));
      }
      else
        --step;
  }
}

int main()
{
  srand(time(NULL));

  int row = rand() % 47 + 4, col = COLUMN;
  // SElemType* maze = (SElemType*) malloc(row * sizeof(col * sizeof(SElemType)));
  SElemType maze[row][col];

  SqStack path, pathway;
  SElemType e;
  InitStack(&path);
  InitStack(&pathway);

  do
  {
    CreateMaze(maze, row, col);
  }
  while (!Maze(maze, &path, row, col));

  if (!StackEmpty(path))
  {
    while (!StackEmpty(path))
    {
      Pop(&path, &e);
      Push(&pathway, e);
    }
    while (!StackEmpty(pathway))
    {
      Pop(&pathway, &e);
      maze[e.i][e.j].pass = 2;
      system("clear");
      PrintMaze(maze, row, col);
      system("sleep 0.5s");
    }
  }
  else
    printf("no way\n");

  return 0;
}
