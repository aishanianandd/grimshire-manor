#include "Location.h"

Kitchen::Kitchen()
: Location(
    "Kitchen",
    "Bright, clean counters. The pantry door sits ajar. A sharp, bitter scent hangs in the air.\n"
) {
    addOption("Check the pantry (missing rat poison)");
    addOption("Read the letter to Dante (warning)");
    addOption("Talk to the kitchen servant (Celeste helping with drinks)");
}
