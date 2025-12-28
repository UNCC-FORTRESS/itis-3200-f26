# **LAB 07 (VARIANT A) – THE HOSPITAL**

**Topic:** Role-Based Access Control (RBAC).

**Story Context:**
> In a hospital, access depends on your JOB, not your Name.
> Doctors can Prescribe. Nurses can Administer. Patients can View.
> **Principle of Least Privilege:** Don't give a Nurse "Prescribe" rights.

**Tools Required:** `AccessControlSim.html` (Tab: RBAC).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Role:** `Nurse`.
2.  **Target:** `Patient Records (Read)`, `Prescriptions (Write)`.

---

## **Part 2: The Policy**

1.  **Action:**
    -   Log in as Nurse.
    -   Try to "Write Prescription".
    -   **Result:** Access Denied.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab07A.docx`

### **Screenshot 1: Denial**
-   **Show:** "Access Denied" popup.
-   **Markup:** **Red Circle**.

### **Part 4: Analysis (Homework Integration)**

1.  **Role Explosion:** If a hospital has 1000 departments, and each needs unique permissions, RBAC can become "Role Explosion" (Nurse-Oncology, Nurse-ER, Nurse-ER-NightShift...). How does **ABAC (Attribute Based Access Control)** fix this?

### **Part 5: References & Further Reading**

1.  **Standard:** [NIST SP 800-162](https://csrc.nist.gov/publications/detail/sp/800-162/final)
    *   *Guide to Attribute Based Access Control (ABAC) - The evolution of RBAC.*
2.  **Concept:** [Role Based Access Control](https://csrc.nist.gov/projects/role-based-access-control)
    *   *NIST's official project page for RBAC standards.*


