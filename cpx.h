#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

// Define the identifier symbol used as a placeholder
#define CPX_PLACEHOLDER(x) CPXPlaceHolder x

// Define your tags 
#define CPX_ELEM(x) CPXElem x(#x)


#define TAG(CLASSNAME) struct CLASSNAME : public CPXElem
#define TAGNAME(CLASSNAME, TAGNAME) CLASSNAME():CPXElem(TAGNAME) {} typedef CLASSNAME THISCLASS
#define PROP(T, PROPNAME) THISCLASS& PROPNAME(T x) { ostringstream oss; oss << x; props[#PROPNAME] = oss.str(); return *this;}


// Represents a node
// Each node has a tag name
// It can contain a string value or a vector of children
struct CPXNode
{
  CPXNode *parent;
  string val;
  const char *tag;
  vector< CPXNode *> children;
  map<string, string> props;
  map<string, string> css;
  
  CPXNode (CPXNode *pParent = nullptr): parent(pParent) {}
  
  // Call to set the text value, all children are removed, since text and children are mutually exclusive
  template<typename T> CPXNode *setVal(const T &s)
  {
    children.clear();
    ostringstream oss;
    oss << s;
    val = oss.str();
    
    return this;
  }
  
  // Add a child node to this node, it clears the value, since text and children are mutually exclusive
  CPXNode *addChild()
  {
    val.clear();
    CPXNode *n = new CPXNode (this);
    children.push_back(n);
    return n;
  }
  
  // Destructor cleans up recursively
  ~CPXNode()
  {
    for(auto n:children) 
    {
      delete n;
    }
    children.clear();
  }
  
  // Dump the node tree in HTML style
  void dump(int indent = 0)
  {
    cout << string(indent * 2, ' ')  << "<" << tag;
    
    for(const auto &prop: props)
    {
      cout << " " << prop.first << "=" << "'" << prop.second << "'"; 
    }
    
    if(css.size())
    {
      cout << " style='";
      for(const auto &style: css)
      {
        cout << style.first << ":" <<  style.second << ";"; 
      }
      cout << "'";
    }
    
    cout << ">" << endl;
    
    if(children.size())
    {
      for(auto n: children)
      {
        n->dump(indent + 1);
      }
    }
    else
    {
      cout << string((indent + 1) * 2, ' ')  << val << endl;
    }
    
    cout << string(indent * 2, ' ')  << "</" << tag << ">" << endl;
  }
};


// Wrapper class that holds a tag name and its serialized props, define as you please
struct CPXElem
{
  const char* tag;
  map<string, string> props;
  CPXElem(const char *pszTag) : tag (pszTag) {}
};


// Class used to wrap up the / operator that appears in closing tags
struct CPXTagCloser
{
  const CPXElem &tag;
  CPXTagCloser(const CPXElem &atag): tag(atag){}
};


// Dummy class used to provide punctuation
struct CPXPlaceHolder 
{
  // _ / TAG 
  // Return CPXTagCloser(TAG)
  const CPXTagCloser operator/(const CPXElem& e)
  {
    return CPXTagCloser(e);
  }
};


// The main meta parser
struct CPX
{
  CPXNode *root;
  CPXNode *current;
  CPX() : root(nullptr), current(nullptr) {}
  
  template<typename T> CPX& addTag(T &e)
  {
    CPXNode *n;
    if(!current)
    {
      n = new CPXNode ();
      root = n;
    }
    else
    {
      n = current->addChild();
    }
    
    current = n;
    
    // Copy the tag and inline props, clear the props so the tag can be reused
    current->tag = e.tag;
    current->props = e.props;
    e.props.clear();
    
    return *this;
  }
  
  // CPX < TAG 
  // Add this node to current and make current into new node (descend)
  CPX& operator< (CPXElem &e)
  {
    return addTag(e);
  }
  
  // CPX > _ or CPX = _
  // Do nothing
  CPX& operator> (const CPXPlaceHolder&) { return *this; }
  
  // CPX > T
  // Put the value into the current tag
  template<typename T> CPX& operator> (const T& val) 
  {
    current->setVal(val);
    return *this; 
  }
  
  // CPX < CLOSER(TAG)
  // Take current up one level
  CPX& operator< (const CPXTagCloser &c)
  {
    current = current->parent;
    return *this;
  }
  
};

/*
 * 
 * Example of how the CPX expression reduces
 * =========================================
 * 
 * cpx < DIV > _ < P > "Hello world" < _ / P > _ < P > "Hell world" < _ / P > _ < P > (2 * 3 / 5.0F) < _ / P > _ < _ / DIV > _ ;
 * 
 * cpx < DIV > _ < P > "Hello world" < CPXTagCloser(P) > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > _ < P > "Hello world" < CPXTagCloser(P) > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < P > "Hello world" < CPXTagCloser(P) > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > "Hello world" < CPXTagCloser(P) > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < CPXTagCloser(P) > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > _ < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < P > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > "Hell world" < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < CPXTagCloser(P) > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > _ < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < P > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > (2 * 3 / 5.0F) < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < CPXTagCloser(P) > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > _ < CPXTagCloser(DIV) > _ ;
 * 
 * cpx < CPXTagCloser(DIV) > _ ;
 * 
 * cpx > _ ;
 * 
 */
