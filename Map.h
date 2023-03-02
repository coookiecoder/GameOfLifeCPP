class Map {
public:
    Map(int Size);
    void NextGeneration();
    void DisplayMap();
private:
    void SetData(int PositionX ,int PositionY, bool Value);
    bool GetData(int PositionX ,int PositionY);
    int CountNeighbor(int PositionX, int PositionY);
    bool * Data;
    int Size;
};
