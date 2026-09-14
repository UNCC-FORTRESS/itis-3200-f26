# Lab 04 (Final) — Grading Rubric

**Total: 100 points** (Part 1: 24, Part 2: 24, Part 3: 12, Part 4: 10, Part 5: 10, Part 6: 8, Part 7: 12). See [`SCREENSHOT_PENALTY_POLICY.md`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/SCREENSHOT_PENALTY_POLICY.md) for the missing-screenshot cap policy, applied on top of this breakdown. **Penalty: −20 points** for submitting generic/example values instead of your own Student-ID-derived ones, duplicate screenshots, or tampered evidence.

This rubric gives you the exact point value of every item and *what* it's assessed on. It does not contain the answers or expected calculations — those live in the private grading key the TAs use. Every `Q#` is graded on the correctness of the underlying reasoning, not just a correct final number or the right one-word outcome: an answer that states the right result without explaining the mechanism gets at most half of that item.

---

## Part 1: Authenticated Encryption — Six Schemes — 24 pts

**Evidence — 12 pts (2 pts per scheme, SS1-SS6)**
- **[2]** per scheme: one combined screenshot showing both the encoding and decoding/verification steps, produced with the scheme's exact structure and the student's own personalized `M`/`K1`/`K2`/`IV`. Ciphertext/tag boxed red, Bob's resulting output (or failure) highlighted yellow.
- **[0]** if missing, if only one half (encode or decode) is shown, or if the scheme was implemented incorrectly (wrong mode, wrong key, HMAC over the wrong input, etc.).

**Analysis — 12 pts (2 pts per scheme)**
- **[2]** per scheme: correct answer on **all three** of (a) whether Bob can recover `M` and why/why not, (b) confidentiality against Eve if `M` is recoverable, (c) integrity against Mallory if `M` is recoverable — each with the mechanism, not just the label.
- **[1]** two of the three sub-answers correct.
- **[0]** fewer than two correct, or a scheme's fundamental nature is misidentified (e.g., calling a functionality-broken scheme merely "weak on integrity").
- Correctly highlighting which scheme(s) provide all three properties is folded into this per-scheme scoring, not a separate line item.

---

## Part 2: Diffie-Hellman & PRNG Rollback Analysis — 24 pts

**Evidence — 4 pts**
- **[4]** `A`, `B`, and `S` computed and shown from both Alice's and Bob's sides, matching, using the student's own `a`/`b` derived from their Student ID.
- **[2]** correct method shown but an arithmetic slip in one value.
- **[0]** missing, or generic/example `a`/`b` used instead of the student's own.

**Analysis — 20 pts**
- **[6] Q1** — correct determination of whether Eve can retroactively recover `S` from a non-rollback-resistant PRNG, with the reasoning for *why* the PRNG's state is reversible.
- **[6] Q2** — correct determination of whether `S` stays secure when only one party's PRNG is rollback-resistant, with the reasoning about which party gets compromised and how.
- **[8] Q3** — a mathematically valid value forcing `S = 1`, with a full proof using the student's own specific `p`/`g`/`a`/`b` values substituted in (not left generic/symbolic).

---

## Part 3: Programming Assignment — The Stateful Interceptor — 12 pts

- **[12]** all three required deliverables present: public GitHub repo link (titled `Lab04Final_Interceptor`), Scenario A console screenshot, Scenario B console screenshot clearly showing the original vs. Mallory-modified message. **[0] if any of the 3 is missing** — this is an all-or-nothing deliverable, not partial credit per item.

---

## Part 4: RSA Key Pairs and Encryption — 10 pts

**Evidence — 3 pts**
- **[1]** Alice's key pair screenshot.
- **[1]** Bob's window — message yellow, ciphertext boxed red.
- **[1]** Alice's window — ciphertext yellow, plaintext boxed red.

**Analysis — 7 pts**
- **[3] Q4** — why publishing the public key is safe but losing the private key is catastrophic, plus the correct mathematical relationship between the two keys.
- **[2] Q5** — correct determination of whether Alice can verify the message came from Bob, with reasoning.
- **[2] Q6** — why RSA operates on a hash/digest rather than the raw message.

---

## Part 5: RSA Digital Signatures & Hybrid Encryption — 10 pts

**Evidence — 3 pts**
- **[1]** Bob's key pair.
- **[1]** Bob's message (yellow) + signature (boxed red).
- **[1]** Alice's verification screenshot — inputs yellow, result boxed red.

**Analysis — 7 pts**
- **[3] Q7** — why signing uses the private key, and whether public-key signing would still prove authorship.
- **[2] Q8** — correct determination of whether Alice can trust a forum-sourced public key really belongs to Bob, with reasoning.
- **[2] Q9** — why hybrid encryption (AES for bulk data + RSA for signature/key material) is used instead of RSA for everything.

---

## Part 6: Certificates — 8 pts

- **[3] Q10** — the specific chain-of-trust verification steps Alice must perform, in the right order.
- **[2] Q11** — correct determination of whether a broken signing algorithm on an intermediate certificate still allows trust, with reasoning.
- **[3] Q12** — what root trust anchors are, how they get onto a computer, and what happens if they're all deleted.

---

## Part 7: The Exponential Wall — Password Salting — 12 pts

**Evidence — 2 pts**
- **[2]** full console-output screenshot, elapsed time and extra-hashes-computed count for the salted run boxed red.

**Analysis — 10 pts**
- **[3] Q13** — how a visible/public salt still defeats pre-computed rainbow-table attacks.
- **[3] Q14** — how a deliberately slow hash creates an online (availability) vulnerability even though it helps against offline attacks.
- **[4] Q15** — why GPUs (not CPUs) are used for password cracking, and how salting specifically reduces GPU cracking efficiency.

---

## Deduction summary

| Item | Effect |
|---|---|
| Missing required screenshot(s) | max-score cap per [`SCREENSHOT_PENALTY_POLICY.md`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/SCREENSHOT_PENALTY_POLICY.md) |
| Generic / example values instead of your own Student ID | −20 |
| Duplicate or tampered screenshot | −20 |
| Late | −20 per 24h, no submission after 48h ([`basicGradingRubric.md`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/basicGradingRubric.md)) |
| Cannot explain own submission when asked | integrity referral per [`guidelines.txt`](https://github.com/UNCC-FORTRESS/itis-3200-f26/blob/main/guidelines.txt) |
