/* [ADDITIONAL SOURCE REVIEW]
 * wheelspeed_rear_avg_calc [medium]: Averages the two rear wheelspeed signals from CAN (0xffffbbac/0xffffbbae, written by 0x2b1d6 from payload bytes bba4-bba7): decode_u16_affine(0x3c23d70a, 0xc2c80000, x) each, mean, re-encode saturate; 0xffff (invalid) handling when either is -1 or 0xffffbbbc < 6 or 0xffffc61e set. Pool 0x2a48c.
 * RAM 0xffffbbac wheelspeed_lr_raw (uint16): Raw LR wheelspeed from CAN payload (0x2b1d6: bba4*0x100+bba5); validity flag 0xffffbbb9 by 0x2b17e; averaged in 0x2b046.
 * RAM 0xffffbbae wheelspeed_rr_raw (uint16): Raw RR wheelspeed (0x2b1d6: bba6*0x100+bba7); validity flag 0xffffbbba by 0x2b1aa; averaged in 0x2b046.
 */
/* ROM address: 0x0002b046; body bytes: 216; decompiled */

undefined4 * candidate_wheelspeed_rear_avg_calc(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar3 = (undefined4 *)0xffff;
  uVar7 = 0x3c23d70a;
  puVar1 = &DAT_0002b110;
  uVar8 = 0xc2c80000;
  if (((DAT_ffffc61e == '\0') && (puVar1 = (undefined4 *)0x6, DAT_ffffbbbc < 6)) &&
     ((wheelspeed_lr_raw_ffffbbac != -1 || (puVar1 = (undefined4 *)0x6, wheelspeed_rr_raw_ffffbbae != -1)))) {
    puVar1 = (undefined4 *)0x6;
    puVar3 = (undefined4 *)(int)wheelspeed_rr_raw_ffffbbae;
    if ((wheelspeed_lr_raw_ffffbbac != -1) &&
       (puVar1 = (undefined4 *)0x6, puVar3 = (undefined4 *)(int)wheelspeed_lr_raw_ffffbbac, wheelspeed_rr_raw_ffffbbae != -1)) {
      fVar4 = (float)rx8_decode_u16_affine
                               (0x3c23d70a,0xc2c80000,(undefined4 *)(int)wheelspeed_lr_raw_ffffbbac);
      fVar5 = (float)rx8_decode_u16_affine(uVar7,uVar8,(int)wheelspeed_rr_raw_ffffbbae);
      puVar1 = (undefined4 *)
               rx8_encode_u16_affine_saturate((fVar4 + fVar5) * 0.5,uVar7,uVar8);
      puVar3 = puVar1;
    }
  }
  uVar6 = 0;
  if (((uint)puVar3 & 0xffff) == 0xffff) {
    uVar7 = 0;
    DAT_ffffbbbb = 1;
  }
  else {
    uVar7 = rx8_decode_u16_affine(uVar7,uVar8);
    uVar2 = rx8_is_outside_tolerance_band(uVar7,uVar6,0x3ba3d70a);
    puVar1 = (undefined4 *)(uVar2 & 0xff);
    if (puVar1 == (undefined4 *)0x0) {
      uVar7 = uVar6;
    }
    DAT_ffffbbbb = 0;
  }
  vehicle_speed_ffffbbb4 = uVar7;
  return puVar1;
}


