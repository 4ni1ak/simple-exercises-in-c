#include <stdio.h>
#define MAX_NAME 100
#define STUDENT_NUMBER 5//optional
#define MAX_EXAM 100

enum lectures {CHEMISTRY, MATHEMATICS, PHYSICS};

typedef struct marks {
    char name[MAX_NAME];
    float class_average[3];

    struct chemistry {
        float mark_C[MAX_EXAM+1];
        float average_C[MAX_EXAM + 1]; // +1 for the class average
    } chemistry;

    struct mathematics {
        float mark_M[MAX_EXAM+1];
        float average_M[MAX_EXAM + 1];
    } mathematics;

    struct physics {
        float mark_P[MAX_EXAM+1];
        float average_P[MAX_EXAM + 1];
    } physics;

} marks;
//functions used
void average_func(marks student[], float weights[][MAX_EXAM], int num_exams_c, int num_exams_m, int num_exams_p);

void print_results();

int main() {
    marks student[STUDENT_NUMBER];
    int i, j, k, Chemistry_total, Mathematics_total, Physics_total, choice;
    float sum=0,lecture_weights[3][MAX_EXAM];
    
	for(i=0;i<3;i++){
	    if(i==1){
    		puts("*This application is a grade average calculator application*");
		}
    	if(i!=1){
			for(j=0;j<60;j++){
    			printf("*");
			}
		}
		puts("\n");
				
	}
	puts("\n\n\n\t\tAnil Akpinar\n\n");
	
	
    do {
        printf("How many Chemistry exams did you take? (maximum 100)\n==> ");
        scanf("%d", &Chemistry_total);
        if (Chemistry_total > 100) {
            printf("Invalid input. Maximum number of exams is 100.\n");
        } else if (Chemistry_total <= 0) {
            printf("Invalid input. Number of exams must be greater than 0.\n");
        }
    } while (Chemistry_total <= 0 || Chemistry_total > 100);

	sum = 0;
	for(i = 0; i < Chemistry_total; i++) {
    	printf("%d. exam weight\n==> ", i+1);
    	scanf("%f", &lecture_weights[CHEMISTRY][i]);
    	sum += lecture_weights[CHEMISTRY][i];
	}

	while (sum != 100) {
    	printf("Invalid input. Total weight of exams must be 100.\n");
    	sum = 0;
    	for(i = 0; i < Chemistry_total; i++) {
	        printf("%d. exam weight\n==> ", i+1);
	        scanf("%f", &lecture_weights[CHEMISTRY][i]);
	        sum += lecture_weights[CHEMISTRY][i];
	    }
	}

    do {
        printf("How many Mathematics exams did you take? (maximum 100)\n==> ");
        scanf("%d", &Mathematics_total);
        if (Mathematics_total > 100) {
            printf("Invalid input. Maximum number of exams is 100.\n");
        } 
		else if (Mathematics_total <= 0) {
            printf("Invalid input. Number of exams must be greater than 0.\n");
        }
    } while (Mathematics_total <= 0 || Mathematics_total > 100);

	sum = 0;
	for(i = 0; i < Mathematics_total; i++) {
	    printf("%d. exam weight\n==> ", i+1);
	    scanf("%f", &lecture_weights[MATHEMATICS][i]);
	    sum += lecture_weights[MATHEMATICS][i];
	}
	
	while (sum != 100) {
	    printf("Invalid input. Total weight of exams must be 100.\n");
	    sum = 0;
	    for(i = 0; i < Mathematics_total; i++) {
	        printf("%d. exam weight\n==> ", i+1);
	        scanf("%f", &lecture_weights[MATHEMATICS][i]);
	        sum += lecture_weights[MATHEMATICS][i];
	    }
	}
	
	do {
	    printf("How many Physics exams did you take? (maximum 100)\n==> ");
        scanf("%d", &Physics_total);
        if (Physics_total > 100) {
            printf("Invalid input. Maximum number of exams is 100.\n");
        } 
		else if (Physics_total <= 0) {
            printf("Invalid input. Number of exams must be greater than 0.\n");
        }
    } while (Physics_total <= 0 || Physics_total >100);
    
	sum = 0;
	for(i = 0; i < Physics_total; i++) {
	    printf("%d. exam weight\n==> ", i+1);
	    scanf("%f", &lecture_weights[PHYSICS][i]);
	    sum += lecture_weights[PHYSICS][i];
	}

while (sum != 100) {
    printf("Invalid input. Total weight of exams must be 100.\n");
    sum = 0;
    for(i = 0; i < Physics_total; i++) {
    	printf("%d. exam weight\n==> ", i+1);
    	scanf("%f", &lecture_weights[PHYSICS][i]);
	    sum += lecture_weights[PHYSICS][i];
	    }
	}
    
    for(i = 0; i < STUDENT_NUMBER; i++) {
        printf("Enter name of student %d\n==> ", i+1);
        getchar();
        fgets(student[i].name, MAX_NAME, stdin);

        for(j = 0; j < Chemistry_total; j++) {
            do {
                printf("Enter Chemistry grade %d for student %s (between 0 and 100)\n==> ", j+1, student[i].name);
                scanf("%f", &student[i].chemistry.mark_C[j]);
                if(student[i].chemistry.mark_C[j] < 0 || student[i].chemistry.mark_C[j] > 100)
                    printf("Invalid input. Grade should be between 0 and 100.\n");
            } while(student[i].chemistry.mark_C[j] < 0 || student[i].chemistry.mark_C[j] > 100);
        }

        for(j = 0; j < Mathematics_total; j++) {
            do {
                printf("Enter Mathematics grade %d for student %s (between 0 and 100) \n==> ", j+1, student[i].name);
                scanf("%f", &student[i].mathematics.mark_M[j]);
                if(student[i].mathematics.mark_M[j] < 0 || student[i].mathematics.mark_M[j] > 100)
                    printf("Invalid input. Grade should be between 0 and 100.\n");
            } while(student[i].mathematics.mark_M[j] < 0 || student[i].mathematics.mark_M[j] > 100);
        }

        for(j = 0; j < Physics_total; j++) {
            do {
                printf("Enter Physics grade %d for student %s (between 0 and 100) \n==> ", j+1, student[i].name);
                scanf("%f", &student[i].physics.mark_P[j]);
                if(student[i].physics.mark_P[j] < 0 || student[i].physics.mark_P[j] > 100)
                    printf("Invalid input. Grade should be between 0 and 100.\n");
            } while(student[i].physics.mark_P[j] < 0 || student[i].physics.mark_P[j] > 100);
        }
    }
    average_func(student, lecture_weights, Chemistry_total, Mathematics_total, Physics_total);
	print_results(student);
    return 0;
}

