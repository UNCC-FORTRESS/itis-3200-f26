# **LAB 08 (VARIANT A) – THE COOKIE JAR**

**Topic:** HTTP State & Client-Side Trust.

**Story Context:**
> Cookies are user-controlled files.
> A server trusting `role=admin` in a cookie is a "Client-Side Trust" vulnerability.

**Tools Required:** `WebLab.html` (Tab: Cookie Shop).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Cookie:** `balance=[ID_Last3]`.
2.  **Goal:** `balance=9999`.

---

## **Part 2: The Edit**

1.  **Action:**
    -   Inspect Element (represented by tool).
    -   Edit Cookie.
    -   Refresh.
    -   Buy Item.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab08A.docx`

### **Screenshot 1: Success**
-   **Show:** High balance and successful purchase.
-   **Markup:** **Red Box** around the edited cookie.

### **Part 4: Analysis (Homework Integration)**

1.  **Fix:** How should the server store the balance? (Session Store / Database). What should be in the cookie? (Only a random Session ID).

### **Part 5: References & Further Reading**

1.  **Documentation:** [MDN: HTTP Cookies](https://developer.mozilla.org/en-US/docs/Web/HTTP/Cookies)
    *   *The definitive guide to how cookies work, including Secure and HttpOnly flags.*
2.  **Video:** [Cookies and Sessions (Computerphile)](https://www.youtube.com/watch?v=GhrvZ5nUWNg)


