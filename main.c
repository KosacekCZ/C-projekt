#include <stdio.h>

void drawSquare(int w) {
    if (w > 2 && w < 70) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                if (j == 0 || j == (w-1)) {
                    printf("X");
                } else if (i == 0 || i == (w-1)) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else {
        fprintf(stderr, "Error: Chybny vstup!\n");
    }
}

void drawHouse(int w, int h) {
    if ((w > 2 && w < 70) && (h > 2 && h < 70)) {
        for (int i = 0; i < h-2; ++i) {
            for (int j = 1; j <= h+1; ++j) {
                if (i == 0 && j == ((w + 1) / 2)) {
                    printf("X");
                } else if (i != 0 && ((j == ((w + 1) / 2) + i) || (j == ((w + 1) / 2) - i))) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j == 0 || j == (w-1)) {
                    printf("X");
                } else if (i == 0 || i == (h-1)) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

    } else {
        fprintf(stderr, "Error: Chybny vstup!\n");
    }
}

void drawAuschwitz(int w, int h, int f) {

}

int main() {
    int w, h, f;
    scanf("%d", &w);

    drawHouse(7, 5);
    return 0;
}