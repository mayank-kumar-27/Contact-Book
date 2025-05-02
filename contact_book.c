#include <stdio.h>
#include <string.h>
struct contact_book
{
    char name[30];
    char phone[20];
    char email[50];
};
int main()
{
    struct contact_book person[100];
    char search[30], remove[30];
    int choice, i = 0;
    printf("\n                          *********************************************************************\n");
    printf("\n                                      --------------Contact Book--------------                 \n");
    printf("\n                          *********************************************************************\n");
    do
    {
        printf("\n                          1. Add a Contact");
        printf("\n                          2. Display Contacts");
        printf("\n                          3. Search for a Contact");
        printf("\n                          4. Delete a Contact");
        printf("\n                          0. Exit");
        printf("\n                          Please choose an option (0-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
            if (i < 100) 
            {
                printf("\nEnter Name: ");
                getchar(); 
                fgets(person[i].name, sizeof(person[i].name), stdin);
                person[i].name[strcspn(person[i].name, "\n")] = '\0'; 

                printf("Enter Phone: ");
                fgets(person[i].phone, sizeof(person[i].phone), stdin);
                person[i].phone[strcspn(person[i].phone, "\n")] = '\0';

                printf("Enter Email: ");
                fgets(person[i].email, sizeof(person[i].email), stdin);
                person[i].email[strcspn(person[i].email, "\n")] = '\0';

                i++;
                printf("\nContact added successfully!\n");
            }
            else
            {
                printf("\nThe contact book is full. Unable to add more contacts.\n");
            }
            break;
        case 2:
            if (i > 0)
            {
                printf("\n%-4s %-30s %-20s %-50s\n", "No.", "Name", "Phone", "Email");
                printf("--------------------------------------------------------------------------------\n");
                for (int j = 0; j < i; j++)
                {
                    printf("%-4d %-30s %-20s %-50s\n", j + 1, person[j].name, person[j].phone, person[j].email);
                }
            }
            else
            {
                printf("\nNo contacts available in your book.\n");
            }
            break;
        case 3: 
            printf("\nEnter Name: ");
            getchar(); 
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0'; 
            int found = 0; 
            for (int k = 0; k < i; k++)
            {
                if (strcmp(person[k].name, search) == 0)
                {
                    printf("\nContact Found:\n");
                    printf("Name: %s\n", person[k].name);
                    printf("Phone: %s\n", person[k].phone);
                    printf("Email: %s\n", person[k].email);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nNo contact found with the name '%s'.\n", search);
            }
            break;
        case 4: 
            printf("\nEnter the Name of the Contact you wish to delete: ");
            getchar(); 
            fgets(remove, sizeof(remove), stdin);
            remove[strcspn(remove, "\n")] = '\0'; 
            int deleted = 0; 
            for (int k = 0; k < i; k++)
            {
                if (strcmp(person[k].name, remove) == 0)
                {
                    for (int l = k; l < i - 1; l++)
                    {
                        person[l] = person[l + 1]; 
                    }
                    i--; 
                    deleted = 1;
                    break;
                }
            }
            if (deleted)
            {
                printf("\nContact '%s' has been successfully deleted.\n", remove);
            }
            else
            {
                printf("\nNo contact found with the name '%s'.\n", remove);
            }
            break;
        case 0: 
            printf("\nThank you for using the Contact Book. Have a wonderful day!\n");
            break;

        default: 
            printf("\nInvalid option! Please select a number between 0 and 4.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}