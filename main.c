#include <stdio.h>
int validateNumbers_a(int w) {
    // check input range
    if ((w > 2 && w < 70)) {
        return 0;
    } else {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
}

int validateNumbers_b(int w, int h) {
    if ((w > 2) && (w < 70) && (h > 2) && (h < 70)) {
            if (w % 2 == 1) {
                return 0;
        } else {
            fprintf(stderr, "Error: Sirka neni liche cislo!\n");
            return 102;
        }
    } else {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
}


int validateNumbers_c(int w, int h, int f) {
    if ((w > 2) && (w < 70) && (h > 2) && (h < 70) && (f > 2) && (f < 70)) {
       if (w % 2 == 1) {
           if (f < h) {
               return 0;
           } else {
               fprintf(stderr, "Error: Neplatna velikost plotu!\n");
               return 103;
           }
       } else {
           fprintf(stderr, "Error: Sirka neni liche cislo!\n");
           return 102;
       }

    } else {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
}



void drawSquareWithInfill(int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((i == 0 || i == (h - 1)) || (j == 0 || j == (w - 1))) {
                printf("X");
            } else {
                if (w == h) {
                    if ((i + j) % 2 == 0) {
                        printf("o");
                    } else {
                        printf("*");
                    }
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void drawSquareWithFence(int w, int h, int f) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w + f; j++) {
            if ((i == 0 || i == h - 1) && j < w) {
                printf("X");
            } else {
                if (j == 0 || j == w - 1) {
                    printf("X");
                } else if (w == h && j < w) {
                    if ((i + j) % 2 == 0) {
                        printf("o");
                    } else {
                        printf("*");
                    }
                } else if (j >= w && i > (h - f) - 1) {
                    if (i == (h - f) || i == (h - 1)) {
                        if ((j + f) % 2 == 0) {
                            printf("|");
                        } else {
                            printf("-");
                        }
                    } else {
                        if ((j + f) % 2 == 0) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                } else if (j < w) {
                    // infill : !w == h
                    printf(" ");
                }
            }
        }
        // newline
        printf("\n");
    }
}

void drawRoof(int w, int h) {
    for (int i = 0; i < (w - 1) / 2; i++) {
        for (int j = 0; j <= w - 2; j++) {
            if ((i == 0 && j == ((w + 1) / 2) - 1) || (i > 0 && (j == ((w + 1) / 2) - 1 + i))) {
                printf("X\n");
            } else if (i > 0 &&  (j == ((w + 1) / 2) - 1 - i)) {
                printf("X");
            } else if (j <= ((w + 1) / 2) - 1 + i) {
                printf(" ");
            }
        }
    }
}

int drawSquare(int w) {
    int rVal = validateNumbers_a(w);
    if (rVal == 0) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                if ((i == 0 || i == (w - 1)) || (j == 0 || j == (w - 1))) {
                    printf("X");
                } else printf(" ");
            }
            printf("\n");
        }
        return 0;
    } else return rVal;
}

int drawHouse(int w, int h) {
    int rVal = validateNumbers_b(w, h);
    if (rVal == 0) {
        drawRoof(w, h);
        drawSquareWithInfill(w, h);
        return 0;
    } else return rVal;
}

int drawHouseWithFence(int w, int h, int f) {
    int rVal = validateNumbers_c(w, h, f);
    if (rVal == 0) {
        drawRoof(w, h);
        drawSquareWithFence(w, h, f);
        return 0;
    } else return rVal;
}


int main() {
     int w, h, f;

    int reads = scanf("%d %d %d", &w, &h, &f);

    if (reads == 1) {
        return drawSquare(w);
    } else if (reads == 2) {
        return drawHouse(w, h);
    } else if (reads == 3) {
        return drawHouseWithFence(w, h, f);
    } else {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
}
