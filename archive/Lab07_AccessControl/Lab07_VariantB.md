# **LAB 07 (VARIANT B) – THE GENERAL**

**Topic:** Mandatory Access Control (MAC) - Bell-LaPadula.

**Story Context:**
> Military Rule: "Read Down, Write Up".
> If you are SECRET, you can Read UNCLASSIFIED.
> But you CANNOT Write to UNCLASSIFIED (Leaking secrets).

**Tools Required:** `AccessControlSim.html` (Tab: MAC).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Clearance:** `SECRET`.

---

## **Part 2: The Rules**

1.  **Action:**
    -   Try to Read TOP SECRET. -> **Denied** (No Read Up).
    -   Try to Write UNCLASSIFIED. -> **Denied** (No Write Down-*property).
    -   Try to Read UNCLASSIFIED. -> **Allowed**.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab07B.docx`

### **Screenshot 1: The * Property**
-   **Show:** Denied Write to Lower Level.
-   **Markup:** **Red Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Availability:** BLP focuses on Confidentiality. Which model focuses on **Integrity** (No Read Down, No Write Up)? (Hint: Biba Model).

### **Part 5: References & Further Reading**

1.  **Model:** [Bell-LaPadula Model](https://en.wikipedia.org/wiki/Bell%E2%80%93LaPadula_model)
    *   *The "No Read Up, No Write Down" rule explained.*
2.  **Comparison:**
```merm
graph TD
    Sub[Subject: SECRET]
    ObjH[Object: TOP SECRET]
    ObjL[Object: UNCLASSIFIED]
    Sub --X No Read--> ObjH
    Sub --X No Write--> ObjL
    Sub --OK Read--> ObjL
```


