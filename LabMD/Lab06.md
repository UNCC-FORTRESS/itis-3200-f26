# **LAB 6 – THE INJECTION (SQLi)**

Topic: SQL Injection, Input Validation, & Access Control Bypass.


Tools Required: Python (IDLE, VS Code, or Google Colab).

---

## **Part 1: Student Identity Parameters (SIP)**

**CRITICAL:** You must use the specific parameters below based on your own identity.

1. **Target Username:** `admin`
    
2. **Your Injection Signature:** `' OR '1'='1' -- [Your_Student_ID]`
    
    - _Example:_ `' OR '1'='1' -- 801234567`
        
    - _Note:_ The `--` is the SQL comment symbol. It tells the database to ignore everything after your ID.
        

---

## **Part 2: The Experiment**

### **Task A: The Vulnerable Database**

Copy the following Python code into a file (e.g., `lab6.py`). This script creates a temporary "In-Memory" database with a serious flaw.

```python
import sqlite3

def run_login():
    # 1. Setup a dummy database in RAM
    conn = sqlite3.connect(':memory:')
    c = conn.cursor()
    c.execute("CREATE TABLE users (user text, password text)")
    
    # 2. Create the Admin account (The target)
    c.execute("INSERT INTO users VALUES ('admin', 'SuperSecretPassword!123')")
    c.execute("INSERT INTO users VALUES ('guest', 'guest123')")
    
    print("--- SECURE LOGIN SYSTEM v1.0 ---")
    username = input("Enter Username: ")
    
    # 3. THE VULNERABILITY
    # We are concatenating the input string directly into the query!
    query = "SELECT * FROM users WHERE user = '" + username + "'"
    
    print(f"\n[DEBUG] Executing SQL: {query}")
    
    try:
        c.execute(query)
        result = c.fetchone()
        
        if result:
            print("\n>> LOGIN SUCCESSFUL! <<")
            print(f"Welcome, {result[0]}.")
            print(f"Your Secret Data: {result[1]}")
        else:
            print("\n>> LOGIN FAILED <<")
    except Exception as e:
        print(f"\n[ERROR] SQL Syntax Error: {e}")

run_login()
```

### **Task B: The Attack**

1. Run the script.
    
2. **Attempt 1 (Normal):** Enter `admin`.
    
    - _Result:_ Login Failed (Because the code doesn't check the password logic correctly in this simplified example, or simply finds no match because we didn't inject).
        
3. **Attempt 2 (The Injection):** Enter your **SIP Injection Signature**:
    
    - `' OR '1'='1' -- 801234567`
        
4. **Result:** The script should print `>> LOGIN SUCCESSFUL! <<` and reveal the Admin password.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Bypass**

- **Requirement:** Screenshot of the terminal output showing the successful login.
    
- **Markup:**
    
    - **Red Box** around the input line where you typed your ID payload.
        
    - **Yellow Highlight** around the `[DEBUG] Executing SQL` line (showing how your input altered the query).
        
    - **Yellow Highlight** around the `>> LOGIN SUCCESSFUL! <<` message.
        

### **Analysis Questions**

1. **Mechanism:** Look at the `[DEBUG]` line in your screenshot. Explain why the database decided to log you in, even though you didn't provide a password. (Hint: What is the result of `'1'='1'`?).
    
2. **Defense:** Lecture 13 discusses **Prepared Statements** (or Parameterized Queries). How does using placeholders (like `?` in SQL) prevent this exact attack?
    

---

---

# **LAB 6 (VARIANT B): COMMAND INJECTION**

Topic: Arbitrary Code Execution (Shell Injection).

Note: Demonstrates why system() calls are dangerous (Lecture 13).

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Payload:** `; echo "Hacked by [Your_Name]"`
    
    - _Example:_ `; echo "Hacked by Jian"`
        
    - _Note:_ If you are on Windows, use `&` instead of `;`. Example: `& echo "Hacked by Jian"`
        

---

## **Part 2: The Experiment**

### **Task A: The Vulnerable Script**

Copy this code. It simulates a "Network Ping Tool" often found on router admin pages.

Python

```python
import os
import platform

def ping_tool():
    target = input("Enter IP address to ping: ")
    
    # Determine command based on OS (Windows uses -n, others use -c)
    param = '-n' if platform.system().lower()=='windows' else '-c'
    
    # VULNERABILITY: Direct concatenation passed to shell
    command = f"ping {param} 1 {target}"
    
    print(f"\n[SERVER] Running command: {command}\n")
    os.system(command)

ping_tool()
```

### **Task B: The Attack**

1. Run the script.
    
2. **Input:** `8.8.8.8` (Normal behavior).
    
