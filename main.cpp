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
