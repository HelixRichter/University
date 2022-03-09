#include <stdio.h>
#include <stdlib.h>

#define ERR_OPEN_FILE 1

void wcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(1);
    }

    int buffer, wcount = 0, empty = 1, separator = 1;

    while ((buffer = fgetc(file)) != EOF) {
        if (buffer == ' ' || buffer == '\n' || buffer == '\t') {
            if (separator == 0) { wcount++; }
            separator = 1;
        } else {
            separator = 0;
            empty = 0;
        }
    }

    if (empty == 0) {
        if (separator == 0) {
            printf("Hey! There are %d words in this file!\n", wcount + 1);
        } else { printf("Hey! There are %d words in this file!\n", wcount); }
    } else { printf("Oh... There 0 words in this file :(\n"); }

    fclose(file);
}

void engletcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(ERR_OPEN_FILE);
    }

    int buffer = fgetc(file);

    int count = 0; // Letter counter
    char ALPHABET[26] = {0}; // Alphabet of big letters
    char alphabet[26] = {0}; // Alphabet of small letters

    while (!feof(file)) {
        if (buffer > 64 && buffer < 91) {
            ALPHABET[buffer - 'A']++;
            count++;
            buffer = fgetc(file);
        } else if (buffer > 96 && buffer < 123) {
            alphabet[buffer - 'a']++;
            count++;
            buffer = fgetc(file);
        } else {
            buffer = fgetc(file);
            count++;
        }
    }

    puts("");
    puts("       Letter Number    Frequency");
    for (int i = 0; i < 26; i++) {
        if (ALPHABET[i] != 0) {
            printf("\t[%c]\t%d\t%4.0f%%\n", i + 'A', ALPHABET[i], (((float) ALPHABET[i] / (float) count) * (float) 100));
        }
    }
    puts("");
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            printf("\t[%c]\t%d\t%4.0f%%\n", i + 'a', alphabet[i], (((float) alphabet[i] / (float) count) * (float) 100));
        }
    }

    fclose(file);
}

void rusletcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(ERR_OPEN_FILE);
    }

    int buffer = fgetc(file);

    int count = 0;
    char ALPHABET[33] = {0};
    char alphabet[33] = {0};

    while (!feof(file)) {
        if (buffer >= 192 && buffer <= 223) {
            ALPHABET[buffer - 192]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer >= 224 && buffer <= 255) {
            alphabet[buffer - 224]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer == 168) {
            ALPHABET[32]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer == 184) {
            alphabet[32]++;
            count++;
            buffer = fgetc(file);
        } else {
            buffer = fgetc(file);
            count++;
        }
    }

    puts("");
    puts("       Letter Number    Frequency");
    for (int i = 0; i <= 32; i++) {
        if (ALPHABET[i] != 0) {
            printf("\t[%c]\t%4d\t%4.0f%%\n", (i == 32) ? (168) : (i + 192), ALPHABET[i], (((ALPHABET[i] + 0.0) / count) * 100));
        }
    }
    puts("");
    for (int i = 0; i <= 32; i++) {
        if (alphabet[i] != 0) {
            printf("\t[%c]\t%4d\t%4.0f%%\n", (i == 32) ? (184) : (i + 224), alphabet[i], (((alphabet[i] + 0.0) / count) * 100));
        }
    }

    fclose(file);
}

void allletcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(ERR_OPEN_FILE);
    }

    int buffer = fgetc(file);

    int count = 0; // Letter counter
    char symbols[256] = {0};

    while (!feof(file)) {
        symbols[buffer]++;
        count++;
        buffer = fgetc(file);
    }

    puts("");
    puts("       Letter Number    Frequency");
    char Unprintable[33][4] = { "EOP", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "SP"};
    for (int i = 0; i < 256; i++) {
        if (i <= 32) {
            if (symbols[i] != 0) {
                printf("\t[%s]\t%d\t%4.0f%%\n", Unprintable[i], symbols[i], (((float) symbols[i] / (float) count) * (float) 100));
            }
        } else {
            if (symbols[i] != 0) {
                printf("\t[%c]\t%d\t%4.0f%%\n", i, symbols[i], (((float) symbols[i] / (float) count) * (float) 100));
            }
        }
    }

    fclose(file);
}

void engallcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(ERR_OPEN_FILE);
    }

    int buffer = fgetc(file);

    int count = 0; // Letter counter
    int ALPHABET[26] = {0}; // Alphabet of big letters
    int alphabet[26] = {0}; // Alphabet of small letters
    int AlPhAbEt[26] = {0}; // Alphabet of all letters

    while (!feof(file)) {
        if (buffer > 64 && buffer < 91) {
            ALPHABET[buffer - 'A']++;
            count++;
            buffer = fgetc(file);
        } else if (buffer > 96 && buffer < 123) {
            alphabet[buffer - 'a']++;
            count++;
            buffer = fgetc(file);
        } else {
            buffer = fgetc(file);
            count++;
        }
    }

    for (int i = 0; i < 26; i++) {
        AlPhAbEt[i] = alphabet[i] + ALPHABET[i];
    }

    puts("");
    puts("       Letter Number    Frequency");
    for (int i = 0; i < 26; i++) {
        if (AlPhAbEt[i] != 0) {
            printf("\t[%c]\t%d\t%4.0f%%\n", i + 'A', AlPhAbEt[i], (((float) AlPhAbEt[i] / (float) count) * (float) 100));
        }
    }

    fclose(file);
}

void rusallcount(char path[]) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        puts("Oops, something went wrong...");
        exit(ERR_OPEN_FILE);
    }

    int buffer = fgetc(file);

    int count = 0;
    int ALPHABET[33] = {0};
    int alphabet[33] = {0};
    int AlPhAbEt[33] = {0};

    while (!feof(file)) {
        if (buffer >= 192 && buffer <= 223) {
            ALPHABET[buffer - 192]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer >= 224 && buffer <= 255) {
            alphabet[buffer - 224]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer == 168) {
            ALPHABET[32]++;
            count++;
            buffer = fgetc(file);
        } else if (buffer == 184) {
            alphabet[32]++;
            count++;
            buffer = fgetc(file);
        } else {
            buffer = fgetc(file);
            count++;
        }
    }

    for (int i = 0; i < 33; i++) {
        AlPhAbEt[i] = alphabet[i] + ALPHABET[i];
    }
    AlPhAbEt[32] = ALPHABET[32] + alphabet[32];

    puts("");
    puts("       Letter Number    Frequency");
    for (int i = 0; i <= 32; i++) {
        if (AlPhAbEt[i] != 0) {
            printf("\t[%c]\t%4d\t%4.0f%%\n", (i == 32) ? (168) : (i + 192), AlPhAbEt[i], (((AlPhAbEt[i] + 0.0) / count) * 100));
        }
    }

    fclose(file);
}