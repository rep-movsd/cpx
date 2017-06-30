#pragma once
#include "cpx.h"

// Helpers for defining tags which have styles
#define STYLEDTAG(CLASSNAME) struct CLASSNAME : public CPXStyledElem
#define STYLEDTAGNAME(CLASSNAME, TAGNAME) CLASSNAME():CPXStyledElem(TAGNAME) {} typedef CLASSNAME THISCLASS

// HTML colors
enum HTMLColor 
{
  BLACK=0x000000, 
  NAVY=0x000080, 
  DARKBLUE=0x00008B, 
  MEDIUMBLUE=0x0000CD, 
  BLUE=0x0000FF, 
  DARKGREEN=0x006400, 
  GREEN=0x008000, 
  TEAL=0x008080, 
  DARKCYAN=0x008B8B, 
  DEEPSKYBLUE=0x00BFFF, 
  DARKTURQUOISE=0x00CED1, 
  MEDIUMSPRINGGREEN=0x00FA9A, 
  LIME=0x00FF00, 
  SPRINGGREEN=0x00FF7F, 
  AQUA=0x00FFFF, 
  CYAN=0x00FFFF, 
  MIDNIGHTBLUE=0x191970, 
  DODGERBLUE=0x1E90FF, 
  LIGHTSEAGREEN=0x20B2AA, 
  FORESTGREEN=0x228B22, 
  SEAGREEN=0x2E8B57, 
  DARKSLATEGRAY=0x2F4F4F, 
  LIMEGREEN=0x32CD32, 
  MEDIUMSEAGREEN=0x3CB371, 
  TURQUOISE=0x40E0D0, 
  ROYALBLUE=0x4169E1, 
  STEELBLUE=0x4682B4, 
  DARKSLATEBLUE=0x483D8B, 
  MEDIUMTURQUOISE=0x48D1CC, 
  INDIGO=0x4B0082, 
  DARKOLIVEGREEN=0x556B2F, 
  CADETBLUE=0x5F9EA0, 
  CORNFLOWERBLUE=0x6495ED, 
  REBECCAPURPLE=0x663399, 
  MEDIUMAQUAMARINE=0x66CDAA, 
  DIMGRAY=0x696969, 
  SLATEBLUE=0x6A5ACD, 
  OLIVEDRAB=0x6B8E23, 
  SLATEGRAY=0x708090, 
  LIGHTSLATEGRAY=0x778899, 
  MEDIUMSLATEBLUE=0x7B68EE, 
  LAWNGREEN=0x7CFC00, 
  CHARTREUSE=0x7FFF00, 
  AQUAMARINE=0x7FFFD4, 
  MAROON=0x800000, 
  PURPLE=0x800080, 
  OLIVE=0x808000, 
  GRAY=0x808080, 
  SKYBLUE=0x87CEEB, 
  LIGHTSKYBLUE=0x87CEFA, 
  BLUEVIOLET=0x8A2BE2, 
  DARKRED=0x8B0000, 
  DARKMAGENTA=0x8B008B, 
  SADDLEBROWN=0x8B4513, 
  DARKSEAGREEN=0x8FBC8B, 
  LIGHTGREEN=0x90EE90, 
  MEDIUMPURPLE=0x9370DB, 
  DARKVIOLET=0x9400D3, 
  PALEGREEN=0x98FB98, 
  DARKORCHID=0x9932CC, 
  YELLOWGREEN=0x9ACD32, 
  SIENNA=0xA0522D, 
  BROWN=0xA52A2A, 
  DARKGRAY=0xA9A9A9, 
  LIGHTBLUE=0xADD8E6, 
  GREENYELLOW=0xADFF2F, 
  PALETURQUOISE=0xAFEEEE, 
  LIGHTSTEELBLUE=0xB0C4DE, 
  POWDERBLUE=0xB0E0E6, 
  FIREBRICK=0xB22222, 
  DARKGOLDENROD=0xB8860B, 
  MEDIUMORCHID=0xBA55D3, 
  ROSYBROWN=0xBC8F8F, 
  DARKKHAKI=0xBDB76B, 
  SILVER=0xC0C0C0, 
  MEDIUMVIOLETRED=0xC71585, 
  INDIANRED=0xCD5C5C, 
  PERU=0xCD853F, 
  CHOCOLATE=0xD2691E, 
  TAN=0xD2B48C, 
  LIGHTGRAY=0xD3D3D3, 
  THISTLE=0xD8BFD8, 
  ORCHID=0xDA70D6, 
  GOLDENROD=0xDAA520, 
  PALEVIOLETRED=0xDB7093, 
  CRIMSON=0xDC143C, 
  GAINSBORO=0xDCDCDC, 
  PLUM=0xDDA0DD, 
  BURLYWOOD=0xDEB887, 
  LIGHTCYAN=0xE0FFFF, 
  LAVENDER=0xE6E6FA, 
  DARKSALMON=0xE9967A, 
  VIOLET=0xEE82EE, 
  PALEGOLDENROD=0xEEE8AA, 
  LIGHTCORAL=0xF08080, 
  KHAKI=0xF0E68C, 
  ALICEBLUE=0xF0F8FF, 
  HONEYDEW=0xF0FFF0, 
  AZURE=0xF0FFFF, 
  SANDYBROWN=0xF4A460, 
  WHEAT=0xF5DEB3, 
  BEIGE=0xF5F5DC, 
  WHITESMOKE=0xF5F5F5, 
  MINTCREAM=0xF5FFFA, 
  GHOSTWHITE=0xF8F8FF, 
  SALMON=0xFA8072, 
  ANTIQUEWHITE=0xFAEBD7, 
  LINEN=0xFAF0E6, 
  LIGHTGOLDENRODYELLOW=0xFAFAD2, 
  OLDLACE=0xFDF5E6, 
  RED=0xFF0000, 
  FUCHSIA=0xFF00FF, 
  MAGENTA=0xFF00FF, 
  DEEPPINK=0xFF1493, 
  ORANGERED=0xFF4500, 
  TOMATO=0xFF6347, 
  HOTPINK=0xFF69B4, 
  CORAL=0xFF7F50, 
  DARKORANGE=0xFF8C00, 
  LIGHTSALMON=0xFFA07A, 
  ORANGE=0xFFA500, 
  LIGHTPINK=0xFFB6C1, 
  PINK=0xFFC0CB, 
  GOLD=0xFFD700, 
  PEACHPUFF=0xFFDAB9, 
  NAVAJOWHITE=0xFFDEAD, 
  MOCCASIN=0xFFE4B5, 
  BISQUE=0xFFE4C4, 
  MISTYROSE=0xFFE4E1, 
  BLANCHEDALMOND=0xFFEBCD, 
  PAPAYAWHIP=0xFFEFD5, 
  LAVENDERBLUSH=0xFFF0F5, 
  SEASHELL=0xFFF5EE, 
  CORNSILK=0xFFF8DC, 
  LEMONCHIFFON=0xFFFACD, 
  FLORALWHITE=0xFFFAF0, 
  SNOW=0xFFFAFA, 
  YELLOW=0xFFFF00, 
  LIGHTYELLOW=0xFFFFE0, 
  IVORY=0xFFFFF0, 
  WHITE=0xFFFFFF, 
};

