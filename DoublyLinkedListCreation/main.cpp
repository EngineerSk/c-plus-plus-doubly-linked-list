#include <iostream>

using namespace std;

struct Node {
    struct Node *previous, *next;
    int data;
} *first = nullptr;

struct Node *create(const int *A, int n) {
    if (A == nullptr || n == 0)
        return nullptr;
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node)), *last;
    temp->previous = nullptr;
    temp->data = A[0];
    temp->next = nullptr;
    first = last = temp;
    for (int i = 1; i < n; ++i) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->previous = last;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    last = temp = nullptr;
    free(temp);
    free(last);
    return first;
}

int length(struct Node *p) {
    if (p == nullptr)
        return 0;
    int counter = 0;
    do {
        ++counter;
        p = p->next;
    } while (p != nullptr);
    return counter;
}

void display(struct Node *p) {
    if (p == nullptr)
        return;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != nullptr);
}

int main() {
    int A[] = {2, 3, 5, 6, 9, 11, 13, 17};
    first = create(A, sizeof(A) / sizeof(int));
    display(first);
    return 0;
}
