#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

int count() {
    int c = 0;
    struct node *p;
    if (last == NULL)
        return 0;
    p = last->next;
    do {
        c++;
        p = p->next;
    } while (p != last->next);
    return c;
}

void display() {
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

void insert_beg(int x) {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (last == NULL) {
        last = t;
        t->next = t;
    } else {
        t->next = last->next;
        last->next = t;
    }
}

void insert_end(int x) {
    insert_beg(x);
    last = last->next;
}

void insert_pos(int x, int pos) {
    int i, n = count();
    struct node *p, *t;
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insert_beg(x);
        return;
    }
    if (pos == n + 1) {
        insert_end(x);
        return;
    }
    p = last->next;
    for (i = 1; i < pos - 1; i++)
        p = p->next;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = p->next;
    p->next = t;
}

void delete_beg() {
    struct node *t;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    t = last->next;
    if (t == last)
        last = NULL;
    else
        last->next = t->next;
    printf("Deleted %d\n", t->data);
    free(t);
}

void delete_end() {
    struct node *p, *t;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    t = last;
    if (last->next == last) {
        last = NULL;
    } else {
        p = last->next;
        while (p->next != last)
            p = p->next;
        p->next = last->next;
        last = p;
    }
    printf("Deleted %d\n", t->data);
    free(t);
}

void delete_pos(int pos) {
    int i, n = count();
    struct node *p, *t;
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        delete_beg();
        return;
    }
    if (pos == n) {
        delete_end();
        return;
    }
    p = last->next;
    for (i = 1; i < pos - 1; i++)
        p = p->next;
    t = p->next;
    p->next = t->next;
    printf("Deleted %d\n", t->data);
    free(t);
}

void delete_val(int x) {
    struct node *p, *q;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    q = last;
    p = last->next;
    do {
        if (p->data == x) {
            if (p == q)
                last = NULL;
            else {
                q->next = p->next;
                if (p == last)
                    last = q;
            }
            free(p);
            printf("Deleted %d\n", x);
            return;
        }
        q = p;
        p = p->next;
    } while (p != last->next);
    printf("%d not found\n", x);
}

void update_pos(int pos, int x) {
    int i;
    struct node *p;
    if (pos < 1 || pos > count()) {
        printf("Invalid position\n");
        return;
    }
    p = last->next;
    for (i = 1; i < pos; i++)
        p = p->next;
    p->data = x;
}

void update_val(int old, int x) {
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        if (p->data == old) {
            p->data = x;
            return;
        }
        p = p->next;
    } while (p != last->next);
    printf("%d not found\n", old);
}

void search(int x) {
    int pos = 1;
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        if (p->data == x) {
            printf("%d found at position %d\n", x, pos);
            return;
        }
        p = p->next;
        pos++;
    } while (p != last->next);
    printf("%d not found\n", x);
}

int main() {
    int ch, x, pos;
    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
        printf("4.Delete from beginning\n5.Delete from end\n6.Delete at position\n7.Delete by value\n");
        printf("8.Update at position\n9.Update by value\n10.Search\n11.Display\n12.Count\n13.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &x);
            insert_beg(x);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &x);
            insert_end(x);
            break;
        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &x, &pos);
            insert_pos(x, pos);
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            printf("Enter value: ");
            scanf("%d", &x);
            delete_val(x);
            break;
        case 8:
            printf("Enter position and new data: ");
            scanf("%d %d", &pos, &x);
            update_pos(pos, x);
            break;
        case 9:
            printf("Enter old value and new value: ");
            scanf("%d %d", &pos, &x);
            update_val(pos, x);
            break;
        case 10:
            printf("Enter value: ");
            scanf("%d", &x);
            search(x);
            break;
        case 11:
            display();
            break;
        case 12:
            printf("Number of nodes = %d\n", count());
            break;
        case 13:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
