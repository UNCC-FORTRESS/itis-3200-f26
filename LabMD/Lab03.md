# **LAB 3 – BLOCK CIPHER MODES**

**Topic**: Block Ciphers, ECB vs. CBC, & Visualizing Determinism.

**Tools Required**: Python (IDLE, VS Code, or Google Colab) & MS Paint (or any image editor).

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity.

1. **The Image:** Create a standard `.bmp` (Bitmap) image using MS Paint.
    
    - **Canvas:** White background.
        
    - **Content:** Write your **Student ID** in large Black text. Draw a **Red Circle** around it.
        
    - **Save As:** `input.bmp` (Select "24-bit Bitmap").
        
2. **The Key:** Your **Student ID** (padded to 16 bytes).
    
    - _Logic:_ If your ID is `801234567`, the script will automatically pad it to `8012345678012345`.
        

---

## **Part 2: The Experiment**

### **Task A: The Script**

Copy the following code into a Python file (e.g., `lab3.py`) or a Google Colab cell.

Python

```python
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os

# --- STUDENT CONFIGURATION ---
# ENTER YOUR STUDENT ID HERE (digits only)
student_id = "801234567" 
# -----------------------------

def get_key(id_str):
    # Create a 16-byte key by repeating/truncating ID
    key = (id_str * 16)[:16]
    return key.encode('utf-8')

def encrypt_image(mode_name, input_file):
    key = get_key(student_id)
    
    with open(input_file, 'rb') as f:
        data = f.read()
    
    # BPM Header is usually 54 bytes. We must NOT encrypt the header
    # or the OS won't recognize the file as an image.
    header = data[:54]
    body = data[54:]
    
    # Pad body to match AES block size (16 bytes)
    padded_body = pad(body, 16)
    
    if mode_name == 'ECB':
        cipher = AES.new(key, AES.MODE_ECB)
    else:
        # CBC needs an IV. We use a zero-IV for simplicity in viewing
        cipher = AES.new(key, AES.MODE_CBC, iv=b'\x00'*16)
        
    encrypted_body = cipher.encrypt(padded_body)
    
    # Reconstruct file: Header + Encrypted Body
    # Note: This technically corrupts the pixel format, but 
    # viewers usually try to render it anyway, showing the "static".
    output_data = header + encrypted_body
    
    output_name = f"output_{mode_name}.bmp"
    with open(output_name, 'wb') as f:
        f.write(output_data)
    print(f"Saved {output_name}")

# Run Encryption
try:
    encrypt_image('ECB', 'input.bmp')
    encrypt_image('CBC', 'input.bmp')
    print("Encryption Complete. Check your folder.")
except FileNotFoundError:
    print("Error: Make sure 'input.bmp' is in the same folder as this script!")
except Exception as e:
    print(f"Error: {e}. (You may need to run: pip install pycryptodome)")
```

### **Task B: Execution**

1. Place your `input.bmp` in the same folder as the script.
    
2. Run the script.
    
3. It will generate `output_ECB.bmp` and `output_CBC.bmp`.
    

### **Task C: Observation**

1. Open all three images on your screen.
    
2. **ECB Image:** You should see a "ghostly" or "staticky" version of your ID and Circle.
    
3. **CBC Image:** You should see pure, random static noise.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: Visual Evidence**

- **Requirement:** A screenshot of your file explorer or image viewer showing **Input**, **ECB**, and **CBC** side-by-side.
    
- **Markup:**
    
    - **Red Box** around the `output_ECB.bmp` image where your ID is still visible.
        
    - **Yellow Highlight** around the `output_CBC.bmp` image (pure static).
        

### **Analysis Questions**

1. **Observation:** In the ECB image, why can you still read your ID? What specific property of ECB mode preserves the patterns (edges/shapes) of the original image?
    
2. **Theory:** The CBC image looks like random noise. This is called **Pseudo-Randomness**. Why does CBC succeed in hiding the pattern where ECB fails? (Hint: Mention the "IV" or the chaining mechanism).
    

---

---

# **LAB 3 (VARIANT B): THE CUT-AND-PASTE ATTACK**

Topic: ECB Vulnerability (Block Independence).

Note: Demonstrates how attackers can rearrange encrypted data without knowing the key.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Valid User String:** `user:[YourID];role:user`
    
2. **Target Role:** `admin`
    

---

## **Part 2: The Experiment**

### **Task A: Block Alignment**

We assume AES-128 (16-byte blocks). We want to trick the server into thinking we are an admin.

We need to craft a specific input.

