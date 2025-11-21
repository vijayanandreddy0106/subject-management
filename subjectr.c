#include <stdio.h>
#include <string.h>

struct Subject {
    int code;
    char name[50];
    int credits;
};

int main() {
    struct Subject s[100];
    int n = 0, i, choice, searchCode;

    while(1) {
        printf("\n-------- SUBJECT MANAGEMENT SYSTEM --------\n");
        printf("1. Add Subject\n");
        printf("2. Display All Subjects\n");
        printf("3. Search Subject by Code\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            // Add Subject
            case 1:
                printf("\nEnter Subject Code: ");
                scanf("%d", &s[n].code);

                printf("Enter Subject Name: ");
                scanf("%s", s[n].name);

                printf("Enter Credits: ");
                scanf("%d", &s[n].credits);

                n++;
                printf("Subject Added Successfully!\n");
                break;

            // Display Subjects
            case 2:
                printf("\n------- SUBJECT LIST -------\n");
                for(i = 0; i < n; i++) {
                    printf("\nCode: %d\nName: %s\nCredits: %d\n",
                           s[i].code, s[i].name, s[i].credits);
                }
                if(n == 0)
                    printf("No subjects added yet.\n");
                break;

            // Search Subject
            case 3:
                printf("\nEnter Subject Code to Search: ");
                scanf("%d", &searchCode);

                int found = 0;
                for(i = 0; i < n; i++) {
                    if(s[i].code == searchCode) {
                        found = 1;
                        printf("\nSubject Found!\n");
                        printf("Code: %d\nName: %s\nCredits: %d\n",
                               s[i].code, s[i].name, s[i].credits);
                        break;
                    }
                }

                if(!found)
                    printf("Subject Not Found!\n");
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
