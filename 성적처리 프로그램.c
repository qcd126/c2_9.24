#include <stdio.h>
// ����ü 
struct Student {
    char name[50]; 
    double math;    
    double eng;     
    double average; 
};
int main() { 
    struct Student students[3];
    // ���Ͽ��� ���� �о���� 
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }
    int i;
    for (i = 0; i < 3; i++) {
        fscanf(file, "%s %lf %lf", students[i].name, &students[i].math, &students[i].eng);
        students[i].average = (students[i].math + students[i].eng) / 2.0; // ���κ� ��� ���
    }
    fclose(file);
    // ���κ�, ���� ���
    double mathAvg = 0.0;
    double engAvg = 0.0;
    for (i = 0; i < 3; i++) {
        mathAvg += students[i].math;
        engAvg += students[i].eng;
    }
    mathAvg /= 3;
    engAvg /= 3;
    printf("���� ���: %.2lf\n", mathAvg);
    printf("���� ���: %.2lf\n", engAvg);
    
    for (i = 0; i < 3; i++) {
        printf("%s�� ���κ� ���: %.2lf\n", students[i].name, students[i].average);
    }
    // ��� ����� ���Ͽ� ����
    file = fopen("averages.txt", "w");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }
    fprintf(file, "���� ���: %.2lf\n", mathAvg);
    fprintf(file, "���� ���: %.2lf\n", engAvg);
    fclose(file);
    return 0;
}

