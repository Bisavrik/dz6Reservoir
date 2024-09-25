#include "Reservoir.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

Reservoir::Reservoir() : width(0), length(0), maxDepth(0) 
{
    strcpy(name, "");
    strcpy(type, "");
}

Reservoir::Reservoir(const char* name, double width, double length, double maxDepth, const char* type)
    : width(width), length(length), maxDepth(maxDepth) 
{
    strcpy(this->name, name);
    strcpy(this->type, type);
}

Reservoir::Reservoir(const Reservoir& other)
    : width(other.width), length(other.length), maxDepth(other.maxDepth) 
{
    strcpy(this->name, other.name);
    strcpy(this->type, other.type);
}

Reservoir::~Reservoir() {}

void Reservoir::setName(const char* name) 
{ 
    strcpy(this->name, name); 
}
const char* Reservoir::getName() const 
{ 
    return name;
}

void Reservoir::setWidth(double width)
{ 
    this->width = width;
}
double Reservoir::getWidth() const 
{ 
    return width;
}

void Reservoir::setLength(double length) 
{ 
    this->length = length;
}
double Reservoir::getLength() const 
{ 
    return length;
}

void Reservoir::setMaxDepth(double maxDepth) 
{ 
    this->maxDepth = maxDepth;
}
double Reservoir::getMaxDepth() const 
{ 
    return maxDepth;
}

void Reservoir::setType(const char* type) 
{ 
    strcpy(this->type, type);
}

const char* Reservoir::getType() const 
{ 
    return type; 
}

double Reservoir::calculateVolume() const
{
    return width * length * maxDepth;
}

double Reservoir::calculateSurfaceArea() const 
{
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const
{
    return strcmp(this->type, other.type) == 0;
}

bool Reservoir::compareSurfaceArea(const Reservoir& other) const 
{
    if (this->isSameType(other)) 
    {
        return this->calculateSurfaceArea() > other.calculateSurfaceArea();
    }
    return false;
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
    if (this != &other)
    {
        strcpy(this->name, other.name);
        this->width = other.width;
        this->length = other.length;
        this->maxDepth = other.maxDepth;
        strcpy(this->type, other.type);
    }
    return *this;
}

void Reservoir::display() const 
{
    cout << "Name: " << name << endl;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "Max Depth: " << maxDepth << endl;
    cout << "Type: " << type << endl;
}

ReservoirManager::ReservoirManager() : size(0), capacity(10)
{
    reservoirs = new Reservoir[capacity];
}

ReservoirManager::~ReservoirManager()
{
    delete[] reservoirs;
}

void ReservoirManager::resize()
{
    capacity *= 2;
    Reservoir* newReservoirs = new Reservoir[capacity];
    for (size_t i = 0; i < size; ++i) 
    {
        newReservoirs[i] = reservoirs[i];
    }
    delete[] reservoirs;
    reservoirs = newReservoirs;
}

void ReservoirManager::addReservoir(const Reservoir& reservoir) 
{
    if (size == capacity)
    {
        resize();
    }
    reservoirs[size++] = reservoir;
}

void ReservoirManager::removeReservoir(size_t index) 
{
    if (index < size) 
    {
        for (size_t i = index; i < size - 1; ++i) 
        {
            reservoirs[i] = reservoirs[i + 1];
        }
        --size;
    }
}

void ReservoirManager::displayAll() const
{
    for (size_t i = 0; i < size; ++i) 
    {
        reservoirs[i].display();
        cout << "-------------------" << endl;
    }
}