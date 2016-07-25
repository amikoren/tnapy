/*
 * tnapy
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 3, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 */
#include "stdio.h"
#include "stdlib.h"
#include "str.h"
#include "list.h"
#include <string.h>
#include "notification.h"

int largest;

int notifier1(char *s)
{
    printf("Notifcation %s", s);
    return 0;
}

int notifier2(char *s)
{
    FILE *f = fopen("/tmp/log.txt", "a");
    if (!f)
	return -1;
    fprintf(f, s);
    
    return 0;
}

int notifier3(char *s)
{
    *(char *)(s+strlen(s)) = 0; 
    *(char *)(s+strlen(s) + 1) = 0; 
    return 0;
}

void calc(void)
{
    item_t *head = NULL;
    char *s, *rev; 

    list_add_tail(&head, 6);
    bad_calc(head);
    list_add_tail(&head, 7);
    list_add_head(&head, 5);

    largest = list_get_largest(head);


    list_delete(head);
    
    list_delete(head);

    str_cpy(&s, "Anakonda");

    rev = str_reverse(s);

    str_free(&s);
    printf("rev: %s\n", rev);
    
    

    notifier_register("n3", notifier3); 
    notifier_register("n2", notifier2); 
    notifier_register("n1", notifier1);       
    
    notify(NULL, "event occurred\n");
    notify(NULL, "event occurred\n");

    return;
}
