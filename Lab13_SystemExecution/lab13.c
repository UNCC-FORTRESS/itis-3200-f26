/*
 * Lab 13: System Execution & Buffer Overflow
 * 
 * COMPILE INSTRUCTIONS:
 * ---------------------
 * 1. Disable Stack Protections (Canary) and Enable Executable Stack (for Shellcode):
 *    gcc -fno-stack-protector -z execstack -o lab13 lab13.c
 * 
 * 2. Disable ASLR (Linux):
 *    echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
 * 
 * USAGE:
 * ------
 * ./lab13 A  (Run Variant A: Stack Trace)
 * ./lab13 B  (Run Variant B: Buffer Overflow)
 * ./lab13 C  (Run Variant C: Shellcode Input)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void secret_function() {
    printf("\n[SUCCESS] You jumped to secret_function()! (Address: %p)\n", secret_function);
    printf("[*] Return Address was successfully overwritten.\n");
    exit(0);
}

// Variant A: Clean Function Call
void variant_a_add(int a, int b) {
    int result = a + b;
    printf("[A] Inside variant_a_add(a=%d, b=%d)\n", a, b);
    printf("[A] Address of 'result' (local var): %p\n", &result);
    // Students can use GDB here to inspect EBP, ESP chains
}

// Variant B: Classic Buffer Overflow
void variant_b_overflow(char *input) {
    char buffer[64];
    
    printf("[B] Inside variant_b_overflow()\n");
    printf("[B] 'buffer' is at: %p\n", buffer);
    printf("[B] Return Address is stored at: %p (approx)\n", (void*)((char*)&buffer + 64 + sizeof(void*))); // Rough estimate for x64/x86 alignment

    // VULNERABILITY: strcpy does not check length!
    strcpy(buffer, input); 
    
    printf("[B] Copied input to buffer. Returning now...\n");
}

// Variant C: Executable Stack (Shellcode Target)
void variant_c_shellcode(char *input) {
    char buffer[512];
    printf("[C] Inside variant_c_shellcode(). Buffer at: %p\n", buffer);
    
    strcpy(buffer, input);
    
    // In a real exploit, the 'RET' would jump back to memory inside 'buffer'
    // where the shellcode lives.
    printf("[C] Function finishing. If you overwrote RET to point to %p, code flows there.\n", buffer);
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <mode> [payload]\n", argv[0]);
        printf("Modes: A (Stack), B (Overflow), C (Shellcode)\n");
        return 1;
    }

    if(strcmp(argv[1], "A") == 0) {
        printf("--- VARIANT A: Stack Inspector ---\n");
        variant_a_add(10, 20);
    } 
    else if(strcmp(argv[1], "B") == 0) {
        printf("--- VARIANT B: Buffer Smash ---\n");
        printf("Target Function: secret_function is at %p\n", secret_function);
        if(argc < 3) {
            printf("Error: Provide a payload argument! (e.g. $(python -c 'print \"A\"*72 + \"\\xEF\\xBE\\xAD\\xDE\"'))\n");
            return 1;
        }
        variant_b_overflow(argv[2]);
    }
    else if(strcmp(argv[1], "C") == 0) {
        printf("--- VARIANT C: Shellcode Runner ---\n");
        if(argc < 3) {
             printf("Error: Provide shellcode payload!\n");
             return 1;
        }
        variant_c_shellcode(argv[2]);
    }
    else {
        printf("Unknown mode: %s\n", argv[1]);
    }

    printf("--- Normal Exit ---\n");
    return 0;
}
