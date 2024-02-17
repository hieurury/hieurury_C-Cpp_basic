#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char username[50];
    int score;
};

struct Question {
    char content[100];
    char answer[50];
};

void clearScreen() {
    system("cls");  // Xoa man hinh console
}

void savePlayers(struct Player* players, int numPlayers) {
    FILE* playerFile = fopen("players.txt", "w");
    if (playerFile != NULL) {
        fprintf(playerFile, "%d\n", numPlayers);
        for (int i = 0; i < numPlayers; i++) {
            fprintf(playerFile, "%s %d\n", players[i].username, players[i].score);
        }
        fclose(playerFile);
    }
}

void loadPlayers(struct Player** players, int* numPlayers) {
    FILE* playerFile = fopen("players.txt", "r");
    if (playerFile != NULL) {
        fscanf(playerFile, "%d", numPlayers);
        *players = (struct Player*)malloc(*numPlayers * sizeof(struct Player));
        for (int i = 0; i < *numPlayers; i++) {
            fscanf(playerFile, "%s %d", (*players)[i].username, &(*players)[i].score);
        }
        fclose(playerFile);
    }
}

void showPlayerList(struct Player* players, int numPlayers) {
    clearScreen();
    printf("Danh sach nguoi choi:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - Diem so: %d\n", players[i].username, players[i].score);
    }
    printf("\n");
}

void showQuestionList(struct Question* questions, int numQuestions) {
    clearScreen();
    printf("Danh sach cau hoi:\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("Cau hoi %d: %s\n", i + 1, questions[i].content);
    }
    printf("\n");
}

void sortPlayers(struct Player* players, int numPlayers) {
    clearScreen();
    // Sap xep nguoi choi theo diem so (vi du: su dung bubble sort)
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                // Hoan doi vi tri
                struct Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    printf("Nguoi choi da duoc sap xep theo diem so.\n");
}

void addQuestion(struct Question** questions, int* numQuestions) {
    clearScreen();
    printf("Nhap noi dung cau hoi: ");
    char content[100];
    scanf(" %[^\n]", content);
    printf("Nhap dap an: ");
    char answer[50];
    scanf(" %[^\n]", answer);

    (*numQuestions)++;
    *questions = (struct Question*)realloc(*questions, *numQuestions * sizeof(struct Question));

    strcpy((*questions)[*numQuestions - 1].content, content);
    strcpy((*questions)[*numQuestions - 1].answer, answer);

    printf("Cau hoi moi da duoc them!\n");

    // Luu du lieu cau hoi vao tep ngay sau khi them
    FILE* questionFile = fopen("questions.txt", "a");
    if (questionFile != NULL) {
        fprintf(questionFile, "%s\n", content);
        fprintf(questionFile, "%s\n", answer);
        fclose(questionFile);
    }
}

void playGame(struct Question* questions, int numQuestions, struct Player* player) {
    clearScreen();
    printf("Chao mung %s den voi tro choi!\n", player->username);

    for (int i = 0; i < numQuestions; i++) {
        printf("Cau hoi %d: %s\n", i + 1, questions[i].content);
        char userAnswer[50];
        scanf(" %[^\n]", userAnswer);
        if (strcmp(userAnswer, questions[i].answer) == 0) {
            player->score++;
            printf("Dung!\n");
        } else {
            printf("Sai.\n");
        }
    }

    printf("Diem cua ban: %d\n", player->score);
    printf("Ket thuc tro choi.\n");
}

int main() {
    int numPlayers = 0;
    struct Player* players = NULL;

    loadPlayers(&players, &numPlayers);

    int numQuestions = 2;
    struct Question* questions = (struct Question*)malloc(numQuestions * sizeof(struct Question));

    // Doc cau hoi tu tep va luu vao cau truc du lieu
    FILE* questionFile = fopen("questions.txt", "r");
    if (questionFile != NULL) {
        for (int i = 0; i < numQuestions; i++) {
            fscanf(questionFile, " %[^\n]", questions[i].content);
            fscanf(questionFile, " %[^\n]", questions[i].answer);
        }
        fclose(questionFile);
    }

    strcpy(questions[0].content, "Cau lenh de in ra 'Hello, World!' la gi?");
    strcpy(questions[0].answer, "printf(\"Hello, World!\");");

    strcpy(questions[1].content, "C trong ngon ngu C la viet tat cua tu gi?");
    strcpy(questions[1].answer, "Control");

    int choice;
    while (1) {
	  // Xoa man hinh console

        printf("----- MENU -----\n");
        printf("1. Xem danh sach nguoi choi\n");
        printf("2. Xem danh sach cau hoi\n");
        printf("3. Sap xep nguoi choi\n");
        printf("4. Them cau hoi\n");
        printf("5. Dang ky dang nhap\n");
        printf("6. Bat dau tro choi\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showPlayerList(players, numPlayers);
                break;
            case 2:
                showQuestionList(questions, numQuestions);
                break;
            case 3:
                sortPlayers(players, numPlayers);
                break;
            case 4:
                addQuestion(&questions, &numQuestions);
                break;
            case 5: {
                char username[50];
                printf("Nhap ten nguoi choi: ");
                scanf("%s", username);

                int playerIndex = -1;
                for (int i = 0; i < numPlayers; i++) {
                    if (strcmp(players[i].username, username) == 0) {
                        playerIndex = i;
                        break;
                    }
                }

                if (playerIndex == -1) {
                    numPlayers++;
                    players = (struct Player*)realloc(players, numPlayers * sizeof(struct Player));
                    strcpy(players[numPlayers - 1].username, username);
                    players[numPlayers - 1].score = 0;
                    printf("Nguoi choi moi da duoc tao!\n");
                    playerIndex = numPlayers - 1;
                } else {
                    printf("Dang nhap thanh cong!\n");
                }

                break;
            }
            case 6:
                if (numPlayers == 0) {
                    printf("Ban can phai dang ky truoc khi bat dau tro choi.\n");
                } else {
                    clearScreen();
                    char username[50];
                    printf("Nhap ten nguoi choi: ");
                    scanf("%s", username);

                    int playerIndex = -1;
                    for (int i = 0; i < numPlayers; i++) {
                        if (strcmp(players[i].username, username) == 0) {
                            playerIndex = i;
                            break;
                        }
                    }

                    if (playerIndex != -1) {
                        playGame(questions, numQuestions, &players[playerIndex]);
                    } else {
                        printf("Nguoi choi khong ton tai. Vui long dang nhap hoac dang ky.\n");
                    }
                }
                break;
            case 7:
                // Luu trang thai tro choi va thoat
                savePlayers(players, numPlayers);
                free(questions);
                free(players);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}
