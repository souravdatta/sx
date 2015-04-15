#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lst.h"

#define NOTNULL(x) assert((x) != NULL)

struct list_lnk *create_list_lnk(void *parent)
{
    struct list_lnk *lnk = malloc(sizeof(struct list_lnk));
    lnk->next = NULL;
    lnk->prev = NULL;
    lnk->parent = parent;

    return lnk;
}

void delete_list_lnk(struct list_lnk *lnk)
{
    free(lnk);
}

struct list  *create_list(void)
{
    struct list *lst = malloc(sizeof(struct list));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

struct list  *add_lnk_first(struct list *lst,
                            struct list_lnk *e)
{
    NOTNULL(e);
    NOTNULL(lst);
	
    if (lst->head == NULL) {
	lst->head = lst->tail = e;		
    }
    else {
	e->next = lst->head;
	lst->head->prev = e;
	lst->head = e;
    }
    
    return lst;
}

struct list  *rmv_list_lnk(struct list *lst,
                           struct list_lnk *e)
{
    NOTNULL(e);
    NOTNULL(lst);
    NOTNULL(lst->head);
    NOTNULL(lst->tail);
    
    if (lst->head == e) {
	lst->head = e->next;
	lst->head->prev = NULL;
    }
    else if (lst->tail == e) {
	lst->tail = e->prev;
	lst->tail->next = NULL;
    }
    else {
	NOTNULL(e->prev);
	NOTNULL(e->next);
	e->prev->next = e->next;
	e->next->prev = e->prev;
    }
	
    e->next = e->prev = NULL;
    return lst;
}

struct list *add_lnk_after(struct list *lst,
			   struct list_lnk *p,
			   struct list_lnk *e)
{
    NOTNULL(e);
    NOTNULL(p);
    
    e->next = p->next;
    e->prev = p;
    
    if (p->next != NULL) {
	p->next->prev = e;
    }
    
    p->next = e;
    return lst;
}

struct list *add_lnk_last(struct list *lst,
			  struct list_lnk *e)
{
    NOTNULL(lst);
    NOTNULL(e);
    
    if (lst->tail == NULL) {
	lst->head = lst->tail = e;
    }
    else {
	lst->tail->next = e;
	e->prev = lst->tail;
	lst->tail = e;
    }
    
    return lst;
}

void delete_list(struct list *lst)
{
    free(lst);
}

void list_each(struct list *lst,
	       void (*fp)(void *arg))
{
    NOTNULL(lst);
    NOTNULL(fp);
    
    struct list_lnk *it = lst->head;
    while (it != NULL) {
	fp(it->parent);
	it = it->next;
    }
}

void list_each_r(struct list *lst,
		 void (*fp)(void *arg))
{
    NOTNULL(lst);
    NOTNULL(fp);

    struct list_lnk *it = lst->tail;
    while (it != NULL) {
	fp(it->parent);
	it = it->prev;
    }
}
