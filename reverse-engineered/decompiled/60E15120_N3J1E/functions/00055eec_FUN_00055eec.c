/* ROM address: 0x00055eec; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054208 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00055eec(uint param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte local_14 [8];
  
  pbVar1 = local_14;
  do {
    sh_copy_bytes_forward_r0_r1_r2();
    uVar2 = (uint)*pbVar1;
    if (((uVar2 == (param_1 & 0xff)) && (pbVar1[1] == param_2)) && (pbVar1[2] == param_3)) break;
  } while (uVar2 < 5);
  return 4 < uVar2;
}


