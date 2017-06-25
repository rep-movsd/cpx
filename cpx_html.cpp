#include "cpx_html.h"

// Helper for enum with string names
#define ENUM(x) {x, #x}
#define MAKE_ENUM_NAMES(T, ...) map<T, string> T ## Names = { __VA_ARGS__ }
#define MAKE_OSTREAM_OP(T) ostream& operator<<(ostream& os, const T& c) { os << T ## Names[c];  return os;  }


MAKE_ENUM_NAMES
(
  HTMLColor, 
 ENUM(BLACK), 
 ENUM(NAVY), 
 ENUM(DARKBLUE), 
 ENUM(MEDIUMBLUE), 
 ENUM(BLUE), 
 ENUM(DARKGREEN), 
 ENUM(GREEN), 
 ENUM(TEAL), 
 ENUM(DARKCYAN), 
 ENUM(DEEPSKYBLUE), 
 ENUM(DARKTURQUOISE), 
 ENUM(MEDIUMSPRINGGREEN), 
 ENUM(LIME), 
 ENUM(SPRINGGREEN), 
 ENUM(AQUA), 
 ENUM(CYAN), 
 ENUM(MIDNIGHTBLUE), 
 ENUM(DODGERBLUE), 
 ENUM(LIGHTSEAGREEN), 
 ENUM(FORESTGREEN), 
 ENUM(SEAGREEN), 
 ENUM(DARKSLATEGRAY), 
 ENUM(LIMEGREEN), 
 ENUM(MEDIUMSEAGREEN), 
 ENUM(TURQUOISE), 
 ENUM(ROYALBLUE), 
 ENUM(STEELBLUE), 
 ENUM(DARKSLATEBLUE), 
 ENUM(MEDIUMTURQUOISE), 
 ENUM(INDIGO), 
 ENUM(DARKOLIVEGREEN), 
 ENUM(CADETBLUE), 
 ENUM(CORNFLOWERBLUE), 
 ENUM(REBECCAPURPLE), 
 ENUM(MEDIUMAQUAMARINE), 
 ENUM(DIMGRAY), 
 ENUM(SLATEBLUE), 
 ENUM(OLIVEDRAB), 
 ENUM(SLATEGRAY), 
 ENUM(LIGHTSLATEGRAY), 
 ENUM(MEDIUMSLATEBLUE), 
 ENUM(MEDIUMSLATEBLUE), 
 ENUM(LAWNGREEN), 
 ENUM(CHARTREUSE), 
 ENUM(AQUAMARINE), 
 ENUM(MAROON), 
 ENUM(PURPLE), 
 ENUM(OLIVE), 
 ENUM(GRAY), 
 ENUM(SKYBLUE), 
 ENUM(LIGHTSKYBLUE), 
 ENUM(BLUEVIOLET), 
 ENUM(DARKRED), 
 ENUM(DARKMAGENTA), 
 ENUM(SADDLEBROWN), 
 ENUM(DARKSEAGREEN), 
 ENUM(LIGHTGREEN), 
 ENUM(MEDIUMPURPLE), 
 ENUM(DARKVIOLET), 
 ENUM(PALEGREEN), 
 ENUM(DARKORCHID), 
 ENUM(YELLOWGREEN), 
 ENUM(SIENNA), 
 ENUM(BROWN), 
 ENUM(DARKGRAY), 
 ENUM(LIGHTBLUE), 
 ENUM(GREENYELLOW), 
 ENUM(PALETURQUOISE), 
 ENUM(LIGHTSTEELBLUE), 
 ENUM(POWDERBLUE), 
 ENUM(FIREBRICK), 
 ENUM(DARKGOLDENROD), 
 ENUM(MEDIUMORCHID), 
 ENUM(ROSYBROWN), 
 ENUM(DARKKHAKI), 
 ENUM(SILVER), 
 ENUM(MEDIUMVIOLETRED), 
 ENUM(INDIANRED), 
 ENUM(PERU), 
 ENUM(CHOCOLATE), 
 ENUM(TAN), 
 ENUM(LIGHTGRAY), 
 ENUM(THISTLE), 
 ENUM(ORCHID), 
 ENUM(GOLDENROD), 
 ENUM(PALEVIOLETRED), 
 ENUM(CRIMSON), 
 ENUM(GAINSBORO), 
 ENUM(PLUM), 
 ENUM(BURLYWOOD), 
 ENUM(LIGHTCYAN), 
 ENUM(LAVENDER), 
 ENUM(DARKSALMON), 
 ENUM(VIOLET), 
 ENUM(PALEGOLDENROD), 
 ENUM(LIGHTCORAL), 
 ENUM(KHAKI), 
 ENUM(ALICEBLUE), 
 ENUM(HONEYDEW), 
 ENUM(AZURE), 
 ENUM(SANDYBROWN), 
 ENUM(WHEAT), 
 ENUM(BEIGE), 
 ENUM(WHITESMOKE), 
 ENUM(MINTCREAM), 
 ENUM(GHOSTWHITE), 
 ENUM(SALMON), 
 ENUM(ANTIQUEWHITE), 
 ENUM(LINEN), 
 ENUM(LIGHTGOLDENRODYELLOW), 
 ENUM(OLDLACE), 
 ENUM(RED), 
 ENUM(FUCHSIA), 
 ENUM(MAGENTA), 
 ENUM(DEEPPINK), 
 ENUM(ORANGERED), 
 ENUM(TOMATO), 
 ENUM(HOTPINK), 
 ENUM(CORAL), 
 ENUM(DARKORANGE), 
 ENUM(LIGHTSALMON), 
 ENUM(LIGHTSALMON), 
 ENUM(ORANGE), 
 ENUM(LIGHTPINK), 
 ENUM(PINK), 
 ENUM(GOLD), 
 ENUM(PEACHPUFF), 
 ENUM(NAVAJOWHITE), 
 ENUM(MOCCASIN), 
 ENUM(BISQUE), 
 ENUM(MISTYROSE), 
 ENUM(BLANCHEDALMOND), 
 ENUM(PAPAYAWHIP), 
 ENUM(LAVENDERBLUSH), 
 ENUM(SEASHELL), 
 ENUM(CORNSILK), 
 ENUM(LEMONCHIFFON), 
 ENUM(FLORALWHITE), 
 ENUM(SNOW), 
 ENUM(YELLOW), 
 ENUM(LIGHTYELLOW), 
 ENUM(IVORY), 
 ENUM(WHITE)
);

MAKE_OSTREAM_OP(HTMLColor);

CPX &operator<(CPX &cpx, CPXStyledElem &e)
{
  cpx.addTag(e);
  cpx.current->css.swap(e.css);
  return cpx;
}