# **LAB 09 (VARIANT A) – THE VIRAL POST**

**Topic:** Reflected XSS.

**Story Context:**
> User input is echoed back to the screen.
> If the browser executes it as code, you have Cross-Site Scripting.
> You will prove you can execute arbitrary JS.

**Tools Required:** `InjectionLab.html` (Tab: XSS).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Payload:** `<script>alert('Hacked by [ID]')</script>`.

---

## **Part 2: The Alert**

1.  **Action:**
    -   Enter payload.
    -   See Alert Popup.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab09A.docx`

### **Screenshot 1: The Popup**
-   **Show:** Alert Box visible.
-   **Markup:** **Red Circle**.

### **Part 4: Analysis (Homework Integration)**

1.  **Cookie Theft:** Write the JavaScript code an attacker would use to send `document.cookie` to `evilsite.com`. (Hint: `new Image().src=...`).

### **Part 5: References & Further Reading**

1.  **Practice:** [Google XSS Game](https://xss-game.appspot.com/)
    *   *Interactive levels to learn XSS payloads.*
2.  **OWASP:** [Cross Site Scripting (XSS)](https://owasp.org/www-community/attacks/xss/)


