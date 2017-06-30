#pragma once
#include "cpx.h"
#include "cpx_html_types.h"

struct CPXStyle
{
  map<string, string> props;
  
  #define MAKE_STYLE_PROP(T, PROPNAME) CPXStyle &PROPNAME(const T &val) { ostringstream oss; oss << val; props[#PROPNAME] = oss.str(); return *this;} 
  MAKE_STYLE_PROP(HTMLColor, color);
  MAKE_STYLE_PROP(int, height);
  MAKE_STYLE_PROP(int, width);

  #define MAKE_STYLE_PROP_ATTR(FNNAME, ATTR, PROPCSS)                 \
  CPXStyle &FNNAME(CpxAttrs::ATTR &val)                               \
  {                                                                   \
    ostringstream oss;                                                \
    oss << static_cast<CpxAttrGroup<CpxAttrs::ATTR>&>(val).name();    \
    props[PROPCSS] = oss.str();                                       \
    return *this;                                                     \
  }                                              

  MAKE_STYLE_PROP_ATTR(display, Display, "display");
  
  /*CPXStyle& display(CpxAttrs::Display &val)
  {
    ostringstream oss;
    oss << static_cast<CpxAttrGroup<CpxAttrs::Display>&>(val).name();
    props["display"] = oss.str();                  
    return *this;                               
  }*/
  
//  void attrH(Horz &h) { std::cout << static_cast<MakeFrom<Horz>&>(h).name() << std::endl; } 
  
  
  
};

