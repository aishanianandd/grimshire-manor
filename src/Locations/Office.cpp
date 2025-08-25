#include "Location.h"

Office::Office()
: Location(
    "Office",
    "A tidy desk faces the window. A faint bitter, metallic smell lingers. Something about the chair looks off."
) {
    addOption("Open the desk drawer (photograph)");
    addOption("Read the sticky note on the desk");
    addOption("Inspect the chair (dark hair)");
    addOption("Talk to the hall maid (strange sounds, glass tap)");
}
