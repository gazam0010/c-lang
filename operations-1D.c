#include <stdio.h>
int main()
{
    int arr[50], arr2[50], arr3[50], choice, i, j, t, len, len2, mergelen, num, pos, elem;

    printf("Enter your choice: \n");
    printf("1. Insertion \n");
    printf("2. Deletion \n");
    printf("3. Search \n");
    printf("4. Sorting \n");
    printf("5. Merge \n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You have chosen INSERTION \n");
        printf("Enter the length of the array: ");
        scanf("%d", &len);
        printf("Please insert data to the array: \n");
        for (i = 0; i <= len; i++)
        {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
        printf("You have entered the follwing data-\n");
        for (i = 0; i <= len; i++)
        {
            printf("arr[%d] = ", i);
            printf("%d \n", arr[i]);
        }
        printf("\n");
    }

    else if (choice == 2)
    {
        printf("You have chosen DELETION \n");

        printf(" \n Enter the length of the array: ");
        scanf("%d", &len);

        printf(" \n Enter %d elements in array: \n ", len);

        for (i = 0; i < len; i++)
        {
            printf("arr[%d] = ", i);
            scanf(" %d", &arr[i]);
        }

        printf(" Define the position of the array element where you want to delete: \n ");
        scanf(" %d", &pos);

        if (pos >= len + 1)
        {
            printf(" \n Deletion is not possible in the array.");
        }
        else
        {
            for (i = pos - 1; i < len - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            printf(" \n The resultant array is: \n");

            for (i = 0; i < len - 1; i++)
            {
                printf(" arr[%d] = ", i);
                printf(" %d \n", arr[i]);
            }
        }
    }

    else if (choice == 3)
    {
        printf("You have chosen SEARCH \n");

        printf(" \n Enter the length of the array: ");
        scanf("%d", &len);

        printf(" \n Enter %d elements in array: \n ", len);

        for (i = 0; i < len; i++)
        {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }

        printf("Enter element to be searched: ");
        scanf("%d", &elem);
        for (i = 0; i < len; i++)
        {
            if (arr[i] == elem)
            {
                printf("Element found at %d", i);
                printf("\n");
            }
        }
    }

    else if (choice == 4)
    {
        printf("You have chosen SORTING \n");
        printf(" \n Enter the length of the array: ");
        scanf("%d", &len);

        printf(" \n Enter %d elements in array: \n ", len);

        for (i = 0; i < len; i++)
        {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < len - 1; i++)
        {
            for (j = i + 1; j < len; j++)
            {
                if (arr[i] > arr[j])
                {
                    t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }

        printf("After bubble sorting the elements are:\n");
        for (i = 0; i < len; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }

    else if (choice == 5)
    {
        printf("You have chosen MERGING \n");

        printf(" \n Enter the length of the Array 1: ");
        scanf("%d", &len);

        printf(" \n Enter the length of the Array 2: ");
        scanf("%d", &len2);

        mergelen = len + len2;
        int k = len;

        printf(" \n Enter %d elements in Array 1: \n ", len);

        for (i = 0; i < len; i++)
        {
            printf("arr1[%d] = ", i);
            scanf(" %d", &arr[i]);
            arr3[i] = arr[i];
        }

        printf(" \n Enter %d elements in Array 2: \n ", len2);

        for (i = 0; i < len2; i++)
        {
            printf("arr2[%d] = ", i);
            scanf(" %d", &arr2[i]);
            arr3[k] = arr2[i];
            k++;
        }

        printf("The merged array is: \n");
        for (i = 0; i < mergelen; i++)
        {
            printf("%d ", arr3[i]);
        }
        printf("\n");
    }

    else
    {
        printf("You have entered a wrong input, kindly enter any number between 1 and 5.");
        printf("\n");
        main();
    }
}
