#include <stdio.h>

typedef struct data
{
    char name[30];
    int scores[3];
    float average;
} STUDENT;

void GetScores(STUDENT *student)
{
    for (int j = 0; j < 3; j++)
    {
        printf("Please enter score #%d: ", j + 1);
        scanf("%d", &student->scores[j]);
    }
}

int GetSum(STUDENT *student)
{
    int sum = 0;
    for (int m = 0; m < 3; m++)
    {
        sum += student->scores[m];
    }

    return sum;
}

float GetAverage(int sum)
{
    return (float)sum / 3;
}

void PrintStudentData(STUDENT *students, int numberOfStudents)
{
    printf("\nStudent data:\n");
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Scores: %d, %d, %d\n", students[i].scores[0], students[i].scores[1], students[i].scores[2]);
        printf("Average score: %.2f\n", students[i].average);
        printf("\n");
    }
}

int main()
{
    int numberOfStudents;

    printf("Enter number of students: ");
    scanf("%d", &numberOfStudents);

    STUDENT *students = malloc(numberOfStudents * sizeof(STUDENT));

    int i = 0;
    while (students)
    {
        printf("Please enter a name of student #%d: ", i + 1);
        scanf("%s", students->name);

        GetScores(students);

        int sum = GetSum(students);

        float average = GetAverage(sum);
        students->average = average;

        i++;
        students++;
    }


    PrintStudentData(students, numberOfStudents);

    return 0;
}
