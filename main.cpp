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
        <P> "Hello world" <_/P>_
        <P> (2 * 3 / 5.0F) <_/P>_
        <P> "Hell world" <_/P>_
      <_/DIV> 
  _;

  cpx.root->dump();
}
