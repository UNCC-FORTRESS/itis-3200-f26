# Lab 13 - Variant A: Stack Frames & Function Calls

**Lab Goal:** Visually trace proper stack frame creation and destruction during C Function execution using the `CSim` tool.
**Tool Required:** `CSim.html` (Provided in the lab folder).

---

### **Part 1: Student Identity Parameters (SIP)**
*   **Your Assigned Stack Base:** `0x1000` (Default)
*   **Your Verified Return Address:** `0x00000004` (The address after the CALL instruction in the tool).
*   **Constraint:** You must take your screenshots *exactly* when requested.

---

### **Part 2: Concept Check (10 Marks)**
1.  **Instruction:** Define what the `CALL` instruction does in terms of `PUSH` and `JMP`.
2.  **Register:** What is the role of `EBP` (Base Pointer) in accessing local variables?

---

### **Part 3: Experiment Evidence (30 Marks)**

**Step-by-Step Instructions:**
1.  Open `CSim.html` in your web browser.
2.  Select **Scenario: Variant A** from the dropdown.
3.  Click **Reset** to start.
4.  **Screenshot 1 (Before Execution):** Capture the state at Line 1 where stack is empty.
5.  Press **Step Next** until you are inside `add()`.
6.  Notice the **Stack Frame** created for `main` and then `add`. Observe the "Saved EBP" and "Return Address".
7.  **Screenshot 2 (Max Stack Depth):** Capture the visual when both frames are active and the stack is deepest.


### **Part 3b: Optional "Real Real" Mode (C Code)**
If you are running on Linux or have GCC (MinGW):
1.  Compile: `gcc -m32 -fno-stack-protector -o lab13 lab13.c`
2.  Run: `./lab13 A`
3.  Use `gdb ./lab13` to break at `variant_a_add` and inspect `info registers`.

---

### **Part 4: Analysis (Homework)**

1.  **Stack Growth:** Does the stack usage grow towards *Higher* or *Lower* memory addresses? Cite evidence from your experiment.
2.  **Frame Teardown:** Why must we do `MOV ESP, EBP` (or `POP EBP`) before `RET`? What happens if `ESP` is pointing to a local variable when `RET` executes?
3.  **Local Variables:** If we added `SUB ESP, 8` inside the function, how many local integer variables (4-byte) would that reserve?

---

### **Part 5: References**
1.  **Paper:** [Smashing The Stack (Aleph One)](http://phrack.org/issues/49/14.html) - *The basics of stack layout.*
2.  **Visual:**
```merm
graph TD
    Caller -->|PUSH Args| Stack
    Caller -->|CALL| Stack
    func[Callee] -->|PUSH EBP| Stack
    func -->|MOV EBP, ESP| Stack
```
