//
// Created by 慰 on 2018/9/19.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct SequenceStringStruct {
    char vec[MAX_LENGTH];
    int length;
} SequenceString;

int Length(SequenceString *s){
    return s->length;
}

int Concact(SequenceString *s, SequenceString *t){
    
}

