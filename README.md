#### Intro

CPX is an attempt to let programmers write HTML like code within C++ not unlike how you can write JSX within JS files

The CPX code is actual legitimate C++ that gets parsed by the compiler and generates an object representing your DOM tree

The magic is achieved through some tricky and perverse operator overloading.

Example:

```cpp
#include <iostream>
#include "cpx.h"

CPX_PLACEHOLDER(_);

// Example typed properties
enum Color {red, green, blue, cyan, magenta, white};

ostream& operator<<(ostream& os, const Color& c)  
{  
  static map<Color, string> names = 
  {  
    MAKE_ENUM_NAME(red), 
    MAKE_ENUM_NAME(green), 
    MAKE_ENUM_NAME(blue), 
    MAKE_ENUM_NAME(cyan), 
    MAKE_ENUM_NAME(magenta), 
    MAKE_ENUM_NAME(white)
  };
  
  os << names[c];  
  return os;  
}  


// Lets define a couple of tags with typed properties
TAG(DivTag)
{
  TAGNAME(DivTag, "div");
  PROP(int, height);
  PROP(int, width);
};

DivTag DIV;


TAG(PTag)
{
  TAGNAME(PTag, "p");
  PROP(Color, color);
};

PTag P;

///////////////////////////////////////////


int main()
{
  CPX cpx;

  cpx
    <DIV .height(20) .width(100)> _
      <P>"Hello world"<_/P>_
      <DIV .width(70) >_
        <P .color(blue) >(2 * 3 / 5.0F)<_/P>_
        <P>"Hell world"<_/P>_
      <_/DIV>_
    <_/DIV> 
  _;

  cpx.root->dump();
}

```

As you can see, we are forced to use some noise symbol like "_" but you can easily transform regular HTML into this form deterministically

This program produces the following output:
```
$ ./a.out
<div height='20' width='100'>
  <p color='blue'>
    Hello world
  </p>
  <div>
    <p>
      1.2
    </p>
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
 

 
 
 