ostream& operator<<(ostream&, const HTMLColor&);


typedef long double ldouble;
typedef unsigned long long llong;

enum Units {Percent, Pixels, Picas, Points, Inches, Millimeters, Centimeters};

template<Units E> struct Suffix { constexpr static const char* suffix();};
template<Units E, typename T> struct Length
{
  T val;
  typedef Suffix<E> TheSuffix;
  Length(T val) : val(val) {};
};

template<Units E, typename T> ostream& operator<<(ostream& os, const Length<E, T> &val)  
{ 
  os << val.val << Length<E, T>::TheSuffix::suffix();  return os;  
}

#define MAKE_SUFFIXED_MEASURE(UNIT, MEASURE, TYPE, SUFFIX, SUFFIX_OP) \
template<> constexpr const char* Suffix<MEASURE>::suffix() { return SUFFIX;}; 

#define MAKE_SUFFIXED_LIT_OP(UNIT, MEASURE, TYPE, SUFFIX_OP) \
UNIT<MEASURE, TYPE> operator "" _ ## SUFFIX_OP(TYPE x){return UNIT<MEASURE, TYPE>(x);}

MAKE_SUFFIXED_MEASURE(Length, Percent, ldouble, "%", pct);
MAKE_SUFFIXED_MEASURE(Length, Pixels, llong, "px", pct);
MAKE_SUFFIXED_MEASURE(Length, Picas, ldouble, "pc", pct);
MAKE_SUFFIXED_MEASURE(Length, Points, ldouble, "pt", pct);
MAKE_SUFFIXED_MEASURE(Length, Inches, ldouble, "in", pct);
MAKE_SUFFIXED_MEASURE(Length, Millimeters, ldouble, "mm", pct);
MAKE_SUFFIXED_MEASURE(Length, Centimeters, ldouble, "cm", pct);

