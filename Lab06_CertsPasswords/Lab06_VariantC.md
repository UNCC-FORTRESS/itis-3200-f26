# **LAB 06 (VARIANT C) – THE SALTY DEFENSE**

**Topic:** Salting Hashes.

**Story Context:**
> To defeat Rainbow Tables, we add a random "Salt" to every password before hashing.
> $H = Hash(Password + Salt)$.
> Since the Rainbow Table was built for $Hash(Password)$, it can't find $H$.

**Tools Required:** `CrackLab.html` (Tab: Salting).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Password:** `pass[ID_LastDigit]`.
2.  **Salt:** `RandomUserSpecificString`.

---

## **Part 2: The Defense**

1.  **Action:**
    -   Create salted hash.
    -   Try Rainbow Lookup.
    -   Result: **Not Found**.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab06C.docx`

### **Screenshot 1: The Fail**
-   **Show:** "Not Found in Checksum Database".
-   **Markup:** **Green Check** indicating security success.

### **Part 4: Analysis (Homework Integration)**

1.  **Uniqueness:** Why must the salt be unique per user? (What if everyone used the exact same salt "Salty"? An attacker would just build a "Salty Rainbow Table").

### **Part 5: References & Further Reading**

1.  **Explanation:** [Salting Passwords](https://auth0.com/blog/adding-salt-to-hashing-a-better-way-to-store-passwords/)
2.  **OWASP:** [Password Storage Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html)
    *   *Industry standard best practices (Use Argon2 or bcrypt).*


