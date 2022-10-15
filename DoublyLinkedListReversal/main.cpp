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
    temp->previous = nullptr;
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
    free(last);
    free(temp);
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
    p = nullptr;
    free(p);
    return counter;
}

void display(struct Node *p) {
    if (p == nullptr)
        return;
    while (p != nullptr) {
        printf("%d ", p->data);
        if (p->next == nullptr) {
            p = p->previous;
            while (p != nullptr) {
                printf("%d ", p->data);
                p = p->previous;
            }
            break;
        }
        p = p->next;
    }

    printf("\n");
    p = nullptr;
    free(p);
}

struct Node *reverse(struct Node *p) {
    if (p == nullptr || p->next == nullptr)
        return p;
    struct Node *temp;
    while (p != nullptr) {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        if (p->previous == nullptr)
            first = p;
        p = temp;
    }
    temp = p = nullptr;
    free(temp);
    free(p);
    return first;
}

int main() {
    int A[] = {2, 3, 5, 7, 10, 15};
    first = create(A, sizeof(A) / sizeof(int));
    display(first);
    reverse(first);
    cout << endl;
    display(first);
    return 0;
}
