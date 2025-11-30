#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int year;
    float rating;
};

int main() {
    struct Movie movies[100];
    int count = 0, choice;
    char search_genre[30]; int i;

    while (1) {
        printf("\n1. Add Movie\n2. Search by Genre\n3. Display All\n4. Exit\nChoose: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Title: "); gets(movies[count].title);
            printf("Genre: "); gets(movies[count].genre);
            printf("Director: "); gets(movies[count].director);
            printf("Year: "); scanf("%d", &movies[count].year);
            printf("Rating: "); scanf("%f", &movies[count].rating);

            count++;
        }
        else if (choice == 2) {
            printf("Enter genre to search: ");
            gets(search_genre);

            for (i = 0; i < count; i++) {
                if (strcmp(movies[i].genre, search_genre) == 0) {
                    printf("\n%s (%d) - Dir: %s, Rating: %.1f\n",
                        movies[i].title, movies[i].year,
                        movies[i].director, movies[i].rating);
                }
            }
        }
        else if (choice == 3) {
            for (i = 0; i < count; i++) {
                printf("\nTitle: %s\nGenre: %s\nDirector: %s\nYear: %d\nRating: %.1f\n",
                    movies[i].title, movies[i].genre, movies[i].director,
                    movies[i].year, movies[i].rating);
            }
        }
        else break;
    }
    return 0;
}
