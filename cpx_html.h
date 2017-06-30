#pragma once
#include "cpx.h"
#include "cpx_html_types.h"
#include "cpx_html_style.h"

// Styled element
// <DIV [STYLE.height(20) .width(100)] .id("main") > _
struct CPXStyledElem: CPXElem
{
  map<string, string> css;
  
  CPXStyledElem(const char *pszTag): CPXElem(pszTag) {}
  
  // Copy the style props, clear the style (since the may be reused later)
  CPXStyledElem &operator[](CPXStyle &style)
  {
    css.clear();
    css.swap(style.props);
    return *this;
  }
};

CPX &operator<(CPX &cpx, CPXStyledElem &e);

