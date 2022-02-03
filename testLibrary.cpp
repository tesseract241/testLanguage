#include <cstdio>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C" DLLEXPORT int printr(float f){
    std::fprintf(stderr, "%f\n", f);
    return 0;
}

extern "C" DLLEXPORT int printd(int n){
    std::fprintf(stderr, "%d\n", n);
    return 0;
}
