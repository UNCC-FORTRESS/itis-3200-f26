# **LAB 10 (VARIANT B) – THE GATEKEEPER**

**Topic:** Firewalls, Packet Filtering, and Access Control Lists (ACLs).

**Tools Required:** 
-   Custom Tool: `NetworkSim.html` (Switch to **"Firewall Mode"**).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Blocked IP:** `192.168.1.[Last2DigitsOfID]`.
2.  **Allowed Port:** `80` (HTTP).

---

## **Part 2: The Traffic Analysis**

1.  Open `NetworkSim.html`. Switch to **Firewall Mode**.
2.  **Start Traffic:**
    -   Click "Simulate Traffic".
    -   Watch the "Packet Log".
    -   You will see packets from various IPs (Good and Bad).
    -   *Current State:* **ALLOW ALL** (Everything gets through).

---

## **Part 3: The Ruleset**

1.  **Identify the Threat:**
    -   Look for packets coming from **Your Blocked IP**.
    -   Note that they are currently "ACCEPTED".
2.  **Configure Rule 1 (Block IP):**
    -   Action: `DENY`.
    -   Source IP: `192.168.1.[XX]`.
    -   Click "Add Rule".
3.  **Configure Rule 2 (Allow Web):**
    -   Action: `ALLOW`.
    -   Destination Port: `80`.
    -   Click "Add Rule".
4.  **Verify:**
    -   Watch the log again.
    -   Are packets from your Bad IP now showing "DROPPED"?

---

## **Part 4: Deliverables**

**Submission File:** `FirstName_LastName_Lab10B.docx`

### **Screenshot 1: The Configuration**
-   **Show:** The "Active Rules" list with your blocking rule.
-   **Markup:** **Red Box** around the DENY rule.

### **Screenshot 2: The Log**
-   **Show:** The Packet Log showing a "DROPPED" packet from your Target IP.
-   **Markup:** **Yellow Highlight** on the RED dropped entry.

### **Analysis Questions**
1.  **Order Matters:** If you have a rule "ALLOW ALL" at the top, and "DENY BAD IP" at the bottom, will the Bad IP be blocked? Why does rule order matter?
2.  **Next Gen:** This is a "Packet Filter" (Layer 3/4). Can it stop an SQL Injection inside a valid HTTP packet? (Hint: No, it only looks at headers. You need a WAF (Web App Firewall) for that).

