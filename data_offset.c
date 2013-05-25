#include <stdio.h>
#include <stdint.h>

struct classA{
    int32_t data; 
};

struct classB{
    int8_t data[4];
};

struct classC{
    int32_t data;
    int32_t data1;
};

int main(){
    struct classA obj;
    struct classA *pa = &obj;
    struct classB *pb = (struct classB*)&obj;
    struct classC *pc = (struct classC*)&obj;
    obj.data = 0;
    printf("%d, %d, %d, %d, %d, %d\n", pa->data, pb->data[0], pb->data[1], pb->data[2], pb->data[3], pc->data);
    obj.data = 1;
    printf("%d, %d, %d, %d, %d, %d\n", pa->data, pb->data[0], pb->data[1], pb->data[2], pb->data[3], pc->data);
    obj.data = 1 << 8;
    printf("%d, %d, %d, %d, %d, %d\n", pa->data, pb->data[0], pb->data[1], pb->data[2], pb->data[3], pc->data);

    printf("%p %p\n",&(pb->data[1]) - &(((struct classB*)0)->data[1]), pb);
    return 0;
}
