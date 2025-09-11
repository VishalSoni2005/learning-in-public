## Expression Evaluation – Complete Guide

1️⃣ Types of Expressions

# 1: There are three standard notations of expressions in computer science:

Infix Expression → Operators are written between operands.
Example: A + B \* C
Problem: Needs parentheses and precedence rules.

# 2: Prefix Expression (Polish Notation) → Operators are written before operands.

Example: + A _ B C (same as A + (B _ C))
Easy for machines, no parentheses required.

# 3: Postfix Expression (Reverse Polish Notation) → Operators are written after operands.

Example: A B C _ + (same as A + (B _ C))
Widely used in compilers, stack-based evaluation.

Expression: (A+B)*(C^D-E)^(F+G*H)-I
Final postfix (you'll see at the end): AB+CD^E-FGH*+^*I-

| Step |  Char   | Action                                           | Stack (bottom → top) | Postfix so far      |
| ---: | :-----: | :----------------------------------------------- | :------------------: | :------------------ |
|    1 |   `(`   | Push `(`                                         |         `(`          | ` `                 |
|    2 |   `A`   | Operand → append `A`                             |         `(`          | `A`                 |
|    3 |   `+`   | Push `+` (inside `(`)                            |        `( +`         | `A`                 |
|    4 |   `B`   | Operand → append `B`                             |        `( +`         | `AB`                |
|    5 |   `)`   | Pop until `(` → popped `+`, discard `(`          |       (empty)        | `AB+`               |
|    6 |   `*`   | Push `*`                                         |         `*`          | `AB+`               |
|    7 |   `(`   | Push `(`                                         |        `* (`         | `AB+`               |
|    8 |   `C`   | Operand → append `C`                             |        `* (`         | `AB+C`              |
|    9 |   `^`   | Push `^` (right-associative → don't pop equals)  |       `* ( ^`        | `AB+C`              |
|   10 |   `D`   | Operand → append `D`                             |       `* ( ^`        | `AB+CD`             |
|   11 |   `-`   | Pop `^` (higher prec) then push `-`              |       `* ( -`        | `AB+CD^`            |
|   12 |   `E`   | Operand → append `E`                             |       `* ( -`        | `AB+CD^E`           |
|   13 |   `)`   | Pop until `(` → popped `-`, discard `(`          |         `*`          | `AB+CD^E-`          |
|   14 |   `^`   | Push `^`                                         |        `* ^`         | `AB+CD^E-`          |
|   15 |   `(`   | Push `(`                                         |       `* ^ (`        | `AB+CD^E-`          |
|   16 |   `F`   | Operand → append `F`                             |       `* ^ (`        | `AB+CD^E-F`         |
|   17 |   `+`   | Push `+`                                         |      `* ^ ( +`       | `AB+CD^E-F`         |
|   18 |   `G`   | Operand → append `G`                             |      `* ^ ( +`       | `AB+CD^E-FG`        |
|   19 |   `*`   | Push `*` (higher than `+`, so `+` not popped)    |     `* ^ ( + *`      | `AB+CD^E-FG`        |
|   20 |   `H`   | Operand → append `H`                             |     `* ^ ( + *`      | `AB+CD^E-FGH`       |
|   21 |   `)`   | Pop until `(` → popped `*` then `+`, discard `(` |        `* ^`         | `AB+CD^E-FGH*+`     |
|   22 |   `-`   | Pop `^` then `*` (both higher) then push `-`     |         `-`          | `AB+CD^E-FGH*+^*`   |
|   23 |   `I`   | Operand → append `I`                             |         `-`          | `AB+CD^E-FGH*+^*I`  |
|   24 | **END** | Pop remaining operators → popped `-`             |       (empty)        | `AB+CD^E-FGH*+^*I-` |

👉 Key point:
If stack top has higher precedence → pop.
If stack top has equal precedence →
For left-associative operators (+, -, \*, /): pop.
For right-associative operator (^): don’t pop.
