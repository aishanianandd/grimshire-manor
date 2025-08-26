#include "Location.h"

Kitchen::Kitchen()
: Location(
    "Kitchen",
    "Bright, clean counters. The pantry door sits ajar. A sharp, bitter scent hangs in the air.\n"
) {
    addOption("Checkout the kitchen cabinet");
    addOption("Read a ripped letter left on counter");
    addOption("Talk to the kitchen servant");
}
