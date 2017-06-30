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
  <DIV .id("root") [STYLE .height(20) .width(100) .display(inline_) ] > _
      <P>"Hello world"<_/P>_
      <DIV>_
        <P [STYLE .color(BLUE)] >"Hell world"<_/P>_
      <_/DIV>_
    <_/DIV> 
  _;

  cpx.root->dump();
}