template <typename ...BaseClasses>
struct CpxAttrGroup : public BaseClasses... 
{  
  const char* name_;
  const char * name() const { return name_;}
  CpxAttrGroup(const char* name_) : BaseClasses()..., name_(name_) {} 
};

/*
struct <shape> {};
struct <color> {};
struct <uri> {};
struct <length> <length>? {};
struct <borderStyle>{1,4} {};
struct <borderStyle> {};
struct <borderWidth> {};
struct <borderWidth>{1,4} {};
struct <length> {};
struct <percentage> {};
struct <angle> {};
struct <absoluteSize> {};
struct <relativeSize> {};
struct <number> {};
struct <marginWidth> {};
struct <marginWidth>{1,4} {};
struct <integer> {};
struct <paddingWidth> {};
struct <paddingWidth>{1,4} {};
struct <time> {};
struct <frequency> {};
*/


// A dummy struct for every CSS attribute 
namespace CpxAttrs
{
  struct BackgroundAttachment {};
  struct BackgroundColor {};
  struct BackgroundImage {};
  struct BackgroundRepeat {};
  struct BorderCollapse {};
  struct BorderSpacing {};
  struct BorderStyle {};
  struct BorderTopColor {};struct BorderRightColor {};struct BorderBottomColor {};struct BorderLeftColor {};
  struct BorderTopStyle {};struct BorderRightStyle {};struct BorderBottomStyle {};struct BorderLeftStyle {};
  struct BorderTopWidth {};struct BorderRightWidth {};struct BorderBottomWidth {};struct BorderLeftWidth {};
  struct BorderWidth {};
  struct Bottom {};
  struct CaptionSide {};
  struct Clear {};
  struct Clip {};
  struct Color {};
  struct CueAfter {};
  struct CueBefore {};
  struct Direction {};
  struct Display {};
  struct Elevation {};
  struct EmptyCells {};
  struct Float {};
  struct FontSize {};
  struct FontStyle {};
  struct FontVariant {};
  struct FontWeight {};
  struct Height {};
  struct Left {};
  struct LetterSpacing {};
  struct LineHeight {};
  struct ListStyleImage {};
  struct ListStylePosition {};
  struct ListStyleType {};
  struct Margin {};
  struct MarginRight {};struct MarginLeft {};
  struct MarginTop {};struct MarginBottom {};
  struct MaxHeight {};
  struct MaxWidth {};
  struct MinHeight {};
  struct MinWidth {};
  struct Orphans {};
  struct OutlineColor {};
  struct OutlineStyle {};
  struct OutlineWidth {};
  struct Overflow {};
  struct Padding {};
  struct PaddingTop {};struct PaddingRight {};struct PaddingBottom {};struct PaddingLeft {};
  struct PageBreakAfter {};
  struct PageBreakBefore {};
  struct PageBreakInside {};
  struct PauseAfter {};
  struct PauseBefore {};
  struct Pitch {};
  struct PitchRange {};
  struct Position {};
  struct Richness {};
  struct Right {};
  struct Speak {};
  struct SpeakHeader {};
  struct SpeakNumeral {};
  struct SpeakPunctuation {};
  struct SpeechRate {};
  struct Stress {};
  struct TableLayout {};
  struct TextAlign {};
  struct TextIndent {};
  struct TextTransform {};
  struct Top {};
  struct UnicodeBidi {};
  struct VerticalAlign {};
  struct Visibility {};
  struct Volume {};
  struct WhiteSpace {};
  struct Widows {};
  struct Width {};
  struct WordSpacing {};
  struct ZIndex {};
}

