#### Intro

CPX is an attempt to let programmers write HTML like code within C++ not unlike how you can write JSX within JS files

The CPX code is actual legitimate C++ that gets parsed by the compiler and generates an object representing your DOM tree

The magic is achieved through some tricky and perverse operator overloading.

Example:

```
  #include <iostream>
  #include "cpx.h"

  CPX_PLACEHOLDER(_);
  CPX_ELEM(DIV);
  CPX_ELEM(P);

  int main()
  {
    CPX cpx;

    cpx
        <DIV> _
          <P>"Hello world"<_/P>_
          <P>(2 * 3 / 5.0F)<_/P>_
          <P>"Hell world"<_/P>_
        <_/DIV> 
    _;

    cpx.root->dump();
  }
```

As you can see, we are forced to use some noise symbol like "_" but you can easily transform regular HTML into this form deterministically

---


#####  Motivation, benefits and caveats

The overall idea for CPX is to make it possible to do in C++ what JSX does in JS
Compile time verified XML-ish dialect that generates a multiway tree of node objects.


The benefits:
 * Write HTML templating in C++ 
 * Avoid "Stringly typed" HTML literals

The caveats:
 * Work in progress, anything may change
 * The possible syntax (and future extension) is limited by whats legal C++ (We don't use macros in the expression)


#####  Future plans

 * Provide a way to add properties 
 * Implement a tree diffing algorithm
 * Build with emscripten to use on the browser
 

 
 
 
