#include <stdint.h>
#include <stdbool.h>

uint8_t printer_control = 0; // 0b 0000 0000

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)       // 0b 0001 0000

bool printer_is_out_of_ink(void) {
    return printer_control & NO_INK;
}

void printer_switch_modes(void) {
    uint8_t copy = printer_control;

    // only do when select_print is 1
    if (copy & SELECT_PRINT) {
        copy |= SELECT_SCAN;
        copy &= ~SELECT_PRINT;
    }

    // only when select_scan is 1
    else if (copy & SELECT_SCAN) {
        copy |= SELECT_PRINT;
        copy &= ~SELECT_SCAN;
    }

    printer_control = copy;
}
