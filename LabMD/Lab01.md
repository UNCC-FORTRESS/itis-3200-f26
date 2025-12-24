# **LAB 1 – CLASSICAL CRYPTOGRAPHY**

**Topic:** Substitution Ciphers, Keyspace, & The Economics of Brute Force.

**Tools Required:** Web Browser ([CyberChef](https://gchq.github.io/CyberChef/)).

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity. Submitting a lab using generic values or another student's values will result in a grade of **0**.

1. **Your Plaintext:** Your **Full Name** followed by the phrase `"is learning security"`.
   - _Example:_ `Jian Xiang is learning security`
    
2. **Your Key (K):** The **last single digit** of your Student ID.
   - _Exception:_ If your ID ends in `0`, use `10`.
      
    - _Example:_ ID `801234567` $\rightarrow$ Key = **4**.
      

---

## **Part 2: The Experiment**

### **Task A: The Encryption (Defender Mode)**

1. Open [CyberChef](https://gchq.github.io/CyberChef/).
   
2. In the Operations search bar, type `ROT` and drag **"ROT13"** (which is a generic Caesar Cipher) into the Recipe column.
   
3. Change the **Amount** (Key) setting to match **Your Key (K)**.
   
4. Type **Your Plaintext** into the Input box.
   
5. Observe the ciphertext in the Output box.
   

### **Task B: The Attack (Adversary Mode)**

1. Clear the Recipe by clicking the trash can icon.
   
2. Copy the **Ciphertext** you generated in Task A and paste it into the **Input** box.
   
3. Search for **"ROT13 Brute Force"** and drag it into the Recipe.
   
4. The Output box will now show a list of all 25 possible shifts. Scroll through them until you find the one that reveals readable English.
   

---

## **Part 3: Deliverables & Screenshots**

Submit a single Word Document (`.docx`) containing the following.

### **Screenshot 1: Encryption Setup**

- **Requirement:** A **Full Desktop** screenshot of Task A.
  
- **Markup:**
  
    - Draw a **Red Box** around the "Amount" setting (showing your Key).
      
    - Use **Yellow Highlighter** on the Output box (showing your Ciphertext).
      

### **Screenshot 2: The Brute Force Attack**

- **Requirement:** A **Full Desktop** screenshot of Task B.
  
- **Markup:**
  
    - Use **Yellow Highlighter** to mark the **single row** in the output list that successfully decoded the message back to your name.
      

---

## **Part 4: Analysis Questions**

1. **Observation:** Look at Screenshot 2. How many "wrong" keys did the computer have to calculate before finding the right one? Is this considered "expensive" for a modern computer?
   
2. **Theory:** In Lecture 1, we discussed **Kerckhoff’s Principle**. Explain why the Caesar Cipher violates this principle if we rely on the "Shift Method" being a secret.
   

---

---

# **LAB 1 (VARIANT B): POLYALPHABETIC CIPHERS**

**Topic:** Vigenère Cipher, Diffusion, & Keyspace Size.

**Note:** Use this variant to rotate content between semesters.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Your Plaintext:** The **City** you were born in + The current **Year**.
   
    - _Example:_ `Shanghai2024`
    
2. **Your Key:** Your **First Name**.
   
    - _Example:_ `JIAN`
      

---

## **Part 2: The Experiment**

### **Task A: Encryption**

1. Open [CyberChef](https://gchq.github.io/CyberChef/).
   
2. Search for **"Vigenère Encode"**. Drag it to the Recipe.
   
3. In the "Passphrase" (Key) box, enter **Your Key**.
   
4. In the Input box, enter **Your Plaintext**.
   

### **Task B: Pattern Observation**

1. Look at your Plaintext. If you have repeating letters (like the two 'a's in "Shanghai"), look at the corresponding letters in the Ciphertext.
   
2. **Modify the Key:** Change the _last letter_ of your Key to the next letter in the alphabet (e.g., Change `JIAN` to `JIAO`).
   
3. Observe how the Ciphertext changes.
   

---

## **Part 3: Deliverables**

### **Screenshot 1: Vigenère Execution**

- **Requirement:** Full Desktop screenshot of Task A.
  
- **Markup:**
  
    - **Red Box** around the "Passphrase" box (Your Name).
      
    - **Yellow Highlight** over the Ciphertext.
      

### **Analysis Questions**

1. **Comparison:** In a Caesar Cipher (Lab 1A), the letter 'a' always maps to the same ciphertext letter. In your Vigenère experiment, did identical letters in the plaintext (if you had any) map to identical letters in the ciphertext? Why or why not?
   
2. **Security:** Why is the Vigenère Cipher significantly harder to "Brute Force" than the Caesar Cipher? (Hint: Discuss the size of the Keyspace).
   

---

---

# **LAB 1 (VARIANT C): ENCODING VS. ENCRYPTION**

**Topic:** Base64, ROT13, and the definition of Confidentiality.

**Note:** This variant focuses on a common misconception in security.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Input Data:** Your **Student ID Number**.
   

---

## **Part 2: The Experiment**

### **Task A: Encoding (Not Encryption)**

1. Open [CyberChef](https://gchq.github.io/CyberChef/).
   
2. Drag **"To Base64"** into the Recipe.
   
3. Type your **Student ID** into the Input.
   
4. Copy the Output.
   

### **Task B: Encryption (Weak Encryption)**

1. Clear the Recipe.
   
2. Drag **"ROT13"** into the Recipe.
   
3. Type your **Student ID** into the Input.
   
4. Copy the Output.
   

### **Task C: The "Hacker" Test**

1. Clear the Recipe again.
   
2. Drag **"From Base64"** into the Recipe.
   
3. Paste the output from **Task B** (The ROT13 output) into the input.
   
4. Observe that it **fails** to decode into anything readable.
   
5. Now paste the output from **Task A** (The Base64 output).
   
6. Observe that it decodes perfectly back to your ID.
   

---

## **Part 3: Deliverables**

### **Screenshot 1: The Comparison**

- **Requirement:** Create a text file or Word doc. Paste your **Base64** result and your **ROT13** result side-by-side.
  
- **Markup:**
  
    - **Yellow Highlight** over the Base64 string.
      
    - **Red Box** around the ROT13 string.
      

### **Analysis Questions**

1. **Concept:** Many developers store passwords in Base64 and think they are safe. Based on Task C, does Base64 provide **Confidentiality**? Why or why not?
   
2. **Definition:** What is the fundamental difference between an **Encoding** (like Base64) and an **Encryption** algorithm? (Hint: Does one require a key?)
   

---

---

# **MARKING KEY: LAB 1**

### **Quick Plagiarism Check**

- **SIP Check:** Look at the Red Box in the screenshot.
  
    - **Lab 1:** Is the "Amount" the last digit of their ID? Is the Input text _their_ name?
      
    - **Variant B:** Is the Key _their_ First Name?
      
    - **Variant C:** Is the Input _their_ Student ID?
    
- **Timestamp Check:** Ensure the Windows Taskbar / Mac Menu bar is visible and shows a recent date.
  

### **Answer Key (Analysis Questions)**

**Lab 1 (Standard)**

- **Q1:** The brute force list shows 25 (or 26) possibilities. This is **trivial/cheap** for a modern computer (fractions of a millisecond).
  
- **Q2:** **Kerckhoff's Principle** states that a system should be secure even if the enemy knows the system (the algorithm), as long as they don't know the key. Caesar Cipher relies on the method (shifting) being the only barrier; once you know it's a shift, you can break it easily because the keyspace is tiny.
  

**Variant B (Vigenère)**

- **Q1:** No. Vigenère is **Polyalphabetic**. The mapping depends on the position of the keyword letter. 'A' might be 'X' in one spot and 'L' in another.
  
- **Q2:** The keyspace for Caesar is 26. The keyspace for Vigenère is $26^L$ (where L is the key length). This is exponentially larger and impossible to scan with the naked eye.
  

**Variant C (Encoding)**

- **Q1:** No. Base64 is an **Encoding** scheme designed for data format compatibility, not secrecy. Anyone can reverse it without a key.
  
- **Q2:** Encryption relies on a **Secret Key** to hide data. Encoding changes the data representation (format) using a publicly known standard with **no key**.