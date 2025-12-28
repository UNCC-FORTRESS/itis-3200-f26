# **LAB 11 (VARIANT A) – THE FINGERPRINT**

**Topic:** Signature IDS.

**Story Context:**
> "If it looks like a duck, it's a duck."
> Signatures match known bad bytes.

**Tools Required:** `IDSLab.html` (Tab: Signature).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Signature:** `DEADBEEF`.

---

## **Part 2: The Block**

1.  **Action:**
    -   Start Stream.
    -   Observe `DEADBEEF` packets being dropped.
    -   Observe `DEADFEED` (clean) packets passing.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab11A.docx`

### **Screenshot 1: The Match**
-   **Show:** Log entry "MATCH FOUND".
-   **Markup:** **Red Box**.

### **Part 4: Analysis (Homework Integration)**

1.  **Polymorphism:** How do virus writers defeat signatures? (They encrypt the virus body with a random key every time, so the file bytes look different).

### **Part 5: References & Further Reading**

1.  **Tool:** [Snort Rule Documentation](http://manual-snort-org.s3-website-us-east-1.amazonaws.com/node27.html)
    *   *How to write real IDS signatures.*
2.  **Visual:**
```merm
graph LR
    Packet --> HeaderCheck{Header Match?}
    HeaderCheck -- Yes --> ContentCheck{Content Match?}
    ContentCheck -- Yes --> Alert[ALERT!]
    HeaderCheck -- No --> Pass[Allow]
```


