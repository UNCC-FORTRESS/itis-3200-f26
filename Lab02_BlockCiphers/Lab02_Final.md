# **LAB 02: Block Cipher Modes of Operation**

**Topic:** ECB, CBC, CTR, and the importance of IVs/Nonces.

**Goal:** Understand how different "Modes of Operation" using the same underlying cipher (e.g., AES) can result in vastly different security properties.

**Tools Required:** `tools/BlockCipherModes.html`

---

## **Step 1: Visual Patterns (The ECB Problem)**

**Context:**
> Electronic Codebook (ECB) is the simplest mode. It breaks the message into blocks and encrypts each independently with the same key. `Enc(Block1)` always equals `Cipher1`.

### **1.1 The Experiment**
1.  Open `tools/BlockCipherModes.html` (Tab 1: Visual Patterns).
2.  **Upload an Image** (Ideally one with large patches of single colors, like a logo or cartoon).
3.  Select **Mode: ECB** and click **Encrypt**.
4.  Observe the result. Can you still "see" the image?
5.  Switch to **Mode: CBC** or **CTR**.
6.  Click **Encrypt** again.
7.  Observe the result. Is it indistinguishable from random noise?

### **1.2 Analysis**
*   **Q1:** Explain why ECB preserves the visual patterns of the image. What does this tell you about encrypting repetitive data (like salary spreadsheets or headers) with ECB?
*   **Q2:** Why does CBC (Cipher Block Chaining) fix this problem? (Hint: Look at the diagram logic in the tool if unsure).

---

## **Step 2: Error Propagation (CBC vs CTR)**

**Context:**
> What happens if a bit gets flipped during transmission? Does the whole message break, or just a part of it? This property is called "Error Propagation".

### **2.1 The Experiment**
1.  Switch to **Tab 2: Error Propagation**.
2.  **Mode: ECB**.
    *   Encrypt the default message.
    *   Click a bit in the **Ciphertext** to flip it (turn it Red).
    *   **Decrypt**. Observe: How much of the plaintext is garbled? (Answer: The bits corresponding to that one block).
3.  **Mode: CBC**.
    *   Encrypt.
    *   Flip a bit in the **First Block** (left side of hex).
    *   **Decrypt**. Observe:
        *   Block N (where you flipped): Completely Garbled.
        *   Block N+1: ONE single bit error.
        *   Block N+2: Perfectly fine.
4.  **Mode: CTR**.
    *   Encrypt.
    *   Flip a bit.
    *   **Decrypt**. Observe: Only **ONE** bit is flipped in the plaintext.

### **2.2 Analysis**
*   **Q3 (The Streaming Question):** If you are streaming 4K video over a noisy wifi connection where bits often flip, which mode would cause less visual glitching: CBC or CTR? Why?
*   **Q4 (Integrity):** If you *wanted* to ensure that any tampering destroys the message (so the receiver knows it's invalid), which mode is "better" at spreading the damage?

---

## **Step 3: The Two-Time Pad (CTR Key Reuse)**

**Context:**
> Counter Mode (CTR) turns a Block Cipher into a Stream Cipher. It generates a "Keystream" and XORs it with the plaintext.
> **Critical Rule:** NEVER reuse the same Key + Nonce (Counter).

### **3.1 The Experiment**
1.  Switch to **Tab 3: CTR Key Reuse**.
2.  Notice **Message 1** and **Message 2** are different.
3.  Observe that `C1` and `C2` are generated using the **Same Keystream**.
4.  Look at the **Attacker's View**. The tool calculates `C1 ⊕ C2`.
5.  Verify that this result is exactly equal to `M1 ⊕ M2`. The Key has been completely eliminated from the equation!

### **3.2 Analysis**
*   **Q5:** If an attacker knows that `M1` starts with the word "Hello", how can they mistakenly decrypt the beginning of `M2` using only `C1 XOR C2`?
*   **Q6:** How do we prevent this in the real world? (Hint: What parameter should change every time we encrypt, typically called a Nonce or IV?)

---

## **Step 4: Deliverables**

**Submission File:** `FirstName_LastName_Lab02_Final.docx`

**Include:**
1.  **Screenshots:**
    *   Step 1: Side-by-side comparison of ECB (Pattern Visible) vs CBC (Noise).
    *   Step 2: Screenshot of CBC Decryption showing "Garbage Block + 1 Bit Error".
    *   Step 3: Screenshot of the "Attacker's View" showing the XOR relationship.
2.  **Answers:** Responses to Questions Q1 through Q6.

---

## **References**
*   [Lecture 03 Slides](file:///c:/Users/theda/Study/sem2/TA6200/LectureNotes/lec03.pdf)
*   [Block Cipher Modes Visualization (Wikipedia)](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation)