1. Open [CyberChef](https://gchq.github.io/CyberChef/).
    
2. **Recipe:** `AES Encrypt` (Key: `00000000000000000000000000000000`, Mode: `ECB`, Input: `Raw`).
    
3. **Input 1 (The Admin Block):** We need to encrypt the word "admin" so it sits perfectly in a block.
    
    - Type exactly 11 bytes of padding, then `admin`.
        
    - Example: `xxxxxxxxxxxadmin` (Total 16 bytes).
        
    - Encrypt this. **Copy the Ciphertext**.
        
4. **Input 2 (The User Session):**
    
    - Input: `user:[YourID];role:user`
        
    - Encrypt this. **Copy the Ciphertext**.
        

### **Task B: The Surgery**

1. Look at the Hex output of **Input 1**. The first 32 hex characters (16 bytes) represent the encrypted block for `xxxxxxxxxxxadmin`.
    
2. Look at the Hex output of **Input 2**. Find the block that corresponds to `role:user`.
    
3. **The Attack:** Manually replace the ciphertext hex of the `user` block with the ciphertext hex of the `admin` block you generated in step 3.
    
4. **Decrypt:** Put this new "Frankenstein" hex string into the `AES Decrypt` recipe.
    
5. **Result:** It should decrypt to `user:[YourID];role:admin`.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Frankenstein String**

- **Requirement:** Screenshot of CyberChef showing the decryption of your modified string.
    
- **Markup:**
    
    - **Yellow Highlight** over the output text showing `role:admin`.
        
    - **Red Box** around the `user:[YourID]` part (proving it's your session).
        

### **Analysis Questions**

1. **Mechanics:** Why did the decryption validly produce "admin" even though you moved that encrypted block from a completely different message?
    
2. **Impact:** If a bank used ECB mode for cookies, could you copy the "Account Balance" block from a rich user's cookie and paste it into your cookie?
    

---

---

# **LAB 3 (VARIANT C): ERROR PROPAGATION**

Topic: ECB vs. CBC Resilience (Self-Healing).

Note: Demonstrates what happens when a bit gets flipped during transmission.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Input String:** A sentence containing your full name, at least 40 characters long.
    
    - _Example:_ `My name is Jian Xiang and I am testing error propagation in crypto.`
        

---

## **Part 2: The Experiment**

### **Task A: Encryption**

1. Use [CyberChef](https://gchq.github.io/CyberChef/).
    
2. Encrypt your string using **AES-ECB** (Any Key). Copy the Hex output.
    
3. Encrypt your string using **AES-CBC** (Any Key, Any IV). Copy the Hex output.
    

### **Task B: The Corruption**

1. Take the **ECB Hex**. Change **one character** in the middle of the string (e.g., change an `A` to a `B`).
    
2. Decrypt this corrupted hex.
    
    - _Observation:_ Only a few letters (one block) are garbled. The rest is readable.
        
3. Take the **CBC Hex**. Change the **exact same character** in the middle.
    
4. Decrypt this corrupted hex.
    
    - _Observation:_ A huge chunk of text is destroyed.
        

---

## **Part 3: Deliverables**

### **Screenshot 1: The Comparison**

- **Requirement:** One screenshot showing both Decryption results (ECB vs CBC).
    
- **Markup:**
    
    - **Yellow Highlight** over the readable parts of the ECB decryption.
        
    - **Red Box** over the "Garbage" text in the CBC decryption.
        

### **Analysis Questions**

1. **ECB:** Why is the error in ECB mode isolated to just 16 bytes (one block)?
    
2. **CBC:** In CBC decryption, the error propagated. Specifically, did the error ruin the _current_ block, the _next_ block, or _all_ future blocks? (Look closely at your output).
    

---

---

# **MARKING KEY: LAB 3**

### **Quick Plagiarism Check**

- **Lab 3 (Standard):**
    
    - Does the input image contain the student's ID?
        
    - Does the **ECB output** show the ghost of _that specific ID_? (If they download a generic ECB penguin image from Google, it won't match their ID).
        
- **Variant B (Cut-Paste):**
    
    - Does the decrypted output show `user:[TheirID]`?
        
- **Variant C (Errors):**
    
    - Does the plaintext sentence contain their name?
        

### **Answer Key (Analysis Questions)**

**Lab 3 (Standard)**

- **Q1:** **Determinism.** In ECB, identical plaintext blocks (e.g., a block of white pixels) always encrypt to identical ciphertext blocks. This preserves the structure/edges of the image.
    
- **Q2:** CBC uses an **IV (Initialization Vector)** and XORs the previous ciphertext block into the next. This "whitening" ensures that identical plaintext blocks produce completely different ciphertext blocks, creating high **Entropy** (looks like random noise).
    

**Variant B (Cut-Paste)**

- **Q1:** In ECB, blocks are **independent**. The cipher doesn't know (or care) that the "admin" block came from a different message. It just decrypts the 16 bytes it sees.
    
- **Q2:** **Yes.** Since blocks are independent, you can swap them between sessions if you know where the data is located.
    

**Variant C (Errors)**

- **Q1:** Blocks are independent. A corruption in Block 5 only affects the decryption of Block 5.
    
- **Q2:** In CBC, a corruption in Ciphertext Block $C_i$ ruins the decryption of Plaintext Block $P_i$, AND it affects **one bit/byte** in Plaintext Block $P_{i+1}$ (because $C_i$ is XORed with the output of the decryption function for block $i+1$). It does **not** propagate to _all_ future blocks (a common misconception); it typically self-heals after two blocks.