typedef struct item_t {
    int val;
    struct item_t *next;
} item_t;


void list_add_head(item_t **head, int val);

void list_add_tail(item_t **head, int val);

void bad_calc(item_t *head);

int list_get_largest(item_t *head);

void list_delete(item_t *head);


