#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int bid;
    char bname[20];
    int price;
    char author[25];
} Book;

void Display(Book* arr1, int size) {
    if (size == 0) {
        printf("No books available to display.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("\nBook ID = %d", arr1[i].bid);
        printf("\nBook Name = %s", arr1[i].bname);
        printf("\nBook Price = %d", arr1[i].price);
        printf("\nBook Author = %s\n", arr1[i].author);
    }
}

void Addbook(Book* arr1, int totalBooks, int numToAdd) {
    for (int i = totalBooks; i < totalBooks + numToAdd; i++) {
        printf("Enter a book ID: ");
        scanf("%d", &arr1[i].bid);
        printf("Enter a book name: ");
        scanf("%s", arr1[i].bname);
        printf("Enter a book price: ");
        scanf("%d", &arr1[i].price);
        printf("Enter a book author name: ");
        scanf("%s", arr1[i].author);
    }
}

void SearchBookById(Book* arr1, int size) {
    int searchId;
    printf("Enter the Book ID to search: ");
    scanf("%d", &searchId);
    
     for (int i = 0; i < size; i++) {
        if (arr1[i].bid == searchId) {
            printf("\nBook found:");
            printf("\nBook ID = %d", arr1[i].bid);
            printf("\nBook Name = %s", arr1[i].bname);
            printf("\nBook Price = %d", arr1[i].price);
            printf("\nBook Author = %s\n", arr1[i].author);
            return; // Exit the function after finding the book
        }
    }
    printf("Book with ID %d not found.\n", searchId);
}

void SearchBookByname(Book* arr1 )
{
	char searchName[20];
                printf("enter book name");
                scanf("%s",searchName);
    
    for (int i = 0; i <=strlen(searchName); i++)
	 {
        if (strcmp(arr1[i].bname,searchName)==0)
		 {
            printf("\nBook found:");
            printf("\nBook ID = %d", arr1[i].bid);
            printf("\nBook Name = %s", arr1[i].bname);
            printf("\nBook Price = %d", arr1[i].price);
            printf("\nBook Author = %s\n", arr1[i].author);
            return; // Exit the function after finding the book
    }
 }
 printf("Book with name %s not found.\n", searchName);
}

void SearchBookByAuthorname(Book* arr1 )
{
	char authorName[20];
                printf("enter author name");
                scanf("%s",authorName);
    
    for (int i = 0; i <=strlen(authorName); i++)
	 {
        if (strcmp(arr1[i].author,authorName)==0)
		 {
            printf("\nBook found:");
            printf("\nBook ID = %d", arr1[i].bid);
            printf("\nBook Name = %s", arr1[i].bname);
            printf("\nBook Price = %d", arr1[i].price);
            printf("\nBook Author = %s\n", arr1[i].author);
            return; // Exit the function after finding the book
    }
 }
 printf("Book with name %s not found.\n", authorName);
}
void RemoveBook(Book* arr1, int* size) {
    int removeId;
    printf("Enter the Book ID to remove: ");
    scanf("%d", &removeId);

    for (int i = 0; i < *size; i++) {
        if (arr1[i].bid == removeId) {
            // Shift books down to fill the gap
            for (int j = i; j < *size - 1; j++) {
                arr1[j] = arr1[j + 1];
            }
            (*size)--; // Decrease the size
            printf("Book with ID %d has been removed.\n", removeId);
            return; // Exit after removing the book
        }
    }
    printf("Book with ID %d not found.\n", removeId);
}

void UpdateBook(Book* arr1, int size) {
    int updateId;
    printf("Enter the Book ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < size; i++) {
        if (arr1[i].bid == updateId) {
            printf("Updating book with ID %d\n", arr1[i].bid);
            printf("Enter new book name: ");
            scanf("%s", arr1[i].bname);
            printf("Enter new book price: ");
            scanf("%d", &arr1[i].price);
            printf("Enter new author name: ");
            scanf("%s", arr1[i].author);
            printf("Book updated successfully.\n");
            return; // Exit after updating the book
        }
    }
    printf("Book with ID %d not found.\n", updateId);
}

int main() {
    int ch;
    int size;
    int totalBooks = 0; 
    int z;
char searchName[20];
    printf("How many books do you want to enter initially? ");
    scanf("%d", &size);

    Book* arr = (Book*)malloc(size * sizeof(Book));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\nPress 1 to add book:");
        printf("\nPress 2 to display books:");
        printf("\nPress 3 to search for a book:");
        printf("\nPress 4 to remove a book:");
        printf("\nPress 5 to update a book:");
        printf("\nPress 0 to exit:");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                printf("How many books do you want to add? ");
                int numToAdd;
                scanf("%d", &numToAdd);

				if((size+totalBooks)<numToAdd)
				{
				
                arr = (Book*)realloc(arr, (totalBooks + numToAdd) * sizeof(Book));
                if (arr == NULL) {
                    printf("Memory allocation failed\n");
                    return 1;
                }
            }

                Addbook(arr, totalBooks, numToAdd);
                totalBooks += numToAdd; // Update total number of books
                break;
            }

            case 2:
    
                Display(arr, totalBooks);
                break;

            case 3:
            	
        
			{
			
            	printf(" How do you want search :6");
            	printf("\nPress 1 to search by id:\nPress 2 to search by book name : \nnPress 3 to search by author name :");
            	scanf("%d",&z);
            	if(z==1)
                SearchBookById(arr, totalBooks);
                if(z==2)
                SearchBookByname(arr);
                if(z==3)
                SearchBookByAuthorname( arr );
                break;
				}
                

            case 4:
                RemoveBook(arr, &totalBooks);
                break;

            case 5:
                UpdateBook(arr, totalBooks);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (ch != 0);

    free(arr);
    return 0;
}