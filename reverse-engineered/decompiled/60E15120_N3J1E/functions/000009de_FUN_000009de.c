/* [ADDITIONAL SOURCE REVIEW]
 * can_exit_reset_mode [high]: MCR &= ~1, waits GSR bit3 clear. Pairs with 0x9c0 (HCAN1 copies at 0x1e94/0x1eb2).
 */
/* ROM address: 0x000009de; body bytes: 30; decompiled */

byte can_exit_reset_mode(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1 & 0xfe;
  *param_1 = bVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) == 0) {
      return bVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}


