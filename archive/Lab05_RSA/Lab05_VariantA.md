# **LAB 05 (VARIANT A) – THE SPY RING**

**Topic:** RSA Key Generation & Encryption.

**Story Context:**
> You are generating keys for a spy ring.
> Basic math: $P=Unknown, Q=Unknown \rightarrow N=P \times Q$.
> If the enemy knows $N$ (Public), can they find $P$ and $Q$? Only if they can factor.

**Tools Required:** `RSALab.html` (Tab: Key Gen).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Primes (P, Q):** Tool generates them from your "Seed" (Student ID).

---

## **Part 2: The Keys**

1.  **Action:**
    -   Generate Keys.
    -   Encrypt: "Meeting at Midnight".
    -   Decrypt the result.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab05A.docx`

### **Screenshot 1: Keys**
-   **Show:** $P, Q, N, e, d$ values.
-   **Markup:** **Red Box** around $d$ (Private Key).

### **Part 4: Analysis (Homework Integration)**

1.  **Factoring:** Integers $P$ and $Q$ are prime. If $N = 143$, find $P$ and $Q$. (Do it by trial division: $\sqrt{143} \approx 11.9$, check primes 2, 3, 5, 7, 11).

### **Part 5: References & Further Reading**

1.  **Video:** [RSA Encryption (Computerphile)](https://www.youtube.com/watch?v=JD72DhDPnsE)
    *   *Excellent breakdown of the trapdoor function.*
2.  **Visual:**
```merm
graph LR
    P[Prime P] & Q[Prime Q] --> N[Modulus N]
    N --> Keys
    P & Q --> Phi[Euler Phi] --> D[Private D]
    D --> Keys
    Keys --> Pub[Public Key = N, e]
    Keys --> Priv[Private Key = N, d]
```
3.  **Tool:** [RSA Calculator](https://www.cs.drexel.edu/~jpopyack/Courses/CSP/Fa17/notes/10.1_Cryptography/RSA_Express_EncryptDecrypt_v2.html)
    *   *Verify your manual calculations.*


