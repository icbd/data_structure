//
//  LNode.c
//  test
//
//  Created by cbd on 12/01/2017.
//  Copyright © 2017 cbd. All rights reserved.
//

#include "LNode.h"


void debug(LinkList list) {
    if (list == NULL) {
        puts("list is NULL!");
        return;
    }
    
    for (int i=0; list->next != NULL; i++) {
        printf("list[%d]:%d\n", i, list->ele);
        list = list->next;
    }
    puts("---");
}


bool lpush(LinkList * p_list, int value) {
    LNode * new_node = (LNode*)malloc(sizeof(LNode));
    if (new_node == NULL) {
        puts("内存不足。");
        return false;
    }
    
    if (*p_list == NULL){
        new_node->ele = 0;
        new_node->next = NULL;
        *p_list = new_node;
        
        return lpush(p_list, value);
        
    }
    
    new_node->ele = value;
    new_node->next = *p_list;
    *p_list = new_node;
    
    return true;
}


bool lpushx(LinkList * p_list, int value) {
    if (*p_list == NULL){
        return false;
    }
    
    return lpush(p_list, value);
}


bool rpush(LinkList * p_list, int value) {
    LNode * new_node = (LNode*)malloc(sizeof(LNode));
    if (new_node == NULL) {
        puts("内存不足。");
        return false;
    }
    
    if (*p_list == NULL){
        new_node->ele = 0;
        new_node->next = NULL;
        *p_list = new_node;
        
        return rpush(p_list, value);
    }
    
    LNode * current = *p_list;
    LNode * before = current;
    while ((current->next) != NULL ) {
        if (current != before) {
            before = before->next;
        }
        current = current->next;
    }
    
    new_node->ele = value;
    new_node->next = current;
    if (before != current) {
        before->next = new_node;
    } else {
        *p_list = new_node;
    }
    
    return true;
}


bool rpushx(LinkList * p_list, int value) {
    if (*p_list == NULL) {
        return false;
    }
    
    return rpush(p_list, value);
}


bool lpop(LinkList * p_list, int * set) {
    LNode * poped = *p_list;
    if (poped->next == NULL) {
        return false;
    }
    *set = poped->ele;
    *p_list = poped->next;
    free(poped);
    
    return true;
}


bool rpop(LinkList * p_list, int * set) {
    LNode * poped = *p_list;
    if (poped->next == NULL) {
        return false;
    }
    
    LNode * before = poped;
    while ((poped->next)->next != NULL) {
        if (before != poped) {
            before = before->next;
        }
        poped = poped->next;
    }
    
    *set = poped->ele;
    if(before != poped) {
        before->next = poped->next;//NULL
    } else {
        *p_list = poped->next;//NULL
    }
    
    free(poped);
    return true;
}


bool lindex(LinkList list, int index, int * set) {
    if (list == NULL) {
        return false;
    }
    int i = 0;
    while (true) {
        if(list->next == NULL) {
            *set = 0;
            return false;
        } else if (i == index) {
            *set = list->ele;
            return true;
        } else{
            i++;
            list = list->next;
        }
    }
}


bool linsert(LinkList * p_list, const char* AB, int pivot, int value) {
    if (*p_list == NULL){
        return false;
    }
    
    LNode * current = *p_list;
    LNode * before = current;
    
    while (true) {
        if (current->ele == pivot) {
            LNode * new_node = (LNode *)malloc(sizeof(LNode));
            new_node->ele = value;
            if (strcmp(AB, "AFTER") == 0) {
                new_node->next = current->next;
                current->next = new_node;
                return true;
            } else if (strcmp(AB, "BEFORE") == 0) {
                if(current == before) {//first
                    return lpush(p_list, value);
                } else {
                    new_node->next = current;
                    before->next = new_node;
                    return true;
                }
                return true;
            } else {
                free(new_node);
                return false;
            }
        }
        
        
        if (current != before) {
            before = current;
        }
        current = current->next;
        
        if(current == NULL){
            break;
        }
    }
    
    return false;
}

bool llen(LinkList list, int * len) {
    if (list == NULL) {
        return false;
    }
    
    int i = 0;
    while (list->next != NULL) {
        list = list->next;
        i++;
    }
    
    *len = i;
    return true;
}


bool lrange(LinkList list, int start, int stop, int * ans[], int * actual_len) {
    if (list == NULL || list->next == NULL) {
        return false;
    }
    
    int ans_len = stop - start + 1;
    if (ans_len < 1) {
        return false;
    }
    
    *ans = (int *)malloc(ans_len * sizeof(int));
    
    int ans_cursor = 0;
    for (int i=0; (i<=stop) && (list->next != NULL); i++) {
        if (i >= start) {
            (*ans)[ans_cursor++] = list->ele;
        }
        list = list->next;
    }
    
    *actual_len = ans_cursor;
    return true;
}


bool rpoplpush(LinkList * p_list) {
    if (*p_list == NULL ) {
        return false;
    }
    
    if ((*p_list)->next == NULL) {
        return true;
    }
    
    int last;
    if (rpop(p_list, &last) ) {
        if (lpush(p_list, last)) {
            return true;
        }
    }
    
    return false;
}


bool lset(LinkList * p_list, int index, int value) {
    if (*p_list == NULL) {
        return false;
    }
    
    LNode * current = *p_list;
    int i = 0;
    while (true) {
        if(current->next == NULL) {
            return false;
        } else if (i == index) {
            current->ele = value;
            return true;
        } else{
            i++;
            current = current->next;
        }
    }
}


bool lrem(LinkList * p_list, int index) {
    if (*p_list == NULL) {
        return false;
    }
    if (index == 0) {
        int tem_set;
        return lpop(p_list, &tem_set);
    }
    
    LNode * current = *p_list;
    
    int i = 0;
    while (true) {
        if(current->next->next == NULL) {
            return false;
        } else if (i == index - 1) {
            current->next = current->next->next;
            free(current->next);
            return true;
        } else{
            i++;
            current = current->next;
        }
    }
}

bool ltrim(LinkList * p_list, int start, int stop) {
    if (*p_list == NULL) {
        return false;
    }
    
    int end = stop;
    if (stop < start) {
        end = start;
    }
    
    int i;
    int tem_set;
    for (i = 0; i < start; i++) {
        if (lpop(p_list, &tem_set) == false) {
            return false;
        }
    }
    
    LNode * current = *p_list;
    if (current->next == NULL) {
        return false;
    }
    
    for (; i < end; i++) {
        if (current->next->next == NULL) {
            return false;
        }
        current = current->next;
    }
    
    while (current->next->next != NULL) {
        LNode * jump = current->next;
        current->next = current->next->next;
        free(jump);
    }
    
    return true;
}

bool lflush(LinkList * p_list) {
    if (*p_list == NULL) {
        return false;
    }
    
    int tem_set;
    while (lpop(p_list, &tem_set)) {
        ;
    }
    
    return true;
}