// A template class for every value that any CSS attribute can have, which inherits
// from the structs in CpxAttrs corresponding to the CSS attributes who can have said value
typedef CpxAttrGroup<CpxAttrs::BackgroundAttachment, CpxAttrs::BackgroundColor, CpxAttrs::BackgroundImage, CpxAttrs::BackgroundRepeat, CpxAttrs::BorderCollapse, CpxAttrs::BorderSpacing, CpxAttrs::BorderStyle, CpxAttrs::BorderTopColor, CpxAttrs::BorderRightColor, CpxAttrs::BorderBottomColor, CpxAttrs::BorderLeftColor, CpxAttrs::BorderTopStyle, CpxAttrs::BorderRightStyle, CpxAttrs::BorderBottomStyle, CpxAttrs::BorderLeftStyle, CpxAttrs::BorderTopWidth, CpxAttrs::BorderRightWidth, CpxAttrs::BorderBottomWidth, CpxAttrs::BorderLeftWidth, CpxAttrs::BorderWidth, CpxAttrs::Bottom, CpxAttrs::CaptionSide, CpxAttrs::Clear, CpxAttrs::Clip, CpxAttrs::Color, CpxAttrs::CueAfter, CpxAttrs::CueBefore, CpxAttrs::Direction, CpxAttrs::Display, CpxAttrs::Elevation, CpxAttrs::EmptyCells, CpxAttrs::Float, CpxAttrs::FontSize, CpxAttrs::FontStyle, CpxAttrs::FontVariant, CpxAttrs::FontWeight, CpxAttrs::Height, CpxAttrs::Left, CpxAttrs::LetterSpacing, CpxAttrs::LineHeight, CpxAttrs::ListStyleImage, CpxAttrs::ListStylePosition, CpxAttrs::ListStyleType, CpxAttrs::MarginRight, CpxAttrs::MarginLeft, CpxAttrs::MarginTop, CpxAttrs::MarginBottom, CpxAttrs::Margin, CpxAttrs::MaxHeight, CpxAttrs::MaxWidth, CpxAttrs::MinHeight, CpxAttrs::MinWidth, CpxAttrs::Orphans, CpxAttrs::OutlineColor, CpxAttrs::OutlineStyle, CpxAttrs::OutlineWidth, CpxAttrs::Overflow, CpxAttrs::PaddingTop, CpxAttrs::PaddingRight, CpxAttrs::PaddingBottom, CpxAttrs::PaddingLeft, CpxAttrs::Padding, CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::PageBreakInside, CpxAttrs::PauseAfter, CpxAttrs::PauseBefore, CpxAttrs::PitchRange, CpxAttrs::Pitch, CpxAttrs::Position, CpxAttrs::Richness, CpxAttrs::Right, CpxAttrs::SpeakHeader, CpxAttrs::SpeakNumeral, CpxAttrs::SpeakPunctuation, CpxAttrs::Speak, CpxAttrs::SpeechRate, CpxAttrs::Stress, CpxAttrs::TableLayout, CpxAttrs::TextAlign, CpxAttrs::TextIndent, CpxAttrs::TextTransform, CpxAttrs::Top, CpxAttrs::UnicodeBidi, CpxAttrs::VerticalAlign, CpxAttrs::Visibility, CpxAttrs::Volume, CpxAttrs::WhiteSpace, CpxAttrs::Widows, CpxAttrs::Width, CpxAttrs::WordSpacing, CpxAttrs::ZIndex> Inherit;
typedef CpxAttrGroup<CpxAttrs::BackgroundAttachment, CpxAttrs::Overflow> Scroll;
typedef CpxAttrGroup<CpxAttrs::BackgroundAttachment, CpxAttrs::Position, CpxAttrs::TableLayout> Fixed;
typedef CpxAttrGroup<CpxAttrs::BackgroundColor, CpxAttrs::BorderTopColor, CpxAttrs::BorderRightColor, CpxAttrs::BorderBottomColor, CpxAttrs::BorderLeftColor> Transparent;
typedef CpxAttrGroup<CpxAttrs::BackgroundImage, CpxAttrs::Clear, CpxAttrs::CueAfter, CpxAttrs::CueBefore, CpxAttrs::Display, CpxAttrs::Float, CpxAttrs::ListStyleImage, CpxAttrs::ListStyleType, CpxAttrs::MaxHeight, CpxAttrs::MaxWidth, CpxAttrs::SpeakPunctuation, CpxAttrs::Speak, CpxAttrs::TextTransform> None;

