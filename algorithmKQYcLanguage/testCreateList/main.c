//
//  main.c
//  testCreateList
//
//  Created by kqy on 18/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
//#include "iostream.h"
//#include <iostream>
//#include <malloc.h>
#include <stdlib.h>
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;
LinkList CreateList1(LinkList List) {
    LNode *s;
    int x;
    List = (LinkList) malloc(sizeof(LNode));
    List -> next = NULL;
    //    printf("before, list data:%d", List->data);
    while (scanf("%d", &x) ==1  && (x!= 99)) {
        s = (LinkList) malloc(sizeof(LNode));
        s -> data = x;
        s -> next = List -> next;
        List -> next = s;
    }
    return List;
}
void printList(LinkList List) {
    LNode *p;
    //    p = (LinkList) malloc(sizeof(LNode))	;
    p = List;
    p = p-> next;
    
    while (p->next != NULL) {
        printf("%d  ", p->data);
        p = p-> next;
    }
    printf("%d  ", p->data);
}
int main(int argc, char *argv[]) {
    LinkList list;
    list = CreateList1(list);
    printList(list);
}
