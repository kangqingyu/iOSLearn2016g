//
//  main.c
//  testCreateList2
//
//  Created by kqy on 19/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;
LinkList createHeadList(LinkList List) {
    LinkList rearList;
    rearList = (LinkList) malloc(sizeof(LNode));
    List = (LinkList) malloc(sizeof(LNode));
    rearList = List;
    //    List->next = NULL;  problem1 : why can't null ? because no malloc.
    int x;
    scanf("%d", &x);
    while (x!= 99) {
        //    while (scanf("%d", &x) == 1 && (x != 99)) {
        //        LNode addPoint;//
        LinkList addPoint;
        addPoint = (LinkList) malloc(sizeof(LNode));
        addPoint ->data = x; // - > wrong?
        rearList -> next = addPoint;
        rearList = rearList -> next;//..
        //        rearList = addPoint;// can also 这样表示的。
        //        headList = addPoint; // headList一直指向当前最后的一个结点
        scanf("%d", &x);
        
    }
    return List;
}

void printList(LinkList List) {
    LinkList displayP  = List;
    displayP = displayP->next;
    while (displayP -> next ) {
        printf("%d   ", displayP->data);
        displayP = displayP -> next;
    }
    printf("%d   ", displayP->data);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //    printf("Hello, World!\n");d
    LinkList list;
    list = createHeadList(list);
    printList(list);
    
    return 0;
}
