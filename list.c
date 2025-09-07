#include <stdio.h>
#include <string.h>
#include "list.h"

void linkInsertFirst(LinkList *list, Student s) {
    LinkList newnode = (LinkList) malloc(sizeof(struct node));

    if(newnode == NULL)return;

    newnode->data = s;
    newnode->link = *list;
    *list = newnode;
}

void linkInsertLast(LinkList *list, Student s) {
    LinkList newnode = (LinkList) malloc(sizeof(struct node));

    if(newnode == NULL)return;

    newnode->data = s;
    newnode->link = NULL;

    LinkList *trav;

    for(trav = list; *trav != NULL; trav = &(*trav)->link){}
    *trav = newnode;
}

void linkInsertLastUnique(LinkList *list, Student s) {
    LinkList *trav;
    for(trav = list; *trav != NULL && strcmp((*trav)->data.id, s.id) != 0; trav = &(*trav)->link){}

    if(*trav == NULL){
    linkInsertLast(list, s);
    }
}

void linkInsertAtPosition(LinkList *list, Student s, int pos) {
    LinkList newnode = malloc(sizeof(struct node));

    if(newnode == NULL) return;

    newnode->data = s;
    int i;
    LinkList *trav;
    for(i = 0, trav = list; *trav != NULL && i < pos; i++, trav = &(*trav)->link){}

    newnode->link = *trav;
    *trav = newnode;
}

Student linkDeleteElem(LinkList *list, char id[]) {
    Student dummy = {"XXXXX", "XXXXX", "X", 0};
    LinkList *trav, temp;
    for(trav = list; *trav != NULL && strcmp((*trav)->data.id, id) != 0; trav = &(*trav)->link){}

        if(*trav == NULL) return dummy;

        temp = *trav;
        Student deleted = temp->data;
        *trav = temp->link;
        free(temp);
        return deleted;
    }

LinkList linkSeparateCourse(LinkList *list, char course[]) {
    LinkList newList = NULL, trav, tail = NULL;
    
    for(trav = *list; trav != NULL; trav = trav->link){
        if(strcmp(trav->data.course, course) == 0){
            LinkList newnode = malloc(sizeof(struct node));
            
            if(newnode != NULL){
                newnode->data = trav->data;
                newnode->link = NULL;

                if(newList == NULL){
                    newList = newnode;
                }else{
                    tail->link = newnode;
                }
                tail = newnode;
            }
        }
    }

    return newList;
}
