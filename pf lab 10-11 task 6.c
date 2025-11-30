#include <stdio.h>
#include <string.h>

struct Salary {
    float basic;
    float bonus;
    float deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary sal;
};

float netSalary(struct Salary s) {
    return s.basic + s.bonus - s.deduction;
}

void display(struct Employee e) {
    printf("\n--- Employee Salary Details ---\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s", e.name);
    printf("Basic Pay: %.2f\n", e.sal.basic);
    printf("Bonus: %.2f\n", e.sal.bonus);
    printf("Deduction: %.2f\n", e.sal.deduction);
    printf("Net Salary: %.2f\n", netSalary(e.sal));
}

int main() {
    struct Employee e;

    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    getchar();

    printf("Enter employee name: ");
    fgets(e.name, sizeof(e.name), stdin);

    printf("Enter basic pay: ");
    scanf("%f", &e.sal.basic);

    printf("Enter bonus: ");
    scanf("%f", &e.sal.bonus);

    printf("Enter deduction: ");
    scanf("%f", &e.sal.deduction);

    display(e);
    return 0;
}
