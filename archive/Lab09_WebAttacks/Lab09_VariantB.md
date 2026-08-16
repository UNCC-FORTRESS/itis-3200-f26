# **LAB 09 (VARIANT B) – THE BYPASS**

**Topic:** SQL Injection (SQLi) and Authentication Logic.

**Tools Required:** 
-   Custom Tool: `SQLi_Login.html` (in `tools/` folder).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Target User:** `admin`.
2.  **Your Signature:** `' OR '1'='1' -- [YourID]`.

---

## **Part 2: The Login Bypass**

1.  Open `SQLi_Login.html`.
2.  **Normal Fail:**
    -   Username: `admin`.
    -   Password: `password`.
    -   Result: "Invalid Credentials".
3.  **The Injection:**
    -   Username: `admin' --`.
    -   Password: `anything`.
    -   **Explanation:** The query becomes `SELECT * FROM users WHERE user = 'admin' --' AND pass = '...'`. The `--` comments out the password check.
    -   Try it. Does it work?

---

## **Part 3: The Tautology Attack**

1.  **Bypass without knowing the Username:**
    -   Username: `' OR '1'='1`.
    -   Password: `anything`.
    -   **Explanation:** `WHERE user = '' OR '1'='1'`. This is always TRUE. It usually logs you in as the *first* user in the database (Admin).
    -   Try it.

2.  **Your Specific Hack:**
    -   Username: `admin`.
    -   Password: Your Signature: `' OR '1'='1' -- [YourID]`.
    -   *Note:* The tool logs the query. We want to see your ID in the log.

---

## **Part 4: Deliverables**

**Submission File:** `FirstName_LastName_Lab09B.docx`

### **Screenshot 1: Success**
-   **Show:** The "Welcome Admin" screen.
-   **Markup:** **Red Box** around the "Executed Query" shown at the bottom (Must include your ID).

### **Analysis Questions**
1.  **The Flaw:** The vulnerable code probably looks like `query = "SELECT * FROM users WHERE u='" + user + "'..."`. Why is string concatenation dangerous here?
2.  **The Fix:** How do **Prepared Statements** (Parameterized Queries) fix this? (Hint: They treat input as *data*, not *code*).