typedef CpxAttrGroup<CpxAttrs::BackgroundRepeat> NoRepeat;
typedef CpxAttrGroup<CpxAttrs::BackgroundRepeat> Repeat;
typedef CpxAttrGroup<CpxAttrs::BackgroundRepeat> RepeatX;
typedef CpxAttrGroup<CpxAttrs::BackgroundRepeat> RepeatY;
typedef CpxAttrGroup<CpxAttrs::BorderCollapse, CpxAttrs::Visibility> Collapse;
typedef CpxAttrGroup<CpxAttrs::BorderCollapse> Separate;
typedef CpxAttrGroup<CpxAttrs::Bottom, CpxAttrs::Clip, CpxAttrs::Height, CpxAttrs::Left, CpxAttrs::Overflow, CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::PageBreakInside, CpxAttrs::Right, CpxAttrs::TableLayout, CpxAttrs::Top, CpxAttrs::Width, CpxAttrs::ZIndex> Auto;

typedef CpxAttrGroup<CpxAttrs::CaptionSide, CpxAttrs::VerticalAlign> Bottom;
typedef CpxAttrGroup<CpxAttrs::CaptionSide, CpxAttrs::VerticalAlign> Top;
typedef CpxAttrGroup<CpxAttrs::Clear, CpxAttrs::Float, CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::TextAlign> Left;
typedef CpxAttrGroup<CpxAttrs::Clear, CpxAttrs::Float, CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::TextAlign> Right;
typedef CpxAttrGroup<CpxAttrs::Clear> Both;
typedef CpxAttrGroup<CpxAttrs::Direction> Ltr;
typedef CpxAttrGroup<CpxAttrs::Direction> Rtl;
typedef CpxAttrGroup<CpxAttrs::Display> Block;
typedef CpxAttrGroup<CpxAttrs::Display> Inline;
typedef CpxAttrGroup<CpxAttrs::Display> InlineBlock;
typedef CpxAttrGroup<CpxAttrs::Display> InlineTable;
typedef CpxAttrGroup<CpxAttrs::Display> ListItem;
typedef CpxAttrGroup<CpxAttrs::Display> Table;
typedef CpxAttrGroup<CpxAttrs::Display> TableCaption;
typedef CpxAttrGroup<CpxAttrs::Display> TableCell;
typedef CpxAttrGroup<CpxAttrs::Display> TableColumn;
typedef CpxAttrGroup<CpxAttrs::Display> TableColumnGroup;
typedef CpxAttrGroup<CpxAttrs::Display> TableFooterGroup;
typedef CpxAttrGroup<CpxAttrs::Display> TableHeaderGroup;
typedef CpxAttrGroup<CpxAttrs::Display> TableRow;
typedef CpxAttrGroup<CpxAttrs::Display> TableRowGroup;
typedef CpxAttrGroup<CpxAttrs::Elevation> Above;
typedef CpxAttrGroup<CpxAttrs::Elevation> Below;
typedef CpxAttrGroup<CpxAttrs::Elevation> Higher;
typedef CpxAttrGroup<CpxAttrs::Elevation> Level;
typedef CpxAttrGroup<CpxAttrs::Elevation> Lower;
typedef CpxAttrGroup<CpxAttrs::EmptyCells> Hide;
typedef CpxAttrGroup<CpxAttrs::EmptyCells> Show;

