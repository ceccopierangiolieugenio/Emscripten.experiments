# Emscripten.experiments
Placeholder for few ([ASM.js](http://asmjs.org)) experiments using [Emscripten](https://kripken.github.io/emscripten-site/)

## Build instructions
* [Install Emscripten](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html)

  In my experiments I used the portable linux SDK ([emsdk-portable](https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz))

* Build the project
 
        source ~/<EMSDK_PATH>/emsdk_portable/emsdk_env.sh
        make -C src

## Tests
* [Simple c String inversion](http://ceccopierangiolieugenio.github.io/Emscripten.experiments/test.1.html)
* [Simple c++ Class](http://ceccopierangiolieugenio.github.io/Emscripten.experiments/test.2.html)
* [Simple SDL Attractor example](http://ceccopierangiolieugenio.github.io/Emscripten.experiments/test.3.html)
* [Simple Float32 Array test](http://ceccopierangiolieugenio.github.io/Emscripten.experiments/test.4.html)
* [Simple Audio test](http://ceccopierangiolieugenio.github.io/Emscripten.experiments/test.5.html)
