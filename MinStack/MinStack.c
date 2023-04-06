#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* data;
    int* mins;
    size_t len;
    size_t cap;
} MinStack;

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("Out of memory!");
        exit(0);
    }
}

MinStack* minStackCreate() {
    size_t cap = 16;
    size_t len = 0;
    int* ptr1 = (int*)malloc(cap * sizeof(int));
    nullCheck(ptr1);
    int* ptr2 = (int*)malloc(cap * sizeof(int));
    nullCheck(ptr2);
    MinStack* res = (MinStack*)malloc(sizeof(MinStack));
    *res = (MinStack){
        .data = ptr1,
        .mins = ptr2,
        .len = len,
        .cap = cap
    };
    return res;
}

void minStackPush(MinStack* obj, int val) {
    obj->len++;
    if (obj->len > obj->cap) {
        obj->cap *= 2;
        obj->data = (int*)realloc(obj->data, obj->cap * sizeof(int));
        nullCheck(obj->data);
        obj->mins = (int*)realloc(obj->mins, obj->cap * sizeof(int));
        nullCheck(obj->mins);
    }
    obj->data[obj->len - 1] = val;
    int min = val;
    if (obj->len > 1) {
        if (obj->mins[obj->len - 2] < val)
            min = obj->mins[obj->len - 2];
    }
    obj->mins[obj->len - 1] = min;
}

void minStackPop(MinStack* obj) {
    obj->len--;
    if (obj->len * 2 < obj->cap) {
        obj->cap /= 2;
        obj->data = (int*)realloc(obj->data, obj->cap * sizeof(int));
        obj->mins = (int*)realloc(obj->mins, obj->cap * sizeof(int));
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->len - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->len - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}

int main() {
    return 0;
}
