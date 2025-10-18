#include<stdio.h>
struct data{
    //case 1.0
        char a;
        int b;
        double c;
    //case 1.1
        // int b;
        // char a;
        // double c;
    //case 1.2
        // double c;
        // char a;
        // int b;
    //case 1.3
        // double c;
        // int b;
        // char a;
    //case 2.0
        // char a;
        // double c; 
        // int b;
    //case 2.1
        // int b;
        // double c; 
        // char a;
};
int main(){
        printf("size of struct is: %zu\n", sizeof(struct data));
        return 0;
}  