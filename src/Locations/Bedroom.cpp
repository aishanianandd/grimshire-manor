#include "Location.h"

Bedroom::Bedroom() : Location(
    "Bedroom",
    "A quiet, perfumed room. A novel rests on the nightstand with the bookmark stuck on page 2.\n"
) {
    addOption("Investigate the staircase");
    addOption("Talk to the maid");
}
