# **LAB 12 (VARIANT A) – THE HIGH SCORE**

**Topic:** Stack Overflow.

**Story Context:**
> `gets()` is the root of all evil.
> It reads until newline, ignoring the buffer limit.

**Tools Required:** `MemoryLab.html` (Tab: Stack).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Name:** `[YourName]`.

---

## **Part 2: The Overflow**

1.  **Action:**
    -   Type name > 8 chars.
    -   Observe memory spill into `score`.
    -   **Result:** High Score.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab12A.docx`

### **Screenshot 1: The RAM**
-   **Show:** Memory view showing 0x41 in the score block.
-   **Markup:** **Red Arrow**.

### **Part 4: Analysis (Homework Integration)**

1.  **DEP:** "Data Execution Prevention" marks the stack as non-executable. How does this stop an attacker from running Shellcode? (They can overwrite EIP, but when it jumps to the stack, the CPU throws an exception).

### **Part 5: References & Further Reading**

1.  **Classic:** [Smashing The Stack For Fun And Profit (Aleph One)](http://phrack.org/issues/49/14.html)
    *   *The most famous security paper ever written.*
2.  **Video:** [Buffer Overflows (Computerphile)](https://www.youtube.com/watch?v=1S0aBV-Waeo)
3.  **Visual:**
```merm
graph BT
    Buffer[Local Buffer] -->|Overflows| EBP[Saved EBP]
    EBP -->|Overflows| RET[Return Address]
    RET --Points To--> Malicious[Shellcode]
    style RET fill:#f96
```


