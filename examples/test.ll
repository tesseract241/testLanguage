; ModuleID = 'my module'
source_filename = "my module"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Struct = type { i32, float }

define i32 @main() {
main_block:
  %returnValue = alloca i32, align 4
  store i32 0, i32* %returnValue, align 4
  %tempstr = alloca %Struct, align 8
  %0 = getelementptr %Struct, %Struct* %tempstr, i32 0, i32 0
  store i32 3, i32* %0, align 4
  %1 = getelementptr %Struct, %Struct* %tempstr, i32 0, i32 1
  store float 0x40159999A0000000, float* %1, align 4
  %tempstr1 = load %Struct, %Struct* %tempstr, align 4
  %c = alloca %Struct, align 8
  store %Struct %tempstr1, %Struct* %c, align 4
  %2 = getelementptr %Struct, %Struct* %c, i32 0, i32 0
  %3 = load i32, i32* %2, align 4
  %d = alloca i32, align 4
  store i32 %3, i32* %d, align 4
  %4 = getelementptr %Struct, %Struct* %c, i32 0, i32 1
  store float 0x4008CCCCC0000000, float* %4, align 4
  %5 = getelementptr %Struct, %Struct* %c, i32 0, i32 0
  %6 = load i32, i32* %5, align 4
  %pricall = call i32 @printd(i32 %6)
  %7 = getelementptr %Struct, %Struct* %c, i32 0, i32 1
  %8 = load float, float* %7, align 4
  %pricall2 = call i32 @printr(float %8)
  %returnValue3 = load i32, i32* %returnValue, align 4
  ret i32 %returnValue3
}

declare i32 @printr(float)

declare i32 @printd(i32)
