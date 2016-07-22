#include <stdlib.h>
#include "notification.h"

typedef struct notifier_t {
    int (*cb)(char *s);
    const char *name;
    struct notifier_t *next;
} notifier_t;

static notifier_t *head;

int notifier_register(const char *name, int (*cb)(char *s))
{
    notifier_t *n = malloc(sizeof(notifier_t));
    if (!n)
	return -1;
    n->name = name;
    n->cb = cb;
    n->next = head;
    head = n;
    return 0;
}

int notify(const *name, char *s)
{
    notifier_t *iter;
    int rc = 0;

    for (iter = head; iter; iter = iter->next)
    {
	if (name && strcmp(name, iter->name))
            continue;
        rc = (iter->cb)(s) || rc;
    }
    return rc;
}

