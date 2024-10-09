#define READING   0x01       // 00000001
#define WRITING   0x02       // 00000010
#define AS_BYTES  0x04       // 00000100
#define AS_BLOCKS 0x08       // 00001000
#define LOCKED    0x10       // 00010000

                             // 00000101
                             // 00000010
                             // 00000110
unsigned char device = READING | AS_BYTES;

int main(void) {
    // WRITING | AS_BYTES
    unsigned char copy = device;
    copy = copy >> 1 | AS_BYTES;
    device = copy;
}
