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
    printf("\n");
}

void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > length(p))
        return;
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0) {
        if (p == nullptr)
            temp->next = nullptr;
        else {
            temp->next = p;
            p->previous = temp;
        }
        temp->previous = nullptr;
        first = temp;
    } else {
        for (int i = 0; i < index - 1; ++i) {
            p = p->next;
        }
        temp->next = p->next;
        if (p->next != nullptr)
            p->next->previous = temp;
        p->next = temp;
        temp->previous = p;
    }
    temp = p = nullptr;
    free(temp);
    free(p);
}

int main() {
//    int A[] = {};
    int A[] = {2, 3, 4, 6, 8, 11, 14, 21, 22, 25, 27};
    first = create(A, sizeof(A) / sizeof(int));
    display(first);
    insert(first, 0, 5);
    insert(first, 0, 4);
    insert(first, 0, 3);
    insert(first, 0, 3);
    insert(first, 0, 2);
    insert(first, 0, 2);
    insert(first, 3, 0);
    insert(first, 4, 1);
    insert(first, 5, 7);
    insert(first, 6, 9);
    display(first);
    return 0;
}