3. **Attack:** Enter `8.8.8.8` followed by your **SIP Payload**.
    
    - _Linux/Mac:_ `8.8.8.8; echo "Hacked by Jian"`
        
    - _Windows:_ `8.8.8.8 & echo "Hacked by Jian"`
        
4. **Observation:** The script will ping Google, and _then_ it will print your hacked message. You have successfully hijacked the control flow.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Shell Execution**

- **Requirement:** Terminal screenshot showing the ping output followed immediately by your echo message.
    
- **Markup:**
    
    - **Red Box** around your Input.
        
    - **Yellow Highlight** around the text `"Hacked by [Name]"` appearing in the output.
        

### **Analysis Questions**

1. **Impact:** If this vulnerability existed on a web server running as `root` (Administrator), what could an attacker do besides just printing text? (e.g., could they delete files?).
    
2. **Defense:** How is **Input Sanitization** different from using **Safe APIs** (like `subprocess` in Python)? Which one is better?
    

---

---

# **LAB 6 (VARIANT C): BROKEN ACCESS CONTROL (IDOR)**

Topic: Insecure Direct Object References & Authorization.

Lecture Reference: Lecture 9 (Access Control Models).

---

## **Part 1: Student Identity Parameters (SIP)**

1. **Your ID (Low Privilege):** `101`
    
2. **Target ID (High Privilege):** `999` (The Dean).
    

---

## **Part 2: The Experiment**

### **Task A: The Script**

This script simulates a "Student Grade Portal".

Python

```python
# Database of grades
database = {
    "101": {"name": "Student", "grade": "B", "notes": "Good effort."},
    "102": {"name": "Classmate", "grade": "A", "notes": "Excellent."},
    "999": {"name": "THE DEAN", "salary": "$500,000", "notes": "ADMIN ACCESS ONLY"}
}

def view_grades():
    print("--- CHARLOTTE.EDU GRADE PORTAL ---")
    # In a real app, this ID would come from the session cookie.
    # Here, the user can just type it in!
    user_id = input("Enter your User ID to view records: ")
    
    if user_id in database:
        print(f"\nloading record for ID: {user_id}...")
        print(database[user_id])
    else:
        print("User not found.")

view_grades()
```

### **Task B: The Breach**

1. Run the script.
    
2. Pretend you are Student 101. Type `101`. See your grade.
    
3. Now, pretend to be a hacker. Type `999`.
    
4. **Result:** You see the Dean's salary.
    

---

## **Part 3: Deliverables**

### **Screenshot 1: The Data Leak**

- **Requirement:** Screenshot showing the retrieval of the Dean's record.
    
- **Markup:**
    
    - **Red Box** around the input `999`.
        
    - **Yellow Highlight** around the output `salary: $500,000`.
        

### **Analysis Questions**

1. **Concept:** This is a failure of **Complete Mediation** (Security Principle). The system checked if ID 999 _exists_, but what did it fail to check?
    
2. **Defense:** In a secure system, simply "hiding" the Dean's ID isn't enough (Security by Obscurity). How should the server verify that User 101 is _allowed_ to see User 999's data? (Keyword: Authorization / Access Control List).
    

---

---

# **TA MARKING KEY: LAB 6**

### **Quick Plagiarism Check**

- **Lab 6 (SQLi):**
    
    - Does the input string in the Red Box contain the student's ID?
        
    - Does the `[DEBUG]` line show the injected comment `--`?
        
- **Variant B (Command Injection):**
    
    - Does the echo output say "Hacked by [Student Name]"?
        
- **Variant C (IDOR):**
    
    - Did they access ID 999?
        

### **Answer Key (Analysis Questions)**

**Lab 6 (Standard)**

- **Q1:** The injection `' OR '1'='1'` makes the `WHERE` clause always true for every row. The `--` comments out the rest of the query (ignoring any subsequent checks). The database returns the first row it finds, which happens to be the Admin.
    
- **Q2:** **Prepared Statements** separate the Code (SQL) from the Data (Input). The database treats the input `admin' OR 1=1` as a _literal string_ (a username with weird characters) rather than executable SQL commands.
    

**Variant B (Command Injection)**

- **Q1:** If running as root, they could execute `rm -rf /` (delete everything), install malware, open a reverse shell, or steal valid SSH keys. It is total system compromise.
    
- **Q2:** **Safe APIs** (like `subprocess.run(["ping", target])`) are better because they automatically handle arguments and do not invoke a shell that parses `;` or `&`. Input sanitization (trying to blacklist characters) is prone to errors/bypasses.
    

**Variant C (IDOR)**

- **Q1:** It failed to check **Authorization** (or Ownership). It checked "Is this a valid ID?" but not "Does the current user _own_ this ID?".
    
- **Q2:** The server must check the **Session** of the requester. `if (session.user_id == requested_id) OR (session.role == 'admin')`. Access should be based on the authenticated identity, not just the user input.