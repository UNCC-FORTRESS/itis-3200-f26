# **LAB 08 (VARIANT B) – THE ONE-CLICK ATTACK**

**Topic:** CSRF.

**Story Context:**
> Alice clicks a link. Her browser says "Oh, a request to Bank.com! I have a cookie for that!" and sends it.
> Bank.com sees the cookie and processes the transfer.
> Alice never typed her password, but the browser authenticated her automatically.

**Tools Required:** `WebLab.html` (Tab: CSRF).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Attacker:** `Mallory_[ID]`.

---

## **Part 2: The Attack**

1.  **Action:**
    -   Embed `POST /transfer` in a button/image.
    -   Victim clicks.
    -   Money moves.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab08B.docx`

### **Screenshot 1: The Transfer**
-   **Show:** Log showing money moving to Mallory.
-   **Markup:** **Red Arrow**.

### **Part 4: Analysis (Homework Integration)**

1.  **Token:** Explain "Synchronizer Token Pattern". Why can't the attacker guess the token? (It is cryptographically random and not stored in a cookie).

### **Part 5: References & Further Reading**

1.  **OWASP:** [Cross-Site Request Forgery (CSRF)](https://owasp.org/www-community/attacks/csrf)
2.  **Visual Flow:**
```merm
sequenceDiagram
    participant User
    participant Bank
    participant Evil
    User->>Bank: Login (Get Session Cookie)
    User->>Evil: Visit Malicious Site
    Evil->>Bank: Auto-Submit Form (Transfer Money)
    Note over Bank: Sees User's Cookie -> Approves!
```


