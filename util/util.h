//
// Created by lioth on 8/5/2017.
//

#ifndef GAMEENGINE_UTIL_H
#define GAMEENGINE_UTIL_H

#include <string>
#include "ini_parser.h"

std::string get_file(const char* filename) {
  static IniParser config("config.ini");
  static const std::string &path = config.get("", "assets_dir");

  return path + "/" + filename;
};

template<class ITER>
class CycleIter{
private:
  ITER begin_;
  ITER end_;
  ITER current_;
public:
  using value_type = decltype(*begin_);

  CycleIter(ITER &&begin, ITER &&end)
    :begin_(std::move(begin))
    ,end_(std::move(end))
    ,current_(begin_)
  {}

  CycleIter& operator++() {
    current_++;
    if(current_ == end_) {
      current_ = begin_;
    }

    return *this;
  }

  value_type& operator*() {
    return *current_;
  }
};

template <class OBJ>
auto make_cycle(OBJ &obj) -> CycleIter<decltype(obj.begin())> {
  return CycleIter<decltype(obj.begin())>(obj.begin(), obj.end());
}

#endif //GAMEENGINE_UTIL_H
