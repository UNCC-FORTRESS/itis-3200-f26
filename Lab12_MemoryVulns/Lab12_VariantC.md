# **LAB 12 (VARIANT C) – THE LAZY CODER**

**Topic:** Format String.

**Story Context:**
> `printf` expects you to tell it how many arguments are coming.
> If you say `%x` but provide no argument, it grabs the next value from the stack anyway.

**Tools Required:** `MemoryLab.html` (Tab: Format).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Secret:** `PASS_[ID]`.

---

## **Part 2: The Leak**

1.  **Action:**
    -   Input `%x %x %s`.
    -   Observe Secret Password.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab12C.docx`

### **Screenshot 1: The Secret**
-   **Show:** Leaked Password.
-   **Markup:** **Red Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Write Primitives:** `%n` writes to a memory address. How can this be used to overwrite the Return Address? (By crafting a string of specific length, then using %n to write that length to a pointer).

### **Part 5: References & Further Reading**

1.  **Exploit:** [Format String Vulnerability](https://owasp.org/www-community/attacks/Format_string_attack)
    *   *Using %x and %n to read/write memory.*
2.  **Defense:** [Printf Security](https://cwe.mitre.org/data/definitions/134.html)
    *   *CWE-134: Uncontrolled Format String.*


