# **LAB 11 – SMASH THE STACK**

**Topic:** Buffer Overflows, Stack Memory Layout, & Overwriting Variables.

**Tools Required:** Online C Compiler (easiest) or GCC on Linux.

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity.

1. **Magic Number:** The **Last 4 Digits** of your Student ID.
    
    - _Example:_ ID `801234567` $\rightarrow$ Magic = `4567`.
        

---

## **Part 2: The Experiment**

### **Task A: The Vulnerable Code**

1. Open an **Online C Compiler** (like OnlineGDB).
    
2. Paste the following code. It has a vulnerability: `gets()` reads input without checking length, allowing you to overflow the `name` buffer into the `isAdmin` variable.
    

C

```
#include <stdio.h>
#include <string.h>

struct User {
    char name[10];      // Buffer of 10 bytes
    int isAdmin;        // Security Flag (0 = No, 1 = Yes)
};

int main() {
    struct User user;
    user.isAdmin = 0;   // Not admin initially

    // --- SIP CONFIGURATION ---
    int magic = 4567;   // REPLACE WITH YOUR ID's LAST 4 DIGITS
    // -------------------------

    printf("Enter Name: ");
    
    // VULNERABILITY: scanf with %s reads until whitespace, 
    // but without a width limit, it acts like gets().
    // It will write past the 10-byte buffer if we type enough.
    scanf("%s", user.name); 

    printf("\n--- DEBUG INFO ---\n");
    printf("Name: %s\n", user.name);
    printf("IsAdmin Value: %d\n", user.isAdmin);

    if (user.isAdmin != 0) {
        printf(">> SUCCESS! Welcome Admin %d <<\n", magic);
    } else {
        printf(">> ACCESS DENIED <<\n");
    }
    return 0;
}
```

### **Task B: The Attack**

1. **Run** the program.
    
2. **Input 1 (Safe):** Type `Bob`.
    
    - _Result:_ `IsAdmin Value: 0` $\rightarrow$ `ACCESS DENIED`.
        
3. **Input 2 (Attack):** We need to overflow the 10-byte buffer.
    
    - Type 20 'A' characters: `AAAAAAAAAAAAAAAAAAAA`
        
4. **Observation:**
    
    - The program will print `IsAdmin Value: 1094795585` (or similar).
        
    - It will print `>> SUCCESS! Welcome Admin ... <<`.
        
    - _Why:_ The binary value for 'AAAA' spilled over into the memory slot for `isAdmin`.
        

---

## **Part 3: Deliverables**

### **Screenshot 1: The Smash**

- **Requirement:** Screenshot of the terminal output showing the "SUCCESS" message.
    
- **Markup:**
    
    - **Red Box** around your input string (`AAAA...`).
        
    - **Yellow Highlight** around the `Welcome Admin [Your Magic Number]` message.
        

### **Analysis Questions**

1. **Memory Layout:** Draw a simple box diagram showing `[ name (10 bytes) ] [ isAdmin (4 bytes) ]`. Show (with arrows) how your 'A's flowed from the first box into the second.
    
2. **Mitigation:** Lecture 21 mentions **"Canaries"**. If there was a "Canary" value placed between `name` and `isAdmin`, how would that stop this attack?
    

---

---

# **LAB 11 (VARIANT B): THE INTEGER OVERFLOW**

Topic: Integer Representation & Signed/Unsigned bugs.

Note: Demonstrates that buffer overflows aren't the only way to corrupt memory.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Withdrawal Amount:** `2147483700` (Slightly larger than the max 32-bit integer $2^{31}-1$).
    

---

## **Part 2: The Experiment**

### **Task A: The Vulnerable Code**

The bank checks if you have enough money using `unsigned` math (where numbers are always positive), but subtracts using `signed` math (where numbers wrap around to negative).

C

```
#include <stdio.h>

int main() {
    int balance = 100;
    long long input_amount; // Use long long to capture large input
    
    printf("Current Balance: $%d\n", balance);
    printf("Withdraw Amount: ");
    scanf("%lld", &input_amount);
    
    int amount = (int)input_amount; // Cast to 32-bit int
    
    // VULNERABILITY: Logic error in handling integer wrap-around
    if (amount < 0) {
        printf("Error: Cannot withdraw negative amounts.\n");
    } 
    else if (amount > balance) {
        printf("Error: Insufficient funds.\n");
    } 
    else {
        // The attack happens here
        balance = balance - amount;
        printf("\n>> WITHDRAWAL SUCCESSFUL! <<\n");
        printf("New Balance: $%d\n", balance);
    }
    return 0;
}
```

### **Task B: The Attack**

1. **Run** the program.
    
2. **Input:** Enter your **SIP Withdrawal Amount** (`2147483700`).
    
