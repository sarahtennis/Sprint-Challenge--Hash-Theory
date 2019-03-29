# Theory of Computation Sprint Challenge

## Computation

Fill out truth tables for the following expressions:

1. `(A ∨ ¬B)`   (alternate: `(A || !B)`)
```
A     B     result
-------------------
0     0       1
0     1       0
1     0       1
1     1       1
```

2. `(¬A ∨ B) ∧ ¬(A ∧ ¬B)`   (alternate: `(!A || B) && !(A && !B)`)
```
A     B     result
-------------------
0     0       1
0     1       1
1     0       0
1     1       1
```

3. `¬(A ∨ B) ∨ ( (A ∨ C) ∧ ¬(B ∨ ¬C) )`   (alternate: `!(A || B) || ( (A || C) && !(B || !C) )`)
  * (Hint: Is it possible to calculate this using code?)

<!-- 
for x in [True, False]:
  for y in [True, False]:
    for z in [True, False]:
      print(x, y, z, not (x or y) or ( (x or z) and not (y or not z))); 
      
True True True False
True True False False
True False True True
True False False False
False True True False
False True False False
False False True True
False False False True 
  -->

```
A     B     C     result
-------------------------
0     0     0       1
0     0     1       1
0     1     0       0
0     1     1       0
1     0     0       0
1     0     1       1
1     1     0       0
1     1     1       0
```

## STRETCH GOAL

The sum of two binary digits can be represented with the following truth table:

* A + B
```
A     B     CARRY   SUM
------------------------
0     0       0      0
0     1       0      1
1     0       0      1
1     1       1      0
```
This can be represented with boolean algebra like so:

* `SUM = A ⊕ B`  (alternate: `A ^ B` or `A xor B`)
* `CARRY = A ∧ B`  (alternate: `A && B`)

#### NOTES
- XOR 2 -> (A && ~B) || (B && ~A)
- XOR 3 -> (((A && ~B) || (B && ~A)) && ~C) || (C && ~((A && ~B) || (B && ~A)))
- Sum only true if odd number of 1s. (exclusively 1 of them, or all of them)
- Carry only true if 2+ number of 1s

```
for x in [False, True]:
  for y in [False, True]:
    for z in [False, True]:
      print(x, y, z, (x and y) or (y and z) or (x and z))

for x in [False, True]:
  for y in [False, True]:
    for z in [False, True]:
      print(x, y, z, (((x and not y) or (y and not x)) and not z) or (z and not ((x and not y) or (y and not x))))
```

How can you represent the SUM and CARRY of adding THREE digits with a truth table and in boolean algebra?

* A + B + C
```
A     B     C      carry   sum
--------------------------------
0     0     0        0      0
0     0     1        0      1
0     1     0        0      1
0     1     1        1      0
1     0     0        0      1
1     0     1        1      0
1     1     0        1      0
1     1     1        1      1
```
* SUM = ( A xor B ) xor C
* CARRY = (A && B) || (B && C) || (A && C)
