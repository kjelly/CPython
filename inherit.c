#include <stdio.h>
typedef void (*myfunc)();
#define Father_HEADER \
  myfunc init;

struct father{
    Father_HEADER
};


struct child1{
    Father_HEADER
    myfunc custom1;
};

struct child2{
    Father_HEADER
    myfunc custom2;
};

void father_init(){
    printf("call father init\n");
}

void child1_init(){
    printf("call child1 init\n");
}

void child2_init(){
    printf("call child2 init\n");
}

void call_init(struct father *obj){
    obj->init();
}

int main(){
    struct father f_obj = {father_init};
    struct child1 c1_obj = {child1_init, 0};
    struct child2 c2_obj = {child2_init, 0};

    call_init(&f_obj);
    call_init((struct father*) &c1_obj);
    call_init((struct father*) &c2_obj);
    return 0;
}
