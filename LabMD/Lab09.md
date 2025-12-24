# **LAB 9 – THE GLASS WIRE (NETWORK FORENSICS)**

Topic: TCP/IP Handshakes, Packet Analysis, & Cleartext Data.

Lecture Reference: Lecture 15 (TCP/IP).

Tools Required: Wireshark (or CloudShark) & a Terminal.

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity.

1. **Target Site:** `http://example.com` (Must be HTTP, not HTTPS).
    
2. **Custom Header:** `X-Student-ID: [Your_Student_ID]`
    
    - _Example:_ `X-Student-ID: 801234567`
        

---

## **Part 2: The Experiment**

### **Task A: The Capture**

1. Open **Wireshark**.
    
2. Select your active network interface (e.g., "Wi-Fi" or "Ethernet").
    
3. Click the blue **Shark Fin** icon to Start Capture.
    
4. Open your Terminal (Mac/Linux) or Command Prompt (Windows).
    
5. Send a specific HTTP request containing your ID:
    
    - **Command:** `curl -v -H "X-Student-ID: 801234567" http://example.com`
        
    - _Note:_ If `curl` is not available, you can use a browser, but `curl` is cleaner.
        
6. Wait for the response text in the terminal.
    
7. Go back to Wireshark and **Stop Capture** (Red Square).
    

### **Task B: The Analysis**

1. In the "Apply a display filter" bar, type: `http`. Press Enter.
    
2. Find the packet that says `GET / HTTP/1.1`.
    
3. Right-click this packet $\rightarrow$ **Follow** $\rightarrow$ **TCP Stream**.
    
4. A new window will pop up showing the full conversation (Red text = You, Blue text = Server).
    
5. Look for your **Custom Header** in the red text.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The TCP Stream**

- **Requirement:** Screenshot of the "Follow TCP Stream" window.
    
- **Markup:**
    
    - **Red Box** around the line `X-Student-ID: 801...`.
        
    - **Yellow Highlight** around the `Host: example.com` line.
        

### **Analysis Questions**

1. **Observation:** In the "Follow TCP Stream" window, you see the _content_ of the data. Did you see the **Three-Way Handshake** (SYN, SYN-ACK, ACK) inside this specific window? Why or why not? (Hint: Does the stream view show _headers_ or _payload_?).
    
2. **Security:** If you logged into a legacy bank website using HTTP (not HTTPS) while sitting in a coffee shop, could a hacker on the same Wi-Fi see your password using this exact method? Explain why.
    

---

---

# **LAB 9 (VARIANT B): THE DNS LEAK**

Topic: UDP Protocol, DNS Privacy, & Cleartext Queries.

Note: Demonstrates that DNS queries are often visible even if the web traffic is encrypted.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Unique Domain:** `[Your_Student_ID].example.com`
    
    - _Example:_ `801234567.example.com`
        

---

## **Part 2: The Experiment**

### **Task A: The Capture**

1. Start **Wireshark** capture.
    
2. In the display filter, type: `udp.port == 53`. (This isolates DNS traffic).
    

### **Task B: The Query**

1. Open your Terminal / Command Prompt.
    
2. Force your computer to look up the unique domain:
    
    - **Windows:** `nslookup 801234567.example.com`
        
    - **Mac/Linux:** `dig 801234567.example.com` or `ping -c 1 801234567.example.com`
        
