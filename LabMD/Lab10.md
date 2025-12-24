# **LAB 10 – BEING THE CPU (x86 ASSEMBLY)**

Topic: Registers (EAX, ESP), The Stack, & Basic Instructions (MOV, PUSH, POP, ADD).


Tools Required: Text Editor (or Pen & Paper) & Calculator.

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity.

1. **Initial EAX Value:** The **First 2 Digits** of your Student ID.
    
    - _Example:_ ID `801234567` $\rightarrow$ EAX = `80`.
        
2. **Initial EBX Value:** The **Last 2 Digits** of your Student ID.
    
    - _Example:_ ID `...67` $\rightarrow$ EBX = `67`.
        

---

## **Part 2: The Experiment**

### **Task A: The Code Trace**

You are the CPU. Your job is to execute the following assembly code line-by-line and track the state of the registers.

**The Code:**

Code snippet

```
; START OF PROGRAM
MOV EAX, [First_2_Digits]  ; Load your unique EAX
MOV EBX, [Last_2_Digits]   ; Load your unique EBX

PUSH EAX       ; 1. Save EAX value onto the top of the Stack
ADD EAX, 5     ; 2. Add 5 to EAX
MOV ECX, EAX   ; 3. Copy EAX value into ECX
POP EAX        ; 4. Restore EAX from the Stack (Undo the ADD!)
ADD EAX, EBX   ; 5. Add EBX to EAX
SUB EAX, 10    ; 6. Subtract 10 from EAX
; END OF PROGRAM
```

### **Task B: The Execution Table**

Create a table (Excel or Word) with 3 columns: **Instruction**, **EAX Value**, and **Stack (Top Value)**. Fill it out step-by-step.

_Example Row:_

- `ADD EAX, 5` | EAX becomes 85 | Stack has 80
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Trace Table**

- **Requirement:** Screenshot of your completed table.
    
- **Markup:**
    
    - **Yellow Highlight** over the **Final Value** of EAX.
        
    - **Red Box** around the row for `POP EAX`.
        

### **Analysis Questions**

1. **The Stack:** In step 4 (`POP EAX`), the value of EAX suddenly changed back to its original number. What happened to the `+5` calculation? Where is that number now? (Hint: Look at ECX).
    
2. **Assembly Logic:** What is the fundamental difference between `MOV EAX, 5` and `ADD EAX, 5`? (Explain in plain English).
    

---

---

# **LAB 10 (VARIANT B): THE FUNCTION CALL (CALL STACK)**

Topic: CALL, RET, and Stack Frames.

Note: Teaches how functions preserve state and return execution flow.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Argument (arg1):** The **Last Single Digit** of your Student ID.
    
    - _Example:_ `7`.
        

---

## **Part 2: The Experiment**

### **Task A: The Code**

We are simulating a C function `int double_it(int x) { return x + x; }`.

Code snippet

```
; MAIN FUNCTION
PUSH [Your_Digit] ; Push argument onto stack (e.g., 7)
CALL Double_It    ; Jump to function, Push Return Address
ADD ESP, 4        ; Clean up stack (remove argument)
HLT               ; Stop

; DOUBLE_IT FUNCTION
Double_It:
  MOV EAX, [ESP+4] ; Read the argument from the stack (skip Ret Addr)
  ADD EAX, EAX     ; Double the value (EAX = EAX + EAX)
  RET              ; Pop Return Address and Jump back
```

### **Task B: The Stack Diagram**

Draw the Stack at the exact moment the CPU is inside Double_It (before RET).

It should look like a tower.

**Stack Structure (Top to Bottom):**

1. **Return Address** (Pushed by CALL)
    
2. **Argument** (Your ID Digit)
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Diagram**

- **Requirement:** A drawing (digital or hand-drawn) of the stack memory.
    
- **Markup:**
    
    - **Red Box** around your specific ID Digit inside the stack.
        

### **Analysis Questions**

