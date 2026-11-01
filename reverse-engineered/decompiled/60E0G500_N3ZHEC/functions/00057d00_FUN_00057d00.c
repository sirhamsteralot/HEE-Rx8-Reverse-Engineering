/* ROM address: 0x00057d00; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5fcc0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 diag22_pide611_sw_name_string(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  byte bVar4;
  
  bVar4 = 0;
  pcVar3 = "SW-N3ZHEC000.HEX";
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    uVar2 = diag_append_u8((int)param_1,(int)cVar1);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 0x18);
  return uVar2;
}