typedef CpxAttrGroup<CpxAttrs::FontStyle, CpxAttrs::FontVariant, CpxAttrs::FontWeight, CpxAttrs::LetterSpacing, CpxAttrs::LineHeight, CpxAttrs::Speak, CpxAttrs::UnicodeBidi, CpxAttrs::WhiteSpace, CpxAttrs::WordSpacing> Normal;
typedef CpxAttrGroup<CpxAttrs::FontStyle> Italic;
typedef CpxAttrGroup<CpxAttrs::FontStyle> Oblique;
typedef CpxAttrGroup<CpxAttrs::FontVariant> SmallCaps;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw100;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw200;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw300;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw400;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw500;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw600;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw700;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw800;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Fw900;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Bold;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Bolder;
typedef CpxAttrGroup<CpxAttrs::FontWeight> Lighter;
typedef CpxAttrGroup<CpxAttrs::ListStylePosition> Inside;
typedef CpxAttrGroup<CpxAttrs::ListStylePosition> Outside;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Armenian;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Circle;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Decimal;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> DecimalLeadingZero;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Disc;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Georgian;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> LowerAlpha;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> LowerGreek;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> LowerLatin;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> LowerRoman;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> Square;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> UpperAlpha;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> UpperLatin;
typedef CpxAttrGroup<CpxAttrs::ListStyleType> UpperRoman;
typedef CpxAttrGroup<CpxAttrs::OutlineColor> Invert;
typedef CpxAttrGroup<CpxAttrs::Overflow, CpxAttrs::Visibility> Hidden;
typedef CpxAttrGroup<CpxAttrs::Overflow, CpxAttrs::Visibility> Visible;
typedef CpxAttrGroup<CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::PageBreakInside> Avoid;
typedef CpxAttrGroup<CpxAttrs::PageBreakAfter, CpxAttrs::PageBreakBefore, CpxAttrs::SpeakHeader> Always;
typedef CpxAttrGroup<CpxAttrs::Pitch, CpxAttrs::SpeechRate, CpxAttrs::Volume> Medium;
typedef CpxAttrGroup<CpxAttrs::Pitch> High;
typedef CpxAttrGroup<CpxAttrs::Pitch> Low;
typedef CpxAttrGroup<CpxAttrs::Pitch> XHigh;
typedef CpxAttrGroup<CpxAttrs::Pitch> XLow;
typedef CpxAttrGroup<CpxAttrs::Position> Absolute;
typedef CpxAttrGroup<CpxAttrs::Position> Relative;
typedef CpxAttrGroup<CpxAttrs::Position> Static;
typedef CpxAttrGroup<CpxAttrs::Speak> SpellOut;
typedef CpxAttrGroup<CpxAttrs::SpeakHeader> Once;
typedef CpxAttrGroup<CpxAttrs::SpeakNumeral> Continuous;
typedef CpxAttrGroup<CpxAttrs::SpeakNumeral> Digits;
typedef CpxAttrGroup<CpxAttrs::SpeakPunctuation> Code;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> Fast;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> Faster;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> Slow;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> Slower;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> XFast;
typedef CpxAttrGroup<CpxAttrs::SpeechRate> XSlow;
typedef CpxAttrGroup<CpxAttrs::TextAlign> Center;
typedef CpxAttrGroup<CpxAttrs::TextAlign> Justify;
typedef CpxAttrGroup<CpxAttrs::TextTransform> Capitalize;
typedef CpxAttrGroup<CpxAttrs::TextTransform> Lowercase;
typedef CpxAttrGroup<CpxAttrs::TextTransform> Uppercase;
typedef CpxAttrGroup<CpxAttrs::UnicodeBidi> BidiOverride;
typedef CpxAttrGroup<CpxAttrs::UnicodeBidi> Embed;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> Baseline;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> Middle;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> Sub;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> Super;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> TextBottom;
typedef CpxAttrGroup<CpxAttrs::VerticalAlign> TextTop;
typedef CpxAttrGroup<CpxAttrs::Volume> Loud;
typedef CpxAttrGroup<CpxAttrs::Volume> Silent;
typedef CpxAttrGroup<CpxAttrs::Volume> Soft;
typedef CpxAttrGroup<CpxAttrs::Volume> XLoud;
typedef CpxAttrGroup<CpxAttrs::Volume> XSoft;
typedef CpxAttrGroup<CpxAttrs::WhiteSpace> Nowrap;
typedef CpxAttrGroup<CpxAttrs::WhiteSpace> Pre;
typedef CpxAttrGroup<CpxAttrs::WhiteSpace> PreLine;
typedef CpxAttrGroup<CpxAttrs::WhiteSpace> PreWrap;
  
