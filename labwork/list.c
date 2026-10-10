int main() {
    int ch, x, pos, old;
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
            if (last == NULL) {
                printf("List is empty\n");
                break;
            }
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            if (last == NULL) {
                printf("List is empty\n");
                break;
            }
            printf("Enter value: ");
            scanf("%d", &x);
            delete_val(x);
            break;
        case 8:
            if (last == NULL) {
                printf("List is empty\n");
                break;
            }
            printf("Enter position and new data: ");
            scanf("%d %d", &pos, &x);
            update_pos(pos, x);
            break;
        case 9:
            if (last == NULL) {
                printf("List is empty\n");
                break;
            }
            printf("Enter old value and new value: ");
            scanf("%d %d", &old, &x);
            update_val(old, x);
            break;
        case 10:
            if (last == NULL) {
                printf("List is empty\n");
                break;
            }
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
