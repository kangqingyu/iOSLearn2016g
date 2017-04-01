//
//  main.cpp
//  jz26_copyCompleteList_p147
//
//  Created by kqy on 01/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
    struct LNode *mutNext;
}LNode, *pNode;
//创建一个单链表
void createLinkedList(pNode *pHead,int num)
{
    if(num <= 0)
    {
        return;
    }
    int data;
    *pHead = (pNode)malloc(sizeof(Node));
    if(!pHead)
    {
        exit(-1);
    }
    cin>>data;
    (*pHead)->data = data;
    (*pHead)->next = NULL;
    (*pHead)->sibling = NULL;
    num--;
    pNode pTemp = *pHead;
    while(num > 0)
    {
        cin>>data;
        pNode pNew = (pNode)malloc(sizeof(Node));
        if(!pNew)
        {
            exit(-1);
        }
        pNew->data = data;
        pNew->next = NULL;
        pNew->sibling = NULL;
        pTemp->next = pNew;
        pTemp = pNew;
        num--;
    }
}
//创建一个复杂链表，为测试方便，这里定死了
void createComplexList(pNode *pHead)
{
    //先创建一个单链表
    createLinkedList(pHead,5);
    //然后为每个结点设置sibling指针
    (*pHead)->sibling = (*pHead)->next->next;
    (*pHead)->next->sibling = (*pHead)->next->next->next->next;
    pNode pTemp = (*pHead)->next->next->next;
    pTemp->sibling = (*pHead)->next;
}
//打印链表
void display(pNode pHead)
{
    pNode pTemp = pHead;
    while(pTemp != NULL)
    {
        cout<<pTemp->data<<" ";
        pTemp = pTemp->next;
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    LNode *pHead;
    pNode pHead = NULL;
    createComplexList(&pHead);
    cout<<"原始链表如下:"<<endl;
    display(pHead);
    
    return 0;
}
