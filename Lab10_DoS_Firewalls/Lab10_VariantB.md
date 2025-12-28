# **LAB 10 (VARIANT B) – THE SHIELD**

**Topic:** Firewall Rules.

**Story Context:**
> You must write a rule to DROP traffic from the attacker identified in Variant A.

**Tools Required:** `FirewallLab.html` (Tab: Firewall).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Bad IP:** `192.168.1.[LastDigit]`.

---

## **Part 2: The Rule**

1.  **Action:**
    -   `DROP FROM [Bad IP]`.
    -   Observe Red packets hitting the wall.
    -   Server Status -> **ONLINE**.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab10B.docx`

### **Screenshot 1: The Block**
-   **Show:** Packets vanishing at firewall line.
-   **Markup:** **Green Check**.

### **Part 4: Analysis (Homework Integration)**

1.  **Allowlisting vs Blocklisting:** Which is more secure? Why is "Default Deny" (Allowlist) harder to implement but better?

### **Part 5: References & Further Reading**

1.  **Guide:** [Iptables Tutorial](https://www.digitalocean.com/community/tutorials/how-to-list-and-delete-iptables-firewall-rules)
    *   *Real-world Linux firewall command line guide.*
2.  **Concept:** [Stateful Inspection](https://www.checkpoint.com/cyber-hub/network-security/what-is-stateful-inspection/)
    *   *History of the Firewall (Check Point).*


