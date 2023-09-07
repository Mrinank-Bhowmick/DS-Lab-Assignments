#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Point {
    int x;
    int y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    srand(time(0)); 

    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point *points = (struct Point *)malloc(n * sizeof(struct Point));


    printf("Enter coordinates of points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d:\n", i + 1);
        points[i].x = rand() % 10 + 1; 
        points[i].y = rand() % 10 + 1;
        printf("x: %d\ny: %d\n", points[i].x, points[i].y);
    }

    printf("\nDistance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("0.00 ");
            } else {
                float distance = calculateDistance(points[i], points[j]);
                printf("%.2f ", distance);
            }
        }
        printf("\n");
    }

    free(points);

    return 0;
}
