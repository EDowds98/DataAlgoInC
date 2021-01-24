#include "Stack.h"

int main() {
    init_stack();
    push(4);
    push(7);
    push(8);
    pop();
    pop();
    push(12);
    pop();
    top();
}