/*
typedef CpxAttrGroup<CpxAttrs::Padding> <paddingWidth>{1,4};
typedef CpxAttrGroup<CpxAttrs::PaddingTop, CpxAttrs::PaddingRight, CpxAttrs::PaddingBottom, CpxAttrs::PaddingLeft> <paddingWidth>;
typedef CpxAttrGroup<CpxAttrs::FontSize> <absoluteSize>;
typedef CpxAttrGroup<CpxAttrs::FontSize> <relativeSize>;
typedef CpxAttrGroup<CpxAttrs::Elevation> <angle>;
typedef CpxAttrGroup<CpxAttrs::LineHeight, CpxAttrs::PitchRange, CpxAttrs::Richness, CpxAttrs::SpeechRate, CpxAttrs::Stress, CpxAttrs::Volume> <number>;
typedef CpxAttrGroup<CpxAttrs::Margin> <marginWidth>{1,4};
typedef CpxAttrGroup<CpxAttrs::MarginRight, CpxAttrs::MarginLeft, CpxAttrs::MarginTop, CpxAttrs::MarginBottom> <marginWidth>;
typedef CpxAttrGroup<CpxAttrs::Orphans, CpxAttrs::Widows, CpxAttrs::ZIndex> <integer>;
typedef CpxAttrGroup<CpxAttrs::BorderSpacing> <length> <length>?;
typedef CpxAttrGroup<CpxAttrs::BorderStyle> <borderStyle>{1,4};
typedef CpxAttrGroup<CpxAttrs::BorderTopStyle, CpxAttrs::BorderRightStyle, CpxAttrs::BorderBottomStyle, CpxAttrs::BorderLeftStyle, CpxAttrs::OutlineStyle> <borderStyle>;
typedef CpxAttrGroup<CpxAttrs::BorderTopWidth, CpxAttrs::BorderRightWidth, CpxAttrs::BorderBottomWidth, CpxAttrs::BorderLeftWidth, CpxAttrs::OutlineWidth> <borderWidth>;
typedef CpxAttrGroup<CpxAttrs::BackgroundImage, CpxAttrs::CueAfter, CpxAttrs::CueBefore, CpxAttrs::ListStyleImage> <uri>;
typedef CpxAttrGroup<CpxAttrs::BackgroundColor, CpxAttrs::BorderTopColor, CpxAttrs::BorderRightColor, CpxAttrs::BorderBottomColor, CpxAttrs::BorderLeftColor, CpxAttrs::Color, CpxAttrs::OutlineColor> <color>;

typedef CpxAttrGroup<CpxAttrs::BorderWidth> <borderWidth>{1,4};
typedef CpxAttrGroup<CpxAttrs::Bottom, CpxAttrs::FontSize, CpxAttrs::Height, CpxAttrs::Left, CpxAttrs::LineHeight, CpxAttrs::MaxHeight, CpxAttrs::MaxWidth, CpxAttrs::MinHeight, CpxAttrs::MinWidth, CpxAttrs::PauseAfter, CpxAttrs::PauseBefore, CpxAttrs::Right, CpxAttrs::TextIndent, CpxAttrs::Top, CpxAttrs::VerticalAlign, CpxAttrs::Volume, CpxAttrs::Width> <percentage>;
typedef CpxAttrGroup<CpxAttrs::Bottom, CpxAttrs::FontSize, CpxAttrs::Height, CpxAttrs::Left, CpxAttrs::LetterSpacing, CpxAttrs::LineHeight, CpxAttrs::MaxHeight, CpxAttrs::MaxWidth, CpxAttrs::MinHeight, CpxAttrs::MinWidth, CpxAttrs::Right, CpxAttrs::TextIndent, CpxAttrs::Top, CpxAttrs::VerticalAlign, CpxAttrs::Width, CpxAttrs::WordSpacing> <length>;
typedef CpxAttrGroup<CpxAttrs::PauseAfter, CpxAttrs::PauseBefore> <time>;
typedef CpxAttrGroup<CpxAttrs::Clip> <shape>;
typedef CpxAttrGroup<CpxAttrs::Pitch> <frequency>;
*/


