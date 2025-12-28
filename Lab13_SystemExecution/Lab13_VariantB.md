# Lab 13 - Variant B: Buffer Overflow

**Lab Goal:** Execute a Stack Buffer Overflow in C to overwrite the Return Address visually.
**Tool Required:** `CSim.html` (Provided in the lab folder).

---

### **Part 1: Student Identity Parameters (SIP)**
*   **Target Address:** `0xCAFEBABE`
*   **Constraint:** You must ensure the log prints "Success! Jumped to 0xCAFEBABE".

---

### **Part 2: Concept Check (10 Marks)**
1.  **Vulnerability:** What function in C is notoriously unsafe because it doesn't check buffer lengths? (e.g., `strcpy` vs `strncpy`).
2.  **Memory:** Why is the Return Address stored on the Stack next to local variables?

---

### **Part 3: Experiment Evidence (30 Marks)**

**Step-by-Step Instructions:**
1.  Open `CSim.html` in your web browser.
2.  Select **Scenario: Variant B** from the dropdown.
3.  **Screenshot 1 (Wait State):** Show the tool paused at the `strcpy` line.
4.  Press **Step Next**. Watch the "buffer" fill up with `AAAA`.
5.  Keep Stepping. Watch as `XXXX` overflows into **Saved EBP** (turns RED).
6.  Finally, watch `DEAD` overwrite the **Return Address** (turns RED/Corrupted).
7.  **Screenshot 2 (Crushed Stack):** Capture the state where the Return Address reads `0xDEAD...`.


### **Part 3b: Optional "Real Real" Mode (C Code)**
Challenge: Exploit `lab13.c` to call `secret_function`.
1.  Compile: `gcc -m32 -fno-stack-protector -z execstack -o lab13 lab13.c`
2.  Find address of `secret_function`: `objdump -d lab13 | grep secret`
3.  Craft payload: `./lab13 B $(python -c 'print "A"*76 + "\xEF\xBE\xAD\xDE"')` (Adjust padding/address).

---

### **Part 4: Analysis (Homework)**

1.  **Offset Calculation:** If `Buffer` is at `EBP-8`, and the Return Address is at `EBP+4` (standard x86), how many bytes of padding do you need before writing the return address?
2.  **Consequences:** If `0xCAFEBABE` was 0x00000000 (NULL), what would happen to the program?
3.  **Real World:** How does this relate to the "Heartbleed" or "Morris Worm" attacks?

---

### **Part 5: References**
1.  **Video:** [Computerphile - Buffer Overflows](https://www.youtube.com/watch?v=1S0aBV-Waeo)
2.  **Visual:**
```merm
graph BT
    Buffer -->|Fill...| SavedEBP
    SavedEBP -->|Overlap| RetAddr
    RetAddr --Now Points To--> HackerCode
```
