//
//  main.c
//  LNode_test
//
//  Created by cbd on 13/01/2017.
//  Copyright © 2017 cbd. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../LNode/LNode.h"


int main(int argc, const char * argv[]) {
    puts("This is LNode_test>>>");
    
    int tem;
    LinkList list;
    lpush(&list, 5);
    lpush(&list, 4);
    lpush(&list, 3);
    lpush(&list, 2);
    lpush(&list, 1);
    lpush(&list, 0);
    debug(list);

    if (ltrim(&list, 7, 7)) {
        puts(">ltrim return is Y");
    } else {
        puts(">ltrim return is N");
    }
    
    debug(list);
    
    
    
    return EXIT_SUCCESS;
    
    if (lflush(&list)) {
        debug(list);
    }
    
//    return EXIT_SUCCESS;
    
    if (lset(&list, 1, 111)) {
        puts(">lset");
        debug(list);
    }
    
    if (lrem(&list, 0)) {
        puts(">lrem");
        debug(list);
    }
    return EXIT_SUCCESS;
    
    if (rpoplpush(&list) ) {
        debug(list);
    }
    return EXIT_SUCCESS;
    
    int start = 1;
    int stop = 3;
    
    int * lrange_ans;
    int lrange_ans_len;
    if (lrange(list, start, stop, &lrange_ans, &lrange_ans_len)) {
        printf("actual_len:%d\n", lrange_ans_len);
        for (int i = 0; i < lrange_ans_len; i++) {
            printf("ans[%d]:%d\n", i, lrange_ans[i]);
        }
    }
    
    return EXIT_SUCCESS;
    
    int value;
    int index = 1;
    if (lindex(list, index, &value)) {
        printf("lindex[%d]:%d\n",index, value);
        debug(list);
    }
    
    if (lpop(&list, &value)) {
        printf("lpop:%d\n", value);
        debug(list);
    }
    
    if (linsert(&list, AFTER, 12, 666)) {
        debug(list);
    }
    
    if (linsert(&list, AFTER, 12, 777)) {
        debug(list);
    }
    
    if (linsert(&list, BEFORE, 12, 888)) {
        debug(list);
    }
    
    if (linsert(&list, BEFORE, 29, 999)) {
        debug(list);
    }
    
    if (linsert(&list, BEFORE, -1, 1000)) {
        debug(list);
    }
    
    if (rpush(&list, 1122)) {
        debug(list);
    }
    
    LinkList list2;
    if (rpush(&list2, 2233)) {
        debug(list2);
    }
    
    if (rpush(&list2, 3344)) {
        debug(list2);
    }
    
    if (lpush(&list2, 1122)) {
        debug(list2);
    }
    
    if (rpop(&list2, &value)) {
        printf("rpop:%d\n", value);
        debug(list2);
    }
    
    LinkList list3;
    if (lpush(&list3, 798)){
        debug(list3);
    }
    if (rpop(&list3, &value)) {
        printf("rpop:%d\n", value);
        debug(list3);
    }
    
    if (rpush(&list3, 798789)) {
        debug(list3);
    }
    
    if (lpop(&list3, &value)) {
        printf("lpop:%d\n", value);
        debug(list3);
    }
    
    
    puts("test end.");
    return EXIT_SUCCESS;
}
