#include <stdio.h>

#define MAX 50

typedef struct {
    char data;
    int link;
}cellType;

typedef struct {
    cellType nodes[MAX];
    int avail;
}virtualHeap;

typedef struct node{
    int head;
}List;

void initVirtualHeap(virtualHeap* vh);
void initList(List *L);
int allocSpace(virtualHeap* vh);
int createNode(virtualHeap* vh, char data);
void display(virtualHeap vh, List L);
void deallocSpace(virtualHeap* vh, int index);

int main(){
    virtualHeap vh;
    List L, M;
    initVirtualHeap(&vh);
    initList(&L);

    int size, i, newNode, temp;
    char data;

    printf("Enter size of list L: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++){
        printf("Enter data at index#%d: ", i);
        scanf(" %c", &data);

        newNode = createNode(&vh, data);
        
        if (L.head == -1){
            L.head = newNode;
            temp = newNode;
        } else {
            vh.nodes[temp].link = newNode;
            temp = newNode;
        }
    }

    initList(&M);

    printf("Enter size of List M: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++){
        printf("Enter data at index#%d: ", i);
        scanf(" %c", &data);

        newNode = createNode(&vh, data);

        if (M.head == -1){
            M.head = newNode;
            temp = newNode;
        } else {
            vh.nodes[temp].link = newNode;
            temp = newNode;
        }
    }

    display(vh, L);
    display(vh, M);

    while (L.head != -1){
        temp = L.head;
        L.head = vh.nodes[L.head].link;
        deallocSpace(&vh, temp);
    }
    
    while (M.head != -1){
        temp = M.head;
        M.head = vh.nodes[M.head].link;
        deallocSpace(&vh, temp);
    }

    display(vh, L);
    display(vh, M);
    
    return 0;
}

void initVirtualHeap(virtualHeap* vh){
    int i; 

    for (i = 0; i < MAX - 1; i++){
        vh->nodes[i].link = i + 1;
    }

    vh->nodes[i].link = -1;
    vh->avail = 0;
}

void initList(List *L){
    L->head = -1;
}

int allocSpace(virtualHeap* vh){
    int freeNode = vh->avail;

    if (freeNode != -1){
        vh->avail = vh->nodes[freeNode].link;
    }

    return freeNode;
}

int createNode(virtualHeap* vh, char data){
    int newNode = allocSpace(vh);

    if(newNode != -1){
        vh->nodes[newNode].data = data;
        vh->nodes[newNode].link = -1;
    } else {
        printf("No Available Space!");
    }

    return newNode;
}

void display(virtualHeap vh, List L){
    int trav = L.head;

    if (trav != -1){
        printf("List: ");
        while (trav != -1){
            printf("%c ", vh.nodes[trav].data);
            trav = vh.nodes[trav].link;
        }
    } else {
        printf("\nList is empty!");
    }
}

void deallocSpace(virtualHeap* vh, int index){
    if (index != -1){
        vh->nodes[index].link = vh->avail;
        vh->avail = index;
    }
}