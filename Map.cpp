#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Map.h"

Map::Map(int Size) {
    this->Data = (bool *) malloc(sizeof (bool) * Size * Size);
    if (this->Data == nullptr) {
        exit(1);
    } else {
        srand(std::time(nullptr));
        this->Size = Size;
        for (int Iteration = 0; Iteration < (Size * Size) / 10; ++Iteration) {
            SetData(rand() % Size, rand() % Size, true);
        }
    }
}

void Map::SetData(int PositionX, int PositionY, bool Value) {
    *(this->Data + PositionY * this->Size + PositionX) = Value;
}

bool Map::GetData(int PositionX, int PositionY) {
    return *(this->Data + PositionY * this->Size + PositionX);
}

int Map::CountNeighbor(int PositionX, int PositionY) {
    int Counter = 0;

    int PositionUp = PositionY - 1;
    int PositionDown = PositionY + 1;
    int PositionLeft = PositionX - 1;
    int PositionRight = PositionX + 1;

    if (PositionX == 0) {
        PositionLeft = this->Size-1;
    }
    if (PositionX == this->Size - 1) {
        PositionRight = 0;
    }
    if (PositionY == 0) {
        PositionUp = this->Size - 1;
    }
    if (PositionY == this->Size - 1) {
        PositionDown = 0;
    }

    if (GetData(PositionLeft, PositionUp)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionX, PositionUp)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionRight, PositionUp)) {
        Counter = Counter + 1;
    }

    if (GetData(PositionLeft, PositionY)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionX, PositionY)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionRight, PositionY)) {
        Counter = Counter + 1;
    }

    if (GetData(PositionLeft, PositionDown)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionX, PositionDown)) {
        Counter = Counter + 1;
    }
    if (GetData(PositionRight, PositionDown)) {
        Counter = Counter + 1;
    }

    return Counter;
}

void Map::NextGeneration() {
    for (int PositionX = 0; PositionX < this->Size; ++PositionX) {
        for (int PositionY = 0; PositionY < this->Size; ++PositionY) {
            if (CountNeighbor(PositionX, PositionY) < 3) {
                SetData(PositionX, PositionY, false);
            }
            else if (CountNeighbor(PositionX, PositionY) == 3) {
                SetData(PositionX, PositionY, true);
            }
            else if (CountNeighbor(PositionX, PositionY) == 4 && GetData(PositionX, PositionY)) {
                SetData(PositionX, PositionY, true);
            }
            else if (CountNeighbor(PositionX, PositionY) > 4) {
                SetData(PositionX, PositionY, false);
            }
        }
    }
}

void Map::DisplayMap() {
    for (int Iteration = 0; Iteration < this->Size + 2; ++Iteration) {
        std::cout << "@ ";
    }

    std::cout<<std::endl;

    for (int PositionX = 0; PositionX < this->Size; ++PositionX) {
        std::cout << "@ ";
        for (int PositionY = 0; PositionY < this->Size; ++PositionY) {
            if (GetData(PositionX, PositionY)) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "@" << std::endl;
    }

    for (int Iteration = 0; Iteration < this->Size + 2; ++Iteration) {
        std::cout << "@ ";
    }

    std::cout<<std::endl;
}