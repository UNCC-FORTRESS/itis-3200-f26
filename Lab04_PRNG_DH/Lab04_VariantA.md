# **LAB 04 (VARIANT A) – THE PAINT EXCHANGE**

**Topic:** Diffie-Hellman & Discrete Log.

**Story Context:**
> Mixing colors is easy. Un-mixing them is hard.
> Math: $g^a \mod p$ is easy. Finding $a$ from $A$ is hard.

**Tools Required:** `RandomLab.html` (Tab: Diffie-Hellman).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Parameters:** $p=23, g=5$.
2.  **Alice Secret (a):** Last Digit of ID + 2.

---

## **Part 2: The Exchange**

1.  **Action:**
    -   Alice (You) calculates Public A.
    -   Bob (Simulated) calculates Public B.
    -   Alice calculates Shared S.
    -   Eve brute forces $a$.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab04A.docx`

### **Screenshot 1: Shared Secret**
-   **Show:** Alice and Bob having the same Key.
-   **Markup:** **Green Box** around the Key.

### **Part 4: Analysis (Homework Integration)**

1.  **Algorithm:** Explain the man-in-the-middle attack steps against unauthenticated Diffie-Hellman. (Step 1: Eve intercepts $g^a$. Step 2: ...).

### **Part 5: References & Further Reading**

1.  **Analogy:** [Paint Mixing (Computerphile)](https://www.youtube.com/watch?v=NmM9HA2MQGI)
    *   *The classic visual explanation of Diffie-Hellman.*
2.  **Standard:** [RFC 3526](https://datatracker.ietf.org/doc/html/rfc3526)
    *   *Standard MODP Groups for Diffie-Hellman (Real world Primes).*
3.  **Visual:**
```merm
graph TD
    Alice -- Mixed + SecretA --> PublicA
    Bob -- Mixed + SecretB --> PublicB
    PublicA --> Bob
    PublicB --> Alice
    Alice -- PublicB + SecretA --> SharedSecret
    Bob -- PublicA + SecretB --> SharedSecret
```


