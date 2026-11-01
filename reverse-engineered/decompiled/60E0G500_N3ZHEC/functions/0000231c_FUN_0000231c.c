/* ROM address: 0x0000231c; body bytes: 114; decompiled */

uint FUN_0000231c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)((ulonglong)((longlong)param_2 * (longlong)param_1) >> 0x20);
  iVar2 = (int)uVar3 >> 0x10;
  uVar1 = (uint)(((int)uVar3 >> 0xf & 1U) == 1);
  uVar3 = ((((((((((((((((uint)((longlong)param_2 * (longlong)param_1) >> 1 |
                        (uint)((uVar3 & 1) == 1) * -0x80000000) >> 1 |
                       (uint)(((int)uVar3 >> 1 & 1U) == 1) * -0x80000000) >> 1 |
                      (uint)(((int)uVar3 >> 2 & 1U) == 1) * -0x80000000) >> 1 |
                     (uint)(((int)uVar3 >> 3 & 1U) == 1) * -0x80000000) >> 1 |
                    (uint)(((int)uVar3 >> 4 & 1U) == 1) * -0x80000000) >> 1 |
                   (uint)(((int)uVar3 >> 5 & 1U) == 1) * -0x80000000) >> 1 |
                  (uint)(((int)uVar3 >> 6 & 1U) == 1) * -0x80000000) >> 1 |
                 (uint)(((int)uVar3 >> 7 & 1U) == 1) * -0x80000000) >> 1 |
                (uint)(((int)uVar3 >> 8 & 1U) == 1) * -0x80000000) >> 1 |
               (uint)(((int)uVar3 >> 9 & 1U) == 1) * -0x80000000) >> 1 |
              (uint)(((int)uVar3 >> 10 & 1U) == 1) * -0x80000000) >> 1 |
             (uint)(((int)uVar3 >> 0xb & 1U) == 1) * -0x80000000) >> 1 |
            (uint)(((int)uVar3 >> 0xc & 1U) == 1) * -0x80000000) >> 1 |
           (uint)(((int)uVar3 >> 0xd & 1U) == 1) * -0x80000000) >> 1 |
          (uint)(((int)uVar3 >> 0xe & 1U) == 1) * -0x80000000) >> 1 | uVar1 * -0x80000000;
  if (iVar2 < 0) {
    if ((iVar2 != -1) || (uVar1 == 0)) {
      uVar3 = 0x80000000;
    }
  }
  else if ((iVar2 != 0) || (uVar1 != 0)) {
    uVar3 = 0x7fffffff;
  }
  return uVar3;
}


