#include "Location.h"

Library::Library()
: Location(
    "Library",
    "Dusty shelves and a cold hearth. Ash clings inside the fireplace; a side table holds scattered papers.\n"
) {
    addOption("Investigate the fireplace");
    addOption("Inspect the side table");
}
