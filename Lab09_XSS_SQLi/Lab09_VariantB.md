# **LAB 09 (VARIANT B) – THE ADMIN LOGIN**

**Topic:** SQL Injection (Bypass).

**Story Context:**
> `SELECT * FROM users WHERE user='$u' AND pass='$p'`.
> If $u$ is `admin' OR 1=1 --`, the query becomes always true.

**Tools Required:** `InjectionLab.html` (Tab: SQLi Login).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Target:** `admin`.
2.  **Injection:** `' OR '1'='1`.

---

## **Part 2: The Bypass**

1.  **Action:**
    -   Enter Injection as User.
    -   Pass can be anything.
    -   **Result:** Login Success.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab09B.docx`

### **Screenshot 1: Success**
-   **Show:** "Welcome Admin".
-   **Markup:** **Green Check**.

### **Part 4: Analysis (Homework Integration)**

1.  **Tautology:** Why is `OR 1=1` called a "Tautology"? (Always True).

### **Part 5: References & Further Reading**

1.  **Cheat Sheet:** [SQL Injection Cheat Sheet](https://portswigger.net/web-security/sql-injection/cheat-sheet)
    *   *PortSwigger's guide to syntax for MySQL, PostgreSQL, Oracle, etc.*
2.  **Visual:**
```merm
graph LR
    Input["' OR 1=1 --"] --> Query["SELECT * FROM users WHERE user='' OR 1=1"]
    Query --> Result[TRUE -> All Rows]
```


