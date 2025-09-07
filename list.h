#ifndef LINK_H
#define LINK_H

typedef struct {
    char id[10];
    char name[50];
    char course[20];
    int year;
} Student;

typedef struct node{
    Student data;
    struct node *link;
} *LinkList;

void linkInsertFirst(LinkList *list, Student s);
void linkInsertLast(LinkList *list, Student s);
void linkInsertLastUnique(LinkList *list, Student s);
void linkInsertAtPosition(LinkList *list, Student s, int pos);
Student linkDeleteElem(LinkList *list, char id[]);
LinkList linkSeparateCourse(LinkList *list, char course[]);

#endif


