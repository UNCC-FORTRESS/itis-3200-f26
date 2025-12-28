# **LAB 12 (VARIANT B) – THE BILLIONAIRE**

**Topic:** Integer Overflow.

**Story Context:**
> `255 + 1 = 0`.
> If you owe $0, you are free.

**Tools Required:** `MemoryLab.html` (Tab: Int).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Goal:** Withdraw $200.

---

## **Part 2: The Math**

1.  **Action:**
    -   Withdraw $200 ( + $60 Fee = 260).
    -   $260 \mod 256 = 4$.
    -   $4 <= 100$. Approved.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab12B.docx`

### **Screenshot 1: The Result**
-   **Show:** "APPROVED".
-   **Markup:** **Green Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Signed vs Unsigned:** If we used a *Signed* 8-bit integer (-128 to 127), what is $127 + 1$? (-128). Why? (Two's Complement).

### **Part 5: References & Further Reading**

1.  **Wiki:** [Integer Overflow](https://en.wikipedia.org/wiki/Integer_overflow)
    *   *Examples in C, Ada, and flight software crashes.*
2.  **Visual:** [Clock Arithmetic](https://mathworld.wolfram.com/ModularArithmetic.html)
    *   *Why 12 + 1 = 1.*


