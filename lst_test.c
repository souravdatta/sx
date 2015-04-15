#include "lst.h"
#include <stdio.h>

struct data
{
	int i;
	struct list_lnk *nl;
};

void show(void *n)
{
	struct data *d = (struct data *)n;
	printf("%d\n", d->i);
}

int main()
{
	struct list *nls = create_list();
	struct data d1, d2, d3, d4, d5;
	d1.i = 1;
	d2.i = 2;
	d3.i = 3;
	d4.i = 4;
	d5.i = 5;

	d1.nl = create_list_lnk(&d1);
	d2.nl = create_list_lnk(&d2);
	d3.nl = create_list_lnk(&d3);
	d4.nl = create_list_lnk(&d4);
	d5.nl = create_list_lnk(&d5);

	nls = add_lnk_first(nls, d1.nl);
	nls = add_lnk_last(nls, d2.nl);
	nls = add_lnk_first(nls, d3.nl);
	nls = add_lnk_after(nls, d3.nl, d4.nl);
	nls = add_lnk_first(nls, d5.nl);
	nls = rmv_list_lnk(nls, d4.nl);
	nls = add_lnk_after(nls, d5.nl, d4.nl);
	nls = rmv_list_lnk(nls, d2.nl);
	nls = add_lnk_after(nls, d3.nl, d2.nl);
	
	list_each(nls, show);

    delete_list_lnk(d1.nl);
    delete_list_lnk(d2.nl);
    delete_list_lnk(d3.nl);
    delete_list_lnk(d4.nl);
    delete_list_lnk(d5.nl);
    delete_list(nls);
	return 0;
}
