#include <stdio.h>
#include <string.h>

struct Player {
    char name[50];
    int age;
    char position[30];
};

struct Team {
    char teamName[50];
    char sport[30];
    struct Player players[50];
    int playerCount;
};

void add_player(struct Team *t) {
    printf("Enter player name: ");
    getchar();
    gets(t->players[t->playerCount].name);

    printf("Age: ");
    scanf("%d", &t->players[t->playerCount].age);
    getchar();

    printf("Position: ");
    gets(t->players[t->playerCount].position);

    t->playerCount++;
}

void search_position(struct Team t, char pos[]) {
	int i;
    printf("\nPlayers with position %s:\n", pos);
    for (i = 0; i < t.playerCount; i++) {
        if (strcmp(t.players[i].position, pos) == 0) {
            printf("%s (Age %d)\n", t.players[i].name, t.players[i].age);
        }
    }
}

void display_team(struct Team t) {
	int i;
    printf("\n--- TEAM DETAILS ---\n");
    printf("Team: %s\nSport: %s\n", t.teamName, t.sport);
    printf("Players:\n");
    for (i = 0; i < t.playerCount; i++) {
        printf("%s - Age %d - %s\n",
               t.players[i].name,
               t.players[i].age,
               t.players[i].position);
    }
}

int main() {
    struct Team t = {"Thunderbolts", "Football", {}, 0};
    int choice;
    char pos[30];

    while (1) {
        printf("\n1. Add Player\n2. Search by Position\n3. Display Team\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) add_player(&t);
        else if (choice == 2) {
            printf("Enter position to search: ");
            getchar();
            gets(pos);
            search_position(t, pos);
        }
        else if (choice == 3) display_team(t);
        else break;
    }
    return 0;
}
