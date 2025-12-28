# **LAB 03 (VARIANT A) – THE CORRUPTED DOWNLOAD**

**Topic:** Cryptographic Hash Functions & Integrity.

**Story Context:**
> You are verifying a critical patch. The vendor provides a SHA-256 hash.
> Even a single bit flip in the file (e.g. download error) must change the hash completely.

**Tools Required:** `HashLab.html` (Tab: Checksum).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **File Content:** `"Patch v1.0 for [Name]"`
2.  **Vendor Hash:** Generated from the above string.

---

## **Part 2: The Experiment**

1.  **Action:**
    -   Generate Hash for valid file.
    -   Change **ONE character** (e.g., capitalize 'P').
    -   Generate Hash again.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab03A.docx`

### **Screenshot 1: The Config**
-   **Show:** Tool showing the "Corrupted" hash.
-   **Markup:** **Red Box** highlighting the difference from the original hash.

### **Part 4: Analysis (Homework Integration)**

1.  **Theory:** Define **Pre-image Resistance**. Why is it important that given $H(x)$, it is computationally infeasible to find $x$? (Relate to password storage).

### **Part 5: References & Further Reading**

1.  **Visual:** [SHA-256 Animation](https://sha256algorithm.com/)
    *   *Step-by-step visualization of the compression function.*
2.  **NIST:** [FIPS 180-4: Secure Hash Standard](https://csrc.nist.gov/publications/detail/fips/180/4/final)
    *   *The official government standard for SHA-2.*
3.  **Avalanche Effect:**
```merm
graph TD
    Input[Input: 'A'] -->|SHA256| H1[Hash 1: 559aead...]
    Input2[Input: 'B'] -->|SHA256| H2[Hash 2: df7e70e...]
    H1 -.->|50% Bits Diff| H2
```


