# Lab 04 (Final): Authenticated Encryption, Diffie-Hellman, RSA, Certificates & Password Salting

**Total: 100 points** (Part 1: 24 points, Part 2: 24 points, Part 3: 12 points, Part 4: 10 points, Part 5: 10 points, Part 6: 8 points, Part 7: 12 points)

**Rubric:** [`Lab04Final_Rubric.md`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/Lab04Final/Lab04Final_Rubric.md)

**Tools required:**
- **[CyberChef](https://uncc-fortress.github.io/CyberChef/)** (backup: [gchq.github.io/CyberChef](https://gchq.github.io/CyberChef/)) — Parts 1, 4, 5. Operations used: **AES Encrypt/Decrypt** (CBC and ECB), **HMAC**, **SHA2**, **RSA Generate Key Pair**, **RSA Encrypt/Decrypt**, **RSA Sign/Verify**.
- **Python 3.8+** — Part 3. **Standard library only, no `pip install`.**
- **A Colab notebook** — Part 7 (link inside).

**Get the Part 3 starter.** Browse the folder at
<https://github.com/UNCC-FORTRESS/itis-3200-f26/tree/main/Lab04Final>, or pull it directly:

```
curl -O https://raw.githubusercontent.com/UNCC-FORTRESS/itis-3200-f26/main/Lab04Final/Lab04FinalInterceptor.py
```

[`Lab04FinalInterceptor.py`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/Lab04Final/Lab04FinalInterceptor.py) — DH key exchange + rollback-resistant PRNG stream cipher + Mallory MITM template (same shape as the old Lab03's starter). You **may** reimplement it in another language, but your console screenshots must show the same two scenarios.

---

## Part 1: Authenticated Encryption — Six Candidate Schemes (24 points)

Alice wants to send Bob a message providing both **confidentiality** and **integrity**. Below are 6 candidate constructions. Some combine encryption and a hash/MAC correctly; some don't, on purpose. Evaluate each with your own personalized parameters in CyberChef.

**Your personalized parameters:**
- `M` = "[Your Name] does not know which one is Diffie and which is Hellman"
- `K1` = [Your Student ID] × 7
- `K2` = [Your Student ID]
- `IV` = FirstName + LastName, padded with your repeated Student ID to reach 16 bytes
- Encryption mode: **AES-CBC** unless a scheme's structure says otherwise (Scheme 4 below explicitly uses ECB)
- HMAC: **HMAC-SHA256**
- Hash (unkeyed, where called for): **SHA-256**

Where a structure calls for `M ‖ tag` (message concatenated with a hash/HMAC output), compute the tag first in its own CyberChef tab, then paste it directly after `M` in the Input box of the AES step — CyberChef doesn't need a dedicated "concatenate" operation for this, string-pasting the two together works fine.

### The 6 schemes

**Scheme 1 — Encrypt-and-MAC.**
```
C = AES-CBC(K1, M)
H = HMAC(K2, M)          <- HMAC over the PLAINTEXT
Alice sends: (C, H)
```

**Scheme 2 — The "Key Paradox."**
```
C = AES-CBC(Key = SHA-256(M), Payload = M)
Alice sends: (C)
```
Note: the AES *key* here is derived from the message itself, not from `K1`. Compute `SHA-256(M)` first, then use that hex digest as the AES key.

**Scheme 3 — The "Checksum" Mistake.**
```
C = AES-CBC(K1, M)
H = SHA-256(C)            <- unkeyed hash, no K2 anywhere
Alice sends: (C, H)
```

**Scheme 4 — The "ECB" Leak.**
```
C = AES-ECB(K1, M)         <- note the mode
H = HMAC(K2, C)
Alice sends: (C, H)
```

**Scheme 5 — The "Commitment."**
```
C = AES-CBC(K1, SHA-256(M))    <- Alice encrypts the HASH of M, not M itself
Alice sends: (C)
```

**Scheme 6 — The "Double-Wrap."**
```
C = AES-CBC(K1, M ‖ HMAC(K2, M))
Alice sends: (C)
```

### Steps (repeat for each of the 6 schemes)

1. Compute whatever sub-values the structure calls for (a hash, an HMAC) in their own CyberChef tabs.
2. Produce Alice's output — `C`, and `H` if the scheme sends one separately.
3. Now play Bob: decrypt/process everything Alice sent using only what Bob would actually have (the shared keys, `C`, and `H` if sent). Try to recover `M`, and — where applicable — independently recompute the integrity check and compare.
4. Take **one** full-desktop screenshot per scheme showing both your encoding steps and your decoding/verification steps together (two CyberChef tabs side-by-side, or two stacked screenshots combined into one image — either is fine as long as both halves and the full desktop/menu bar are visible in a single image file).

### Deliverables (12 pts — 2 pts per scheme)

- **SS1-SS6 (2 pts each):** the combined encode+decode screenshot for each scheme. Box red around any ciphertext/tag Alice produces; highlight yellow whatever Bob ends up with (recovered message, or the failure/mismatch if he can't get one).

### Analysis (12 pts — 2 pts per scheme)

For **each** scheme, answer in 2-4 sentences:
- **(a) Functionality:** Can Bob actually recover the original `M`? If not, explain precisely why not — this may *be* the scheme's fatal flaw, not a side note.
- **(b) If `M` is recoverable:** does the scheme provide **confidentiality** against a passive eavesdropper Eve? If not, how does she recover `M`?
- **(c) If `M` is recoverable:** does the scheme provide **integrity** against an active attacker Mallory? If not, describe the specific undetected modification she can make.

Conclude by **highlighting in yellow** whichever scheme(s) provide all three: functional, confidential, *and* tamper-evident.

---

## Part 2: Diffie-Hellman & PRNG Rollback Analysis (24 points)

**Personalized DH exchange.** Alice and Bob perform a DH key exchange using:
- Prime **p = 23**, generator **g = 5**
- Alice's secret `a` = last digit of your Student ID (if 0 or 1, use 3)
- Bob's secret `b` = second-to-last digit of your Student ID (if 0 or 1, use 4)

### Deliverable (4 pts)

Show your work for all three, in one place: `A = g^a mod p`, `B = g^b mod p`, and the shared secret `S` computed **both ways** — `S = B^a mod p` (Alice's side) and `S = A^b mod p` (Bob's side) — confirming they match.

### Analysis (20 pts)

Eve is eavesdropping on the exchange above.

- **Q1 (6 pts):** if Alice and Bob's PRNGs are *not* rollback-resistant, and Eve later learns their internal state, can Eve retroactively recover your shared secret `S`? Why or why not?
- **Q2 (6 pts):** if Alice switches to a rollback-resistant PRNG but Bob doesn't, is `S` still secure? Why or why not?
- **Q3 (8 pts):** Mallory intercepts the exchange and wants Alice and Bob to agree on a shared secret she knows in advance, specifically `S = 1`, without either side noticing a mismatch. Using your specific `p`, `g`, `a`, `b` values, find a value Mallory can substitute to force `S = 1` for both sides. Prove mathematically that it works.

---

## Part 3: Programming Assignment — The Stateful Interceptor (12 points)

Build a simulated secure session using Diffie-Hellman + a stateful PRNG stream cipher, then implement Mallory as an active man-in-the-middle who intercepts, decrypts, modifies, and re-encrypts traffic without either party detecting it.

**Starter template:** [`Lab04FinalInterceptor.py`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/Lab04Final/Lab04FinalInterceptor.py) (linked at the top of this document). Do not remove or modify existing code; only add the logic described in its comments.

**Classes/functions to implement:**
- `SecurePRNG`: `init()` seeds a 32-byte internal state from the DH shared secret; `generate()` produces N pseudorandom bytes; **must update its internal state via a hash function after every generation block** so the process can't be reversed (rollback resistance — this is Part 2's PRNG concept, made concrete).
- `stream_cipher()`: calls `prng.generate()` for a keystream, returns `plaintext XOR keystream`.
- `Entity` (Alice/Bob): `init()` sets up DH keys; `get_public_hex()` (already implemented, don't change); `establish_session()` computes the shared secret and seeds `SecurePRNG`.
- `Mallory`: `init()` sets up her own DH keys; `intercept()` — on a key exchange, stores the sender's key, generates her own fake shared secret, and returns her own public key instead; on an encrypted message, decrypts with the sender-side PRNG, modifies the plaintext, re-encrypts with the recipient-side PRNG.

**Two required execution flows:**
1. **Scenario A (secure):** Alice/Bob DH-exchange public keys, derive matching shared secrets, Alice stream-encrypts a message (your own choice of text), Bob decrypts it intact.
2. **Scenario B (MITM):** Mallory sits between Alice and Bob during key exchange, so each of them actually shares a secret with *her*, not each other. Alice encrypts a message; Mallory decrypts it, modifies a word, re-encrypts for Bob; Bob decrypts without error — he has no way to detect the tampering from the ciphertext alone.

**Deliverables (12 pts — 0 if any of the 3 are missing):**
- Public GitHub repo link, titled `Lab04Final_Interceptor`.
- Full-screen screenshot of console output for Scenario A.
- Full-screen screenshot of console output for Scenario B, clearly showing your original message and Mallory's modified version.

---

## Part 4: RSA Key Pairs and Encryption (10 points)

RSA is asymmetric: a Public Key (shareable) encrypts, a Private Key (secret) decrypts.

1. **Generate Alice's keys.** In CyberChef, use "Generate RSA Key Pair," 1024-bit, PEM format. Bake. You now have Alice's public and private key.
2. **Bob encrypts a message.** New CyberChef tab: "RSA Encrypt," paste Alice's public key as the key, mode RSA-OAEP, digest SHA-1, then "To binary." Message: `"Can you send me <your student ID> dollars for V-Bucks"`. The output is the ciphertext.
3. **Alice decrypts.** New tab: "From binary" then "RSA Decrypt," paste the ciphertext and Alice's private key.

**Deliverables (3 pts):** (1 pt) Alice's key pair screenshot. (1 pt) Bob's window, message highlighted yellow, ciphertext boxed red. (1 pt) Alice's window, ciphertext highlighted yellow, plaintext boxed red.

**Analysis (7 pts):**
- **Q4 (3 pts):** why is it safe to post the Public Key publicly but catastrophic to lose the Private Key? What's the mathematical relationship between them?
- **Q5 (2 pts):** Bob's message is confidential (only Alice can read it) — but can Alice confirm it actually came from Bob and not an impostor? Why/why not?
- **Q6 (2 pts):** why include a hash (message digest) in RSA encryption/signing rather than operating on the raw message directly?

---

## Part 5: RSA Digital Signatures & Hybrid Encryption (10 points)

Part 4 gave confidentiality only. Now add authenticity: Bob AES-encrypts a message, then signs it with his own RSA private key.

1. **Bob generates his own RSA key pair** (1024-bit, PEM), posts the public key.
2. **Bob AES-encrypts.** "AES Encrypt," CBC mode, raw input, hex output, key = IV = your Student ID (repeated to meet the length requirement). Message: `"Thank you for sending me <your student ID> dollars, I have a lot of Fortnite skins now!"`. Save the resulting ciphertext.
3. **Bob signs the ciphertext.** Add "RSA Sign" then "To binary" after the AES step; key = Bob's private key; digest SHA-256. Output is the signature.
4. **Alice verifies.** New tab: "From binary" then "RSA Verify"; key = Bob's public key, signature input = the signature from step 3, message input = the ciphertext from step 2, Digest: SHA-256. A valid result shows "Verified: true".

**Deliverables (3 pts):** (1 pt) Bob's key pair. (1 pt) Bob's message highlighted yellow + signature boxed red. (1 pt) Alice's signature and ciphertext inputs highlighted yellow + verification result boxed red.

**Analysis (7 pts):**
- **Q7 (3 pts):** why does Bob sign with his *Private* key rather than his Public key? Would signing with the Public key still prove authorship?
- **Q8 (2 pts):** Alice got Bob's public key from "an online forum" — can she actually prove it's really Bob's key and not Mallory's? Why/why not? (This sets up Part 6.)
- **Q9 (2 pts):** this lab uses **hybrid encryption** — AES for the message, RSA only for the signature. Why not just use RSA to encrypt the whole message and sign it directly? (Hint: computational efficiency.)

---

## Part 6: Certificates (8 points)

Conceptual, referencing the Certificate Authorities lecture content. Scenario: Alice receives a certificate for "Mallory," signed by "Bob," and must follow a chain of trust back to a root CA ("BC").

- **Q10 (3 pts):** list the specific chain of certificates Alice must verify to trust Mallory's key.
- **Q11 (2 pts):** if Bob's intermediate certificate was signed using an algorithm now considered broken, does Alice still trust Mallory? Why or why not?
- **Q12 (3 pts):** "You cannot gain trust if you trust nothing — you need a root of trust." In a real browser, who are the trust anchors, and how do they get onto your computer? What happens if you manually delete all Root CA certificates and then visit a site like Google or Canvas?

*(Optional supplementary interactive practice for this section: [CertAuthorityTool.html](https://uncc-fortress.github.io/itis-3200-f26/archive/Lab06_CertsPasswords/tools/CertAuthorityTool.html) and [CertLab.html](https://uncc-fortress.github.io/itis-3200-f26/archive/Lab06_CertsPasswords/tools/CertLab.html).)*

---

## Part 7: The Exponential Wall — Password Salting Simulation (12 points)

1. Open the provided Python/Colab notebook: **https://colab.research.google.com/drive/1C4E4JwCuJ_W6-4olBm0GH2RA_fGLITMd?usp=sharing**.
2. Select "Open in Colab" if prompted, read through the code, then run it.
3. Observe the brute-force time difference between the unsalted and salted password databases (the salted attack may take 1-3 minutes — that delay *is* the security benefit in action).

**Deliverable (2 pts):** full screenshot of the output console, red box around the elapsed time and extra-hashes-computed count for the salted database.

**Analysis (10 pts):**
- **Q13 (3 pts):** salts are stored in plaintext next to the username — an attacker who steals the database can see them. If salts are visible, how do they still defeat a pre-computed rainbow-table attack?
- **Q14 (3 pts):** a slow hash defends against *offline* attacks — but explain the new vulnerability it creates for *online* attacks. If verifying one password costs the server 0.5 CPU-seconds, how could an attacker weaponize that to crash the login portal?
- **Q15 (4 pts):** why do attackers use GPUs rather than CPUs for password cracking specifically? How does salting reduce a GPU cracking rig's efficiency?

*(Optional supplementary interactive practice: [CrackLab.html](https://uncc-fortress.github.io/itis-3200-f26/archive/Lab06_CertsPasswords/tools/CrackLab.html) and [HashCracker.html](https://uncc-fortress.github.io/itis-3200-f26/archive/Lab06_CertsPasswords/tools/HashCracker.html).)*

---

## References & Further Reading

Lab-wise, if you face any difficulties regarding the setup, tool usage, or markup help, please feel free to reach out to the TAs during office hours or via email. All assessments and deductions are done at the discretion of the TAs, but mostly based off of a preset rubric to ensure fairness and consistency — if you have any reservations with how your submission was graded, please raise them within three days of receiving your points.

1. **Computerphile:** [Secret Key Exchange (Diffie-Hellman)](https://www.youtube.com/watch?v=NmM9HA2MQGI) — Part 2's key exchange.
2. **Ref:** [Authenticated Encryption (Wikipedia)](https://en.wikipedia.org/wiki/Authenticated_encryption) — background for reasoning about Part 1's schemes.
3. **Computerphile:** [Public Key Cryptography](https://www.youtube.com/watch?v=GSIDS_lvRv4) — the RSA/asymmetric-encryption ideas behind Parts 4-5.
4. **Ref:** [Chain of Trust (Wikipedia)](https://en.wikipedia.org/wiki/Chain_of_trust) — background for Part 6's certificate questions.
5. **OWASP:** [Password Storage Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html) — background for Part 7's salting/hashing questions.

None of these walk through this lab's specific schemes, parameters, or values — figuring those out is the point of the exercise.

## AI Appendix & submission format

Follow [`guidelines.txt`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/guidelines.txt) (screenshot markup, `FirstName_LastName_Lab04Final.docx` naming, AI-use disclosure). Not restated here. The missing-screenshot cap in [`SCREENSHOT_PENALTY_POLICY.md`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/SCREENSHOT_PENALTY_POLICY.md) applies on top of the rubric.
