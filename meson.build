project('testLanguage', 'cpp', default_options: ['warning_level=3', 'cpp_std=c++17'])
sources = ['main.cpp', 'testLanguageLexer.cpp', 'testLanguageParser.cpp', 'testLanguageListener.cpp', 'testLanguageBaseListener.cpp']
llvm_dep = dependency('llvm', version : '>=4.0', modules : ['all'], static : true)
testLanguage = executable('testLanguage', sources, include_directories: '/usr/include/antlr4-runtime/', objects: '/usr/lib/libantlr4-runtime.a', dependencies : [llvm_dep], override_options : ['buildtype=release'])
testLanguage_debug = executable('testLanguage_debug', sources, include_directories: '/usr/include/antlr4-runtime/', objects: '/usr/lib/libantlr4-runtime.a', dependencies : [llvm_dep], override_options : ['buildtype=debug'])
testLanguageLibrary = static_library('testLanguageLibrary', 'testLibrary.cpp', override_options : ['buildtype=release'])
testLanguageLibrary_debug = static_library('testLanguageLibrary_debug', 'testLibrary.cpp', override_options : ['buildtype=debug'])
