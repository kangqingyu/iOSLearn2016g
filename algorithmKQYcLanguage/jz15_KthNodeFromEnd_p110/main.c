//
//  main.c
//  jz15_KthNodeFromEnd_p110
//
//  Created by kqy on 19/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
typedef struct ListNode {
    int value;
    struct ListNode *next;
}ListNod, *pList;
void displayList(struct ListNode *List) {
    struct ListNode *disList = List;
    disList = disList -> next;
    while (disList ->next) {
        printf("%d  ", disList->value);
        disList = disList -> next;
    }
    printf("%d  ", disList->value);
    
}
pList autoCreateList(struct ListNode *List, int count) {
    pList  newNode;
    List = (pList)malloc(sizeof(ListNod));
#warning ok ???
    //    List = newNode;// newNode还没分配，就先指向，可以吗？
    pList  p ;
    p =  List;   // & 是多的？？？刚开始多写了*.
    int i = 0;
    for(i = 1; i < count + 1; ++i) {
        newNode = (pList )malloc(sizeof( ListNod));
        newNode -> value = i;
        p ->next = newNode;
        p = p -> next;
    }
    return List;
}
int  findLastKNode(pList list, int k) {
    pList firstP, secondP;
    firstP = list;
    secondP = list;
    while (k--) {
        if (k < 0) {// 健壮。
            printf("k out of range");
            break;
        }
        firstP = firstP->next;
    }
    while (firstP -> next) {
        firstP = firstP->next;
        secondP = secondP ->next;
    }
    secondP = secondP -> next;
    return secondP->value;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    pList list ;
    list = autoCreateList(list, 6);
    displayList(list);
    int lastK = findLastKNode(list, 3);
    printf("\nanswer: %d\n", lastK);
    return 0;
}
