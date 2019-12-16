//
// Created by Liu Wei on 2019-11-04.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    char vec[MAX_LENGTH];
    int length;
} Str;

Str Init_Str(char *s) {
    Str result;
    char *p = s;

    while (*p != '\0') {
        result.vec[result.length] = *p;
        result.length++;
        p++;
    }

    return result;
}

int Concat(Str *s, Str *t){
    if(s->length + t->length > MAX_LENGTH){
        return 0;
    }

    for(int i=s->length; i<s->length + t->length; i++){
        s->vec[i] = t->vec[i-s->length];
    }
}


int SubStr(Str *s, Str *subStr, int startIndex, int count){
    subStr->length = 0;
    for(int i =0; i < count; i++){
        subStr->vec[i] = s->vec[i + startIndex];
        subStr->length++;
    }

    return 1;
}

int main() {
//    char s[10];
//    s[0] = 'h';
//    s[1] = 'e';
//    s[2] = 'l';
//    s[3] = '\0';

char s[] = "hello";


//    char t[10];
//    t[0] = 'w';
//    t[1] = 'o';
//    t[2] = 'r';
//    t[3] = 'l';
//    t[4] = '\0';

    char t[] = " world";

//    char *s = (char *)malloc(sizeof(char));
//    scanf("%s", s);

    Str s1 = Init_Str(s);
    Str s2 = Init_Str(t);

    Str *p1 = (Str*)malloc(sizeof(Str));
    p1=&s1;

    Str *p2 = (Str*)malloc(sizeof(Str));
    p2=&s2;

//    Concat(p1, p2);

    SubStr(&s1, &s2,2,3);
    getchar();
}