3. The command will likely fail (because the domain doesn't exist), but the _request_ was still sent.
    
4. Stop Wireshark capture.
    

### **Task C: The Inspection**

1. Look for a packet labeled **"Standard query ... A https://www.google.com/url?sa=E&source=gmail&q=801234567.example.com"**.
    
2. Click on it.
    
3. In the bottom pane, expand the **Domain Name System (query)** tree.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The DNS Packet**

- **Requirement:** Screenshot of the Wireshark Packet Details pane.
    
- **Markup:**
    
    - **Red Box** around the `Name: 801234567.example.com` field in the details tree.
        

### **Analysis Questions**

1. **Protocol:** DNS uses **UDP** (User Datagram Protocol). HTTP uses **TCP**.
    
    - Lecture 15 says UDP is "unreliable" (no guarantee of delivery). Why does DNS prefer a fast, unreliable protocol over the reliable TCP?
        
2. **Privacy:** Even if you use a VPN or HTTPS, your **DNS queries** might still be visible to your ISP (Internet Service Provider) unless you use "DNS over HTTPS (DoH)." What does this captured packet reveal about your browsing habits?
    

---

---

# **LAB 9 (VARIANT C): THE ARP BROADCAST**

Topic: Layer 2 Networking, MAC Addresses, & Broadcasting.

Note: Visualizing how computers find each other on a local network.

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Target IP:** The Gateway/Router IP of your current network.
    
    - _Common IPs:_ `192.168.1.1` or `10.0.0.1`. (Check your WiFi settings to be sure).
        

---

## **Part 2: The Experiment**

### **Task A: Clearing the Cache**

Computers remember MAC addresses to save time. We need to make your computer "forget" so it is forced to ask again.

1. **Windows (Admin CMD):** `arp -d *`
    
2. **Mac/Linux:** `sudo arp -d -a` (or just toggle your WiFi off and on).
    

### **Task B: The Broadcast**

1. Start **Wireshark** capture.
    
2. Filter: `arp`.
    
3. Open Terminal and **Ping the Gateway**:
    
    - `ping 192.168.1.1` (Replace with your actual gateway).
        
4. Stop Capture.
    

### **Task C: The Identification**

1. Look for a packet that says:
    
    - **Who has 192.168.1.1? Tell [Your Device IP]**
        
2. This is your computer shouting to the room.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The ARP Packet**

- **Requirement:** Screenshot of the Wireshark packet list.
    
- **Markup:**
    
    - **Yellow Highlight** over the Info column reading "Who has... Tell...".
        

### **Analysis Questions**

1. **Networking:** Why is ARP called a **"Broadcast"** protocol? Does your computer send this packet to just the router, or to _every_ device on the WiFi?
    
2. **Security:** Lecture 15 mentions **"ARP Poisoning"** (or Spoofing). Since ARP relies on trust ("I am the router!"), explain how an attacker could use a fake ARP reply to become a **Man-in-the-Middle**.
    

---

---

# **MARKING KEY: LAB 9**

### **Quick Plagiarism Check**

- **Lab 9 (Standard):**
    
    - Does the Red Box in the TCP stream show `X-Student-ID: [Their ID]`?
        
- **Variant B (DNS):**
    
    - Does the DNS Query Name contain their Student ID?
        
- **Variant C (ARP):**
    
    - (Harder to check unique parameters here, so rely on the timestamp in the Wireshark capture window).
        

### **Answer Key (Analysis Questions)**

**Lab 9 (Standard)**

- **Q1:** **No.** The "Follow TCP Stream" feature reassembles the _payload_ (the data inside the packets). The handshake (SYN/ACK) happens at the _transport layer_ to establish the connection before data is sent. To see the handshake, you must look at the raw packet list, not the stream view.
    
- **Q2:** **Yes.** HTTP sends data in **Cleartext** (as seen in the stream). Anyone with a packet sniffer (like Wireshark) on the same network can reassemble the TCP stream and read the `Password: ...` field just as easily as reading the headers.
    

**Variant B (DNS)**

- **Q1:** **Speed / Latency.** DNS needs to be incredibly fast. The overhead of setting up a TCP handshake (3 packets) just to ask "Where is https://www.google.com/search?q=google.com?" is too slow. UDP is "fire and forget"—much faster.
    
- **Q2:** It reveals **intent**. Even if the ISP can't see _what_ you read on a website (because of HTTPS), they know _which_ websites you are visiting (e.g., "healthline.com" or "political-party.org") based on the DNS lookup.
    

**Variant C (ARP)**

- **Q1:** It is sent to **Everyone** (Broadcast Address `FF:FF:FF:FF:FF:FF`). Your computer doesn't know _where_ the router is physically, so it shouts to the whole room.
    
- **Q2:** The protocol is stateless and trusting. If an attacker replies "I am 192.168.1.1" _before_ the real router does, your computer will believe the hacker. You will then send all your internet traffic to the hacker's MAC address instead of the router.