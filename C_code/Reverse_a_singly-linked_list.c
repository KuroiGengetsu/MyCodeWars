#include <stdio.h>
#include <stdlib.h>

// CodeWars
// struct Node
// {
//     int value;
//     struct Node *next;
// };

// struct Node * reverse_list(struct Node *node)
// {
//     struct Node *end = (struct Node*)malloc(sizeof(struct Node));
//     end -> next = NULL;
//     // node = node -> next;
//     while(node != NULL) {
//         end -> value = node -> value;
//         node = node -> next;
//         struct Node *last = (struct Node*)malloc(sizeof(struct Node));
//         last -> next = end;
//         end = last;
//     }
//     return end -> next;
// }

typedef struct LinkNode {
    int val;
    struct LinkNode *next;
} LinkNode;


LinkNode *create_list(char *src);
LinkNode *reverse_list(LinkNode *head);
void print_list(LinkNode *head);
void free_all(LinkNode *head);


int main() {
    LinkNode *lst1 = create_list("12345");
    print_list(lst1);
    LinkNode *rlst1 = reverse_list(lst1);
    print_list(rlst1);
    free_all(lst1);
    free_all(rlst1);
    return 0;
}


LinkNode *create_list(char *src) {
    LinkNode *head = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode *linker = head;
    while(*src) {
        LinkNode *store = (LinkNode*)malloc(sizeof(LinkNode));
        store -> val = *src++ - '0';
        linker -> next = store;
        linker = store;
    }
    linker -> next = NULL;
    return head;
}






LinkNode *reverse_list(LinkNode *head) {
    LinkNode *end = (LinkNode*)malloc(sizeof(LinkNode));
    end -> next = NULL;
    head = head -> next;
    while(head != NULL) {
        end -> val = head -> val;
        head = head -> next;
        LinkNode *last = (LinkNode*)malloc(sizeof(LinkNode));
        last -> next = end;
        end = last;
    }
    return end;
}


void print_list(LinkNode *head) {
    while(head -> next != NULL) {
        head = head -> next;
        printf("%d", head->val);
    }
    putchar('\n');
}


void free_all(LinkNode *head) {
    while(head -> next != NULL) {
        LinkNode *trash = head;
        head = head -> next;
        free(trash);
    }
    free(head);
}
