/* ROM address: 0x00064304; body bytes: 104; decompiled */

undefined4 FUN_00064304(char param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while (((&DAT_ffff8936)[uVar1 * 0x34] != param_1 || (DAT_ffff8d74 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  iVar2 = uVar1 * 0x34;
  *param_2 = (&DAT_ffff8930)[uVar1 * 0x1a];
  param_2[1] = (&DAT_ffff8932)[uVar1 * 0x1a];
  param_2[2] = (&DAT_ffff8934)[uVar1 * 0x1a];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8936)[iVar2];
  *(undefined1 *)((int)param_2 + 7) = (&DAT_ffff8937)[iVar2];
  *(undefined1 *)(param_2 + 4) = (&DAT_ffff8938)[iVar2];
  return 1;
}


