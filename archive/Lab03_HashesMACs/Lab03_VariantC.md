# **LAB 03 (VARIANT C) – THE BITCOIN MINER**

**Topic:** Proof of Work & Hash Difficulty.

**Story Context:**
> Bitcoin secures its ledger by requiring miners to solve a puzzle.
> Find `Nonce` such that `Hash(Block + Nonce)` starts with N zeros.

**Tools Required:** `HashLab.html` (Tab: Mining).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Block Data:** `"Transaction: [Name] sends 10 BTC"`
2.  **Difficulty:** 3 Hex Zeros.

---

## **Part 2: The Mine**

1.  **Action:**
    -   Mine for Difficulty 3. Record Nonce.
    -   Mine for Difficulty 4. Note the time increase.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab03C.docx`

### **Screenshot 1: Success**
-   **Show:** "Block Solved!" with your Nonce.
-   **Markup:** **Green Box** around the leading zeros.

### **Part 4: Analysis (Homework Integration)**

1.  **Economics:** Why must the puzzle be *hard* to solve but *easy* to verify? Explain this in terms of "Asymmetry of Work".

### **Part 5: References & Further Reading**

1.  **Bitcoin:** [Whitepaper (Satoshi Nakamoto)](https://bitcoin.org/bitcoin.pdf)
    *   *Read Section 4: Proof-of-Work.*
2.  **Video:** [How Bitcoin Works (Computerphile)](https://www.youtube.com/watch?v=Lx9zgZCMqXE)
3.  **Concept:**
```merm
graph LR
    Block -->|Hash| H[0000abc...]
    H -->|Check Difficulty| Valid{Starts with 0000?}
    Valid -- No --> Increment[Nonce++] --> Block
    Valid -- Yes --> Broadcast[Success!]
```


