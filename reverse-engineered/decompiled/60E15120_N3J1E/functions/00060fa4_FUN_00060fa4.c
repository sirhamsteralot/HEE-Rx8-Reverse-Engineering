/* ROM address: 0x00060fa4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f894 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined ** FUN_00060fa4(ushort *param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if ((ppuVar1 == &vector_Illegal_instr) ||
     (ppuVar1 == (undefined **)((int)&vector_Illegal_instr + 1))) {
    ppuVar1 = (undefined **)&DAT_0007e442;
    if (*(byte *)((int)param_1 + 9) < (byte)(&DAT_0007e442)[*param_1]) {
      ppuVar1 = (undefined **)FUN_00062ebc((char)*(byte *)((int)param_1 + 9) + 1);
      return ppuVar1;
    }
  }
  return ppuVar1;
}


