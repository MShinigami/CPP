#include <iostream>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Modify the path as per your Turbo C installation

    int x1, y1, x2, y2;

    std::cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int error = dx - dy;
    int x = x1;
    int y = y1;

    while (true) {
        putpixel(x, y, WHITE);

        if (x == x2 && y == y2) {
            break;
        }

        int error2 = 2 * error;

        if (error2 > -dy) {
            error -= dy;
            x += sx;
        }

        if (error2 < dx) {
            error += dx;
            y += sy;
        }
    }

    // Delay to view the line (you can remove this)
    delay(5000);

    // Close the graphics window
    closegraph();

    return 0;
}
