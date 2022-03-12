#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE *fp1, *fp2;
struct Library x, p, temp;

struct Library
{
    char bk_name[100];
    int bk_id;
    int bk_price;
    char publish[100];
};

int read_lines()
{
    int i, lines;
    fp1 = fopen("lib.dat", "rb");

    char temp1;

    for (temp1 = getc(fp1); temp1 != EOF; temp1 = getc(fp1))
    {
        if (temp1 == '\n')
            lines = lines + 1;
    }
    fclose(fp1);

    return lines;
}

int search_record(int id)
{
    int i, lines, found_count1 = 0;
    fp1 = fopen("lib.dat", "r+");

    for (i = 1; i <= lines; i++)
    {
        fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);

        if (p.bk_id == id)
        {
            found_count1 = 1;
        }
    }
    fclose(fp1);

    return found_count1;
}

int main()
{
    int i, choice, price, del_id;
    char bk_name[100];
    int lines = 0;

    printf("\n\n## Library Management ##\n");

    printf("\n1. Insert new record\n");
    printf("2. Delete a record \n");
    printf("3. Display records of book\n");
    printf("4. Modify an existing record\n");
    printf("5. List all record\n");
    printf("6. Exit");

    printf("\n\nEnter one of the above : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:

        printf("Insert a new record");
        int end_id = 0;

        lines = read_lines();

        if (lines > 0)
        {
            fp1 = fopen("lib.dat", "rb");
            for (i = 1; i <= lines; i++)
            {
                fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);
                if (i == lines)
                {
                    end_id = p.bk_id;
                }
            }
            fclose(fp1);
        }

        printf("\nEnter book name: ");
        scanf("%s", x.bk_name);

        fp1 = fopen("lib.dat", "ab");

        end_id++;

        printf("Enter publisher name: ");
        scanf("%s", &x.publish);

        printf("Enter price: ");
        scanf("%d", &x.bk_price);

        if (fprintf(fp1, "%d %s %s %d", end_id, x.bk_name, x.publish, x.bk_price))
        {
            printf("\nBook record successfully entered!\n");
            fprintf(fp1, "\n");
        }
        else
        {
            printf("\nERROR: Some error occured!\n");
        }

        fclose(fp1);

        main();
        getch();
        break;

    case 2:
        printf("\n\n Delete a Record \n");
        int a = 2;
        printf("Enter a book ID to delete: ");
        scanf("%d", &del_id);

        lines = read_lines();

        fp1 = fopen("lib.dat", "r+");
        fp2 = fopen("copy.txt", "a+");

        for (i = 1; i <= lines; i++)
        {
            fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);

            if (p.bk_id != del_id)
            {
                fprintf(fp2, "%d %s %s %d", p.bk_id, p.bk_name, p.publish, p.bk_price);
                fprintf(fp2, "\n");
            }
            if (p.bk_id == del_id)
            {
                a = 0;
            }
        }
        fclose(fp1);
        fclose(fp2);

        remove("lib.dat");
        rename("copy.txt", "lib.dat");
        if (a == 0)
        {
            printf("\nRecord successfully deleted!\n");
        }
        else
        {
            printf("\nERROR: Either record not found or some other error occured!\n\n");
        }
        getch();
        break;

    case 3:
        printf("\n Display record of a specific book \n");
        int view_id;
        printf("Enter a book ID to view record: ");
        scanf("%d", &view_id);

        int found_count = 0;

        lines = read_lines();

        fp1 = fopen("lib.dat", "r+");

        for (i = 1; i <= lines; i++)
        {
            fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);

            if (p.bk_id == view_id)
            {
                found_count = 1;
                printf("\n------------------------------------------\n");
                printf("Book ID: %d \n Book Name: %s \n Publisher: %s \n Book Price: %d", p.bk_id, p.bk_name, p.publish, p.bk_price);
                printf("\n------------------------------------------");
                break;
            }
        }
        if (found_count == 0)
        {
            printf("\nERROR: Record does not exists! \n");
        }

        fclose(fp1);
        getch();
        break;

    case 4:

        printf("\nModify an existing record \n");
        int edit_id;
        printf("Enter a book ID to edit or modify its record: ");
        scanf("%d", &edit_id);

        int found_count1, modified = 0;

        lines = read_lines();

        found_count1 = search_record(edit_id);

        if (found_count1 == 0)
        {
            printf("\nERROR: Book ID %d does not exist \n", edit_id);
            break;
        }
        if (found_count1 == 1)
        {
            printf("\nEnter new records of book ID %d below \n", edit_id);

            printf("\nEnter new book name: ");
            scanf("%s", temp.bk_name);

            printf("Enter new publisher name: ");
            scanf("%s", temp.publish);

            printf("Enter new price: ");
            scanf("%d", &temp.bk_price);

            lines = read_lines();

            fp1 = fopen("lib.dat", "r+");
            fp2 = fopen("temp.txt", "a+");

            for (i = 1; i <= lines; i++)
            {
                fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);

                if (p.bk_id != edit_id)
                {
                    fprintf(fp2, "%d %s %s %d", p.bk_id, p.bk_name, p.publish, p.bk_price);
                    fprintf(fp2, "\n");
                }
                if (p.bk_id == edit_id)
                {
                    modified = 1;
                    fprintf(fp2, "%d %s %s %d", edit_id, temp.bk_name, temp.publish, temp.bk_price);
                    fprintf(fp2, "\n");
                }
            }

            if (modified == 1)
            {
                printf("\nRecord successfully modified! \n");
            }

            fclose(fp1);
            fclose(fp2);

            remove("lib.dat");
            rename("temp.txt", "lib.dat");
        }
        getch();
        break;

    case 5:

        printf("\n\n List all records\n");

        lines = read_lines();

        if (lines > 0)
        {
            fp1 = fopen("lib.dat", "rb");
            for (i = 1; i <= lines; i++)
            {
                fscanf(fp1, "%d %s %s %d", &p.bk_id, p.bk_name, p.publish, &p.bk_price);

                printf("\n------------------------------------------\n");
                printf("Book ID: %d \n Book Name: %s \n Publisher: %s \n Book Price: %d", p.bk_id, p.bk_name, p.publish, p.bk_price);
                printf("\n------------------------------------------");
            }
            fclose(fp1);
        }
        else
        {
            printf("\nERROR: No record found!\n");
        }
        getch();
        break;

    case 6:
        exit(0);
    }

    return 0;
}
