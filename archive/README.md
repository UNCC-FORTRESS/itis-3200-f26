# Archive — retired labs and extra tools not tied to a graded lab

Two different kinds of thing live here. Most of this folder is tools built for earlier versions of some labs, before the labs settled into their current form — kept because the tools themselves are solid, and several make good starting points if you're doing a course project. But `Lab03_AuthEncryption_DH_MITM/` and `Lab04_RSA_Certs_PasswordSalting/` are different: those are the **full, real, previously-assigned labs**, retired here wholesale because `../Lab04Final/` now consolidates and replaces both. Nothing wrong with either one — they just aren't the assigned version anymore.

| Folder | What it's about, and where the real content ended up |
|---|---|
| `Lab03_AuthEncryption_DH_MITM/` | **Superseded, not never-shipped.** The full former Lab 03 (9-scheme authenticated-encryption analysis, Diffie-Hellman/PRNG rollback, the Mallory MITM programming assignment) — its content now lives in `../Lab04Final/` (schemes trimmed from 9 to 6). |
| `Lab04_RSA_Certs_PasswordSalting/` | **Superseded, not never-shipped.** The full former Lab 04 (RSA encrypt/sign/verify, hybrid encryption, certificate chain-of-trust theory, password-salting) — its content now lives in `../Lab04Final/`. |
| `Lab03_HashesMACs/` | Hashes/MACs tools (`HashLab.html`, `MiniHashCollider.html`) from an early lab-3 design. That ground is now covered by `../Lab_HashingMAC/` (hashing/MAC) and `../Lab04Final/` (the schemes). |
| `Lab03_05_MegaLab/` | A combined ledger/key-exchange/messenger tool set (`LedgerLab.html`, `KeyExchangeSim.html`, `CryptoMessenger.html`) covering similar ground to the folder above. |
| `Lab04_PRNG_DH/` | Diffie-Hellman/PRNG tools. That material now ships as **part of `../Lab04Final/`**. |
| `Lab05_RSA/` | RSA tools (`RSACalc.html`, `RSALab.html`). RSA now ships as **part of `../Lab04Final/`** instead, via CyberChef. |
| `Lab06_CertsPasswords/` | Certificate-authority and password-cracking tools (`CertAuthorityTool.html`, `CertLab.html`, `CrackLab.html`, `HashCracker.html`). This material appears as written questions inside **`../Lab04Final/`**. These are good optional interactive supplements if you want more hands-on practice with that section. |
| `Lab07_AccessControl/` | An RBAC/ABAC access-control tool (`AccessControlSim.html`). The real Lab 05 uses the Bell-LaPadula model instead — see `../Lab05_AccessControl_BLP/`. Still a neat contrast if you're interested in comparing access-control models for a project. |
| `Lab08_WebIntro/` | Cookie/CSRF tools (`CookieShop.html`, `CSRF_Simulation.html`, `WebLab.html`). This material appears in **Lab 05**'s origin/cookie/CSRF questions, with hands-on exploitation in **Lab 06**'s DVWA exercise. Good optional supplements for Lab 05. |
| `Lab09_WebAttacks/` | An earlier XSS/SQLi tool design — `Lab09_XSS_SQLi/` at the top level has more variants and a dedicated SQLi tool, so that one's the one to use. |
| `Lab10_DoS_Firewalls/` | An earlier DoS/firewalls tool design — `Lab10_NetworkSecurity/` at the top level has a richer multi-stage attack scenario, so that one's the one to use. |

**Also worth a look, at the top level (not archived, no numbering conflict with anything):** `Lab09_XSS_SQLi/`, `Lab10_NetworkSecurity/`, `Lab11_IDS/`, `Lab12_MemoryVulns/`, `Lab13_SystemExecution/` — fully built, not part of the graded sequence, and good material if you're looking for a project starting point.
