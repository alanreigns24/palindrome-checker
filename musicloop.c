#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[100];
    struct Song* next;
};

struct Song* createSong(char name[]) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    return newSong;
}

struct Song* insertSong(struct Song* tail, char name[]) {
    struct Song* newSong = createSong(name);
    if (tail == NULL) {
        newSong->next = newSong; 
        return newSong;
    } else {
        newSong->next = tail->next;
        tail->next = newSong;
        return newSong;
    }
}

void playSongs(struct Song* tail, int loops) {
    if (tail == NULL) {
        printf("No songs in playlist.\n");
        return;
    }

    struct Song* current = tail->next;
    printf("\n--- Now Playing ---\n");
    for (int i = 0; i < loops; i++) {
        printf("\nLoop %d:\n", i + 1);
        struct Song* temp = current;
        do {
            printf("Playing: %s\n", temp->name);
            temp = temp->next;
        } while (temp != current);
    }
}

int main() {
    int numSongs, loopCount;
    char songName[100];
    struct Song* tail = NULL;

    printf("Enter number of songs to add: ");
    scanf("%d", &numSongs);
    getchar(); 

    for (int i = 0; i < numSongs; i++) {
        printf("Enter name of song %d: ", i + 1);
        fgets(songName, sizeof(songName), stdin);
        songName[strcspn(songName, "\n")] = 0; 
        tail = insertSong(tail, songName);
    }

    printf("Enter how many times you want to loop the playlist: ");
    scanf("%d", &loopCount);

    playSongs(tail, loopCount);

    return 0;
}
