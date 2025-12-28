# **LAB 03 (VARIANT B) – THE LOTTERY FRAUD**

**Topic:** Hash Collisions & Birthday Paradox.

**Story Context:**
> A fraudster wants two lottery tickets to have the same hash ID.
> Using a weak 16-bit hash, finding a collision is trivial.

**Tools Required:** `HashLab.html` (Tab: Collision).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Hash Size:** 16-Bits.

---

## **Part 2: The Attack**

1.  **Action:**
    -   Run the "Birthday Attack" simulator.
    -   Wait for a collision.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab03B.docx`

### **Screenshot 1: Collision**
-   **Show:** "COLLISION FOUND" with the two inputs.
-   **Markup:** **Red Circle** around the matching hashes.

### **Part 4: Analysis (Homework Integration)**

1.  **Probability:** The formula for collision probability is $1 - e^{-n^2 / 2k}$. Calculate the number of items ($n$) needed to have a 50% chance of collision for a 16-bit hash ($k=2^{16}=65536$).

### **Part 5: References & Further Reading**

1.  **Case Study:** [The Flame Malware](https://www.microsoft.com/en-us/msrc/blog/2012/06/flame-malware-collision-attack-explained)
    *   *How world-class hackers used an MD5 collision to fake a Microsoft Update signature.*
2.  **Google:** [Shattered (SHA-1 Collision)](https://shattered.io/)
    *   *The first practical collision attack against SHA-1.*
3.  **Math:** [Birthday Paradox Explained](https://betterexplained.com/articles/understanding-the-birthday-paradox/)


