#include <bits/stdc++.h>

#define WIDTH 20
#define HEIGHT 9

using namespace std;

void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
    if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT)
        return;

    if(img[y][x] == 9) {
        img[y][x] = label;
        labelComponent(img, x-1, y, label);
        labelComponent(img, x, y-1, label);
        labelComponent(img, x+1, y, label);
        labelComponent(img, x, y+1, label);
    }
}

void blobColoring(unsigned char img[HEIGHT][WIDTH]) {
    int label = 1;

    for(int y=0;y<HEIGHT;++y) {
        for(int x=0;x<WIDTH;++x) {
            if(img[y][x] == 9)
                labelComponent(img,x,y,label++);
        }
    }

}

void printImage(unsigned char img[HEIGHT][WIDTH], char *msg) {
    printf("%s\n", msg);
    for(int y=0; y<HEIGHT; ++y) {
        for(int x=0; x<WIDTH; ++x) {
            if(img[y][x] == 0)
                printf(".");
            else
                printf("%-1d", img[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

using namespace std;

int main(void)
{
    unsigned char image[HEIGHT][WIDTH] = {
        0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
        9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
        0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
        0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
        0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
        9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
        9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
        9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
        0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9
    };

    printImage(image, "<Original image>");
    blobColoring(image);
    printImage(image, "<Labelled image>");
}
