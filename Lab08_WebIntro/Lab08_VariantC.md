# **LAB 08 (VARIANT C) – THE SESSION SNIFFER**

**Topic:** Session Hijacking.

**Story Context:**
> HTTPS encrypts the wire, but if you force HTTP, or if you access the machine directly (XSS), you can steal the `JSESSIONID`.
> `JSESSIONID` is the Key to the Kingdom.

**Tools Required:** `WebLab.html` (Tab: Hijack).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Target:** `Admin`.
2.  **Key:** `SESSION_[Random]`.

---

## **Part 2: The Injection**

1.  **Action:**
    -   Inject stolen session token.
    -   Refresh.
    -   Become Admin.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab08C.docx`

### **Screenshot 1: Pwned**
-   **Show:** "Welcome, Admin".
-   **Markup:** **Green Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Binding:** How can we bind a session to a user IP? (If request IP changes, invalid session). What are the downsides/usability issues? (Mobile phones switch IPs (WiFi -> 4G) constantly).

### **Part 5: References & Further Reading**

1.  **Tool:** [Wireshark](https://www.wireshark.org/)
    *   *The standard tool for sniffing network packets.*
2.  **Concept:** [Session Hijacking](https://www.invicti.com/learn/session-hijacking/)


