# Lab 13 - Variant C: Shellcode Injection

**Lab Goal:** Visualizing how the Return Address is replaced with a Stack Pointer to execute injected code.
**Tool Required:** `CSim.html` (Provided in the lab folder).

---

### **Part 1: Student Identity Parameters (SIP)**
*   **Shellcode Payload:** `0xCC00CC00` (Simulated).
*   **Constraint:** Execution must jump *into* the stack memory range (`0x1000` or below).

---

### **Part 2: Concept Check (10 Marks)**
1.  **Shellcode:** Why is it called "Shellcode"? (Historically used to spawn `/bin/sh`).
2.  **Execution:** Why does the stack need to be marked "Executable" (RWX) for this to work?

---

### **Part 3: Experiment Evidence (30 Marks)**

**Step-by-Step Instructions:**
1.  Open `CSim.html` in your web browser.
2.  Select **Scenario: Variant C** from the dropdown.
3.  **Screenshot 1 (Clean Stack):** Initial state before `gets()`.
4.  Step through the input.
5.  Observe the buffer filling with: `NOP Sled` -> `Shellcode` -> `Return Address Override`.
6.  Notice that the **Return Address** is overwritten with `0xBFFF...` (A Stack Address).
7.  **Screenshot 2 (Execution Redirect):** Capture the moment the tool says "Jumping to Stack Address".


### **Part 3b: Optional "Real Real" Mode (C Code)**
Challenge: Inject real Shellcode (e.g., `execve(/bin/sh)`).
1.  Compile (Disable NX): `gcc -m32 -fno-stack-protector -z execstack -o lab13 lab13.c`
2.  Generate Shellcode (from Shell-Storm or Metasploit).
3.  Run: `./lab13 C <PAYLOAD>`

---

### **Part 4: Analysis (Homework)**

1.  **NOP Sled:** The code uses `0x90909090`. What is a "NOP Sled" and why is it useful when you don't know the *exact* stack address?
2.  **NX Bit:** Modern CPUs have an "NX" (No-Execute) bit. How does this stop Variant C?
3.  **Payload:** If you couldn't use `0x00` bytes (null terminators) in your shellcode because of `strcpy`, how would you put `0` into a register? (Hint: `XOR EAX, EAX`).

---

### **Part 5: References**
1.  **Article:** [Shellcode Tutorial](https://www.vividmachines.com/shellcode/shellcode.html)
2.  **Visual:**
```merm
graph TD
    Stack -->|Contains| NOP_Sled
    NOP_Sled -->|Slides To| Shellcode
    EIP --Jumps To--> NOP_Sled
```
