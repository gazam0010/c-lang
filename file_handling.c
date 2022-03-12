#include <stdio.h>

FILE *fp1, *fp2;
struct Library x, p, temp;

struct Library
{
    char bk_name[100];
    int bk_id;
    int bk_price;
};

int read_lines()
{
    int i, lines;
    fp1 = fopen("lib.txt", "rb");

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
    fp1 = fopen("lib.txt", "r+");

    for (i = 1; i <= lines; i++)
    {
        fscanf(fp1, "%s %d %d", p.bk_name, &p.bk_id, &p.bk_price);

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

        printf("Insert new record");
        fp1 = fopen("lib.txt", "ab");

        printf("\nEnter book name: ");
        scanf("%s", x.bk_name);

        printf("Enter ID: ");
        scanf("%d", &x.bk_id);

        printf("Enter price: ");
        scanf("%d", &x.bk_price);

        fprintf(fp1, "%s %d %d", x.bk_name, x.bk_id, x.bk_price);
        fprintf(fp1, "\n");
        fclose(fp1);
        printf("Data successfully written\n");
        printf("The file is now closed.");

        fclose(fp1);
        main();

        break;

    case 2:
        printf("\n\n Delete a Record \n");
        int a = 2;
        printf("Enter a book ID to delete: ");
        scanf("%d", &del_id);

        lines = read_lines();

        fp1 = fopen("lib.txt", "r+");
        fp2 = fopen("copy.txt", "a+");

        for (i = 1; i <= lines; i++)
        {
            fscanf(fp1, "%s %d %d", p.bk_name, &p.bk_id, &p.bk_price);

            if (p.bk_id != del_id)
            {
                fprintf(fp2, "%s %d %d", p.bk_name, p.bk_id, p.bk_price);
                fprintf(fp2, "\n");
            }
            if (p.bk_id == del_id)
            {
                a = 0;
            }
        }
        fclose(fp1);
        fclose(fp2);

        remove("lib.txt");
        rename("copy.txt", "lib.txt");
        if (a == 0)
        {
            printf("\nRecord successfully deleted!\n");
        }
        else
        {
            printf("\nEither record not found or some other error occured!\n");
        }

        break;

    case 3:
        printf("\n Display record of specific book \n");
        int view_id;
        printf("Enter a book ID to view record: ");
        scanf("%d", &view_id);

        int found_count = 0;

        lines = read_lines();

        fp1 = fopen("lib.txt", "r+");

        for (i = 1; i <= lines; i++)
        {
            fscanf(fp1, "%s %d %d", p.bk_name, &p.bk_id, &p.bk_price);

            if (p.bk_id == view_id)
            {
                found_count = 1;
                printf("\n\nBook name: %s \n Book id: %d \n Book price: %d", p.bk_name, p.bk_id, p.bk_price);
                break;
            }
        }
        if (found_count == 0)
        {
            printf("\n Record does not exists! \n");
        }

        fclose(fp1);

        break;

    case 4:

        printf("\nModify an existing record \n");
        int edit_id;
        printf("Enter a book ID to edit or modify its record: ");
        scanf("%d", &edit_id);

        int found_count1;

        lines = read_lines();

        found_count1 = search_record(edit_id);

        if (found_count1 == 0)
        {
            printf("\n Book ID %d does not exist \n", edit_id);
            break;
        }
        if (found_count1 == 1)
        {

            printf("\nEnter new records of book ID %d below \n", edit_id);

            printf("\nEnter new book name: ");
            scanf("%s", temp.bk_name);

            printf("Enter new book ID: ");
            scanf("%d", &temp.bk_id);

            printf("Enter new price: ");
            scanf("%d", &temp.bk_price);

            lines = read_lines();

            fp1 = fopen("lib.txt", "r+");
            fp2 = fopen("temp.txt", "a+");

            for (i = 1; i <= lines; i++)
            {
                fscanf(fp1, "%s %d %d", p.bk_name, &p.bk_id, &p.bk_price);

                if (p.bk_id != edit_id)
                {
                    fprintf(fp2, "%s %d %d", p.bk_name, p.bk_id, p.bk_price);
                    fprintf(fp2, "\n");
                }
            }

            if (fprintf(fp2, "%s %d %d", temp.bk_name, temp.bk_id, temp.bk_price) && fprintf(fp2, "\n"))
            {
                printf("\nRecord successfully modified! \n");
            }

            fclose(fp1);
            fclose(fp2);

            remove("lib.txt");
            rename("temp.txt", "lib.txt");
        }

        break;

    case 5:

        printf("\n\n List all record\n");
        fp1 = fopen("lib.txt", "rb");

        lines = read_lines();

        fp1 = fopen("lib.txt", "rb");
        for (i = 1; i <= lines; i++)
        {
            fscanf(fp1, "%s %d %d", p.bk_name, &p.bk_id, &p.bk_price);

            printf("\n\nBook name: %s \n Book id: %d \n Book price: %d", p.bk_name, p.bk_id, p.bk_price);
        }
        fclose(fp1);
        break;

    case 6:
        exit(0);
    }

    return 0;
}