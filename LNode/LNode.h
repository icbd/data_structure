//  单向链表练习
//  LNode.h
//  test
//
//  Created by cbd on 12/01/2017.
//  Copyright © 2017 cbd. All rights reserved.
//

#ifndef LNode_h
#define LNode_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define AFTER "AFTER"
#define BEFORE "BEFORE"

typedef struct LNode_tag {
    struct LNode_tag * next;
    int ele;
}LNode, *LinkList;

void debug(LinkList list) ;
bool lpush(LinkList * p_list, int value) ;
bool lpushx(LinkList * p_list, int value) ;
bool rpush(LinkList * p_list, int value) ;
bool rpushx(LinkList * p_list, int value) ;
bool lpop(LinkList * p_list, int * set) ;
bool rpop(LinkList * p_list, int * set) ;
bool lindex(LinkList list, int index, int * set) ;
bool linsert(LinkList * list, const char* AB, int pivot, int value) ;
bool llen(LinkList list, int *len) ;
bool lrange(LinkList list, int start, int stop, int * ans[], int * actual_len) ;
bool rpoplpush(LinkList * p_list) ;
bool lset(LinkList * p_list, int index, int value) ;
bool lrem(LinkList * p_list, int index) ;
bool lrem(LinkList * p_list, int index) ;
bool ltrim(LinkList * p_list, int start, int stop) ;
bool lflush(LinkList * p_list) ;


#endif /* LNode_h */
