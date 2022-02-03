# testLanguage

## Intro

This repository is only meant for me to learn how to work with ANTLR and LLVM.  
testLanguage is not meant to be performant, safe nor used in any real context.  
Most syntax/semantics errors will only be caught at the lower level they are encountered, hopefully get a message explaining what's gone wrong, and then the compiler will crash out.

## Features

Currently testLanguage implements defining variable and function types, variables and functions.
Basic types are int32 and float, everything is built on those.
For control flow, it offers if/else/then and a single version of for that covers both iterating an index over a range, and iterating over a vector.
Additionally there's the option to defer actions, which will make them happen at scope block exit in a LIFO order.
For details you can look at the testLanguage.g4 file, which defines the grammar.

## Building the Compiler

Like most of my projects, this repository is built using [meson](https://mesonbuild.com).  
Meson only supports out of source builds, so the first thing to do is to create a directory where the compilation artifacts will go.  
On linux, this would be something like `mkdir build`.  
After that, you can type `meson setup directory_name` where *directory_name* is *build* in our example.
Finally, you can type `meson compile -C directory_name` where *directory_name* is *build* in our example.
This will build both testLanguage and testLanguage_debug, the release and debug versions of the compiler, and the additional libTestLanguageLibrary.a / libTestLanguageLibrary_debug.a for getting access to printing functions (the source for them is in testLibrary.cpp).  

## Using the Compiler

With testLanguage and testLanguageLibrary.a available, you write your program with your favourite text editor and compile it by typing `address/to/testLanguage your_source` which will produce a file called *your_source.ll*.  
You can then link that using clang with `clang your_source.ll address/to/testLanguageLibrary.a -o output_name` where *output_name* is the name you want to give to your executable.  
You can then run your executable with `./output_name`

## License
[LLVM](https://llvm.org) is under its own version of the Apache2 license, available [here](https://github.com/llvm/llvm-project/blob/main/llvm/LICENSE.TXT).
[ANTL](https://github.com/antlr/antlr4) is under BSD3 license with exceptions, available [here](https://github.com/antlr/antlr4/blob/master/LICENSE.txt)
Anything that doesn't fall under those licenses comes under the MIT license, included in this repository.
