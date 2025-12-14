#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20
typedef struct {
    int key;
    char name[30];
    int used;
} Employee;
int hashFunction(int key, int m) { return key % m; }
void insert(Employee ht[], int m, int key, char name[]) {
    for (int i = 0; i < m; i++) {
        int idx = (hashFunction(key, m) + i) % m;
        if (!ht[idx].used) {
            ht[idx] = (Employee){ key, "", 1 };
            strcpy(ht[idx].name, name);
            printf("Inserted key %d at index %d\n", key, idx);
            return;
        }
    }
    printf("Hash table is full! Cannot insert key %d\n", key);
}
void search(Employee ht[], int m, int key) {
    for (int i = 0; i < m; i++) {
        int idx = (hashFunction(key, m) + i) % m;
        if (!ht[idx].used) break;
        if (ht[idx].key == key) {
            printf("Found key %d at index %d (Name: %s)\n", key, idx, ht[idx].name);
            return;
        }
    }
    printf("Key %d not found!\n", key);
}
void display(Employee ht[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++)
        if (ht[i].used)
            printf("Index %d --> Key: %d, Name: %s\n", i, ht[i].key, ht[i].name);
        else
            printf("Index %d --> Empty\n", i);
}
int main() {
    int m, n, key;
    char name[30];
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    Employee ht[MAX_SIZE] = {0};
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter 4-digit key for employee %d: ", i+1);
        scanf("%d", &key);
        printf("Enter name: ");
        scanf(" %[^\n]", name);
        insert(ht, m, key, name);
    }
    display(ht, m);
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    search(ht, m, key);
    return 0;
}