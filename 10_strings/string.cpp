#include <emscripten.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>

extern "C"{
    EMSCRIPTEN_KEEPALIVE
    double add(double a, double b) {
    return a + b;
    }

    EMSCRIPTEN_KEEPALIVE
    const char* exclaim(char* message) {
    std::string *input = new std::string(message); //this needs a delete
    return (*input + "!").c_str();
    }

    EMSCRIPTEN_KEEPALIVE
    int mymalloc(int size) {
    return (int)malloc(size);
    }

    EMSCRIPTEN_KEEPALIVE
    void myfree(int p) { //this isn't being used
    free((void *)p);
    }
}


