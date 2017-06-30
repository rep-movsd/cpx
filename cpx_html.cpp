#include "cpx_html.h"

CPX &operator<(CPX &cpx, CPXStyledElem &e)
{
  cpx.addTag(e);
  cpx.current->css.swap(e.css);
  return cpx;
}

// Defines user literal operators to construct wrapper types 
// eg 10_pct makes a PercentI object
// These wrapper types write a string suffix like % when sent to ostream
// See MAKE_SUFFIXED_TYPE 
MAKE_SUFFIXED_LIT_OP(Length, Percent, ldouble, pct);
MAKE_SUFFIXED_LIT_OP(Length, Pixels, llong, px);
MAKE_SUFFIXED_LIT_OP(Length, Picas, ldouble, pc);
MAKE_SUFFIXED_LIT_OP(Length, Points, ldouble, pt);
MAKE_SUFFIXED_LIT_OP(Length, Inches, ldouble, in);
MAKE_SUFFIXED_LIT_OP(Length, Millimeters, ldouble, mm);
MAKE_SUFFIXED_LIT_OP(Length, Centimeters, ldouble, cm);

// Helper for enum with string names
#define ENUM(x)  {x, #x}
#define MAKE_ENUM_NAMES(T, ...) map<T, string> T ## Names =  { __VA_ARGS__ }
#define MAKE_OSTREAM_OP(T) ostream& operator<<(ostream& os, const T& c)  { os << T ## Names[c];  return os;  }

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

/*
 < absoluteSize> <absolu*teSize>("<absolute-size>");
 <angle> <angle>("<angle>");
 <borderStyle> <borderStyle>("<border-style>");
 <borderStyle>{1,4} <borderStyle>{1,4}("<border-style>{1,4}");
 <borderWidth> <borderWidth>("<border-width>");
 <borderWidth>{1,4} <borderWidth>{1,4}("<border-width>{1,4}");
 <color> <color>("<color>");
 <frequency> <frequency>("<frequency>");
 <integer> <integer>("<integer>");
 <length> <length>("<length>");
 <length> <length>? <length> <length>?("<length> <length>?");
 <marginWidth> <marginWidth>("<margin-width>");
 <marginWidth>{1,4} <marginWidth>{1,4}("<margin-width>{1,4}");
 <number> <number>("<number>");
 <paddingWidth> <paddingWidth>("<padding-width>");
 <paddingWidth>{1,4} <paddingWidth>{1,4}("<padding-width>{1,4}");
 <percentage> <percentage>("<percentage>");
 <relativeSize> <relativeSize>("<relative-size>");
 <shape> <shape>("<shape>");
 <time> <time>("<time>");
 <uri> <uri>("<uri>");
 */

Fw100 fw100("100");
Fw200 fw200("200");
Fw300 fw300("300");
Fw400 fw400("400");
Fw500 fw500("500");
Fw600 fw600("600");
Fw700 fw700("700");
Fw800 fw800("800");
Fw900 fw900("900");
Above above("above");
Absolute absolute("absolute");
Always always("always");
Armenian armenian("armenian");
Auto auto_("auto");
Avoid avoid("avoid");
Baseline baseline("baseline");
Below below("below");
BidiOverride bidiOverride("bidi-override");
Block block("block");
Bold bold("bold");
Bolder bolder("bolder");
Both both("both");
Bottom bottom("bottom");
Capitalize capitalize("capitalize");
Center center("center");
Circle circle("circle");
Code code("code");
Collapse collapse("collapse");
Continuous continuous("continuous");
Decimal decimal("decimal");
DecimalLeadingZero decimalLeadingZero("decimal-leading-zero");
Digits digits("digits");
Disc disc("disc");
Embed embed("embed");
Fast fast("fast");
Faster faster("faster");
Fixed fixed("fixed");
Georgian georgian("georgian");
Hidden hidden("hidden");
Hide hide("hide");
High high("high");
Higher higher("higher");
Inherit inherit("inherit");
Inline inline_("inline");
InlineBlock inlineBlock("inline-block");
InlineTable inlineTable("inline-table");
Inside inside("inside");
Invert invert("invert");
Italic italic("italic");
Justify justify("justify");
Left left("left");
Level level("level");
Lighter lighter("lighter");
ListItem listItem("list-item");
Loud loud("loud");
Low low("low");
Lower lower("lower");
LowerAlpha lowerAlpha("lower-alpha");
LowerGreek lowerGreek("lower-greek");
LowerLatin lowerLatin("lower-latin");
LowerRoman lowerRoman("lower-roman");
Lowercase lowercase("lowercase");
Ltr ltr("ltr");
Medium medium("medium");
Middle middle("middle");
NoRepeat noRepeat("no-repeat");
None none("none");
Normal normal("normal");
Nowrap nowrap("nowrap");
Oblique oblique("oblique");
Once once("once");
Outside outside("outside");
Pre pre("pre");
PreLine preLine("pre-line");
PreWrap preWrap("pre-wrap");
Relative relative("relative");
Repeat repeat("repeat");
RepeatX repeatX("repeat-x");
RepeatY repeatY("repeat-y");
Right right("right");
Rtl rtl("rtl");
Scroll scroll("scroll");
Separate separate("separate");
Show show("show");
Silent silent("silent");
Slow slow("slow");
Slower slower("slower");
SmallCaps smallCaps("small-caps");
Soft soft("soft");
SpellOut spellOut("spell-out");
Square square("square");
Static static_("static");
Sub sub("sub");
Super super("super");
Table table("table");
TableCaption tableCaption("table-caption");
TableCell tableCell("table-cell");
TableColumn tableColumn("table-column");
TableColumnGroup tableColumnGroup("table-column-group");
TableFooterGroup tableFooterGroup("table-footer-group");
TableHeaderGroup tableHeaderGroup("table-header-group");
TableRow tableRow("table-row");
TableRowGroup tableRowGroup("table-row-group");
TextBottom textBottom("text-bottom");
TextTop textTop("text-top");
Top top("top");
Transparent transparent("transparent");
UpperAlpha upperAlpha("upper-alpha");
UpperLatin upperLatin("upper-latin");
UpperRoman upperRoman("upper-roman");
Uppercase uppercase("uppercase");
Visible visible("visible");
XFast xFast("x-fast");
XHigh xHigh("x-high");
XLoud xLoud("x-loud");
XLow xLow("x-low");
XSlow xSlow("x-slow");
XSoft xSoft("x-soft");