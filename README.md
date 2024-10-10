# cpp02

---

## fixed point numbers

(considering base-2)

### What are Fixed-Point Numbers in Base 2?

Just like in decimal (base 10), fixed-point numbers in binary (base 2) have a fixed number of bits for the integer part and a fixed number of bits for the fractional part.

### Why Use Binary?

Computers use binary because it's efficient for processing. Each bit can be either 0 or 1, making it straightforward to work with.

### Structure of a Fixed-Point Number

Let's say we want to represent a fixed-point number with:
+ 4 bits for the integer part
+ 4 bits for the fractional part

So, the overall format would look something like this:
```
IIII.FFFF
```

Where:
+ IIII is the integer part (4 bits)
+ FFFF is the fractional part (4 bits)

### How It Works:
+ Integer Part: The 4 bits can represent numbers from 0 to 2⁴ - 1 (which is 15 in decimal).
  + Examples:
    + 0000 (0)
    + 0001 (1)
    + 1111 (15)

+ Fractional Part: The 4 bits can represent fractions that are powers of 1/2
  + Examples:
    + 0000 (0.0)
    + 0001 (0.0625, which is 1/16)
    + 1111 (0.9375, which is 15/16)

### Putting It Together
If we wanted to represent the decimal number 3.25 in this fixed-point format:

+ Integer Part:
  + 3 in binary is 0011 (3 fits within 4 bits).
+ Fractional Part:
  + 0.25 in binary is 0100 (since = 1/4 and 1/4 = 4/16)

So, 3.25 would be represented as:

```
0011.0100
```

### Reading a Fixed-Point Number

To convert 0011.0100 back to decimal:

+ Integer Part: 0011 = 3
+ Fractional Part:0100 = (0 * 1/2) + (1 * 1/4) + (0 * 1/8) + (0 * 1/16) = 0.25

Adding these together -> 3 + 0.25 = 3.25

### Limitations

+ Range: The maximum you can represent with 4 bits for the integer part is 15, so you can’t represent numbers larger than that.
+ Precision: You can only represent fractions that can be expressed within 4 bits after the decimal point, limiting how precise your values can be.