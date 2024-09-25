#include "Reservoir.h"

int main() 
{
    Reservoir r1("Lake", 1000, 2000, 50, "Lake");
    Reservoir r2("Pond", 500, 1000, 10, "Pond");

    ReservoirManager manager;
    manager.addReservoir(r1);
    manager.addReservoir(r2);

    manager.displayAll();

    return 0;
}