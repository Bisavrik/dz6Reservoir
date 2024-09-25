#ifndef RESERVOIR_H
#define RESERVOIR_H

class Reservoir 
{
private:
    char name[50];
    double width;
    double length;
    double maxDepth;
    char type[20];

public:
    Reservoir();
    explicit Reservoir(const char* name, double width, double length, double maxDepth, const char* type);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    void setName(const char* name);
    const char* getName() const;

    void setWidth(double width);
    double getWidth() const;

    void setLength(double length);
    double getLength() const;

    void setMaxDepth(double maxDepth);
    double getMaxDepth() const;

    void setType(const char* type);
    const char* getType() const;

    double calculateVolume() const;
    double calculateSurfaceArea() const;
    bool isSameType(const Reservoir& other) const;
    bool compareSurfaceArea(const Reservoir& other) const;

    Reservoir& operator=(const Reservoir& other);
    void display() const;
};

class ReservoirManager 
{
private:
    Reservoir* reservoirs;
    size_t size;
    size_t capacity;

    void resize();

public:
    ReservoirManager();
    ~ReservoirManager();

    void addReservoir(const Reservoir& reservoir);
    void removeReservoir(size_t index);
    void displayAll() const;
};

#endif 
