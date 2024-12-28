#include <stdio.h>
struct Student {
    char name[50];
    int marks[5]; 
    float average;
};
void inputStudentData(struct Student *s);
void calculateAverage(struct Student *s);
void displayStudentData(struct Student s);

int main() {
    int n; 
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        inputStudentData(&students[i]);
        calculateAverage(&students[i]);
    }
    printf("\nStudent Details and Grades:\n");
    for (int i = 0; i < n; i++) {
        displayStudentData(students[i]);
    }
    return 0;
}
void inputStudentData(struct Student *s) {
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", s->name); 
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}
void calculateAverage(struct Student *s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    s->average = total / 5.0;
}
void displayStudentData(struct Student s) {
    printf("\nName: %s\n", s.name);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s.marks[i]);
    }
    printf("\nAverage: %.2f\n", s.average);
}
