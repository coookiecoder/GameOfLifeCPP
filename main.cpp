#include <unistd.h>
#include <cstdlib>
#include "Map.h"

int main() {
    Map GameOfLife(50);
    GameOfLife.DisplayMap();
    for (int Iteration = 0; Iteration < 100000; ++Iteration) {
        system("clear");
        GameOfLife.NextGeneration();
        GameOfLife.DisplayMap();
        usleep(10000);
    }
    return 0;
}
