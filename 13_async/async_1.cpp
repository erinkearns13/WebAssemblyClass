#include <emscripten.h>
#include <emscripten/bind.h>
#include <iostream>
using namespace emscripten;


    
EM_ASYNC_JS(int, find_height, (), {
    console.log('waiting for a fetch');
    const response = await fetch('https://swapi.dev/api/people/1').then(r=>r.json());
    console.log('got the fetch response');
        // (normally you would do something with the fetch here)
    return parseInt(response.height);
});

int sendData() {
    return find_height();
}



EMSCRIPTEN_BINDINGS(my_module) {
    function("sendData", &sendData);
}