3. **Observation:**
    
    - This number is too big for a signed 32-bit integer. It wraps around and becomes something like `-600`.
        
    - The check `amount > balance` becomes `-600 > 100` (False).
        
    - The math `balance - amount` becomes `100 - (-600) = 700`.
        
    - You just withdrew money and _gained_ balance!
        

---

## **Part 3: Deliverables**

### **Screenshot 1: The Heist**

- **Requirement:** Screenshot showing the "New Balance" being _higher_ than the starting balance.
    
- **Markup:**
    
    - **Red Box** around your massive input number.
        
    - **Yellow Highlight** around the final positive balance.
        

### **Analysis Questions**

1. **Math:** Explain why `2147483700` became a negative number inside the program. (Keyword: **Two's Complement** or **Signed Bit**).
    
2. **Language Safety:** Why do modern languages like Python or Rust prevent this specific bug automatically?
    

---

---

# **LAB 11 (VARIANT C): FORMAT STRING ATTACK**

Topic: Reading Stack Memory (printf vulnerability).

Lecture Reference: Lecture 20 (Format Strings).

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Secret Code:** Your **Student ID** (in Hexadecimal).
    
    - _Example:_ ID `801234567` $\rightarrow$ Hex `2FC20897`.
        
    - _Use:_ [RapidTables Decimal to Hex Converter](https://www.rapidtables.com/convert/number/decimal-to-hex.html).
        

---

## **Part 2: The Experiment**

### **Task A: The Vulnerable Code**

C

```
#include <stdio.h>

int main() {
    // This variable sits on the stack. Normally, the user can't see it.
    // REPLACE WITH YOUR HEX ID
    int secret = 0x2FC20897; 
    
    char user_input[100];
    
    printf("Echo Service. Type something: ");
    scanf("%s", user_input);
    
    // VULNERABILITY: Missing format string argument!
    // Should be: printf("%s", user_input);
    printf(user_input); 
    
    printf("\n");
    return 0;
}
```

### **Task B: The Leak**

1. **Run** the program.
    
2. **Input:** `%x %x %x %x %x %x`
    
3. **Observation:** The program prints raw hex values from the stack.
    
4. Look closely at the output. One of those hex values is your **Secret Code** (e.g., `2fc20897`). You just read "secret" memory!
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Leak**

- **Requirement:** Screenshot showing the hex dump output.
    
- **Markup:**
    
    - **Yellow Highlight** around the hex string that matches your converted Student ID.
        

### **Analysis Questions**

1. **Mechanics:** Why did typing `%x` print stack memory? The program didn't have any variables to print there!
    
2. **Writing Memory:** If `%x` _reads_ memory, what dangerous format specifier allows an attacker to _write_ to memory? (Hint: Lecture 20 mentions `%n`).
    

---

---

# **MARKING KEY: LAB 11**

### **Quick Plagiarism Check**

- **Lab 11 (Stack Smash):**
    
    - Does the "Welcome Admin" message include the last 4 digits of the student's ID?
        
- **Variant B (Integer):**
    
    - Is the input number the specific large value requested?
        
    - Is the balance higher than 100?
        
- **Variant C (Format String):**
    
    - Does the leaked hex value match the hex conversion of their Student ID?
        

### **Answer Key (Analysis Questions)**

**Lab 11 (Standard)**

- **Q1:** [Diagram should show 'A's filling the Name buffer and spilling into the Integer box]. Memory is contiguous; C does not put "walls" between variables.
    
- **Q2:** **Canary.** A random value (e.g., `0xDEADBEEF`) is placed between `name` and `isAdmin`. Before the function returns (or uses `isAdmin`), the computer checks if the canary is still `0xDEADBEEF`. If we overflow `name`, we _must_ overwrite the canary first. The check fails, and the program crashes safely instead of hacking.
    

**Variant B (Integer)**

- **Q1:** **Signed Integers** use the first bit (MSB) to indicate +/-. When you count past the max positive value (`0111...`), you flip the first bit to 1 (`1000...`), which the computer interprets as a negative number.
    
- **Q2:** **Python handles integers dynamically** (arbitrary precision). It automatically expands the memory for the number so it never overflows. **Rust** forces you to explicitly handle wrap-around or it panics (crashes) in debug mode.
    

**Variant C (Format String)**

- **Q1:** `printf` expects arguments on the stack corresponding to every `%` specifier. If you provide `%x` but don't provide a variable, `printf` blindly grabs whatever is currently sitting on the stack (which happens to be our local variables) and prints it.
    
- **Q2:** **%n**. It writes the _number of characters printed so far_ into a pointer provided on the stack. Attackers use this to overwrite return addresses.