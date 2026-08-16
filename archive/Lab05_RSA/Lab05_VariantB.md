# **LAB 05 (VARIANT B) – THE ROYAL DECREE**

**Topic:** Digital Signatures.

**Story Context:**
> The King issues a decree: "Tax Free Year".
> Problem: Authenticity.
> Solution: Sign the hash of the decree with the Private Key. Anyone can verify with the Public Key.
> Attack: You are a forger trying to fake a decree.

**Tools Required:** `RSALab.html` (Tab: Sign).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Message:** "Pay [Name] 100 Gold".

---

## **Part 2: The Signature**

1.  **Action:**
    -   Sign your message.
    -   Verify it relative to Public Key.
    -   **Forgery Attempt:** Change message to "Pay [Name] 1000 Gold" but keep the old signature. Verify -> **FALSE**.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab05B.docx`

### **Screenshot 1: Verification**
-   **Show:** "Signature Valid: TRUE".
-   **Markup:** **Green Check** mark.

### **Part 4: Analysis (Homework Integration)**

1.  **Mechanics:** A valid RSA signature $S$ satisfies $S^e \equiv H(m) \mod N$. Show algebraically why this works given $S = H(m)^d$. ($H(m)^{de} \equiv H(m)^1$).

### **Part 5: References & Further Reading**

1.  **Concept:** [Digital Signatures](https://www.khanacademy.org/computing/computer-science/cryptography/modern-crypt/v/digital-signature-1)
    *   *Khan Academy: Signing with Private Key, Verifying with Public.*
2.  **Standard:** [PKCS #1](https://tools.ietf.org/html/rfc8017)
    *   *RSA Cryptography Specifications.*


