# **LAB 03-05: THE CRYPTO TRILOGY**
## **Integrity, Exchange, & Privacy**

**Topic:** Hash Functions, Diffie-Hellman, & RSA.

**Story Context:**
> This mission has three critical stages.
> 1.  **Verify Integrity:** You must confirm the mission parameters haven't been tampered with.
> 2.  **Establish Secure Comms:** You need to agree on a secret key with your handler (Bob) over an open channel.
> 3.  **Encrypted Transport:** Finally, you will generate long-term asymmetric keys to securely receive the mission payload.

**Tools:**
*   `HashLab.html` (Tab: Checksum)
*   `RandomLab.html` (Tab: Diffie-Hellman)
*   `RSALab.html` (Tab: Key Gen)

---

## **Part 1: Validation (Integrity)**
*Less weight is placed here, but integrity is the foundation of security.*

### **1.1 Identity Parameters**
*   **Input String:** `"Patch v1.0 for [YourName]"` (e.g., "Patch v1.0 for John Doe")
*   **Algorithm:** SHA-256

### **1.2 The Check**
1.  Open `HashLab.html` -> **Checksum Tab**.
2.  Type your Input String exactly.
3.  Observe the Hash (Digest).
4.  **Experiment:** Change **one single character** in your name (e.g., lowercase to uppercase). Notice how the hash changes completely (Avalanche Effect).

### **1.3 Screenshot A**
*   **Show:** The tool showing the hash of your valid Input String.
*   **Markup:** Box the first 4 characters of the hash.

---

## **Part 2: The Handshake (Key Exchange)**
*Securely agreeing on a key without sending it.*

### **2.1 Identity Parameters**
*   **Public Parameters:** $p=23$, $g=5$.
*   **Your Secret (a):** (Last Digit of your Student ID) + 2. *If ID ends in 0, use 2.*

### **2.2 The Exchange**
1.  Open `RandomLab.html` -> **Diffie-Hellman Tab**.
2.  Enter $p$ and $g$.
3.  Enter your **Secret (a)** for Alice (You).
4.  Click **Calculate Public A**.
5.  (Simulation) Bob will automatically generate his keys.
6.  Look at the **Shared Secret**.

### **2.3 Screenshot B**
*   **Show:** The completed exchange where Alice and Bob have the same Shared Secret.
*   **Markup:** **Green Box** around the final Shared Secret.

---

## **Part 3: The Vault (Asymmetric Encryption)**
*Generating public/private keypairs for future messages.*

### **3.1 Identity Parameters**
*   **Seed:** Your Student ID.

### **3.2 Key Generation**
1.  Open `RSALab.html` -> **Key Gen Tab**.
2.  Enter your Student ID as the Seed.
3.  Click **Generate Primes (P, Q)**.
4.  Click **Generate Keys (N, e, d)**.

### **3.3 Encryption Test**
1.  Enter Message: `"Midnight"`
2.  Encrypt it using your **Public Key**.
3.  Decrypt the result using your **Private Key** to verify it works.

### **3.4 Screenshot C**
*   **Show:** The generated keys ($P, Q, N, e, d$).
*   **Markup:** **Red Box** around your **Private Key (d)**.

---

## **Part 4: Deliverables & Analysis**

**Submission File:** `FirstName_LastName_Lab03_05.pdf` (or .docx)

**Include:**
1.  **Screenshots A, B, and C** (clearly labeled).
2.  **Analysis Questions:**
    *   **Q1 (Hashes):** Why is "Pre-image Resistance" important for password security? (i.e., Why shouldn't we be able to go from Hash -> Password?)
    *   **Q2 (Diffie-Hellman):** In this lab, we authenticated nothing. If Eve intercepted your Public Key $A$ and sent Bob her own Public Key $E$ instead, what attack is this?
    *   **Q3 (RSA):** If an attacker knows your Public Modulus $N$, what mathematical problem solves for $P$ and $Q$? Why is this considered "hard"?
