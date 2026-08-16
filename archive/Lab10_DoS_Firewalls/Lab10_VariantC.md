# **LAB 10 (VARIANT C) – THE REFLECTOR**

**Topic:** DNS Amplification (DRDoS).

**Story Context:**
> Spoofing the source IP allows you to trick a third party (DNS Server) into hitting the victim.
> If the Response > Request, you get Amplification.

**Tools Required:** `FirewallLab.html` (Tab: Amplification).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Reflector:** `8.8.8.8` (Simulated).

---

## **Part 2: The Attack**

1.  **Action:**
    -   Send Spoofed Packet.
    -   Watch Massive Response hit Victim.
    -   Note Amplification Factor.

---

## **Part 3: Deliverables**

**Submission File:** `FirstName_LastName_Lab10C.docx`

### **Screenshot 1: The Boom**
-   **Show:** Giant packet animation.
-   **Markup:** **Red Arrow** on the "50x" text.

### **Part 4: Analysis (Homework Integration)**

1.  **Ingress Filtering:** If every ISP checked "Is this packet actually coming from my customer's IP?", could spoofing exist? (No). Why don't they all do it? (Cost / Legacy infrastructure / Lazy).

### **Part 5: References & Further Reading**

1.  **Attack:** [DNS Amplification (US-CERT)](https://www.cisa.gov/news-events/alerts/2013/03/29/dns-amplification-attacks)
    *   *Official government alert on the mechanism.*
2.  **Visual:**
```merm
graph LR
    Attacker -->|Source=Victim| DNS[Open DNS Resolver]
    DNS -->|Big Response| Victim
```


