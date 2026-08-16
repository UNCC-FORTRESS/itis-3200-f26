# **LAB 09 (VARIANT A) – THE REFLECTION**

**Topic:** Cross-Site Scripting (Reflected XSS), Input Sanitization, and Browser Security.

**Tools Required:** 
-   Custom Tool: `XSS_Search.html` (in `tools/` folder).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Your Payload:** `<svg/onload=alert('HackedBy[Name]')>`

---

## **Part 2: The Vulnerability Probe**

1.  Open `XSS_Search.html`.
2.  **Normal Usage:**
    -   Type `Hello` in the search bar.
    -   Result: "Results for: Hello". (The input is reflected back).
3.  **HTML Injection:**
    -   Type `<b>Bold</b>`.
    -   Result: Does it show **Bold** as text or actually emboldened?
    -   If it's bold, the application is vulnerable to HTML injection.

---

## **Part 3: The Exploit (XSS)**

1.  **Script Injection:**
    -   Type `<script>alert(1)</script>`.
    -   *Note:* Modern browsers might block this specific vector or it might fail in `innerHTML`.
2.  **The SVG Bypass:**
    -   Type your SIP Payload: `<svg/onload=alert('HackedBy[Name]')>`.
    -   Click Search.
    -   **Observation:** An Alert Box should pop up. This proves you executed code on the page.

---

## **Part 4: Deliverables**

**Submission File:** `FirstName_LastName_Lab09A.docx`

### **Screenshot 1: The Alert**
-   **Show:** The Alert Box appearing over the search page.
-   **Markup:** **Red Circle** around the alert text "HackedBy...".

### **Analysis Questions**
1.  **Impact:** If you can make an alert box appear, what else can you do? (Hint: Can you read `document.cookie` and send it to your server? What does that mean for user accounts?).
2.  **Mitigation:** How should the developer fix this? (Hint: Output Encoding / Escaping special characters like `<` and `>`).

