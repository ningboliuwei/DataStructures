//
// Created by 慰 on 2018/9/19.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct SequenceStringStruct {
    char vec[MAX_LENGTH];
    int length;
} SequenceString;

int Length(SequenceString *s) {
    return s->length;
}

int Concact(SequenceString *s, SequenceString *t) {
    int tLength = Length(t);
    int sLength = Length(s);
    // 因为还要在最后放个 \0 ？
    if (sLength + tLength >= MAX_LENGTH) {
        return 0;
    }

    for (int i = 0; i < tLength; i++) {
        s->vec[sLength + i] = t->vec[i];
    }

    s->length = sLength + tLength;
    s->vec[s->length] = '\0';

    return 1;
}

int SubString(SequenceString *s, SequenceString *subStr, int start, int length) {
    // 越界
    if (start < 0 || start > length || length < 1 || start + length > s->length) {
        return 0;
    }

    int i = 0;
    for (i = 0; i < length; i++) {
        subStr->vec[i] = s->vec[start + i];
    }
    subStr->vec[i] = '\0';
    subStr->length = i - 1;

    return 1;

}

int Compare(SequenceString *s, SequenceString *t) {
    int i = 0;

    for (i = 0; i < s->length && i < t->length && s->vec[i] == t->vec[i]; i++) {
        // Do nothing
    }

    return s->vec[i] - t->vec[i];
}

int Insert(SequenceString *s, int start, SequenceString *t) {
    // 无法插入
    if (start < 0 || start > s->length || s->length + t->length >= MAX_LENGTH) {
        return 0;
    }

    for (int i = s->length - 1 + t->length; i > start + t->length; i--) {
        s->vec[i] = s->vec[i - t->length];
    }

    for (int i = 0; i < t->length; i++) {
        s->vec[start + i] = t->vec[i];
    }

    s->length = s->length + t->length;
    s->vec[s->length] = '\0';

    return 1;
}

int Delete(SequenceString *s, int start, int length) {
    if (start < 0 || s->length < start + length) {
        return 0;
    }

    int i = 0;

    for (i = start; i < s->length - length; i++) {
        s->vec[i] = s->vec[i + length];
    }

    s->vec[i] = '\0';
    s->length = s->length - length;

    return 1;
}

int InputString(SequenceString *s, char *value) {
    int i = 0;

    for (i = 0; value[i] != '\0'; i++) {
        s->vec[i] = value[i];
    }

    s->vec[i] = '\0';
    s->length = i;
}

int OutputString(SequenceString *s) {
    for (int i = 0; s->vec[i] != '\0'; i++) {
        printf("%c", s->vec[i]);
    }

    printf("\n");
}

int main() {
    SequenceString *s1 = (SequenceString *) malloc(sizeof(SequenceString));
    SequenceString *s2 = (SequenceString *) malloc(sizeof(SequenceString));

    char s[MAX_LENGTH];
    printf("Input a string: ");
    gets(s);
    InputString(s1, s);
    OutputString(s1);

    InputString(s2, " world");
    OutputString(s2);

    int result = Compare(s1, s2);

    if (result == 0) {
        printf("s1 == s2");
    } else if (result < 0) {
        printf("s1 < s2");
    } else {
        printf("s1 > s2");
    }

    printf("\n");

    Concact(s1, s2);
    printf("after concat: ");
    OutputString(s1);

    printf("length of s1 is: %d\n", Length(s1));

    Insert(s1, 3, s2);
    printf("after insertion: ");
    OutputString(s1);
    printf("length of s1 is: %d\n", Length(s1));

    Delete(s1, 3, 4);
    printf("after deletion: ");
    OutputString(s1);
    printf("length of s1 is: %d\n", Length(s1));

    getchar();
}

