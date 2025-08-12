#include <stdio.h>


int add(int a,int b){
    return a+b;
}

int check(int (*op)(int, int), int a, int b,int expected)
{
    if(op(a,b)==expected){
        return 1;
    }
    else{
        return 0;
    }
}

struct Tests
{
    int Failed;
    int Passed;
    int Total;
};

int main(){
    struct Tests test;
    test.Failed=0;
    test.Passed=0;
    test.Total=0;
    int (*test_func)(int,int);
    test_func=add;
    int args[2]={1,2};
    
    if(check(test_func,1,2,3)){
        test.Passed++;
        test.Total++;
    }
    else{
        test.Failed++;
        test.Total++;
    }

    printf("Passed: %d\nFailed: %d\nTotal: %d\n",test.Passed,test.Failed,test.Total);
    
    
}