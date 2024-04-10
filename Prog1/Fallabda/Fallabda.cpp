#include <iostream>
#include <windows.h>

int main() {
    // Konzol ablak mérete
    const int width = 80;
    const int height = 20;

    // Labda kezdőpozíciója és sebessége
    int ballX = width / 2;
    int ballY = height / 2;
    int ballSpeedX = 1;
    int ballSpeedY = 1;

    // Labda mozgatása
    while (true) {
        // Labda pozíciójának frissítése
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        // Labda ütközésének ellenőrzése a falakkal
        if (ballX == 1 || ballX == width - 2) {
            ballSpeedX = -ballSpeedX;
        }
        if (ballY == 1 || ballY == height - 2) {
            ballSpeedY = -ballSpeedY;
        }

        // Konzol törlése
        system("cls");

        // Labda és falak újrarajzolása
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    std::cout << "#";
                } else if (j == ballX && i == ballY) {
                    std::cout << "O";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        // Kis várakozás a labda mozgásának láthatóvá tételéhez
        Sleep(50);
    }

    return 0;
}
