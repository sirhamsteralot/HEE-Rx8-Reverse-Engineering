/* ROM address: 0x000378dc; body bytes: 202; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037ffc (202 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000378dc(ushort param_1,byte param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (DAT_ffffc4a1 == '\x01') {
    uVar3 = 1;
  }
  else {
    DAT_ffffc4a1 = '\x01';
    DAT_ffffc48e = (undefined2)((int)(uint)param_1 >> 1);
    iVar2 = (uint)param_2 + (uint)param_1 + -1;
    DAT_ffffc490 = (undefined2)((int)(iVar2 + (uint)(iVar2 < 0)) >> 1);
    DAT_ffffc4a4 = 1;
    if (param_3 == '\x01') {
      DAT_ffffc288 = 0;
      DAT_ffffc28b = 0;
      DAT_ffffc49c = 1;
    }
    else if (param_3 == '\x02') {
      DAT_ffffc289 = 0;
      DAT_ffffc28c = 0;
      DAT_ffffc49c = 2;
    }
    else if (param_3 == '\x03') {
      DAT_ffffc49c = 3;
      DAT_ffffc28a = 0;
      DAT_ffffc28d = 0;
    }
    else if (param_3 == '\x04') {
      DAT_ffffc49c = 4;
    }
    else {
      DAT_ffffc49c = 0;
    }
    uVar3 = 0;
    DAT_ffffc49f = 0;
    DAT_ffffc4a6 = 0;
    DAT_ffffc4a5 = 0;
    DAT_ffffc4a0 = 0;
  }
  DAT_ffffc496 = param_1;
  ref_setSR(uVar1);
  return uVar3;
}


