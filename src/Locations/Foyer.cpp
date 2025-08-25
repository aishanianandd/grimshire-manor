#include "Location.h"

Foyer::Foyer()
: Location(
    "Foyer",
    "Polished floors, a grand staircase, and the front door latched from within. Quiet echoes under the high ceiling.\n"
) {
    addOption("Examine the staircase");
    addOption("Inspect the front door latch");
    addOption("Look for scuff marks / footprints");
}
