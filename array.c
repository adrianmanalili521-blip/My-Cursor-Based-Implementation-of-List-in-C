#include <stdio.h>
#include <string.h>
#include "array.h"

void arrayInsertFirst(ArrayList *list, Student s) {
    if (list->size < MAX) {
        for (int i = list->size; i > 0; i--) {
            list->data[i] = list->data[i-1];
        }
        list->data[0] = s;
        list->size++;
    }
}

void arrayInsertLast(ArrayList *list, Student s) {
    if (list->size < MAX) {
        list->data[list->size++] = s;
    }
}

void arrayInsertLastUnique(ArrayList *list, Student s) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->data[i].id, s.id) == 0) return; // already exists
    }
    arrayInsertLast(list, s);
}

void arrayInsertAtPosition(ArrayList *list, Student s, int pos) {
    if (list->size < MAX && pos >= 0 && pos <= list->size) {
        for (int i = list->size; i > pos; i--) {
            list->data[i] = list->data[i-1];
        }
        list->data[pos] = s;
        list->size++;
    }
}

Student arrayDeleteElem(ArrayList *list, char id[]) {
    Student dummy = {"XXXXX", "XXXXX", "X", 0};
    int found = -1;

    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->data[i].id, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) return dummy;

    Student deleted = list->data[found];
    for (int i = found; i < list->size - 1; i++) {
        list->data[i] = list->data[i+1];
    }
    list->size--;

    return deleted;
}

ArrayList arraySeparateCourse(ArrayList *list, char course[]) {
    ArrayList newList;
    newList.size = 0;

    int i = 0;
    while (i < list->size) {
        if (strcmp(list->data[i].course, course) == 0) {
            arrayInsertLast(&newList, list->data[i]);
            arrayDeleteElem(list, list->data[i].id);
        } else {
            i++;
        }
    }

    return newList;
}
