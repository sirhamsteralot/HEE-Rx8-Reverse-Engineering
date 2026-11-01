/* [MATH AND UNITS REVIEW]
 * 0.27777776 approximates 1/3.6, the km/h-to-m/s factor. Applied to an acceleration-like value and compared with +/-9.8, it suggests (km/h)/s to m/s^2; upstream timebase is not confirmed, so this remains a dimensional candidate.
 */
/* ROM address: 0x0002d318; body bytes: 262; decompiled */

undefined1 * FUN_0002d318(void)

{
  char cVar1;
  undefined1 *puVar2;
  float fVar3;
  
  cVar1 = DAT_ffffbfb9;
  fVar3 = DAT_ffffbfa0 - DAT_ffffbfa4;
  puVar2 = (undefined1 *)0x1;
  if (((((inferred_ram_ad18_ffffad18_ffffad18 == '\x01') || (puVar2 = (undefined1 *)0x1, DAT_ffffbbcf == '\x01')) ||
       (puVar2 = (undefined1 *)0x1, DAT_ffffb53a == '\x01')) ||
      ((puVar2 = (undefined1 *)(uint)DAT_ffffbced, puVar2 == (undefined1 *)0x1 &&
       ((((DAT_ffffbcf6 == '\0' && (DAT_ffffbfb9 == '\0')) &&
         ((DAT_ffffbfb5 == 0 && ((puVar2 = &DAT_ffffbfba, DAT_ffffbfba == '\0' && (fVar3 < -15.0))))
         )) || ((puVar2 = (undefined1 *)(uint)DAT_ffffbfb5, puVar2 == (undefined1 *)0x1 &&
                ((fVar3 < -15.0 && (puVar2 = (undefined1 *)0x1d4c, 0x1d4b < DAT_ffffbcf2))))))))))
     || (((DAT_ffffbd49 == '\0' && (DAT_ffffbfa0 < 22.5)) ||
         (((9.799999 < DAT_ffffbccc * 0.27777776 || (DAT_ffffbccc * 0.27777776 < -9.799999)) ||
          (puVar2 = (undefined1 *)(uint)DAT_ffffbc34, puVar2 == (undefined1 *)0x1)))))) {
    DAT_ffffbcea = 1;
  }
  else {
    DAT_ffffbcea = 0;
  }
  if (-15.0 <= fVar3) {
    DAT_ffffbcf2 = 0;
  }
  else {
    puVar2 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffbcf2,1);
    DAT_ffffbcf2 = (ushort)puVar2;
  }
  DAT_ffffbcf6 = cVar1;
  return puVar2;
}


