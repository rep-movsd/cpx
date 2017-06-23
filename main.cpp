#include <iostream>
#include "cpx.h"

CPX_PLACEHOLDER(_);

// Example typed enum property
enum Color {red, green, blue, cyan, magenta, white};
MAKE_ENUM_NAMES(Color, ENUM_NAME(red), ENUM_NAME(green), ENUM_NAME(blue));
MAKE_OSTREAM_OP(Color);


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
