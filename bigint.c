#include <stdlib.h>
#include <string.h>  
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "bigint.h"

Big_int* create_big_int(){
    Big_int* temp = (Big_int*)malloc(sizeof(Big_int));
    scanf("%s",temp->str_num);
    if(temp->str_num[0]=='-'){
        temp->sign='-';
        temp->str_num[0]='0';
    }
    else{
        temp->sign='+';
    }
    int k=int_block-1;
    int j=0;
    for(int i=strlen(temp->str_num)-1;i>=0;i--){
        if(isdigit(temp->str_num[i]) != 0){
            temp->num[k] += pow(10,j)*((int)temp->str_num[i] - (int)'0');
            j++;
            if((strlen(temp->str_num)-i)%max_size==0 || i==0){
                j=0;
                k--;
            }
        }
        else{
            printf("INVALID INPUT\n");
            return temp;                    //will return wrong value
        }
    }
    return temp;
}

void print_value(Big_int* n){
    if(NULL==n){
        return ;
    }
    if('-'==n->sign){
        printf("-");
    }
    for(int i=0;i<int_block;i++){
        if(n->num[i]!=0){
            printf("%d",n->num[i]);
        }
    }
    printf("\n");
}

Big_int* subtract(Big_int* a,Big_int* b){
    if(NULL==a || NULL==b){
        return NULL;
    }
    Big_int* temp = (Big_int*)malloc(sizeof(Big_int));
    if(a->sign=='+'&&b->sign=='-'){
        b->sign='+';
        temp=add(a,b);
    }
    else if(a->sign=='-'&&b->sign=='+'){
        b->sign='-';
        temp=add(a,b);
    }
    else{
        for(int i=0;i<int_block;i++){
            if(a->num[i] < b->num[i]){
                temp=b;
                b=a;
                a=temp;
                if(a->sign=='-'){    
                    temp->sign='+';
                }
                else{
                    temp->sign='-';
                }
                
                break;
            }
            else if(a->num[i]>b->num[i]){
                temp->sign=a->sign;
                break;
            }
        }
            for(int i=int_block-1;i>=0;i--){
                temp->num[i]=a->num[i]-b->num[i];
                int j=i;
                if(temp->num[j]<0 && j>=0){
                    temp->num[j]+=(long int)pow(10,max_size);
                    a->num[j-1]--;
                    j--;
                    while(a->num[j]<0 && j>0){
                        a->num[j]+=(long int)pow(10,max_size);
                        a->num[j-1]--;
                        j--;
                    }
                }
            }
        
    }
    
    return temp;
}

Big_int* add(Big_int* a,Big_int* b){
    if(NULL==a || NULL==b){
        return NULL;
    }
    Big_int* temp = (Big_int*)malloc(sizeof(Big_int));
    if(a->sign=='+' && b->sign=='+'){
        temp->sign=='+';
        for(int i=int_block-1;i>=0;i--){
            temp->num[i]=a->num[i]+b->num[i];
            int j=i-1;
            if(temp->num[j+1]/(long int)pow(10,max_size)!=0 && j>=0){
                b->num[j]++;
                while(j>0 && (b->num[j])/(long int)pow(10,max_size)!=0){
                    b->num[j]=b->num[j]%(long int)pow(10,max_size);
                    b->num[j-1]++;
                    j--;
                }
            }
            temp->num[i]=temp->num[i]%(long int)pow(10,max_size);
        }
    }
    else if(a->sign=='-' && b->sign=='-'){
        temp->sign='-';
        for(int i=int_block-1;i>=0;i--){
            temp->num[i]=a->num[i]+b->num[i];
            int j=i-1;
            if(temp->num[j+1]/(long int)pow(10,max_size)!=0 && j>=0){
                b->num[j]++;
                while(j>0 && (b->num[j])/(long int)pow(10,max_size)!=0){
                    b->num[j]=b->num[j]%(long int)pow(10,max_size);
                    b->num[j-1]++;
                    j--;
                }
            }
            temp->num[i]=temp->num[i]%(long int)pow(10,max_size);
        }
    }
    else{
        if(a->sign=='+'){
            b->sign='+';
            temp=subtract(a,b);
        }
        else{
            a->sign='+';
            temp=subtract(b,a);
        }
    }
    return temp;
}
