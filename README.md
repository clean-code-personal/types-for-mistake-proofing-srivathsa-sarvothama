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

## This repo

Here, we try switching a few parts of the code to the functional paradigm.

We've made the Image class immutable - it can be initialized, but not modified.
Automatically, it becomes impossible to make the previous assignment's mistake: We cannot alter `imageToAdd` after it has been initialized.
This is one example of mistake-proofing

We've also made the brightener functionality in a couple of functions. The class was keeping state (data member) only for the sake of one function

## Your assignment

- Add `const` in every opportunity, including the member functions of `Image`
- The call to `StoreImageAnalytics` has a mistake - it's passing the brightened image instead of the raw image. Try making the "brightened image" as a different class, to catch this error at compile time, then fix it.
- `AddBrighteningImage` was returning a `bool` to indicate success or failure. Now it returns the brightened image. In general, exceptions are better for expressing errors, than return values. Try throwing an exception in case of failure.
