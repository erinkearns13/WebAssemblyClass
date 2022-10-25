#include <emscripten.h>
#include <emscripten/bind.h>
#include <iostream>
using namespace emscripten;

static int delayAndReturn(bool sleep) {
  if (sleep) {
    emscripten_sleep(0);
  }
  return 42;
}


EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("delayAndReturn", &delayAndReturn);
}