project('testLanguage', 'cpp', default_options: ['warning_level=3', 'cpp_std=c++17'])
includes = ['/usr/include/antlr4-runtime/', 'antlr']
sources = ['main.cpp', 'antlr/testLanguageLexer.cpp', 'antlr/testLanguageParser.cpp', 'antlr/testLanguageListener.cpp', 'antlr/testLanguageBaseListener.cpp']
llvm_dep = dependency('llvm', version : '>=4.0', modules : ['all'], static : true)
testLanguage = executable('testLanguage', sources, include_directories: includes , objects: '/usr/lib/libantlr4-runtime.a', dependencies : [llvm_dep], override_options : ['buildtype=release'])
testLanguage_debug = executable('testLanguage_debug', sources, include_directories: includes, objects: '/usr/lib/libantlr4-runtime.a', dependencies : [llvm_dep], override_options : ['buildtype=debug'])
testLanguageLibrary = static_library('testLanguageLibrary', 'testLibrary.cpp', override_options : ['buildtype=release'])
testLanguageLibrary_debug = static_library('testLanguageLibrary_debug', 'testLibrary.cpp', override_options : ['buildtype=debug'])