/*functions*/ 
void average_func(marks student[], float weights[][MAX_EXAM], int num_exams_c, int num_exams_m, int num_exams_p) {
    int i, j, k;
    for (i = 0; i < STUDENT_NUMBER; i++) {
        for (j = 0; j < MAX_EXAM; j++) {
            student[i].chemistry.average_C[j] = 0;
            student[i].mathematics.average_M[j] = 0;
            student[i].physics.average_P[j] = 0;
        }
        student[i].chemistry.average_C[MAX_EXAM] = 0;
        student[i].mathematics.average_M[MAX_EXAM] = 0;
        student[i].physics.average_P[MAX_EXAM] = 0;

        for (j = 0; j < num_exams_c; j++) {//chemistry notes are collected for each student
            student[i].chemistry.average_C[j] += student[i].chemistry.mark_C[j] * weights[CHEMISTRY][j] / 100;
            student[i].chemistry.average_C[MAX_EXAM] += student[i].chemistry.mark_C[j] * weights[CHEMISTRY][j] / 100;
        }

        for (j = 0; j < num_exams_m; j++) {//mathematics notes are collected for each student
            student[i].mathematics.average_M[j] += student[i].mathematics.mark_M[j] * weights[MATHEMATICS][j] / 100;
            student[i].mathematics.average_M[MAX_EXAM] += student[i].mathematics.mark_M[j] * weights[MATHEMATICS][j] / 100;
        }

        for (j = 0; j < num_exams_p; j++) {//physics notes are collected for each student
            student[i].physics.average_P[j] += student[i].physics.mark_P[j] * weights[PHYSICS][j] / 100;
            student[i].physics.average_P[MAX_EXAM] += student[i].physics.mark_P[j] * weights[PHYSICS][j] / 100;
        }

        student[i].chemistry.average_C[MAX_EXAM] /= num_exams_c;//For each course, the average of the exams taken in that course is taken.
    	student[i].mathematics.average_M[MAX_EXAM] /= num_exams_m;
        student[i].physics.average_P[MAX_EXAM] /= num_exams_p;
        student[0].class_average[CHEMISTRY]   +=  student[i].chemistry.average_C[MAX_EXAM];//the average of each course is summed (to find the class average)
    	student[0].class_average[MATHEMATICS] +=  student[i].mathematics.average_M[MAX_EXAM]; 
    	student[0].class_average[PHYSICS]     +=  student[i].physics.average_P[MAX_EXAM];
    	
    }	
    	for(i=0;i<3;i++){
    	student[0].class_average[i]   /=   STUDENT_NUMBER;//find the class average
		} 
}
void print_results(marks student[]){
	int i;

	printf("***********************************************************************************************************\n");
	printf("*|%-25s|%-25s|%-25s|%-25s|*\n", "Student Name", "Chemistry Average(^,v)", "Mathematics Average(^,v)", "Physics Average(^,v)");
	printf("*|%-25s|%-25s|%-25s|%-25s|*\n", "-------------------------", "-------------------------", "-------------------------", "-------------------------");
	for (i = 0; i < STUDENT_NUMBER; i++) {
	    printf("*|%-25s|%-25.2f%c|%-25.2f%c|%-25.2f%c|*\n", student[i].name,
													        student[i].chemistry.average_C[MAX_EXAM],
													       (student[i].chemistry.average_C[MAX_EXAM] == student[0].class_average[CHEMISTRY] ? '=' : (student[i].chemistry.average_C[MAX_EXAM] > student[0].class_average[CHEMISTRY] ? '^' : 'v')),
													        student[i].mathematics.average_M[MAX_EXAM],
													       (student[i].mathematics.average_M[MAX_EXAM] == student[0].class_average[MATHEMATICS] ? '=' : (student[i].mathematics.average_M[MAX_EXAM] > student[0].class_average[MATHEMATICS] ? '^' : 'v')),
													        student[i].physics.average_P[MAX_EXAM],
													       (student[i].physics.average_P[MAX_EXAM] == student[0].class_average[PHYSICS] ? '=' : (student[i].physics.average_P[MAX_EXAM] > student[0].class_average[PHYSICS] ? '^' : 'v')));
	}
	printf("*|%-25s|%-25s|%-25s|%-25s|*\n", "-------------------------", "-------------------------", "-------------------------", "-------------------------");
	printf("*|%-25s|%-25.2f|%-25.2f|%-25.2f|*\n", "Class Average", student[0].class_average[CHEMISTRY], student[0].class_average[MATHEMATICS], student[0].class_average[PHYSICS]);
	printf("***********************************************************************************************************\n");
	printf("\nPress any key to see those who are above the average grade\n");
	getch();
	
	printf("\nStudents above class average for each lecture:\n");

	// Chemistry
	printf("\n*Chemistry*\n");
	printf("*|%-30s|*\n", "---------------------------");
	printf("*|%-30s|*\n", "Name");
	printf("*|%-30s|*\n", "---------------------------");
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (student[i].chemistry.average_C[MAX_EXAM] > student[0].class_average[CHEMISTRY]) {
			printf("*|%-30s|*\n", student[i].name);
		}
	}
	
	printf("*%-30s*\n", "********************************");
	
	// Mathematics
	printf("\n*Mathematics*\n");
	printf("*|%-30s|*\n", "---------------------------");
	printf("*|%-30s|*\n", "Name");
	printf("*|%-30s|*\n", "---------------------------");
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (student[i].mathematics.average_M[MAX_EXAM] > student[0].class_average[MATHEMATICS]) {
			printf("*|%-30s|*\n", student[i].name);
		}
	}
	
	printf("*%-30s*\n", "********************************");
	
	// Physics
	printf("\n*Physics*\n");
	printf("*|%-30s|*\n", "---------------------------");
	printf("*|%-30s|*\n", "Name");
	printf("*|%-30s|*\n", "---------------------------");
	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (student[i].physics.average_P[MAX_EXAM] > student[0].class_average[PHYSICS]) {
			printf("*|%-30s|*\n", student[i].name);
		}
	}
	
	printf("*%-30s*\n", "********************************");
		
		
		
	printf("\nThank you for using me\n\tSee you later :)\n");
	printf("\tAnil Akpinar\n\t");
	getchar();//:)
}//V 0.0.3