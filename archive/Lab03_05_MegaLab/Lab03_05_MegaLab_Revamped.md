# **LAB 03-05 (REVAMPED): OPERATION TRUSTED CONDUIT**

**Topic:** Applied Cryptography: Integrity, Key Exchange, & Asymmetric Encryption.

**Story Context:**
> **Agent:** Welcome to the field. Your mission is to secure a communication line for the "Resistance".
> The enemy ("Eve") monitors all traffic. She can see what you send, but she cannot break the math... unless you make a mistake.
>
> **Your Mission Objectives:**
> 1.  **Vetting:** Verify that the "Mission Log" (Blockchain) is authentic and untouched.
> 2.  **Handshake:** Establish a secure session provided by HQ (Bob) while under surveillance.
> 3.  **Comms:** Encrypt and transmit the classified payload using Digital Envelopes (RSA).

**Tools Required:**
*   `tools/LedgerLab.html` (Integrity Simulator)
*   `tools/KeyExchangeSim.html` (Diffie-Hellman Visualizer)
*   `tools/CryptoMessenger.html` (RSA Email Client)

---

## **Part 1: The Ledger (Integrity check)**
*Mission: Verify if the historical records have been altered.*

The Resistance uses a "Blockchain" to store sensitive mission dates. We suspect Eve modified an old record to hide her tracks.

### **Step-by-Step Instructions**
1.  **Launch Tool:** Open `tools/LedgerLab.html` in your browser.
2.  **Verify Baseline:** Look at the 3 Blocks on screen.
    *   Note that the arrow links between them are **GREEN**. This means the cryptographic chain is valid.
    *   Block #1 (Genesis) Hash is part of Block #2's input. Block #2's Hash is part of Block #3's input.
3.  **The Attack Experiment:**
    *   Go to **Block #1** (The first block).
    *   Locate the text area containing `Student: Alice...`.
    *   **Change the Date:** Delete the year `2026` and type `2025`.
4.  **Observe the Avalanche:**
    *   Look immediately at the **Hash** of Block #1. It changed instantly.
    *   Look at the link to **Block #2**. It is now **RED (BROKEN)**.
    *   *Why?* Block #2 contains the *old* hash of Block #1. Since Block #1 changed, the link no longer matches.
    *   Notice that Block #3 is also invalid, because the chain leading to it is broken.

### **Deliverable A (Screenshot)**
*   **Action:** Leave the chain in its "Broken" state.
*   **Screenshot:** Capture the full chain showing the **Red / Broken links**.
*   **Caption:** "Evidence of Tampering in Block #1".

---

## **Part 2: The Handshake (Diffie-Hellman)**
*Mission: Agree on a secret key without Eve stealing it.*

You need to agree on a numeric "Secret Key" with HQ (Bob) to encrypt your future calls. However, you are in a public room and Eve (The Spy) is listening to everything you shout.

### **Step-by-Step Instructions**
1.  **Launch Tool:** Open `tools/KeyExchangeSim.html`.
    *   You are **Alice** (Left Panel).
    *   HQ is **Bob** (Right Panel).
    *   The Enemy is **Eve** (Middle Panel).
2.  **Phase 1: Weak Encryption (The Risk)**
    *   Ensure Global Parameters are small: `Modulus (p) = 23`, `Generator (g) = 5`.
    *   **Alice:** Enter a Secret `a` (e.g., `6`). Click **1. Calc Public (A)**.
        *   *Watch the arrow:* You sent "8" to the network. Eve sees "8". Bob sees "8".
    *   **Bob:** Enter a Secret `b` (e.g., `15`). Click **2. Calc Public (B)**.
        *   *Watch the arrow:* Bob sends "19" to the network. Eve sees "19".
    *   **The Crack:** Look at Eve's Panel. She has `p=23, g=5, A=8, B=19`.
        *   Click **Try to Calculate Secret**.
        *   *Observation:* Eve successfully cracks it because `p` is too small. She found your secret key! **Mission Failed.**
3.  **Phase 2: Strong Encryption (The Solution)**
    *   **Change Global Parameters:** Set `Modulus (p)` to `99991` (a larger prime).
    *   **Alice:** Click **1. Calc Public (A)** again. (New Public Value generated).
    *   **Bob:** Click **2. Calc Public (B)** again.
    *   **Establish Key:** Both Alice and Bob Click **3. Calc Shared Secret**.
        *   Confirm both Green Boxes show the **SAME number**.
4.  **The Final Test:**
    *   Go to Eve's Panel. Click **Try to Calculate Secret**.
    *   *Observation:* Eve fails or takes too long. The math is now too hard for a simple brute force. **Mission Success.**

### **Deliverable B (Screenshot)**
*   **Screenshot:** Show Alice and Bob with the **Same Shared Secret** (Green Boxes) using the large modulus ($99991$).

---

## **Part 3: The Payload (RSA)**
*Mission: Send the classified blueprint.*

Now that you have a secure channel, you need to send a one-way message that *only* Bob can read. You will use Asymmetric Encryption (Public/Private Keys).

### **Step-by-Step Instructions**
1.  **Launch Tool:** Open `tools/CryptoMessenger.html`.
2.  **Generate Identity:**
    *   Click **Generate New Keypair**.
    *   You now see two keys:
        *   **Public Key:** The "Mailbox Address" you give to people.
        *   **Private Key:** The "Mailbox Key" you keep in your pocket. **NEVER SHARE THIS.**
3.  **The Loopback Test (Simulation):**
    *   Normally, you would paste Bob's Public Key. For this lab, act as both sender and receiver to verify the math works.
    *   **Copy** your entire **Public Key** (from the left box).
    *   **Paste** it into the **"Recipient's Public Key"** box (on the right).
4.  **Encrypt (The Sender):**
    *   Message: `"The Eagle has landed. Package secure."`
    *   Click **Encrypt & Send**.
    *   Look at the **Ciphertext** output. It is a garbled mess of characters. This is what Eve sees.
5.  **Decrypt (The Receiver):**
    *   Copy that **Ciphertext**.
    *   Paste it into the **Inbox** (bottom card).
    *   Click **Decrypt with My Private Key**.
    *   *Observation:* The original text appears clearly.

### **Deliverable C (Screenshot)**
*   **Screenshot:** Show the **Inbox Panel** with the successfully decrypted message ("The Eagle has landed...").

---

## **Part 4: Mission Debrief (Analysis)**

**Submission File:** `Agent_Name_MissionReport.pdf` (or .docx)

**1. Integrity Analysis (The Ledger)**
> In Part 1, when you changed the date in Block 1, why was the link between Block 2 and Block 3 *also* broken? Explain how the "Chain" is built using hashes.

**2. Secrecy Analysis (The Handshake)**
> In Part 2 (Phase 1), Eve easily cracked your code. In Phase 2, she failed. What specific variable ($p$, $g$, $A$, or $B$) made the difference, and why does increasing it make the "Discrete Log Problem" harder?

**3. Asymmetric Analysis (The Envelope)**
> In Part 3, you used a Public Key to encrypt.
> *   **Hypothesis:** If an attacker stole your *Public Key* (the one you pasted), could they decrypt the message you sent?
> *   **Explain:** Why is the Private Key the *only* thing that can open the message?
