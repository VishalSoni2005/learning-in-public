# 🧭 Eulerian Path & Circuit – Quick Notes

## 🔑 Definitions

- **Eulerian Path** → A path that visits every **edge exactly once**.
- **Eulerian Circuit** → An Eulerian Path that **starts and ends at the same vertex**.

---

## ✅ Rules (Undirected Graph)

1. **Eulerian Circuit** exists if:

   - Graph is **connected** (ignoring isolated vertices), AND
   - **All vertices have even degree**.

2. **Eulerian Path (not circuit)** exists if:

   - Graph is **connected**, AND
   - **Exactly 2 vertices** have odd degree.
   - Path starts at one odd-degree vertex and ends at the other.

3. Otherwise → **No Eulerian Path or Circuit**.

---

## 🧮 Quick Checks

- Count vertices with **odd degree**:

  - `0` → Eulerian Circuit
  - `2` → Eulerian Path
  - `>2` → Neither

- Graph must be **connected** (ignoring isolated vertices).
- Special Case: Graph with **no edges** → Eulerian Circuit (trivial).

---

## ⚡ Interview / Contest Patterns

- **Check existence** → return `0` (none), `1` (path), `2` (circuit).
- **Find actual path/circuit** → Use **Hierholzer’s Algorithm** (DFS-based).
- **Trick Qs**:
  - Disconnected graph? → No Eulerian Path/Circuit.
  - Graph with only isolated vertices? → Eulerian Circuit.

---

## 📝 One-Liner

**“Eulerian Path = ≤ 2 odd vertices, Eulerian Circuit = 0 odd vertices, but graph must be connected.”**
