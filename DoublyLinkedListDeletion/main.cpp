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
    temp->data = A[0];
    temp->previous = temp->next = nullptr;
    first = last = temp;
    for (int i = 0; i < n; ++i) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->previous = last;
        last->previous = temp;
        last = temp;
    }
    last = temp = nullptr;
    free(last);
    free(temp);
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
    p = nullptr;
    free(p);
    printf("\n");
}

void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > length(p))
        return;
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0) {
        temp->next = p;
        temp->previous = nullptr;
        if (p != nullptr)p->previous = temp;
        first = temp;
    } else {
        for (int i = 0; i < index - 1; ++i) {
            p = p->next;
        }
        temp->next = p->next;
        temp->previous = p;
        if (p->next != nullptr)
            p->next->previous = temp;
        p->next = temp;
    }
    temp = p = nullptr;
    free(temp);
    free(p);
}

int deleteElement(struct Node *p, int index) {
    if (index < 1 || index > length(p))
        return -1;
    int x;
    if (index == 1) {
        x = p->data;
        first = p->next;
        if (p->next != nullptr) p->next->previous = nullptr;
    } else {
        for (int i = 0; i < index - 1; ++i)
            p = p->next;
        x = p->data;
        if (p->next != nullptr)
            p->next->previous = p->previous;
        p->previous->next = p->next;
        p->next = p->previous = nullptr;
    }
    free(p);
    return x;
}

int main() {
    int A[] = {};
    first = create(A, sizeof(A) / sizeof(int));
    display(first);
    insert(first, 1, 4);
    insert(first, 0, 7);
    insert(first, 0, 6);
    insert(first, 0, 8);
    insert(first, 0, 3);
    insert(first, 0, 5);
    insert(first, 4, 2);
    insert(first, 2, 0);
    insert(first, 7, 9);
    insert(first, 8, 11);
    insert(first, 0, 1);
    insert(first, 10, 6);
    display(first);
    cout << deleteElement(first, 5) << endl;
    display(first);
    cout << deleteElement(first, 6) << endl;
    display(first);
    cout << deleteElement(first, 0) << endl;
    display(first);
    cout << deleteElement(first, 1) << endl;
    display(first);
    return 0;
}
