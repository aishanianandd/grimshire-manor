#include "Location.h"

Office::Office()
: Location(
    "Office",
    "A tidy desk faces the window. A faint bitter, metallic smell lingers. Something about the chair looks off.\n"
) {
    addOption("Open the desk drawer");
    addOption("Read the sticky note on the desk");
    addOption("Inspect the chair)");
    addOption("Talk to the head maid");
}
