/*
 * Basic function for link list.
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
#include "type_define.h"

/*
 * Initialize a null linked list.
 */
Status InitList_L(LinkList* L)
{
  *L = (LinkList) malloc(sizeof(LNode));
  if (!*L)
    exit(OVERFLOW);
  (*L)->next = NULL;
  return OK;
}

/*
 * Insert a node at number i.
 */
Status ListInsert_L(LinkList L, int i, ElemType e)
{
  LinkList p = L;
  int j = 0;

  while (p && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (!p || j > i - 1)
    return ERROR;

  LinkList s = (LinkList) malloc(sizeof(LNode));
  if (!s)
    exit(OVERFLOW);
  s->data.x = e.x;
  s->data.y = e.y;
  s->next = p->next;
  p->next = s;
  return OK;
}

/*
 * Delete a node at number i.
 */
Status ListDelete_L(LinkList L, int i)
{
  if (!L)
    return ERROR;

  LinkList p = L, q;
  int j = 0;

  while (p->next && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (!(p->next) || j > i - 1)
    return ERROR;

  q = p->next;
  p->next = q->next;
  free(q);

  return OK;
}

/*
 * Get element at number i.
 */
Status GetElem_L(LinkList L, int i, ElemType* e)
{
  if (!L)
    return ERROR;

  LinkList p = L->next;
  int j = 1;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }

  if (!p || j > i)
    return ERROR;

  (*e).x = p->data.x;
  (*e).y = p->data.y;
  return OK;
}

/*
 * Print the linked list.
 */
Status PrintList_L(LinkList L)
{
  if (!L)
    return ERROR;

  L = L->next;
  while (L)
  {
    printf("(%d,%d) ", L->data.x, L->data.y);
    L = L->next;
  }
  return OK;
}

/*
 * Destroy the linked list.
 */
Status DestroyList_L(LinkList L)
{
  if (!L)
    return ERROR;

  LinkList p;
  while (L)
  {
    p = L->next;
    free(L);
    L = p;
  }

  return OK;
}
