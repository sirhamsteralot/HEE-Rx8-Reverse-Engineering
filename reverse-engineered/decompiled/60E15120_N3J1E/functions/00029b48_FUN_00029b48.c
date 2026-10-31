/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): 0x41980000; decode = raw * 1 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00029b48; body bytes: 170; decompiled */

char * FUN_00029b48(void)

{
  byte bVar2;
  char *pcVar1;
  byte bVar3;
  char *pcVar4;
  
  bVar3 = DAT_ffffbc82;
  bVar2 = rx8_encode_u8_affine_saturate(0x41980000,0x3f800000,0);
  if (bVar2 < bVar3) {
    bVar3 = bVar2;
  }
  pcVar4 = (char *)((short)(ushort)bVar3 * 5);
  pcVar1 = pcVar4;
  if (((((((&CAL_Table_3D___110__1075)[(int)pcVar4] == '\0') &&
         (pcVar1 = pcVar4 + 0x75981, *pcVar1 == '\0')) &&
        (pcVar1 = pcVar4 + 0x75982, *pcVar1 == '\0')) &&
       ((pcVar1 = pcVar4 + 0x75983, *pcVar1 == '\0' &&
        (pcVar1 = (char *)(uint)engine_running_ffffa428, pcVar1 == (char *)((int)&vector_Poweron_Reset + 1)))))
      && (pcVar1 = (char *)(int)DAT_ffffaa62, pcVar1 == (char *)0x0)) ||
     ((DAT_ffffa938 == 0 && (pcVar1 = (char *)(uint)DAT_ffffa93a, pcVar1 != (char *)0x0)))) {
    DAT_ffffbb26 = 1;
  }
  else {
    DAT_ffffbb26 = 0;
  }
  return pcVar1;
}


