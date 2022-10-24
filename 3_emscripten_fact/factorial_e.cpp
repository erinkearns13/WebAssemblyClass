#include <emscripten/emscripten.h>

extern "C"{
  double EMSCRIPTEN_KEEPALIVE fact(int i) {
    long long n = 1;
    for (;i > 0; i--) {
      n *= i;
    }
    return (double)n;
  }
}