1. **Mechanism:** When the `RET` instruction runs, how does the CPU know where to go back to? (Hint: What did `CALL` push onto the stack secretly?).
    
2. **Cleanup:** Why do we perform `ADD ESP, 4` after the function returns? What are we removing?
    

---

---

# **LAB 10 (VARIANT C): THE BOMB DEFUSAL (CONDITIONALS)**

Topic: Flags, Jumps (JE, JNE), & Reverse Engineering logic.

Note: Similar to the famous "CMU Bomb Lab" but simplified for paper tracing.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Secret Pin:** Your **Student ID**.
    
    - _Example:_ `801234567`
        

---

## **Part 2: The Experiment**

### **Task A: The "Bomb" Code**

You found this assembly code inside a malware sample. You need to find the input that defuses it.

Code snippet

```
; INPUT is in EAX
MOV EBX, [Your_Student_ID] ; Hardcoded check
CMP EAX, EBX               ; Compare Input vs Secret
JE  Defuse_Bomb            ; Jump if Equal
JMP Explode_Bomb           ; Else, jump to explosion

Explode_Bomb:
  MOV EAX, 0xDEAD          ; Code for Death
  HLT

Defuse_Bomb:
  MOV EAX, 0xCAFE          ; Code for Success
  HLT
```

### **Task B: The Inputs**

1. **Scenario 1:** Input `EAX = 12345`. Trace the code. Does it Explode or Defuse?
    
2. **Scenario 2:** Input `EAX = [Your_Student_ID]`. Trace the code. Does it Explode or Defuse?
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Logic Path**

- **Requirement:** A text description or flow chart showing which path the CPU takes for **Scenario 2**.
    
- **Markup:**
    
    - **Yellow Highlight** over the instruction `JE Defuse_Bomb`.
        

### **Analysis Questions**

1. **Registers:** The `CMP` instruction doesn't change EAX or EBX. So where does it store the result of the comparison? (Hint: The EFLAGS register).
    
2. **Hacking:** If you could modify the binary code (the assembly), how could you make the bomb _always_ defuse, no matter what number is entered? (Hint: Change `JE` to something else, or change the `CMP`).
    

---

---

# **MARKING KEY: LAB 10**

### **Quick Plagiarism Check**

- **Lab 10 (Standard):**
    
    - Does the EAX Start Value match the ID?
        
    - Does the Math check out? (e.g., `80 + 5 = 85`).
        
- **Variant B (Stack):**
    
    - Is the Argument in the stack diagram the last digit of their ID?
        
- **Variant C (Bomb):**
    
    - Did they identify that `Input == ID` triggers the jump?
        

### **Answer Key (Analysis Questions)**

**Lab 10 (Standard)**

- **Q1:** **The register ECX.** The `POP` instruction overwrote EAX with the old value from the stack (restoring the state), but the calculated value (`85`) is safely stored in ECX because of line 3.
    
- **Q2:** `MOV` overwrites the destination with a new value (Assignment). `ADD` takes the existing value and increases it (Math). `MOV EAX, 5` sets EAX to 5. `ADD EAX, 5` sets EAX to $EAX + 5$.
    

**Variant B (Stack)**

- **Q1:** The `CALL` instruction automatically pushes the **Instruction Pointer (EIP)** of the _next_ instruction onto the stack. `RET` simply pops that address back into EIP.
    
- **Q2:** We are removing the **Argument** (4 bytes). The function is done with it, so we clean up the stack to prevent memory leaks (stack overflow).
    

**Variant C (Bomb)**

- **Q1:** It sets the **Zero Flag (ZF)** in the EFLAGS register. If the two numbers are equal, $A - B = 0$, so ZF is set to 1. `JE` looks at ZF.
    
- **Q2:** Change `JE` (Jump if Equal) to `JMP` (Jump Always). Or change the target of `JMP Explode` to `Defuse`. Or `NOP` (No Operation) the jump entirely.