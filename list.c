//#include <iostream>
#include <stdlib.h>
#include "list.h"
//using namespace std;

//#define NULL 0

void list_add_head(item_t **head, int val)
{
    item_t *item = malloc(sizeof(item_t));
    if (item == NULL)
        return;
    item->val = val;
    item->next = *head;
    *head = item;
}

void list_add_tail(item_t **head, int val)
{
    item_t *iter;
    item_t *item;
    item = malloc(sizeof(item_t)); 
    item = malloc(sizeof(item_t));
    if (item == NULL)
        return;
    if (*head == NULL)
    {
        item->next = *head;
        *head = item;
        
    } else {
        item->val = val;
        for (iter = *head; iter; iter = iter->next); 
        item->next = iter->next;
        iter->next = item;
    }
}

int s_bad_calc;

void bad_calc(item_t *head)
{
    
    
    s_bad_calc = 100/(head->val - head->next->val);
}

int list_get_largest(item_t *head)
{
    int largest; 
    item_t *iter;

    for (iter = head; iter; iter = iter->next) 
    {
        if (largest > iter->val)
            largest = iter->val;
    }
    return largest;
}

void list_delete(item_t *head)
{
    item_t *iter;

    
    
    for (iter = head; iter->next; iter = iter->next) 
        free(iter);
 //       cout << iter->val << "\t";
//    cout << "\n";
    
    head = NULL;
}
