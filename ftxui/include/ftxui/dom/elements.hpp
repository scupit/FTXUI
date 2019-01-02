#ifndef FTXUI_DOM_ELEMENTS_HPP
#define FTXUI_DOM_ELEMENTS_HPP

#include <functional>

#include "ftxui/color.hpp"
#include "ftxui/dom/node.hpp"

namespace ftxui {
namespace dom {

using Element = std::unique_ptr<Node>;
using Decorator = std::function<Element(Element)>;
using Child = std::unique_ptr<Node>;
using Children = std::vector<Child>;

// --- Layout ----
Element vbox(Children);
Element hbox(Children);
Element dbox(Children);
Element flex();
Element flex(Element);

// --- Widget --
Element text(std::wstring text);
Element separator();
Element gauge(float ratio);
Element frame(Child);
Element frame(Child title, Child content);

// -- Style ---
Element bold(Element);
Element dim(Element);
Element inverted(Element);
Element underlined(Element);
Element blink(Element);
Element color(Color, Element);
Element bgcolor(Color, Element);
Decorator color(Color);
Decorator bgcolor(Color);

// --- Util ---
Element hcenter(Element);
Element vcenter(Element);
Element center(Element);

// --- Util ---
Element nothing(Element element);
Decorator compose(Decorator, Decorator);

template <class... Args>
Children unpack(Args... args) {
  Children vec;
  (vec.push_back(std::forward<Args>(args)), ...);
  return vec;
}

template <class... Args>
Element vbox(Args... children) {
  return vbox(unpack(std::forward<Args>(children)...));
}

template <class... Args>
Element hbox(Args... children) {
  return hbox(unpack(std::forward<Args>(children)...));
}

template <class... Args>
Element dbox(Args... children) {
  return dbox(unpack(std::forward<Args>(children)...));
}

};  // namespace dom
};  // namespace ftxui

#endif /* end of include guard: FTXUI_DOM_ELEMENTS_HPP */
