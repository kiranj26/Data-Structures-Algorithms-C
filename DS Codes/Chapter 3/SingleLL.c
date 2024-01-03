#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node * link;
};

void display(struct node * start){
    // if list is empty
    if(start->link == NULL){
        printf("list is empty\n");
        return;
    }
    struct node * p;
    p = start;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

void count(struct node * start){ 
    struct node * p;
    p = start;
    int count =0;
    while(p != NULL){
        p= p->link;
        count++;
    }
    printf("No of Elements Found = %d\n", count);
}

void search (struct node * start, int data){ 
    struct node * p;
    p = start;

    int pos = 1;
    while(p != NULL){
        if(p->info == data)
        {
            printf("Item %d found at position %d\n", data, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found \n", data);
}

struct node * addatbeg(struct node * start, int data){
    struct node * temp;
    temp  = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    temp->link = start;
    start = temp;

    return start;
}
struct node * addatend(struct node * start, int data){
    struct node * p;
    p = start;
    // take p to point to the last eleent of the LL
    while(p->link != NULL)
    {
        p = p->link;
    }

    // create temp node
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));

    // now load temp link with null and data loaded
    temp->info = data;
    temp->link = NULL;

    // finally oint current last node to temp node
    p->link = temp;

    return start;
}
struct node * addbefore(struct node * start, int data , int label){
    // first check if start is not pointing to any thing
    if (start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }

    // if the label is pointing to start
    if (start->info == label)
    {
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));

        temp->info = data;

        temp->link = start;
        start = temp;

        return start;
    }

    // if the label is pointing to anything apart from first element
    struct node * p;
    p = start;
    while(p->link != NULL)
    {
        if (p->link->info == label)
        {
            struct node * temp;
            temp = (struct node *)malloc(sizeof(struct node));

            temp->info = data;

            temp->link = p->link;
            p->link = temp;

            return start;
        }
        p= p->link;
    }
    printf("No such element in list called %d \n", label);
    return start;
}
struct node * addafter(struct node * start, int data , int label){
    // traverse till we find the node containing the label
    struct node * p;
    p =start;
    while(p != NULL)
    {
        // if we found the element in the node pointed by p
        if (p->info == label)
        {
            // then we create a new node
            struct node * temp;
            temp = (struct node *)malloc(sizeof(struct node));
            temp -> info = data;

            // assign temps link as next node 
            temp->link = p->link;
            // change current link of p to point to new node
            p->link = temp;

            return start;
        }
        p = p->link;
    }
    printf("Could not find element %d in node \n", data);
    return start;
}
struct node * addatpos(struct node * start, int data, int pos){
    int i;
    // if the pos asked is first position
    if (pos == 1)
    {
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;

        temp->link = start;
        start = temp;

        return start;
    }
    struct node * p;
    p = start;

    // traverse p till the position -1 or if p reaches end
    for(i=1;i<pos-1 && p!= NULL;i++)
    {
        p = p->link;
    }

    // if p reached end of list 
    if (p == NULL)
    {
        printf("We only have no in list less than %d\n",pos);
        return start;
    }else{
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;

        temp->link = p->link;
        p->link = temp;
    }
    return start;
}
struct node * delete(struct node * start, int data){
    // cant delete from empty list
    if (start == NULL)
    {
        printf("List Already Empty\n");
        return start;
    }
    // If we want to delete first node
    if(start->info == data)
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp = start;
        start = temp->link;
        free(temp);
        return start;
    }

    // if delete in between
    struct node * p;
    p = start;

    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            struct node * temp = (struct node *)malloc(sizeof(struct node));
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found in list\n", data);
    return start;
}
struct node * reverse(struct node * start){
    struct node * ptr, *prev, *next;

    prev = NULL;
    ptr = start;

    while(ptr != NULL){
        next = ptr->link;

        ptr->link = prev;

        prev = ptr;
        ptr = next;
    }

    start = prev;
    return start;
}

struct node * create_list(struct node * start){
    int no_of_nodes,data;

    start = NULL;
    printf("Enter no of nodes to be added :::::::::::::\n");
    scanf("%d", &no_of_nodes);

    printf("Enter the element for node 1 :::::::::::::\n");
    scanf("%d", &data);

    start = addatbeg(start, data);

    // for all remaning element add at the end
    for(int i=2;i<=no_of_nodes;i++){
        printf("Enter the element for node %d :::::::::::::\n",i);
        scanf("%d", &data);
        start = addatend(start, data);
    }

    return start;
}

int main()
{
    // Initialising start to point to nothing initially.
    struct node * start = NULL;
    int choice,val,data,label,pos;
    // UI
    while(1)
    {
        printf("Enter Choice: \n");
        printf("1. Create List: \n");
        printf("2. Display List: \n");
        printf("3, Count: \n");
        printf("4. Search: \n");
        printf("5. Add to empty List / add at the beginning of the list \n");
        printf("6. Add at the end of the list \n");
        printf("7. Add after the node \n");
        printf("8. Add before the node \n");
        printf("9. Add at position \n");
        printf("10. delete from the list \n");
        printf("11. Reverse the list \n");
        printf("12. Quit the program \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 : 
                printf("Creating the list : : : : : : : : : : : : : : : : : \n");
                start = create_list(start);
                break;

            case 2 :
                printf("Printing the list : : : : : : : : : : : : : : : : : \n");
                display(start);
                break;
            case 3:
                count(start);
                break;
            case 4:
                printf("Enter the value you want to search\n");
                scanf("%d", &val);
                search(start, val);
                break;
            case 5 : 
                printf("Adding to the list : :  : : : : : : : : : : : : : \n ");
                printf("Insert Data to be added in beginning\n");
                scanf("%d", &data);
                start = addatbeg(start, data);
                break;
            case 6 : 
                printf("Adding to the list : :  : : : : : : : : : : : : : \n ");
                printf("Insert Data to be added in the end\n");
                scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 7:
                printf("Enter Element to be added\n");
                scanf("%d", &data);
                printf("Enter after which node to be added\n");
                scanf("%d", &label);
                start = addafter(start, data, label);
                break;
            case 8:
                printf("Enter Element to be added\n");
                scanf("%d", &data);
                printf("Enter before which node to be added\n");
                scanf("%d", &label);
                start = addbefore(start, data, label);
                break;
            case 9:
                printf("Enter Element to be added\n");
                scanf("%d", &data);
                printf("Enter positiond\n");
                scanf("%d", &pos);
                start = addatpos(start, data, pos);
                break;
            case 10 :
                start = reverse(start);
                break;
            default :
                printf("Invalid choice \n");
                break;
        }

        
    }
}