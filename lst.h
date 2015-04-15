#ifndef __LST_H__
#define __LST_H__

struct list_lnk
{
    struct list_lnk *next;
    struct list_lnk *prev;
    void *parent;
};

struct list
{
    struct list_lnk *head;
    struct list_lnk *tail;
};

struct list_lnk *create_list_lnk(void *parent);
void delete_list_lnk(struct list_lnk *lnk);

struct list *create_list(void);
struct list *add_lnk_first(struct list *lst,
                            struct list_lnk *e);
struct list *rmv_list_lnk(struct list *lst,
                           struct list_lnk *e);
struct list *add_lnk_after(struct list *lst,
                            struct list_lnk *p,
                            struct list_lnk *e);
struct list *add_lnk_last(struct list *lst,
                           struct list_lnk *e);
void delete_list(struct list *lst);
void list_each(struct list *lst,
						void (*fp)(void *arg));
void list_each_r(struct list *lst,
						  void (*fp)(void *arg));


#endif

