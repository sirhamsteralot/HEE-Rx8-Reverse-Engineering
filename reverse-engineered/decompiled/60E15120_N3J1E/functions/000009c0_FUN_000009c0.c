/* [ADDITIONAL SOURCE REVIEW]
 * can_enter_reset_mode [high]: MCR |= 1 then waits GSR bit3 (0x08) set, 4000-iteration timeout. Emulator: with the GSR handshake modeled, boot passes; without it boot spun here forever.
 */
/* ROM address: 0x000009c0; body bytes: 30; decompiled */

uint can_enter_reset_mode(char *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)*param_1 | 1;
  *param_1 = (char)uVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}


