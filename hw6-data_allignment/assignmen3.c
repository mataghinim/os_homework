#include<stdio.h>
#pragma pack(1)
//#pragma pack(2)
//#pragma pack(4)
//#pragma pack(8)

struct PackedStruct {
    char a;
    int b;
    double c;

};
int main(){
        printf("size of struct is: %zu\n", sizeof(struct PackedStruct));
        return 0;
}  