## simple implementation of the xor string
string encryption.

# example
```cpp
int __cdecl main() {
    std::cout << crypt_string("example");
}
```

# small api
```cpp

// quick and easy use of a macros for crypt string
#define crypt_string(s) ::cryptor::create(s).decrypt()
```
# supported compilers and platforms
Tested to be working on MSVC v140-v142 

# output example
```asm
main:
  push    ebp
  mov     ebp, esp
  and     esp, 0FFFFFFF8h
  sub     esp, 20h
  mov     eax, dword_404390
  push    ebx
  mov     ebx, 80808081h
  mov     [esp+24h+var_5], 0
  mul     ebx
  push    ebp
  mov     [esp+28h+var_20], eax
  lea     ebp, [ebx-1]
  mov     eax, dword_404390
  push    esi
  mov     esi, edx
  mul     ebp
  push    edi
  mov     edi, eax
  mov     ebp, edx
  mov     eax, dword_404394
  mul     ebx
  mov     ecx, eax
  mov     ebx, edx
  mov     eax, dword_404394
  mov     edx, 80808080h
  mul     edx
  add     ecx, esi
  mov     [esp+30h+var_20], eax
  adc     ebx, 0
  add     edi, ecx
  mov     ecx, [esp+30h+var_20]
  adc     ebp, 0
  mov     [esp+30h+var_18], edi
  xor     eax, eax
  add     ebx, ebp
  adc     eax, eax
  add     ecx, ebx
  adc     edx, eax
  shrd    ecx, edx, 7
  mov     edx, dword_404390
  mov     al, dl
  xor     al, 0Ah
  mov     [esp+30h+var_6], dl
  mov     [esp+30h+var_7], al
  add     cl, dl
  mov     al, dl
  mov     [esp+30h+var_4], cl
  xor     al, 21h
  mov     cl, dl
  mov     [esp+30h+var_8], al
  xor     cl, 74h
  mov     al, dl
  mov     [esp+30h+var_9], cl
  xor     al, 73h
  mov     [esp+30h+var_C], cl
  mov     [esp+30h+var_A], al
  mov     al, dl
  xor     al, 65h
  mov     [esp+30h+var_B], al
  lea     eax, [esp+30h+var_C]
  xchg    ax, ax
  ```
  ```asm
sub_xxxxxxx:
  push    ebp
  mov     ebp, esp
  and     esp, 0FFFFFFF8h
  sub     esp, 18h
  push    ebx
  push    ebp
  push    esi
  mov     esi, ds:rand
  push    edi
  call    esi ; rand
  movd    xmm0, eax
  cvtdq2pd xmm0, xmm0
  mulsd   xmm0, ds:qword_403150
  mulsd   xmm0, ds:qword_403160
  addsd   xmm0, ds:qword_403148
  call    sub_402230
  mov     [esp+28h+var_4], eax
  mov     [esp+28h+var_8], edx
  call    esi ; rand
  movd    xmm0, eax
  cvtdq2pd xmm0, xmm0
  mulsd   xmm0, ds:qword_403150
  mulsd   xmm0, ds:qword_403168
  addsd   xmm0, ds:qword_403158
  call    sub_402230
  mov     [esp+28h+var_C], eax
  mov     [esp+28h+var_10], edx
  call    esi ; rand
  movd    xmm0, eax
  cvtdq2pd xmm0, xmm0
  mulsd   xmm0, ds:qword_403150
  mulsd   xmm0, ds:qword_403178
  addsd   xmm0, ds:qword_403170
  call    sub_402230
  mov     [esp+28h+var_14], eax
  mov     ebp, edx
  call    esi ; rand
  movd    xmm0, eax
  cvtdq2pd xmm0, xmm0
  mulsd   xmm0, ds:qword_403150
  mulsd   xmm0, ds:qword_403188
  addsd   xmm0, ds:qword_403180
  call    sub_402230
  mov     ebx, eax
  mov     edi, edx
  call    esi ; rand
  movd    xmm0, eax
  cvtdq2pd xmm0, xmm0
  mulsd   xmm0, ds:qword_403150
  mulsd   xmm0, ds:qword_403198
  addsd   xmm0, ds:qword_403190
  call    sub_402230
  mov     esi, eax
  movsx   eax, ds:byte_403138
  push    edx
  cdq
  push    esi
  push    edx
  push    eax
  call    __allmul
  mov     esi, eax
  mov     [esp+28h+var_18], edx
  movsx   eax, ds:byte_403139
  push    edi
  cdq
  push    ebx
  push    edx
  push    eax
  call    __allmul
  mov     ebx, [esp+28h+var_18]
  add     esi, eax
  movsx   eax, ds:byte_40313B
  push    ebp
  push    [esp+2Ch+var_14]
  adc     ebx, edx
  cdq
  push    edx
  push    eax
  call    __allmul
  push    [esp+28h+var_10]
  add     esi, eax
  movsx   eax, ds:byte_40313C
  push    [esp+2Ch+var_C]
  adc     ebx, edx
  cdq
  push    edx
  push    eax
  call    __allmul
  push    [esp+28h+var_8]
  add     esi, eax
  movsx   eax, ds:byte_40313E
  push    [esp+2Ch+var_4]
  adc     ebx, edx
  cdq
  push    edx
  push    eax
  call    __allmul
  add     esi, eax
  movsx   eax, ds:byte_40313F
  pop     edi
  adc     ebx, edx
  cdq
  add     esi, eax
  mov     dword ptr qword_404390, esi
  adc     ebx, edx
  mov     dword ptr qword_404390+4, ebx
  pop     esi
  pop     ebp
  pop     ebx
  mov     esp, ebp
  pop     ebp
  retn
  ```
