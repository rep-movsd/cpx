#### Intro

CPX is an attempt to let programmers write HTML like code within C++ not unlike how you can write JSX within JS files

The CPX code is actual legitimate C++ that gets parsed by the compiler and generates an object representing your DOM tree

The magic is achieved through some tricky and perverse operator overloading.

Example:

```cpp
#include <iostream>
#include "cpx.h"
#include "cpx_html.h"

CPX_PLACEHOLDER(_);

// Lets define a couple of tags with typed properties
STYLEDTAG(DivTag) 
{ 
  STYLEDTAGNAME(DivTag, "div");
  PROP(string, id);
};
STYLEDTAG(PTag) { STYLEDTAGNAME(PTag, "p");};

DivTag DIV;
PTag P;

///////////////////////////////////////////

struct CPXStyle STYLE;

int main()
{
  CPX cpx;

  cpx
    <DIV .id("root") (STYLE .height(20) .width(100)) > _
      <P>"Hello world"<_/P>_
      <DIV>_
        <P (STYLE .color(BLUE)) >"Hell world"<_/P>_
      <_/DIV>_
    <_/DIV> 
  _;

  cpx.root->dump();
}
```

As you can see, we are forced to use some noise symbol like "_" but you can easily transform regular HTML into this form deterministically

This program produces the following output:
```
rep ~/projects/cpx * master $ g++ main.cpp cpx_html.cpp
rep ~/projects/cpx * master $ ./a.out
<div id='root' style='height:20;width:100;'>
  <p style='color:BLUE;'>
    Hello world
  </p>
  <div>
    <p>
      Hell world
    </p>
  </div>
</div>
```
Is that neat or what?

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

 * Implement a tree diffing algorithm
 * Build with emscripten to use on the browser
 * Add standard attributes for css styles and HTML elements
 

 
 
 
