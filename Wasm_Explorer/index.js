console.log("hello world")
fetch("./test.wasm").then(r=>r.arrayBuffer()).then(buffer=>{
    return WebAssembly.instantiate(buffer)
}).then(r=>{
    console.log(r.instance.exports.fact(6))
})
// fetch("./test.wasm").then(r=>r.arrayBuffer()).then(buffer=>{
//     return WebAssembly.instantiate(buffer)
// }).then(({instance,module})=>{
//     console.log(instance)
//     console.log(module)
// })

// WebAssembly.instantiateStreaming(fetch("./test.wasm")).then(r=>{
//     console.log(r)
// })