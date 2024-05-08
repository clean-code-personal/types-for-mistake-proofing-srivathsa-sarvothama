# Use data-types to mistake-proof

One of the strengths about C++ is strong typing. Mistakes with data-types _can be_ caught at compile-time, without even having to run the code. Think of mistakes such as:
- calling a function with the wrong parameters
- comparing a string and an integer

## Concepts

### Immutability

Declaring something as `const` indicates that it's a different type than the 'regular' types. It can only be initialized, not changed.

Features of immutable types:
- No sync issues in a multi-threaded environment
- No accidental change of state = fewer "non-reproducible" issues
- Easier to share references, especially using `shared_ptr`

### Functional paradigm

A function maps one type to another. For instance, image-compression maps a "raw image" to a "compressed image". Pure functions stick to mapping, without side-effects. Once they are proven, they will "always work".

### Type safety

We could use a native type, such as an array of bytes to keep both "raw image" and "compressed image". Now consider a function that displays a raw image - it would accept an array of bytes. However, we could accidentally pass a compressed image to it, and we would know the mistake only when we run it.

On the other hand, consider separate classes such as `RawImage` and `CompressedImage` and the display function accepted `RawImage`. Then any accidental function-call with `CompressedImage` in it would result in a compiler error, or even a red-squiggly in the IDE.

### Putting it together

Pure functions can be proven by unit-testing. When their output is treated as immutable, it will not change - so we don't need to track their state through our program-flow. Use of strong types helps the compiler to catch issues before the code is run = mistake-proofing.

Overall, it leads to lesser code and lower bugs.

## This assignment

TBD