extern Fw100 fw100;
extern Fw200 fw200;
extern Fw300 fw300;
extern Fw400 fw400;
extern Fw500 fw500;
extern Fw600 fw600;
extern Fw700 fw700;
extern Fw800 fw800;
extern Fw900 fw900;
extern Above above;
extern Absolute absolute;
extern Always always;
extern Armenian armenian;
extern Auto auto_;
extern Avoid avoid;
extern Baseline baseline;
extern Below below;
extern BidiOverride bidiOverride;
extern Block block;
extern Bold bold;
extern Bolder bolder;
extern Both both;
extern Bottom bottom;
extern Capitalize capitalize;
extern Center center;
extern Circle circle;
extern Code code;
extern Collapse collapse;
extern Continuous continuous;
extern Decimal decimal;
extern DecimalLeadingZero decimalLeadingZero;
extern Digits digits;
extern Disc disc;
extern Embed embed;
extern Fast fast;
extern Faster faster;
extern Fixed fixed;
extern Georgian georgian;
extern Hidden hidden;
extern Hide hide;
extern High high;
extern Higher higher;
extern Inherit inherit;
extern Inline inline_;
extern InlineBlock inlineBlock;
extern InlineTable inlineTable;
extern Inside inside;
extern Invert invert;
extern Italic italic;
extern Justify justify;
extern Left left;
extern Level level;
extern Lighter lighter;
extern ListItem listItem;
extern Loud loud;
extern Low low;
extern Lower lower;
extern LowerAlpha lowerAlpha;
extern LowerGreek lowerGreek;
extern LowerLatin lowerLatin;
extern LowerRoman lowerRoman;
extern Lowercase lowercase;
extern Ltr ltr;
extern Medium medium;
extern Middle middle;
extern NoRepeat noRepeat;
extern None none;
extern Normal normal;
extern Nowrap nowrap;
extern Oblique oblique;
extern Once once;
extern Outside outside;
extern Pre pre;
extern PreLine preLine;
extern PreWrap preWrap;
extern Relative relative;
extern Repeat repeat;
extern RepeatX repeatX;
extern RepeatY repeatY;
extern Right right;
extern Rtl rtl;
extern Scroll scroll;
extern Separate separate;
extern Show show;
extern Silent silent;
extern Slow slow;
extern Slower slower;
extern SmallCaps smallCaps;
extern Soft soft;
extern SpellOut spellOut;
extern Square square;
extern Static static_;
extern Sub sub;
extern Super super;
extern Table table;
extern TableCaption tableCaption;
extern TableCell tableCell;
extern TableColumn tableColumn;
extern TableColumnGroup tableColumnGroup;
extern TableFooterGroup tableFooterGroup;
extern TableHeaderGroup tableHeaderGroup;
extern TableRow tableRow;
extern TableRowGroup tableRowGroup;
extern TextBottom textBottom;
extern TextTop textTop;
extern Top top;
extern Transparent transparent;
extern UpperAlpha upperAlpha;
extern UpperLatin upperLatin;
extern UpperRoman upperRoman;
extern Uppercase uppercase;
extern Visible visible;
extern XFast xFast;
extern XHigh xHigh;
extern XLoud xLoud;
extern XLow xLow;
extern XSlow xSlow;
extern XSoft xSoft;