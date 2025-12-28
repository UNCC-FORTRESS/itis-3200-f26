# **LAB 10 (VARIANT A) – THE AVALANCHE**

**Topic:** Network Availability, DoS (Denial of Service), and Resource Exhaustion.

**Tools Required:** 
-   Custom Tool: `NetworkSim.html` (in `tools/` folder).

---

## **Part 1: Student Identity Parameters (SIP)**

1.  **Target IP:** `10.0.0.80`.
2.  **Attack Protocol:** `UDP_FLOOD`.

---

## **Part 2: The Baseline**

1.  Open `NetworkSim.html`.
2.  Switch to **"Attacker Mode"**.
3.  **Start Ping:**
    -   Click "Ping Target".
    -   Observe the "Server Load" (Green Bar). It should stay low (~5%).
    -   Observe "Latency". Should be low (<20ms).

---

## **Part 3: The Slow Loris (Resource Exhaustion)**

1.  **Config:**
    -   Set Attack Type: `HTTP_SLOW`. (Simulates SlowLoris).
    -   Intensity: `Low`.
    -   Click **"Start Attack"**.
2.  **Observe:**
    -   The Server Load creeps up slowly.
    -   It might not crash, but other users will feel slowness.

---

## **Part 4: The UDP Flood (Volumetric DoS)**

1.  **Config:**
    -   Set Attack Type: `UDP_FLOOD`.
    -   Intensity: `MAXIMUM`.
    -   Click **"Start Attack"**.
2.  **Observe:**
    -   The "Packets Per Second" counter explodes.
    -   The Server Load hits 100% Red.
    -   **Result:** "SERVER OFFLINE / CONNECTION TIMEOUT".

---

## **Part 5: Deliverables**

**Submission File:** `FirstName_LastName_Lab10A.docx`

### **Screenshot 1: The Crash**
-   **Show:** The NetworkSim tool showing 100% Load and "OFFLINE".
-   **Markup:** **Red Box** around the "OFFLINE" status.

### **Screenshot 2: Statistics**
-   **Show:** The high packet count.
-   **Markup:** **Yellow Highlight** on the PPS (Packets Per Second) counter.

### **Analysis Questions**
1.  **Botnets:** You did this from one browser (1 computer). Why do attackers need thousands of zombies (Botnet) for a DDoS (Distributed DoS)? (Hint: Can the server just block your one IP?).
2.  **Protocol:** Why is UDP preferred over TCP for flooding? (Hint: Does UDP require a handshake?).

