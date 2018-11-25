//
// Created by Liu Wei on 2018/11/20.
//

#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 10
typedef char DataType;

typedef struct
{
    DataType data[MAXLEN];
    int top;
}SeqStack;

int InitSeqStack (SeqStack &st)
{

    st.top=-1;

}

int Push (SeqStack &st, DataType x)
{

    if(MAXLEN-1== st.top)
        return 0;
    else
    {
        st.top++;
        st.data[st.top]=x;
        return 1;
    }

}



int IsSeqEmpty(SeqStack st)
{

    if(-1 == st.top)
        return 1;
    else
        return 0;

}

int main()
{
    SeqStack st;
    DataType x='*';
    DataType y='#';
    InitSeqStack(st);

    scanf("%c",&x);
    while(x != '#')
    {
        if(x == '('||x == '[')
        {
            Push(st,x);
            scanf("%c",&x);
        }
        else
        {
            scanf("%c",&y);
            while(!IsSeqEmpty(st))
            {
                if(-1 == st.top)
                    printf("OK");
                else
                {
                    x=st.data[st.top];
                    if((x == '('&& y == ']')||(x == '['&&y == ')'))
                    {
                        printf("Error");
                        break;
                    }
                    else
                    {
                        scanf("%c",&y);
                        st.top--;
                    }
                }
            }
        }

    }

    return 1;
}

