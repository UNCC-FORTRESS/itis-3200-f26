# **LAB 07 (VARIANT C) – THE LINUX ADMIN**

**Topic:** Discretionary Access Control (DAC) - Unix Permissions.

**Story Context:**
> "chmod 755 script.sh"
> 7 (Owner): rwx
> 5 (Group): r-x
> 5 (World): r-x
> You need to make a file "Private" (Only you can read/write).

**Tools Required:** `AccessControlSim.html` (Tab: DAC).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **File:** `diary_[ID].txt`.
2.  **Goal:** `chmod 600` (rw-------).

---

## **Part 2: The Chmod**

1.  **Action:**
    -   Create file.
    -   Set permissions to `600`.
    -   Simulate "Other User" trying to read.
    -   **Result:** Denied.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab07C.docx`

### **Screenshot 1: The Lock**
-   **Show:** Permission string `-rw-------`.
-   **Markup:** **Green Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Octal:** Convert `rwxr-xr--` to Octal. (r=4, w=2, x=1). (7, 5, 4 -> 754).

### **Part 5: References & Further Reading**

1.  **Guide:** [Linux File Permissions](https://www.redhat.com/sysadmin/linux-file-permissions-explained)
    *   *Understanding rwx, Octal codes, and chown/chmod.*
2.  **Vulnerability:** [Confused Deputy Problem](https://en.wikipedia.org/wiki/Confused_deputy_problem)
    *   *Why DAC fails when programs trick users.*


