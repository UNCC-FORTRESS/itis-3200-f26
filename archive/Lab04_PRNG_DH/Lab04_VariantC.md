# **LAB 04 (VARIANT C) – THE TIME TRAVELER**

**Topic:** Seeding Weakness.

**Story Context:**
> Using Time as a seed is dangerous.
> An attacker knows the time. Therefore, they know the key.

**Tools Required:** `RandomLab.html` (Tab: Seed Attack).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Seed:** Current Day of Month.

---

## **Part 2: The Crack**

1.  **Action:**
    -   Generate "Admin Token" from the secret time.
    -   Brute force the seed range (0-100) to find the matching time.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab04C.docx`

### **Screenshot 1: Seed Found**
-   **Show:** "SEED FOUND: 24" (or your day).
-   **Markup:** **Green Box** around the result.

### **Part 4: Analysis (Homework Integration)**

1.  **Entropy:** Define "Entropy" in bits. If a seed is an 8-character password chosen from lowercase letters ($26^8$), calculate the entropy bits. bits = $\log_2(26^8)$.

### **Part 5: References & Further Reading**

1.  **Guide:** [NIST SP 800-90A](https://csrc.nist.gov/publications/detail/sp/800-90a/rev-1/final)
    *   *Recommendations for Random Number Generation Using Deterministic Random Bit Generators.*
2.  **Video:** [Random Numbers (Numberphile)](https://www.youtube.com/watch?v=SxP30euw3-0)


