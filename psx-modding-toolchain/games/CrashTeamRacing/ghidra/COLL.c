
// called "COLL" for "Collisions"

// COLL_GetThreadMeta
undefined ** FUN_8001d094(uint param_1)

{
  if (param_1 < 0xe2) {
    return &PTR_s_NO_FUNC_80081088 + param_1 * 3;
  }
  return &PTR_s_NO_FUNC_80081088;
}



// WARNING: Removing unreachable block (ram,0x8001d4e0)

// Static Instance collision (part of function after this one)
// Get normal, calculate reflection/bounce(?)
uint FUN_8001d0c4(short *param_1,byte *param_2)

{
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;

  // number of vertices is four and not three
  if (param_2[1] == 4) 
  {  
	*(byte **)(param_1 + 0x24) = param_2;
	
	// 1f80014a
    param_1[0x21] = param_1[0x21] + 1;
  }
  
  // no collision flag is zero i.e. it has collision (this check the upper byte only?)
  if ((param_1[0x11] & 0x40U) == 0) 
  { 
    *(undefined4 *)(param_1 + 0xe4) = 0;
    uVar5 = (int)*param_1 - (int)param_1[8];
    uVar7 = (int)param_1[2] - (int)param_1[10]; 
    *(uint *)(param_1 + 0xe2) = uVar5;
    *(uint *)(param_1 + 0xe6) = uVar7;
    sVar2 = *(short *)(param_2 + 0x10);
    *(undefined4 *)(param_1 + 0xea) = 0;
    iVar14 = (int)sVar2 - (int)param_1[8];
    *(int *)(param_1 + 0xe8) = iVar14;
    iVar12 = 0;
    iVar15 = (int)*(short *)(param_2 + 0x14) - (int)param_1[10];
    *(int *)(param_1 + 0xec) = iVar15;
    uVar13 = 0;
    if ((*param_2 & 0x40) != 0) {
      iVar12 = (int)param_1[1] - (int)param_1[9];
      *(int *)(param_1 + 0xe4) = iVar12;
      uVar13 = (int)*(short *)(param_2 + 0x12) - (int)param_1[9];
      *(uint *)(param_1 + 0xea) = uVar13;
    }
    uVar8 = uVar5 & 0xffff | iVar12 << 0x10;
    uVar3 = iVar15 * 0x10000;

	
    gte_ldR11R12(uVar8);
    gte_ldR13R21(uVar7 & 0xffff | iVar14 * 0x10000);
    gte_ldR22R23(uVar13 & 0xffff | uVar3);
    gte_ldVXY0(uVar8);
    gte_ldVZ0(uVar7);
    gte_mvmva(0,0,0,3,0);
    iVar11 = gte_stMAC1();
    iVar4 = gte_stMAC2();
	
	
	*(int *)(param_1 + 0xd6) = iVar11;
    *(int *)(param_1 + 0xd8) = iVar4;
    
	if (0 < iVar4) 
	{  
      gte_ldLZCS(iVar4);
      iVar9 = gte_stLZCR();
	  
      uVar3 = iVar9 - 2;
      uVar8 = uVar3;
      if ((int)uVar3 < 0) {
        uVar8 = 0;
      }
      if (0xc < (int)uVar3) {
        uVar8 = 0xc;
      }
      uVar3 = 0xc - uVar8;
      iVar9 = iVar11 >> (uVar3 & 0x1f);
      iVar4 = iVar4 << (uVar8 & 0x1f);
      if (-1 < iVar9) {
        iVar10 = 0;
        if (iVar9 != 0) {
          iVar10 = iVar4 / iVar9;
          if (iVar9 == 0) {
            trap(0x1c00);
          }
          if ((iVar9 == -1) && (iVar4 == -0x80000000)) {
            trap(0x1800);
          }
        }
        *(int *)(param_1 + 0xda) = iVar10;
        iVar4 = 0;
        iVar9 = (int)(iVar10 * uVar5) >> 0xc;
        if ((*param_2 & 0x40) != 0) {
          iVar4 = iVar10 * iVar12 >> 0xc;
        }
        uVar3 = iVar9 - iVar14 & 0xffffU | (iVar4 - uVar13) * 0x10000;
        *(int *)(param_1 + 0xee) = iVar9;
        *(int *)(param_1 + 0xf0) = iVar4;
        iVar4 = (int)(iVar10 * uVar7) >> 0xc;
        iVar9 = iVar4 - iVar15;
        *(int *)(param_1 + 0xf2) = iVar4;


        gte_ldR11R12(uVar3);
        gte_ldR13R21(iVar9);
        gte_ldVXY0(uVar3);
        gte_ldVZ0(iVar9);
        gte_mvmva(0,0,0,3,0);


        uVar3 = SEXT24(*(short *)(param_2 + 0x16));
        iVar4 = ((int)param_1[3] + uVar3) * ((int)param_1[3] + uVar3);
        iVar9 = getCopReg(2,0xc800);
        *(int *)(param_1 + 0xdc) = iVar4;
        iVar4 = iVar4 - iVar9;
        *(int *)(param_1 + 0xde) = iVar9;
        if (-1 < iVar4) {
          if (iVar4 != 0) {
            if (iVar11 != 0) {
              if (iVar11 == 0) {
                trap(0x1c00);
              }
              if ((iVar11 == -1) && (iVar4 * 0x1000 == -0x80000000)) {
                trap(0x1800);
              }
              iVar10 = iVar10 - (iVar4 * 0x1000) / iVar11;
            }
            *(int *)(param_1 + 0xe0) = iVar10;
          }
		  
		  // 1f80014a
          uVar3 = (uint)(*(int *)(param_1 + 0x42) < iVar10);
          
		  iVar11 = 0;
		  
		  // 1f80014a
          if (*(int *)(param_1 + 0x42) >= iVar10) {
            iVar9 = 0;
            iVar17 = 0;
            if (0 < iVar10) {
              iVar4 = uVar5 * iVar10;
              iVar11 = iVar4 >> 0xc;
              iVar9 = iVar12 * iVar10 >> 0xc;
              iVar17 = (int)(uVar7 * iVar10) >> 0xc;
            }
            
			if ((((*param_2 & 0x20) == 0) || ((int)*(short *)(param_2 + 0x12) <= iVar9)) ||
               (bVar1 = (int)*(short *)(param_2 + 0x12) + (int)*(short *)(param_2 + 2) < iVar9,
               uVar3 = (uint)bVar1, !bVar1)) 
			{
              *(byte **)(param_1 + 0x24) = param_2;
              *(int *)(param_1 + 0x42) = iVar10;
              
			  // 1f80014a
			  param_1[0x21] = param_1[0x21] + 1;
              
			  *(int *)(param_1 + 0xf4) = iVar11;
              *(int *)(param_1 + 0xf6) = iVar9;
              *(int *)(param_1 + 0xf8) = iVar17;
              iVar12 = 0;
              if ((*param_2 & 0x40) != 0) {
                iVar12 = iVar9 - uVar13;
              }
              iVar15 = iVar17 - iVar15;
              uVar5 = iVar11 - iVar14 & 0xffffU | iVar12 << 0x10;
			  
			  
              gte_ldR11R12(uVar5);
              gte_ldR13R21(iVar15);
              gte_ldVXY0(uVar5);
              gte_ldVZ0(iVar15);
			  
			  // Multiply Vector By Matrix With Vector Addition
              gte_mvmva(0,0,0,3,0);
			  
			  
			  uVar6 = gte_stMAC1();
              iVar4 = SquareRoot0(uVar6);
              
			  
			  iVar10 = 0x1000000 / iVar4;
              if (iVar4 == 0) {
                trap(0x1c00);
              }
              
			  // normalVecX
			  iVar16 = (iVar11 - iVar14) * iVar10 >> 0xc;
              *(int *)(param_1 + 0xfa) = iVar16;
			  
			  // normalVecY
              iVar14 = iVar12 * iVar10 >> 0xc;
              *(int *)(param_1 + 0xfc) = iVar14;
              
			  // normalVecZ
			  iVar4 = iVar15 * iVar10 >> 0xc;
              *(int *)(param_1 + 0xfe) = iVar4;
              
			  iVar15 = (int)*(short *)(param_2 + 0x16);
              param_1[0xe] = param_1[8] + (short)iVar11;
			  
			  // set normal vector of quadblock
              param_1[0x38] = (short)iVar16;
              param_1[0x39] = (short)iVar14;
              param_1[0x3a] = (short)iVar4;
			  
              param_1[0x10] = param_1[10] + (short)iVar17;
              param_1[0xf] = param_1[9] + (short)iVar9;
              *(undefined *)(param_1 + 0x3f) = 6;
              iVar12 = iVar16 * iVar15 >> 0xc;
              *(int *)(param_1 + 0x100) = iVar12;
              iVar14 = iVar14 * iVar15 >> 0xc;
              *(int *)(param_1 + 0x102) = iVar14;
              iVar15 = iVar4 * iVar15 >> 0xc;
              *(int *)(param_1 + 0x104) = iVar15;
              sVar2 = *(short *)(param_2 + 0x10) + (short)iVar12;
              param_1[0x3c] = sVar2;
              param_1[0x34] = sVar2;
              sVar2 = *(short *)(param_2 + 0x12) + (short)iVar14;
              param_1[0x3d] = sVar2;
              param_1[0x35] = sVar2;
              uVar3 = (uint)*(ushort *)(param_2 + 0x14) + iVar15;
              param_1[0x3e] = (short)uVar3;
              param_1[0x36] = (short)uVar3;
            }
          }
        }
      }
    }
  }
  else 
  {
	// normal vector is {0, 0x1000, 0}
    param_1[0x39] = 0x1000;
    uVar3 = 6;
    param_1[0x38] = 0;
    param_1[0x3a] = 0;
    *(undefined *)(param_1 + 0x3f) = 6;
    *(undefined4 *)(param_1 + 0x42) = 0;
    *(byte **)(param_1 + 0x24) = param_2;
    param_1[0xe] = param_1[8];
    param_1[0xf] = param_1[9];
    param_1[0x10] = param_1[10];
    param_1[0x21] = param_1[0x21] + 1;
  }
  return uVar3;
}


// COLL_SearchCallback_Instances
// param1 - VisData node
void FUN_8001d610(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;

  piVar3 = *(int **)(param_1 + 0x14);
  if (piVar3 != (int *)0x0) {
    iVar1 = *piVar3;
    piVar4 = piVar3 + 2;
    //iterate through all quadblocks withing visdata
    while (iVar1 != 0) {
      iVar1 = *(int *)(param_2 + 0xc4) + -1;
      if (-1 < iVar1) {
        iVar2 = iVar1 * 4 + param_2; // four vertices
        do {
          iVar1 = iVar1 + -1; // substract from counter, one quadblock checked
          if (piVar3 == *(int **)(iVar2 + 0x88)) goto LAB_8001d750;
          iVar2 = iVar2 + -4;
        } while (-1 < iVar1);
      }
      // closest to this specific quadblock(s?)
      if (((((((*(byte *)piVar3 & 0x80) == 0) || (piVar4[5] == 0)) ||
            ((*(uint *)(*(int *)(piVar4[5] + 0x2c) + 0x28) & 0xf) != 0)) &&
           ((*(short *)(param_2 + 0x30) <= *(short *)((int)piVar4 + 2) &&
            (*(short *)(piVar4 + -1) <= *(short *)(param_2 + 0x36))))) &&
          ((*(short *)(param_2 + 0x32) <= *(short *)(piVar4 + 1) &&
           ((*(short *)((int)piVar4 + -2) <= *(short *)(param_2 + 0x38) &&
            (*(short *)(param_2 + 0x34) <= *(short *)((int)piVar4 + 6))))))) &&
         (*(short *)piVar4 <= *(short *)(param_2 + 0x3a))) {
        FUN_8001d0c4(param_2,piVar3); 
      }
LAB_8001d750:
      piVar3 = piVar3 + 8;
      iVar1 = *piVar3;
      piVar4 = piVar4 + 8;
    }
  }
  return;
}


// COLL_CheckDriver_AI
// param1 is driver pos,
// param2 is driver rot
void FUN_8001d77c(short *param_1,short *param_2,short *param_3)

{
  short sVar1;
  int iVar2;

  iVar2 = (int)param_3[3] * (int)param_3[3];
  *(int *)(param_3 + 4) = iVar2;
  *param_3 = *param_1;
  param_3[1] = param_1[1];
  sVar1 = param_1[2];
  param_3[2] = sVar1;
  param_3[0xf] = param_3[1];
  param_3[0xe] = *param_3;
  *(int *)(param_3 + 0xc) = iVar2;
  param_3[0x10] = sVar1;
  param_3[0xb] = param_3[3];
  param_3[8] = *param_2;
  param_3[9] = param_2[1];
  param_3[10] = param_2[2];
  sVar1 = (short)((int)param_3[8] - (int)param_3[0xb]);
  if ((int)*param_3 - (int)param_3[3] < (int)param_3[8] - (int)param_3[0xb]) {
    sVar1 = (short)((int)*param_3 - (int)param_3[3]);
  }
  param_3[0x18] = sVar1;
  sVar1 = (short)((int)param_3[9] - (int)param_3[0xb]);
  if ((int)param_3[1] - (int)param_3[3] < (int)param_3[9] - (int)param_3[0xb]) {
    sVar1 = (short)((int)param_3[1] - (int)param_3[3]);
  }
  param_3[0x19] = sVar1;
  sVar1 = (short)((int)param_3[10] - (int)param_3[0xb]);
  if ((int)param_3[2] - (int)param_3[3] < (int)param_3[10] - (int)param_3[0xb]) {
    sVar1 = (short)((int)param_3[2] - (int)param_3[3]);
  }
  param_3[0x1a] = sVar1;
  sVar1 = (short)((int)param_3[8] + (int)param_3[0xb]);
  if ((int)param_3[8] + (int)param_3[0xb] < (int)*param_3 + (int)param_3[3]) {
    sVar1 = (short)((int)*param_3 + (int)param_3[3]);
  }
  param_3[0x1b] = sVar1;
  sVar1 = (short)((int)param_3[9] + (int)param_3[0xb]);
  if ((int)param_3[9] + (int)param_3[0xb] < (int)param_3[1] + (int)param_3[3]) {
    sVar1 = (short)((int)param_3[1] + (int)param_3[3]);
  }
  param_3[0x1c] = sVar1;
  sVar1 = (short)((int)param_3[10] + (int)param_3[0xb]);
  if ((int)param_3[10] + (int)param_3[0xb] < (int)param_3[2] + (int)param_3[3]) {
    sVar1 = (short)((int)param_3[2] + (int)param_3[3]);
  }
  *(undefined4 *)(param_3 + 0x42) = 0x1000;
  param_3[0x1d] = sVar1;
  param_3[0x21] = 0;
  param_3[0x1e] = 0;
  *(undefined4 *)(param_3 + 0xd2) = 0;
  *(undefined4 *)(param_3 + 0x62) = 0;

  // Search BSP, check collision with LEV instances
  FUN_8001ebec(*(undefined4 *)(*(int *)(param_3 + 0x16) + 0x18),param_3 + 0x18,FUN_8001d610,param_3)
  ;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

// COLL_CheckDriver_Player
// check collisions with all quadblocks (no instances)
void FUN_8001d944(int param_1,int param_2)
// param_1 = thread
// param_2 = Racer struct Pointer
{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  undefined4 uVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_30;
  int local_2c;
  int local_28;

  //turn off 17th flag of Actions Flag set (means ?)
  *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) & 0xfffeffff;

  DAT_1f800118._0_2_ = (short)((uint)*(undefined4 *)(param_2 + 0x2d4) >> 8);
  iVar13 = (*(int *)(param_2 + 0x2d8) >> 8) + 0x80;
  DAT_1f800118._2_2_ = (short)iVar13;
  DAT_1f80011c._0_2_ = (short)((uint)*(undefined4 *)(param_2 + 0x2dc) >> 8);
  DAT_1f800108 = (short)((uint)*(undefined4 *)(param_2 + 0x2d4) >> 8);
  iVar9 = (*(int *)(param_2 + 0x2d8) >> 8) + -0x100;
  DAT_1f80010a = (short)iVar9;
  DAT_1f80010c = (short)((uint)*(undefined4 *)(param_2 + 0x2dc) >> 8);
  DAT_1f800134 = **(int **)(PTR_DAT_8008d2ac + 0x160);
  DAT_1f800130 = 0x10;

  // ground and wall quadblock flags
  DAT_1f80012c = 0x3000;

  // If 3P or 4P
  // low-LOD collision (2 triangles)
  DAT_1f80012a = 0;

  // if number of screens is less than 3 (1P or 2P)
  if ((byte)PTR_DAT_8008d2ac[0x1ca8] < 3) 
  {
	// high-LOD collision (8 triangles)
    DAT_1f80012a = 2;
  }

  DAT_1f800146 = 0;
  DAT_1f800144 = 0;
  DAT_1f800138 = (short)DAT_1f800118;
  if (DAT_1f800108 < (short)DAT_1f800118) {
    DAT_1f800138 = DAT_1f800108;
  }
  iVar13 = iVar13 * 0x10000 >> 0x10;
  iVar9 = iVar9 * 0x10000 >> 0x10;
  DAT_1f80013a = DAT_1f800118._2_2_;
  if (iVar9 < iVar13) {
    DAT_1f80013a = DAT_1f80010a;
  }
  DAT_1f80013c = (short)DAT_1f80011c;
  if (DAT_1f80010c < (short)DAT_1f80011c) {
    DAT_1f80013c = DAT_1f80010c;
  }
  DAT_1f80013e = (short)DAT_1f800118;
  if ((short)DAT_1f800118 < DAT_1f800108) {
    DAT_1f80013e = DAT_1f800108;
  }
  DAT_1f800140 = DAT_1f800118._2_2_;
  if (iVar13 < iVar9) {
    DAT_1f800140 = DAT_1f80010a;
  }
  DAT_1f800142 = (short)DAT_1f80011c;
  if ((short)DAT_1f80011c < DAT_1f80010c) {
    DAT_1f800142 = DAT_1f80010c;
  }
  DAT_1f800124._0_2_ = DAT_1f800108;
  DAT_1f800124._2_2_ = DAT_1f80010a;
  DAT_1f800128 = DAT_1f80010c;

  // quadblock under driver
  if (*(int *)(param_2 + 0x350) != 0)
  {
	// COLL_Quadblock_Graphics
    FUN_8001f41c(*(int *)(param_2 + 0x350),&DAT_1f800108);
  }

  if (((DAT_1f800146 == 0) && (DAT_1f800134 != 0)) && (*(int *)(DAT_1f800134 + 0x18) != 0))
  {
	// Search full BSP tree for COLL_SearchCallback_QuadBlocks_Graphics
    FUN_8001ebec(*(int *)(DAT_1f800134 + 0x18),&DAT_1f800138,FUN_8001f5f0,&DAT_1f800108);
  }

  // thread -> instance
  iVar9 = *(int *)(param_1 + 0x34);

  if (DAT_1f800146 == 0) {
    *(uint *)(iVar9 + 0x70) = ((uint)*(byte *)(param_2 + 0x4a) + 1) * 0x1000000 | 0x4000;
    *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) & 0xffffbfff;
    *(int *)(param_2 + 0x2d0) = *(int *)(param_2 + 0x2d8) + -0x10000;
  }

  else
  {
    *(uint *)(iVar9 + 0x70) =
         _DAT_1f800178 >> 6 & 0xff | (_DAT_1f800178 >> 0x10 & 0x3fc0) << 2 |
         ((uint)(DAT_1f80017c >> 6) & 0xff) << 0x10 |
         ((uint)*(byte *)(param_2 + 0x4a) + 1) * 0x1000000;

	// save quadblock height
    *(int *)(param_2 + 0x2d0) = (int)DAT_1f800124._2_2_ << 8;

	*(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 4;

	// get quadblock terrain
    cVar1 = *(char *)(DAT_1f800188 + 0x38);

    if (

		(
			// if terrain is mud
			(cVar1 == '\x0e') ||

			// if terrain is water
			(cVar1 == '\x04')

		) ||

		// if terrain is "fastwater"
		(cVar1 == '\r')
	   )
	{
	  // set split height to zero,
	  // height of all water, and mud
      *(undefined2 *)(iVar9 + 0x56) = 0;

	  // instance is now vertically split
      *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) | 0x2000;
    }

    puVar3 = PTR_DAT_8008d2ac;

	// if number of screens is less than 2
    if ((byte)PTR_DAT_8008d2ac[0x1ca8] < 2)
	{
	  // quadblock flags
      uVar2 = *(ushort *)(DAT_1f800188 + 0x12);

	  // if quadblock is not wall
	  if ((uVar2 & 0x2000) == 0) {

		// if quadblock is not invisible
        if ((uVar2 & 1) == 0) {

		  // if quadblock is not reflective (ice)
          if ((uVar2 & 4) == 0)
		  {
			// instance is not reflective
            *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) & 0xffffbfff;
          }

		  // if quadblock is reflective (ice)
          else
		  {
			// instance is reflective
            *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) | 0x4000;

			// vertical line for split or reflection
            *(undefined2 *)(iVar9 + 0x56) = *(undefined2 *)(*(int *)(puVar3 + 0x160) + 0x184);
          }
        }

		// ====================

		// what? shouldn't 0x186 be ice reflection,
		// from personal tests? What does 0x184 do?

		// ====================


		// if quadblock is invisible
        else
		{
		  // instance is reflective
          *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) | 0x4000;

		  // vertical line for split or reflection
          *(undefined2 *)(iVar9 + 0x56) = *(undefined2 *)(*(int *)(puVar3 + 0x160) + 0x186);
        }
      }
    }
    iVar15 = (int)*(short *)(param_2 + 0x370) * 5 + (int)DAT_1f800178 * 3;
    iVar14 = (int)*(short *)(param_2 + 0x372) * 5 + (int)DAT_1f80017a * 3;
    iVar13 = (int)*(short *)(param_2 + 0x374) * 5 + (int)(short)DAT_1f80017c * 3;

    // uVar6 = sqrt(param_1 * 2 ^ param_2), get distance or length of something
    uVar6 = FUN_80059070(iVar15 * iVar15 + iVar14 * iVar14 + iVar13 * iVar13,0x18);

    uVar6 = uVar6 >> 0xc;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar15 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar14 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar13 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    // normalize a vector
    *(undefined2 *)(param_2 + 0x370) = (short)((iVar15 * 0x1000) / (int)uVar6);
    *(undefined2 *)(param_2 + 0x372) = (short)((iVar14 * 0x1000) / (int)uVar6);
    *(undefined2 *)(param_2 + 0x374) = (short)((iVar13 * 0x1000) / (int)uVar6);

	// if quadblock can make an echo sound
    if ((*(ushort *)(DAT_1f800188 + 0x12) & 0x80) != 0)
	{
      // turn on flag for engine sounds to echo
      *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) | 0x10000;
    }

	// quadblock under driver
    *(int *)(param_2 + 0x350) = DAT_1f800188;

    if (
			(*(int *)(param_2 + 0x2d8) <= *(int *)(param_2 + 0x2d0) + 0x1000) ||

			(
				(
					// if terrain is mud
					*(char *)(DAT_1f800188 + 0x38) == '\x0e' &&

					// mud is always at height (y = 0)

					// if you are under the mud
					(*(int *)(param_2 + 0x2d8) < 1)
				)
			)
		)
	 {
	  // if quadblock is ground
      if ((*(ushort *)(DAT_1f800188 + 0x12) & 0x1000) != 0)
	  {
        *(uint *)(param_2 + 0xa4) = _DAT_1f800178;
        uVar2 = DAT_1f80017c;

		// driver is not in air, they're on ground
        *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 8;

		*(ushort *)(param_2 + 0xa8) = uVar2;
      }

	  uVar6 = _DAT_1f800178;

	  // if driver was not previously touching quadblock
	  if (*(int *)(param_2 + 0xa0) == 0)
	  {
		  // set quadblock touched, to quadblock under you
        *(int *)(param_2 + 0xa0) = DAT_1f800188;

        *(uint *)(param_2 + 0x360) = uVar6;
        *(ushort *)(param_2 + 0x364) = DAT_1f80017c;
      }

      if (((DAT_1f8001d4 != 0) && (DAT_1f8001d8 != 0)) && (DAT_1f8001dc != 0)) {
        uVar12 = (uint)*(byte *)(DAT_1f8001d4 + 8);
        iVar14 = (int)DAT_1f8001d0;
        iVar13 = (int)DAT_1f8001d2;
        uVar10 = (uint)*(byte *)(DAT_1f8001d4 + 9);
        uVar6 = (uint)*(byte *)(DAT_1f8001d4 + 10);
        iVar15 = ((int)(iVar14 * (*(byte *)(DAT_1f8001d8 + 8) - uVar12)) >> 0xc) +
                 ((int)(iVar13 * (*(byte *)(DAT_1f8001dc + 8) - uVar12)) >> 0xc) + uVar12;
        iVar11 = ((int)(iVar14 * (*(byte *)(DAT_1f8001d8 + 9) - uVar10)) >> 0xc) +
                 ((int)(iVar13 * (*(byte *)(DAT_1f8001dc + 9) - uVar10)) >> 0xc) + uVar10;
        iVar13 = ((int)(iVar14 * (*(byte *)(DAT_1f8001d8 + 10) - uVar6)) >> 0xc) +
                 ((int)(iVar13 * (*(byte *)(DAT_1f8001dc + 10) - uVar6)) >> 0xc) + uVar6;
        if (iVar15 < 0) {
          iVar15 = 0;
        }
        if (0xff < iVar15) {
          iVar15 = 0xff;
        }
        iVar14 = iVar11;
        if (iVar11 < 0) {
          iVar14 = 0;
        }
        if (0xff < iVar11) {
          iVar14 = 0xff;
        }
        iVar11 = iVar13;
        if (iVar13 < 0) {
          iVar11 = 0;
        }
        if (0xff < iVar13) {
          iVar11 = 0xff;
        }
        iVar14 = ((iVar15 * 0x4c >> 8) + (iVar14 * 0x96 >> 8) + (iVar11 * 0x1e >> 8)) * -0x20 +
                 0xc00;
        iVar13 = iVar14;
        if (iVar14 < 0) {
          iVar13 = 0;
        }
        iVar15 = iVar13 << 3;
        if (0x1000 < iVar14) {
          iVar13 = 0x1000;
          iVar15 = 0x8000;
        }
        iVar13 = (iVar15 - iVar13) * 8;
        *(undefined2 *)(param_2 + 0x508) =
             (short)((uint)*(ushort *)(param_2 + 0x508) * 200 + iVar13 >> 8);
        *(undefined2 *)(iVar9 + 0x22) = (short)((uint)*(ushort *)(iVar9 + 0x22) * 200 + iVar13 >> 8)
        ;
      }
    }
  }
  if (*(int *)(param_2 + 0x2d0) + 0x8000 < *(int *)(param_2 + 0x2d8))
  {
	// terrain meta
    uVar7 = FUN_80057c68(10);
    *(undefined4 *)(param_2 + 0x35c) = uVar7;
  }

  // if driver height is under
  if (*(int *)(param_2 + 0x2d8) <

	  // fixed height value for instant death?
      ((int)*(short *)(*(int *)(**(int **)(PTR_DAT_8008d2ac + 0x160) + 0x18) + 6) + -0x40) * 0x100)
  {
	// player needs mask grab
    *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 1;
  }

  iVar9 = *(int *)(param_2 + 0x8c) - *(int *)(param_2 + 0x3a4);

  if (
	 (
		// quadblock under driver
		(*(int *)(param_2 + 0xa0) != 0) &&

		((*(ushort *)(param_2 + 0xaa) & 9) == 0)
	  ) &&

		// not mask grab
		(*(char *)(param_2 + 0x376) != '\x05')
	  )
  {
    *(int *)(param_2 + 0x88) =
         *(int *)(param_2 + 0x88) + ((int)((uint)*(ushort *)(param_2 + 0x360) << 0x10) >> 0x11);
    *(int *)(param_2 + 0x8c) =
         *(int *)(param_2 + 0x8c) + ((int)((uint)*(ushort *)(param_2 + 0x362) << 0x10) >> 0x11);
    *(int *)(param_2 + 0x90) =
         *(int *)(param_2 + 0x90) + ((int)((uint)*(ushort *)(param_2 + 0x364) << 0x10) >> 0x11);
  }

  // driver -> quadBlock (just touched)
  iVar13 = *(int *)(param_2 + 0xa0);

  *(undefined4 *)(param_2 + 0x3a0) = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)(param_2 + 0x3a4) = *(undefined4 *)(param_2 + 0x8c);
  *(undefined4 *)(param_2 + 0x3a8) = *(undefined4 *)(param_2 + 0x90);

  // if you are not touching a quadblock (mid-jump)
  if (iVar13 == 0) {
LAB_8001e4d0:

    // jump timer
	if (*(short *)(param_2 + 0x3f2) != 0)
	{
      //turn on 20th bit of Actions Flag set, racer is now airborne
      *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) | 0x80000;
    }

    if (*(short *)(param_2 + 0x3fa) != 0)
	{
      //turn on 7th bit of Actions Flag set (means racer is doing an artificial jump?)
      *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) | 0x40;
    }

	// terrain data (of air?), this could be the YEEHAW!-trigger / SKR%
	uVar7 = FUN_80057c68(10);
    *(undefined4 *)(param_2 + 0x358) = uVar7;

	// terrainID (nothing)
    *(undefined *)(param_2 + 0xc2) = 10;

	puVar3 = PTR_DAT_8008d2ac;

    //turn off 1st bit of Actions Flag set (means player is not touching the ground)
    *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) & 0xfffffffe;

	*(short *)(param_2 + 0x3fc) = *(short *)(param_2 + 0x3fc) + *(short *)(puVar3 + 0x1d04);

	// amount of time the player can jump after leaving quadblock, 3-4 frames, 0xa0 milliseconds
	iVar9 = (uint)*(ushort *)(param_2 + 0x3f4) - (uint)*(ushort *)(puVar3 + 0x1d04);
    *(undefined2 *)(param_2 + 0x3f4) = (short)iVar9;

	// can't go negative
    if (iVar9 * 0x10000 < 0) {
      *(undefined2 *)(param_2 + 0x3f4) = 0;
    }

    iVar9 = 7;
    if (*(short *)(param_2 + 0x3f4) == 0) {
      *(undefined2 *)(param_2 + 0x3f2) = 0;
      *(undefined2 *)(param_2 + 0x3fa) = 0;
    }
  }

  // if you are touching a quadblock
  else {

	// if quadblock is not killplane
    if ((*(ushort *)(iVar13 + 0x12) & 0x200) == 0) {

	  if (
			(
				// if you are not being mask grabbed
				(*(char *)(param_2 + 0x376) != '\x05') &&

				((*(ushort *)(param_2 + 0xaa) & 1) == 0)
			) &&

			// if quadblock is ground
			((*(ushort *)(iVar13 + 0x12) & 0x1000) != 0)
		  )
	  {

		// if quadblock (just touched) respawnIndex is invalid
		if (*(byte *)(iVar13 + 0x3e) == 0xff) {

		  // Level ID on Adventure Arena
          if (*(int *)(PTR_DAT_8008d2ac + 0x1a10) - 0x19U < 5)
		  {
			// last "valid" quadblock (for mask grab)
			// = quadblock just touched
            *(int *)(param_2 + 0x354) = iVar13;
          }
        }

		// if respawnIndex is valid
		else
		{
		  // level -> respawn points
          iVar13 = *(int *)(*(int *)(PTR_DAT_8008d2ac + 0x160) + 0x14c) +

					// respawnIndex * 0xc
                   (uint)*(byte *)(iVar13 + 0x3e) * 0xc;

          if (
				// if driver is not exempt from skipping big track portion
				(
					// if racer didn't cross the startline backwards
					((*(uint *)(param_2 + 0x2c8) & 0x1000000) == 0) &&

					// if respawn->0x8 is not 0, or 1,
					// if these are not the quadblocks right behind the finish line,
					// if this is not a No-Mask-Zone (NMZ),
					(1 < *(byte *)(iVar13 + 8))
				) &&

				// if big skip is detected, how?

				// track length * 2 ?
				((int)((uint)(*(ushort *)(*(int *)(*(int *)(PTR_DAT_8008d2ac + 0x160) + 0x14c) + 6) >> 2) << 3)

				// less than
				<

				// distanceToFinish_checkpoint - 8x dist_to_finish of quadblock touched
				(int)(*(int *)(param_2 + 0x48c) + (uint)*(ushort *)(iVar13 + 6) * -8))

				// if it were inverted, would it make any more sense?:
				// if 8x dist_to_finish of quadblock touched - distanceToFinish_checkpoint
				// <, or >,
				// track length * 2?
			  )
		  {
			// player needs to be mask grabbed, illegal shortcut
            *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 1;
          }

		  // if there was not an illegal shortcut,
		  // or if you're in an NMZ
          else
		  {
			// track length
			// level -> respawn points[0] -> dist_to_finish
            uVar2 = *(ushort *)(*(int *)(*(int *)(PTR_DAT_8008d2ac + 0x160) + 0x14c) + 6);

            if (
					(
						// if more than 50% track completion
						(
							// quadblock just touched
							// lev->restartPts[ quadblock (driver 0xa0) -> respawn_index ] -> dist to finish
							(uint)*(ushort *)(iVar13 + 6) <

							// track length / 2
							(uint)((int)((uint)uVar2 * 0xf) >> 4)
						) &&

						// last valid quadblock
						// lev->restartPts[ quadblock (driver 0x354) -> respawn_index ] is valid
						(bVar4 = *(byte *)(*(int *)(param_2 + 0x354) + 0x3e), bVar4 != 0xff)
					) &&

					// if backtracked more than 25% completion in one jump
					(
					  (uint)*(ushort *)

					    // last valid quadblock
						// lev->restartPts[ quadblock (driver 0x354) -> respawn_index ] -> dist to finish
						((uint)bVar4 * 0xc + *(int *)(*(int *)(PTR_DAT_8008d2ac + 0x160) + 0x14c) + 6)

						+

						// track length / 4
						(uint)(uVar2 >> 2)

						<

						// quadblock just touched
						// lev->restartPts[ quadblock (driver 0xa0) -> respawn_index ] -> dist to finish
						(uint)*(ushort *)(iVar13 + 6)
					)
			   )
			{
			  // mask-grab the driver
			  goto LAB_8001e340;
			}

			// last "valid" quadblock touched (for mask grab) = quadblock just touched
			*(undefined4 *)(param_2 + 0x354) = *(undefined4 *)(param_2 + 0xa0);
          }
        }
      }
    }

	// if quadblock is killplane
	else {
LAB_8001e340:

	  // player needs to be mask grabbed
      *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 1;
    }

    *(undefined2 *)(param_2 + 0x3fc) = 0;

	//turn off 7th and 20th bits of Actions Flag set (means ? (7) and racer is in the air)
    *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) & 0xfff7ffbf;

	// if driver is not touching a quadblock (driver is in the air)
	if ((*(ushort *)(param_2 + 0xaa) & 8) == 0) goto LAB_8001e4d0;

    if (

		// If you are on ice
		// Also could be an effect after hitting Red Potion
		(*(short *)(param_2 + 0x50a) == 2) ||

		// If Icy Tracks Cheat is enabled
		((*(uint *)(PTR_DAT_8008d2ac + 8) & 0x80000) != 0))
	{

	  // Set terrain to Ice
      *(undefined *)(param_2 + 0xc2) = 6;
      uVar6 = 6;
    }

	// If you are not on ice
    else
	{
	  // driver -> quadblock -> terrainType
      bVar4 = *(byte *)(*(int *)(param_2 + 0xa0) + 0x38);

      uVar6 = (uint)bVar4;

      if (
			// if you are not currently on ice
			(bVar4 != 6) &&

			// you "were" on ice last frame
			(*(char *)(param_2 + 0xc2) == '\x06')
		  )
	  {
		// make the car hit the breaks for a second
        *(undefined2 *)(param_2 + 0x414) = 0xfec0;
      }

	  // set new driver -> terrainType
      *(byte *)(param_2 + 0xc2) = bVar4;
    }

	// terrain meta
    uVar7 = FUN_80057c68(uVar6);
    *(undefined4 *)(param_2 + 0x358) = uVar7;
    *(undefined4 *)(param_2 + 0x35c) = uVar7;

	// driver can jump 0.16s after leaving quadblock
	*(undefined2 *)(param_2 + 0x3f4) = 0xa0;

    //uVar6 = Actions Flag set
    uVar6 = *(uint *)(param_2 + 0x2c8);
    //turn on 1st bit of Actions Flag set (means player is touching the ground)
    *(uint *)(param_2 + 0x2c8) = uVar6 | 1;
    if ((*(uint *)(param_2 + 0x2cc) & 1) == 0) {
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      //turn on 1st, 2nd and 8th bits of Actions Flag set (means racer is on the ground (1),
      //racer started touching the ground in this frame (2) and ? (8))
      *(uint *)(param_2 + 0x2c8) = uVar6 | 0x83;
      *(undefined2 *)(param_2 + 0x414) = 0x140;

      // Map value from [oldMin, oldMax] to [newMin, newMax]
      // inverting newMin and newMax will give an inverse range mapping
      uVar6 = FUN_80058f9c(iVar9,0x100,0x3c00,0x78,0xfa);

      //if racer is not being mask grabbed
      if (*(char *)(param_2 + 0x376) != '\x05')
	  {
		// volume
        uVar6 = (uVar6 & 0xff) << 0x10;

		// if no echo
        if ((*(uint *)(param_2 + 0x2c8) & 0x10000) == 0)
		{
		  // no distortion, equal left/right
          uVar6 = uVar6 | 0x8080;
        }

		// if echo
        else
		{
		  // add echo
          uVar6 = uVar6 | 0x1008080;
        }

		// OtherFX_Play_LowLevel
		// sound of landing on ground
        FUN_800284d0(7,1,uVar6);
      }
    }
    iVar9 = 6;
  }
  iVar13 = 8 - iVar9;
  local_30 = iVar9 * *(short *)(param_2 + 0x368) + iVar13 * *(short *)(param_2 + 0xa4) >> 3;
  local_2c = iVar9 * *(short *)(param_2 + 0x36a) + iVar13 * *(short *)(param_2 + 0xa6) >> 3;
  local_28 = iVar9 * *(short *)(param_2 + 0x36c) + iVar13 * *(short *)(param_2 + 0xa8) >> 3;

  //if Hazard Timer is positive (racer in hazard)
  if (0 < (int)*(short *)(param_2 + 0xe)) {
  	//uVar6 = Hazard Timer * 0xC
    uVar6 = (int)*(short *)(param_2 + 0xe) * 0xc;

	// approximate trigonometry
	sVar5 = (short)*(int *)(&DAT_800845a0 + (uVar6 & 0x3ff) * 4);
    iVar9 = *(int *)(&DAT_800845a0 + (uVar6 & 0x3ff) * 4) >> 0x10;

	if ((uVar6 & 0x400) == 0) {
      iVar13 = (int)sVar5;
      if ((uVar6 & 0x800) != 0) {
        iVar14 = -iVar9;
        goto LAB_8001e680;
      }
    }
    else {
      iVar14 = (int)sVar5;
      iVar13 = iVar9;
      if ((uVar6 & 0x800) == 0) {
        iVar9 = -iVar14;
      }
      else {
LAB_8001e680:
        iVar13 = -iVar13;
        iVar9 = iVar14;
      }
    }
	
    gte_ldVXY0(iVar13 * 0x19 >> 10 & 0xffff);
    gte_ldVZ0(iVar9 * 0x19 >> 10);

	// rtv0     cop2 $0486012  v0 * rotmatrix
    gte_rtv0();

	read_mt(iVar9,iVar14,iVar13);
	
    local_30 = local_30 + iVar9;
    local_2c = local_2c + iVar14;
    local_28 = local_28 + iVar13;
  }

  // uVar6 = sqrt(param_1 * 2 ^ param_2)
  uVar6 = FUN_80059070(local_30 * local_30 + local_2c * local_2c + local_28 * local_28,0x18);

  uVar6 = uVar6 >> 0xc;
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  if ((uVar6 == 0xffffffff) && (local_30 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  *(undefined2 *)(param_2 + 0x368) = (short)((local_30 << 0xc) / (int)uVar6);
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  if ((uVar6 == 0xffffffff) && (local_2c << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  *(undefined2 *)(param_2 + 0x36a) = (short)((local_2c << 0xc) / (int)uVar6);
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  if ((uVar6 == 0xffffffff) && (local_28 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  uVar10 = SEXT24(*(short *)(param_2 + 0x39a));
  *(undefined2 *)(param_2 + 0x36c) = (short)((local_28 << 0xc) / (int)uVar6);

  // approximate trigonometry
  sVar5 = (short)*(int *)(&DAT_800845a0 + (uVar10 & 0x3ff) * 4);
  iVar9 = *(int *)(&DAT_800845a0 + (uVar10 & 0x3ff) * 4) >> 0x10;

  if ((uVar10 & 0x400) == 0) {
    iVar13 = (int)sVar5;
    if ((uVar10 & 0x800) != 0) {
      iVar14 = -iVar9;
      goto LAB_8001e84c;
    }
  }
  else {
    iVar14 = (int)sVar5;
    iVar13 = iVar9;
    if ((uVar10 & 0x800) == 0) {
      iVar9 = -iVar14;
    }
    else {
LAB_8001e84c:
      iVar13 = -iVar13;
      iVar9 = iVar14;
    }
  }
  lVar8 = ratan2(-(int)*(short *)(param_2 + 0x368) * iVar9 + *(short *)(param_2 + 0x36c) * iVar13 >>
                 0xc,(int)*(short *)(param_2 + 0x36a));
  *(undefined2 *)(param_2 + 0x2f0) = (short)lVar8;

  //if Hazard Timer is negative
  if (*(short *)(param_2 + 0xe) < 1)
  {
    //if racer is on the ground
    if ((*(uint *)(param_2 + 0x2c8) & 1) != 0)
	{
      //iVar9 = Speed
      iVar9 = (int)*(short *)(param_2 + 0x38c);

	  //iVar9 = |iVar9|
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }

	  //if |iVar9| > 0x1000
      if (0x1000 < iVar9)
	  {
      	//iVar9 = Visual Offset from Ground
        iVar9 = (int)*(char *)(param_2 + 0x377);

		//iVar9 = |iVar9|
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }

		//if Visual Offset from Ground < 4 and (?)
        if ((iVar9 < 4) && ((*(uint *)(*(int *)(param_2 + 0x358) + 4) & 1) != 0)) {
          *(undefined2 *)(param_2 + 0x3ee) = 4;
        }
        goto LAB_8001e964;
      }
    }
    *(undefined2 *)(param_2 + 0x3ee) = 0;
  }
  //if racer is in hazard
  else {

	//iVar9 = Visual Offset from Ground
    iVar9 = (int)*(char *)(param_2 + 0x377);

	//iVar9 = |iVar9|
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    //if Visual Offset from Ground < 4 and ((?), racer is not spinning)
    if ((iVar9 < 4) && (*(undefined2 *)(param_2 + 0x3ee) = 4, *(char *)(param_2 + 0x376) != '\x03'))
    {
      //iVar9 = Visual Offset from Ground
      iVar9 = (int)*(char *)(param_2 + 0x377);

      //if Visual Offset from Ground < 1, skip next 3 lines of code
      if (iVar9 < 1) goto code_r0x8001e96c;

	  // OtherFX_Play
      FUN_80028468(0x10,1);
    }
  }
LAB_8001e964:
	//iVar9 = Visual Offset from Ground
  iVar9 = (int)*(char *)(param_2 + 0x377);
code_r0x8001e96c:
	//iVar9 = |iVar9|
  if (iVar9 < 0) {
    iVar9 = -iVar9;
  }
  //if Visual Offset from Ground > 9
  if (9 < iVar9) {
    *(undefined2 *)(param_2 + 0x3ee) = 0;
  }

  // if you're close to the ground
  if (*(short *)(param_2 + 0x3ee) == 0) {

	//bVar4 = Visual Offset from Ground - 4
    bVar4 = *(char *)(param_2 + 0x377) - 4;

	if (
			//if Visual Offset from Ground is positive
			('\0' < *(char *)(param_2 + 0x377)) &&

			// Set new offset
			(*(byte *)(param_2 + 0x377) = bVar4,

			// if you are about to go through floor
			(int)((uint)bVar4 << 0x18) < 1))
	{
      //prevent Visual Offset from Ground from going negative
      *(undefined *)(param_2 + 0x377) = 0;

	  // if driver -> terrain -> flags & play_sound
	  if ((*(uint *)(*(int *)(param_2 + 0x358) + 4) & 0x20) != 0)
	  {
		// half volume, no distort, balance left/right
        uVar7 = 0x808080;

        // if echo
        if ((*(uint *)(param_2 + 0x2c8) & 0x10000) != 0)
		{
		  // add echo
          uVar7 = 0x1808080;
        }

		// OtherFX_Play_LowLevel
		// play sound depending on terrain
        FUN_800284d0((uint)*(ushort *)(*(int *)(param_2 + 0x358) + 0x32),0,uVar7);
      }
    }

	//bVar4 = Visual Offset from Ground - 4;
    bVar4 = *(char *)(param_2 + 0x377) - 4;

    //Visual Offset from Ground -= 4
    *(byte *)(param_2 + 0x377) = bVar4;

    //if Visual Offset from Ground is negative
    if ((int)((uint)bVar4 << 0x18) < 0) {
    	//prevent it from going negative
      *(undefined *)(param_2 + 0x377) = 0;
    }
  }

  // if you're not close to the ground
  else {
    *(short *)(param_2 + 0x3ee) = *(short *)(param_2 + 0x3ee) + -1;
    *(char *)(param_2 + 0x377) = *(char *)(param_2 + 0x377) + '\x03';
  }

  //if Y pos < -0x8000 and (?)
  if ((*(int *)(param_2 + 0x2d8) < -0x8000) &&

	 // Level -> 0xdc
	 // flag, toggle enable mask grab below height
     ((*(uint *)(*(int *)(PTR_DAT_8008d2ac + 0x160) + 0xdc) & 2) != 0))
  {
	// player needs to be mask grabbed,
	// too far underwater in Crash Cove
    *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 1;
  }

  if (
		(
			(
				//if racer is not being mask grabbed
				(*(char *)(param_2 + 0x376) != '\x05') &&

				// if player needs to be grabbed (hit kill plane)
				((*(ushort *)(param_2 + 0xaa) & 1) != 0)
			) &&

			// last quadblock touched by driver,
			// why?
			(*(int *)(param_2 + 0x354) != 0)
		) &&

		((
			// if debug no-grab variable is off
			(DAT_8008d000 & 0x1000) == 0 &&

			((*(uint *)(param_2 + 0xbc) & 8) == 0)
		))
	 )

  {
	// NOP-ing this allows you to jump out of bounds,
	// and not get mask-grabbbed when you hit kill planes

	// Player_MaskGrab_Init
    FUN_800671b0(param_1,param_2);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

// Similar to other search, this time rigged
// for graphics, but NOP-ing will also break collision for AI and shot Items, why?
// COLL_SearchTree_NoCallback
void FUN_8001eb0c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  undefined4 uVar9;
  short sVar10;
  uint uVar11;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  int iVar12;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  undefined4 unaff_s7;
  int iVar13;
  int iVar14;
  undefined4 unaff_s8;
  undefined4 unaff_retaddr;
  undefined auStackX0 [16];

  *(short *)((int)param_3 + 6) = (short)param_4;
  *(short *)((int)param_3 + 0x16) = (short)param_4;
  
  // 1f80014a
  *(short *)((int)param_3 + 0x42) = 0;
  
  *(short *)(param_3 + 0xf) = 0;
  
  // 1f800136
  *(short *)((int)param_3 + 0x3e) = 0;
  
  param_3[0x69] = 0;
  param_3[0x31] = 0;
  uVar9 = *param_1;
  sVar2 = *(short *)(param_1 + 1);
  iVar7 = *(int *)(param_3[0xb] + 0x18);
  *param_3 = uVar9;
  *(short *)(param_3 + 1) = sVar2;
  param_3[7] = uVar9;
  *(short *)(param_3 + 8) = sVar2;
  sVar2 = *(short *)(param_2 + 1);
  param_3[4] = *param_2;
  *(short *)(param_3 + 5) = sVar2;
  param_3[0x21] = 0x1000;
  param_3[2] = param_4 * param_4;
  param_3[6] = param_4 * param_4;
  sVar2 = *(short *)param_3;
  sVar8 = *(short *)(param_3 + 4);
  sVar5 = *(short *)((int)param_3 + 2);
  sVar10 = *(short *)((int)param_3 + 0x12);
  sVar4 = sVar2;
  if ((int)sVar2 - (int)sVar8 < 0) {
    sVar4 = sVar8;
    sVar8 = sVar2;
  }
  *(short *)((int)param_3 + 0x36) = sVar4;
  *(short *)(param_3 + 0xc) = sVar8;
  sVar2 = *(short *)(param_3 + 1);
  sVar8 = *(short *)(param_3 + 5);
  sVar4 = sVar5;
  if ((int)sVar5 - (int)sVar10 < 0) {
    sVar4 = sVar10;
    sVar10 = sVar5;
  }
  *(short *)(param_3 + 0xe) = sVar4;
  *(short *)((int)param_3 + 0x32) = sVar10;
  sVar5 = sVar2;
  if ((int)sVar2 - (int)sVar8 < 0) {
    sVar5 = sVar8;
    sVar8 = sVar2;
  }
  *(short *)((int)param_3 + 0x3a) = sVar5;
  *(short *)(param_3 + 0xd) = sVar8;
  if (iVar7 == 0) {
    DAT_1f800030 = unaff_s0;
    return;
  }
  _DAT_1f800050 = &_gp_4;
  iVar3 = 0x1f800000;
  sVar2 = *(short *)(param_3 + 0xc);
  sVar8 = *(short *)((int)param_3 + 0x32);
  sVar5 = *(short *)(param_3 + 0xd);
  sVar10 = *(short *)((int)param_3 + 0x36);
  iVar13 = (int)*(short *)(param_3 + 0xe);
  iVar14 = (int)*(short *)((int)param_3 + 0x3a);
  iVar12 = iVar7;
  DAT_1f800030 = unaff_s0;
  DAT_1f800034 = unaff_s1;
  DAT_1f800038 = unaff_s2;
  DAT_1f80003c = unaff_s3;
  DAT_1f800040 = unaff_s4;
  DAT_1f800044 = unaff_s5;
  DAT_1f800048 = unaff_s6;
  _DAT_1f80004c = unaff_s7;
  DAT_1f800054 = (undefined *)register0x00000074;
  _DAT_1f800058 = unaff_s8;
  DAT_1f80005c = unaff_retaddr;
  do {
    uVar11 = *(uint *)(iVar12 + 0x18);
    if ((uVar11 + 1 & 0xffff) != 0) {
      iVar12 = (uVar11 & 0x3fff) * 0x20 + iVar7;
      if (((((*(int *)(iVar12 + 4) >> 0x10) - iVar13 < 1) &&
           (iVar6 = *(int *)(iVar12 + 0xc), (int)(short)*(int *)(iVar12 + 4) - (int)sVar10 < 1)) &&
          ((int)sVar2 - (*(int *)(iVar12 + 8) >> 0x10) < 1)) &&
         ((((short)*(int *)(iVar12 + 8) - iVar14 < 1 && ((int)sVar5 - (iVar6 >> 0x10) < 1)) &&
          (*(undefined2 *)(iVar3 + 0x70) = (short)uVar11, (int)sVar8 - (int)(short)iVar6 < 1)))) {
        iVar3 = iVar3 + 2;
      }
    }
    if ((int)uVar11 >> 0x10 != 0xffffffff) {
      iVar12 = ((int)uVar11 >> 0x10 & 0x3fffU) * 0x20 + iVar7;
      if ((((*(int *)(iVar12 + 4) >> 0x10) - iVar13 < 1) &&
          (iVar6 = *(int *)(iVar12 + 0xc), (int)(short)*(int *)(iVar12 + 4) - (int)sVar10 < 1)) &&
         (((int)sVar2 - (*(int *)(iVar12 + 8) >> 0x10) < 1 &&
          ((((short)*(int *)(iVar12 + 8) - iVar14 < 1 && ((int)sVar5 - (iVar6 >> 0x10) < 1)) &&
           (*(undefined2 *)(iVar3 + 0x70) = (short)(uVar11 >> 0x10),
           (int)sVar8 - (int)(short)iVar6 < 1)))))) {
        iVar3 = iVar3 + 2;
      }
    }
    while( true ) {
      if (iVar3 == 0x1f800000) {
        return;
      }
      psVar1 = (short *)(iVar3 + 0x6e);
      iVar3 = iVar3 + -2;

	  // ptrVisData
      iVar12 = ((int)*psVar1 & 0x3fffU) * 0x20 + iVar7;

	  // If this is not a leaf node, break
      if (((int)*psVar1 & 0x4000U) == 0) break;
	  
	  // as long as we have leaf nodes, keep going...

	  DAT_1f800064 = iVar13;
      _DAT_1f800068 = iVar14;
      DAT_1f80006c = iVar3;

	  // COLL_SearchCallback_QuadBlocks_Graphics
      FUN_8001f5f0(iVar12,param_3);

	  iVar3 = DAT_1f80006c;
      iVar13 = DAT_1f800064;
      iVar14 = _DAT_1f800068;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

// param1, pointer to visData
// param2, pointer to hitbox (min + max of x,y,z)
// param3, callback if item collides with anything
// COLL_SearchTree_WithCallback
void FUN_8001ebec(int param_1,short *param_2,code *param_3,undefined4 param_4)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  int iVar9;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  undefined4 unaff_s7;
  int iVar10;
  int iVar11;
  undefined4 unaff_s8;
  undefined4 unaff_retaddr;
  undefined auStackX0 [16];

  // if level has no visData, quit
  if (param_1 == 0) {
    DAT_1f800030 = unaff_s0;
    return;
  }

  // start array of VisDataIDs
  // inside scratchpad
  iVar6 = 0x1f800000;

  sVar2 = *param_2;
  sVar3 = param_2[1];
  sVar4 = param_2[2];
  sVar5 = param_2[3];
  iVar10 = (int)param_2[4];
  iVar11 = (int)param_2[5];
  iVar9 = param_1;
  DAT_1f800030 = unaff_s0;
  DAT_1f800034 = unaff_s1;
  DAT_1f800038 = unaff_s2;
  DAT_1f80003c = unaff_s3;
  DAT_1f800040 = unaff_s4;
  DAT_1f800044 = unaff_s5;
  DAT_1f800048 = unaff_s6;
  _DAT_1f80004c = unaff_s7;
  _DAT_1f800050 = (undefined *)register0x00000070;
  DAT_1f800054 = (undefined *)register0x00000074;
  _DAT_1f800058 = unaff_s8;
  DAT_1f80005c = unaff_retaddr;

  // at start of loop, iVar9 is first VisData in LEV,
  // which is the root node of the BSP tree
  do
  {
	// get child IDs (assuming branch, not leaf)
    uVar8 = *(uint *)(iVar9 + 0x18);

	// if left child exists
    if ((uVar8 + 1 & 0xffff) != 0)
	{
	  // set new VisData pointer, to left child
      iVar9 = (uVar8 & 0x3fff) * 0x20 + param_1;

      if (

			(
				(
					// if minPos[y] is less than iVar10
					((*(int *)(iVar9 + 4) >> 0x10) - iVar10 < 1) &&

					(
						iVar7 = *(int *)(iVar9 + 0xc),

						// if minPos[x] is less than sVar5
						(int)(short)*(int *)(iVar9 + 4) - (int)sVar5 < 1
					)
				) &&

				// if maxPos[x] is more than sVar2
				((int)sVar2 - (*(int *)(iVar9 + 8) >> 0x10) < 1)
			) &&
			(
				(
					(
						// if minPos[z] < iVar11
						(short)*(int *)(iVar9 + 8) - iVar11 < 1 &&

						// if maxPos[z] > sVar4
						((int)sVar4 - (iVar7 >> 0x10) < 1)
					) &&

					(
						// set ID list index to VisData left child ID,
						// array starts 0x70 bytes after start of scratchpad
						*(undefined2 *)(iVar6 + 0x70) = (short)uVar8,

						// if maxPos[y] > sVar3
						(int)sVar3 - (int)(short)iVar7 < 1
					)
				)
			)
		  )
	  {
		// increment array index
        iVar6 = iVar6 + 2;
      }
    }

	// if right child exists
    if ((int)uVar8 >> 0x10 != 0xffffffff)
	{
	  // set new VisData pointer, to right child
      iVar9 = ((int)uVar8 >> 0x10 & 0x3fffU) * 0x20 + param_1;

      if (
			(
				// if minPos[y] is less than iVar10
				((*(int *)(iVar9 + 4) >> 0x10) - iVar10 < 1) &&

				(
					iVar7 = *(int *)(iVar9 + 0xc),

					// if minPos[x] is less than sVar5
					(int)(short)*(int *)(iVar9 + 4) - (int)sVar5 < 1
				)
			) &&
			(
				(
					// if maxPos[x] is more than sVar2
					(int)sVar2 - (*(int *)(iVar9 + 8) >> 0x10) < 1 &&

					(
						(
							(
								// if minPos[z] is less than iVar11
								(short)*(int *)(iVar9 + 8) - iVar11 < 1 &&

								// if maxPos[z] is more than iVar11
								((int)sVar4 - (iVar7 >> 0x10) < 1)
							) &&

							// set ID list index to VisData right child ID,
							// array starts 0x70 bytes after start of scratchpad
							(*(undefined2 *)(iVar6 + 0x70) = (short)(uVar8 >> 0x10),

							// if maxPos[y] > sVar3
							(int)sVar3 - (int)(short)iVar7 < 1)
						)
					)
				)
			)
		  )
	  {
		// increment array index
        iVar6 = iVar6 + 2;
      }
    }

    while( true )
	{
	  // if nothing in the array was written,
	  // due to pointer never incrementing
      if (iVar6 == 0x1f800000) {
        return;
      }

	  // backtrack the array
      psVar1 = (short *)(iVar6 + 0x6e);
      iVar6 = iVar6 + -2;

	  // ptrVisData of last index
	  iVar9 = ((int)*psVar1 & 0x3fffU) * 0x20 + param_1;

	  // If this is not a leaf node, break
      if (((int)*psVar1 & 0x4000U) == 0) break;
	  
	  // as long as we have leaf nodes, keep going...

      DAT_1f800064 = iVar10;
      _DAT_1f800068 = iVar11;
      DAT_1f80006c = iVar6;

	  // function callback
	  // iVar9 is VisData
      (*param_3)(iVar9,param_4);

	  iVar6 = DAT_1f80006c;
      iVar10 = DAT_1f800064;
      iVar11 = _DAT_1f800068;
    }

  } while( true );
}


// part of triangle collision
uint FUN_8001ede4(undefined2 *param_1,short *param_2,short *param_3,short *param_4)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;

  iVar6 = (int)*param_2;
  iVar7 = (int)param_2[1];
  iVar8 = (int)param_2[2];
  sVar1 = param_4[1];
  uVar9 = *param_3 - iVar6;
  iVar10 = param_3[1] - iVar7;
  uVar11 = param_3[2] - iVar8;
  uVar2 = uVar9 & 0xffff | iVar10 * 0x10000;
  gte_ldR11R12(uVar2);
  gte_ldR13R21(uVar11 & 0xffff | (*param_4 - iVar6) * 0x10000);
  gte_ldR22R23(sVar1 - iVar7 & 0xffffU | (param_4[2] - iVar8) * 0x10000);
  gte_ldVXY0(uVar2);
  gte_ldVZ0(uVar11);
  gte_mvmva(0,0,0,3,0);
  iVar3 = gte_stMAC2();
  iVar4 = gte_stMAC1();
  gte_ldLZCS(iVar3);
  iVar5 = gte_stLZCR();
  uVar2 = iVar5 - 2;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0 < iVar5 + -0xe) {
    uVar2 = 0xc;
  }
  if ((int)(uVar2 - 0xc) < 0) {
    iVar4 = iVar4 >> (-(uVar2 - 0xc) & 0x1f);
  }
  iVar5 = 0;
  if (iVar4 != 0) {
    iVar4 = (iVar3 << (uVar2 & 0x1f)) / iVar4;
    if ((-1 < iVar4) && (iVar5 = iVar4, 0 < iVar4 + -0x1000)) {
      iVar5 = 0x1000;
    }
  }
  gte_ldIR0(iVar5);
  gte_ldMAC1(iVar6);
  gte_ldMAC2(iVar7);
  gte_ldMAC3(iVar8);
  gte_ldsv_(uVar9,iVar10,uVar11);
  gte_gpl12();
  read_mt(uVar9,iVar10,uVar11);
  *param_1 = (short)uVar9;
  param_1[1] = (short)iVar10;
  param_1[2] = (short)uVar11;
  return sVar1 - iVar7;
}



// hand-written assembly,
// stores $s0, $s1, and $s2
// then restores registers, and saves t2
// into $a0->58
void FUN_8001ef1c(void)
{
		// does a breakpoint at 8001ef1c ever hit anyway?

        8001ef1c e0 ff bd 27     addiu      sp,sp,-0x20
        8001ef20 10 00 b0 af     sw         s0,0x10(sp)
        8001ef24 14 00 b1 af     sw         s1,0x14(sp)
        8001ef28 1c 00 bf af     sw         ra,0x1c(sp)
        8001ef2c 18 00 b2 af     sw         s2,0x18(sp)

		// FUN_8001ef50, except skipping 9 instructions
		8001ef30 dd 7b 00 0c     jal        FUN_8001ef74
        8001ef34 58 00 8a 8c     _lw        t2,0x58(a0)

        8001ef38 1c 00 bf 8f     lw         ra,0x1c(sp)
        8001ef3c 18 00 b2 8f     lw         s2,0x18(sp)
        8001ef40 14 00 b1 8f     lw         s1,0x14(sp)
        8001ef44 10 00 b0 8f     lw         s0,0x10(sp)
        8001ef48 08 00 e0 03     jr         ra
        8001ef4c 20 00 bd 27     _addiu     sp,sp,0x20
}


// called once per triangle on a quadblock (graphics COLL)
void FUN_8001ef50(int param_1,short *param_2,short *param_3,short *param_4)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;

  // FUN_8001ef74 is this same function, except skipping
  // the first 9 instructions

  sVar1 = param_2[3];
  uVar6 = *(undefined4 *)(param_2 + 6);
  iVar7 = *(int *)(param_2 + 8);
  *(short *)(param_1 + 0x3c) = *(short *)(param_1 + 0x3c) + 1;
  *(short *)(param_1 + 0x52) = sVar1;
  *(undefined4 *)(param_1 + 0x54) = uVar6;
  *(int *)(param_1 + 0x58) = iVar7;
  uVar8 = (uint)*(short *)(param_1 + 0x14);
  gte_ldR11R12(*(undefined4 *)(param_1 + 0x10));
  iVar11 = (int)*(short *)(param_1 + 0x1c) - (int)*(short *)(param_1 + 0x10);
  uVar12 = (int)*(short *)(param_1 + 0x1e) - (int)*(short *)(param_1 + 0x12);
  iVar14 = (int)*(short *)(param_1 + 0x20) - uVar8;
  gte_ldR13R21(iVar11 * 0x10000 | uVar8 & 0xffff);
  gte_ldR22R23(uVar12 & 0xffff | iVar14 * 0x10000);
  gte_ldVXY0(param_1 + 0x54);
  gte_ldVZ0(iVar7);
  gte_mvmva_b(0,0,0,3,0);
  iVar5 = gte_stMAC2();
  iVar2 = gte_stMAC1();
  if (iVar5 < 0) {
    iVar2 = -(iVar2 + (iVar7 >> 0x10) * -0x2000) / (iVar5 >> 0xc);
    gte_ldMAC1((int)*(short *)(param_1 + 0x10));
    gte_ldMAC2((int)*(short *)(param_1 + 0x12));
    gte_ldMAC3(uVar8);
    gte_ldsv_(iVar11,uVar12,iVar14);
    gte_ldIR0(iVar2);
    if ((-1 < iVar2) && (iVar2 + -0x1000 < 1)) {
      gte_gpl12_b();
      read_mt(iVar11,uVar12,iVar14);
      *(short *)(param_1 + 0x4c) = (short)iVar11;
      *(short *)(param_1 + 0x4e) = (short)uVar12;
      *(short *)(param_1 + 0x50) = (short)iVar14;
      psVar3 = param_3;
      if (*(short *)(param_1 + 0x52) == 3) {
        iVar2 = (int)param_2[2];
        iVar9 = param_3[2] - iVar2;
        iVar7 = param_4[2] - iVar2;
        iVar2 = iVar14 - iVar2;
        iVar5 = iVar9;
        if (iVar9 < 0) {
          iVar5 = -iVar9;
        }
        iVar14 = iVar7;
        if (iVar7 < 0) {
          iVar14 = -iVar7;
        }
        iVar10 = iVar9;
        if (iVar5 - iVar14 < 0) {
          psVar3 = param_4;
          param_4 = param_3;
          iVar10 = iVar7;
          iVar7 = iVar9;
        }
        iVar14 = (int)*param_2;
        iVar5 = *psVar3 - iVar14;
        iVar9 = *param_4 - iVar14;
        iVar11 = iVar11 - iVar14;
      }
      else {
        iVar2 = (int)*param_2;
        if (*(short *)(param_1 + 0x52) == 1) {
          iVar14 = *param_3 - iVar2;
          iVar7 = *param_4 - iVar2;
          iVar2 = iVar11 - iVar2;
          iVar5 = iVar14;
          if (iVar14 < 0) {
            iVar5 = -iVar14;
          }
          iVar11 = iVar7;
          if (iVar7 < 0) {
            iVar11 = -iVar7;
          }
          iVar10 = iVar14;
          if (iVar5 - iVar11 < 0) {
            psVar3 = param_4;
            param_4 = param_3;
            iVar10 = iVar7;
            iVar7 = iVar14;
          }
          iVar11 = (int)param_2[1];
          iVar5 = psVar3[1] - iVar11;
          iVar9 = param_4[1] - iVar11;
          iVar11 = uVar12 - iVar11;
        }
        else {
          iVar2 = (int)param_2[1];
          iVar11 = param_3[1] - iVar2;
          iVar7 = param_4[1] - iVar2;
          iVar2 = uVar12 - iVar2;
          iVar5 = iVar11;
          if (iVar11 < 0) {
            iVar5 = -iVar11;
          }
          iVar9 = iVar7;
          if (iVar7 < 0) {
            iVar9 = -iVar7;
          }
          iVar10 = iVar11;
          if (iVar5 - iVar9 < 0) {
            psVar3 = param_4;
            param_4 = param_3;
            iVar10 = iVar7;
            iVar7 = iVar11;
          }
          iVar11 = (int)param_2[2];
          iVar5 = psVar3[2] - iVar11;
          iVar9 = param_4[2] - iVar11;
          iVar11 = iVar14 - iVar11;
        }
      }
      iVar14 = -0x1000;
      iVar13 = -0x1000;
      if (iVar10 == 0) {
        iVar14 = -0x1000;
        if (iVar7 == 0) {
          return;
        }
        iVar13 = (iVar2 << 0xc) / iVar7;
        if ((-1 < iVar13) && (iVar13 + -0x1000 < 1)) {
          iVar14 = (iVar11 * 0x1000 - iVar13 * iVar9) / iVar5;
        }
      }
      else {
        iVar9 = iVar9 * iVar10 - iVar7 * iVar5 >> 6;
        if (iVar9 != 0) {
          iVar13 = ((iVar11 * iVar10 - iVar2 * iVar5) * 0x40) / iVar9;
          if ((-1 < iVar13) && (iVar13 + -0x1000 < 1)) {
            iVar14 = (iVar2 * 0x1000 - iVar13 * iVar7) / iVar10;
          }
        }
      }
      iVar2 = *(int *)(param_1 + 100);
      if ((-1 < iVar14) && (iVar14 + iVar13 + -0x1000 < 1))
	  {
		// quadblock flags & TriggerScript
        if ((*(ushort *)(iVar2 + 0x12) & 0x40) != 0) {
          *(uint *)(param_1 + 0x1a4) = *(uint *)(param_1 + 0x1a4) | (uint)*(byte *)(iVar2 + 0x38);
          return;
        }
        *(int *)(param_1 + 0x80) = iVar2;
        *(short *)(param_1 + 200) = (short)iVar14;
        *(short *)(param_1 + 0xca) = (short)iVar13;
        uVar6 = *(undefined4 *)(psVar3 + 4);
        uVar4 = *(undefined4 *)(param_4 + 4);
        *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_2 + 4);
        *(undefined4 *)(param_1 + 0xd0) = uVar6;
        *(undefined4 *)(param_1 + 0xd4) = uVar4;
        *(short *)(param_1 + 0x3e) = *(short *)(param_1 + 0x3e) + 1;
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x4c);
        *(undefined2 *)(param_1 + 0x6c) = *(undefined2 *)(param_1 + 0x50);
        *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x54);
        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x58);
      }
    }
  }
  return;
}


// called once per triangle on a quadblock (physics COLL)
void FUN_8001f2dc(int param_1,undefined4 *param_2,short *param_3,short *param_4)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;

  // vector param_4 minus param_2
  gte_ldR11R12((int)*param_4 - (int)*(short *)param_2 & 0xffff);
  gte_ldR22R23((int)param_4[1] - (int)*(short *)((int)param_2 + 2) & 0xffff);
  gte_ldR33((int)param_4[2] - (int)*(short *)(param_2 + 1) & 0xffff);
  
  // vector param_3 minus param_2
  gte_ldsv_((int)*param_3 - (int)*(short *)param_2,
            (int)param_3[1] - (int)*(short *)((int)param_2 + 2),
            (int)param_3[2] - (int)*(short *)(param_2 + 1));
  
  // 0 for low-poly, 2 for high-poly
  uVar1 = (uint)*(byte *)(param_1 + 0x1ab);
  
  // quadblock offset 0x3f
  uVar3 = (uint)*(byte *)(param_1 + 0x1aa);
  
  gte_op0_b(0);
  
  // data from quadblock 0x48 - 0x5c
  iVar4 = (int)*(short *)(param_1 + 0x1a8);
  
  iVar5 = gte_stMAC1();
  iVar6 = gte_stMAC2();
  iVar7 = gte_stMAC3();
  
  gte_ldR11R12(*param_2);
  gte_ldR13R21((uint)*(ushort *)(param_2 + 1));
  
  iVar5 = (iVar5 >> (uVar1 & 0x1f)) * iVar4 >> (uVar3 & 0x1f);
  iVar6 = (iVar6 >> (uVar1 & 0x1f)) * iVar4 >> (uVar3 & 0x1f);
  iVar4 = (iVar7 >> (uVar1 & 0x1f)) * iVar4 >> (uVar3 & 0x1f);
  
  gte_ldsv_(iVar5,iVar6,iVar4);
  
  *(short *)(param_2 + 3) = (short)iVar5;
  *(short *)((int)param_2 + 0xe) = (short)iVar6;
  gte_rtir_b();
  iVar7 = gte_stMAC1();
  *(short *)(param_2 + 4) = (short)iVar4;
  *(short *)((int)param_2 + 0x12) = (short)(iVar7 >> 1);
  if (iVar5 < 0) { // absolute x
    iVar5 = -iVar5;
  }
  if (iVar6 < 0) { // absolute y 
    iVar6 = -iVar6;
  }
  if (iVar4 < 0) { // absolute z
    iVar4 = -iVar4;
  }
  sVar2 = 1;
  if (iVar5 - iVar6 < 0) {
    sVar2 = 1;
    if (-1 < iVar6 - iVar4) {
      sVar2 = 3;
    }
  }
  else if (-1 < iVar5 - iVar4) { //if z > x
    sVar2 = 2;
  }
  *(short *)((int)param_2 + 6) = sVar2;
  return;
}


// COLL_Quadblock_Graphics
// param1 - ptrQuadblock
void FUN_8001f41c(int param_1,int param_2)

{
  // ??? used to write to quadBlocksRendered ???
  // "at + 100 = 80096404" from 226 ? which is quadblocksrendered
  *(int *)(param_2 + 100) = param_1;

  if (
		(
			(
				// quadblock flags
				((*(uint *)(param_2 + 0x24) & (int)*(short *)(param_1 + 0x12)) != 0) &&

				// quadblock flags
				((*(uint *)(param_2 + 0x28) & (int)*(short *)(param_1 + 0x12)) == 0)
			) &&

			// min[y] less than [???]
			((*(int *)(param_1 + 0x2c) >> 0x10) - (int)*(short *)(param_2 + 0x38) < 1)
		) &&

		(
			(
				(
					// min[x] less than [???]
					(int)(short)*(int *)(param_1 + 0x2c) - (int)*(short *)(param_2 + 0x36) < 1 &&

					// max[x] more than [???]
					((int)*(short *)(param_2 + 0x30) - (*(int *)(param_1 + 0x30) >> 0x10) < 1)
				) &&

				(
					(
						// min[z] less than [???]
						(int)(short)*(int *)(param_1 + 0x30) - (int)*(short *)(param_2 + 0x3a) < 1 &&

						// max[z] more than [???]
						((int)*(short *)(param_2 + 0x34) - (*(int *)(param_1 + 0x34) >> 0x10) < 1)
					)
				)
			)
		)
	  )
  {
	// max[y] more than [???]
    if ((int)*(short *)(param_2 + 0x32) - (int)(short)*(int *)(param_1 + 0x34) < 1)
	{
	  // if 3P or 4P mode,
	  // then use low-LOD quadblock collision (two triangles)
      if ((*(ushort *)(param_2 + 0x22) & 2) == 0) 
	  {
		// 2 triangles on a low-poly quadblock
        FUN_8001f67c(param_2,param_1);
		
		// call FUN_8001ef50 two times, one per triangle
		  
        FUN_8001ef50();
        if (*(uint *)(param_1 + 4) >> 0x10 != (*(uint *)(param_1 + 4) & 0xffff)) {
          FUN_8001ef50();
        }
      }
      else {
        if ((*(ushort *)(param_2 + 0x22) & 8) == 0) 
		{
		  // 8 triangles on a low-poly quadblock
          FUN_8001f6f0(param_2,param_1);
        }
		
		// call FUN_8001ef50 eight times, one per triangle
		
        FUN_8001ef50();
        FUN_8001ef50();
        FUN_8001ef50();
        FUN_8001ef50();
        if (*(uint *)(param_1 + 4) >> 0x10 != (*(uint *)(param_1 + 4) & 0xffff)) {
          FUN_8001ef50();
          FUN_8001ef50();
          FUN_8001ef50();
          FUN_8001ef50();
          return;
        }
      }
    }
  }
  return;
}


// COLL_SearchCallback_QuadBlocks_Graphics
// param_1 - VisData
void FUN_8001f5f0(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;

  // if visData flag is water
  if ((*param_1 & 2) != 0) {
    *(uint *)(param_2 + 0x1a4) = *(uint *)(param_2 + 0x1a4) | 0x8000;
  }

  // number of quadblocks
  uVar1 = param_1[6];

  // pointer to quadblocks
  uVar2 = param_1[7];

  do
  {
	// COLL_Quadblock_Graphics
    FUN_8001f41c(uVar2,param_2);

	uVar1 = uVar1 - 1;
    uVar2 = uVar2 + 0x5c;
  } while (0 < (int)uVar1);

  if ((*(ushort *)(param_2 + 0x22) & 1) != 0)
  {
	// check collision with VisData instances
    FUN_8001d610(param_1,param_2);
  }
  return;
}


// 2 triangles on a low-poly quadblock (physics coll)
void FUN_8001f67c(int param_1,int param_2)

{
  undefined uVar1;

  FUN_8001f7f0();
  
  // quadblock offset 0x3f
  uVar1 = *(undefined *)(param_2 + 0x3f);
  
  // always 2 for high poly
  *(undefined *)(param_1 + 0x1ab) = 2;
  
  *(undefined *)(param_1 + 0x1aa) = uVar1;
  
  if (*(short *)(param_1 + 0xec) != *(short *)(param_1 + 0xee)) {
    *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x5a);
    FUN_8001f2dc();
  }
  *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x58);
  FUN_8001f2dc();
  return;
}


// 8 triangles on a high-poly quadblock (physics coll)
void FUN_8001f6f0(int param_1,int param_2)

{
  undefined uVar1;

  FUN_8001f7f0();
  
  // quadblock offset 0x3f
  uVar1 = *(undefined *)(param_2 + 0x3f);
  
  // always 0 for low poly
  *(undefined *)(param_1 + 0x1ab) = 0;
  
  *(undefined *)(param_1 + 0x1aa) = uVar1;
  
  if (*(short *)(param_1 + 0xec) != *(short *)(param_1 + 0xee)) {  // Do we hit two quads? if then, check two quads.
    *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x50); // quads vert 0
    FUN_8001f2dc();
    *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x52); // quads vert 1
    FUN_8001f2dc();
    *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x54); // quads vert 2
    FUN_8001f2dc();
    *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x56); // quads vert 3
    FUN_8001f2dc();
  }
  *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x48); // quads vert 0
  FUN_8001f2dc();
  *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x4a); // quads vert 1
  FUN_8001f2dc();
  *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x4c); // quads vert 2
  FUN_8001f2dc();
  *(undefined2 *)(param_1 + 0x1a8) = *(undefined2 *)(param_2 + 0x4e); // quads vert 3
  FUN_8001f2dc();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

// called once per quadblock, before triangle collision
void FUN_8001f7f0(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_t8;

  uVar1 = in_t8[1];
  *(undefined4 *)(param_1 + 0xf0) = *in_t8;
  *(undefined4 *)(param_1 + 0xf4) = uVar1;
  *(undefined4 **)(param_1 + 0xf8) = in_t8;
  uVar1 = in_t8[0x23ca1];
  *(undefined4 *)(param_1 + 0x104) = in_t8[0x23ca0];
  *(undefined4 *)(param_1 + 0x108) = uVar1;
  *(undefined4 **)(param_1 + 0x10c) = in_t8 + 0x23ca0;
  *(undefined4 *)(param_1 + 0xec) = 0x8f290004;
  uVar1 = in_t8[0x11];
  *(undefined4 *)(param_1 + 0x118) = in_t8[0x10];
  *(undefined4 *)(param_1 + 0x11c) = uVar1;
  *(undefined4 **)(param_1 + 0x120) = in_t8 + 0x10;
  uVar1 = in_t8[0x23ca5];
  *(undefined4 *)(param_1 + 300) = in_t8[0x23ca4];
  *(undefined4 *)(param_1 + 0x130) = uVar1;
  *(undefined4 **)(param_1 + 0x134) = in_t8 + 0x23ca4;
  uVar1 = in_t8[0x3fffd];
  *(undefined4 *)(param_1 + 0x140) = in_t8[0x3fffc];
  *(undefined4 *)(param_1 + 0x144) = uVar1;
  *(undefined4 **)(param_1 + 0x148) = in_t8 + 0x3fffc;
  uVar1 = in_t8[0xc40d];
  *(undefined4 *)(param_1 + 0x154) = in_t8[0xc40c];
  *(undefined4 *)(param_1 + 0x158) = uVar1;
  *(undefined4 **)(param_1 + 0x15c) = in_t8 + 0xc40c;
  uVar1 = in_t8[0x6401];
  *(undefined4 *)(param_1 + 0x168) = in_t8[0x6400];
  *(undefined4 *)(param_1 + 0x16c) = uVar1;
  *(undefined4 **)(param_1 + 0x170) = in_t8 + 0x6400;
  uVar1 = in_t8[0xd];
  *(undefined4 *)(param_1 + 0x17c) = in_t8[0xc];
  *(undefined4 *)(param_1 + 0x180) = uVar1;
  *(undefined4 **)(param_1 + 0x184) = in_t8 + 0xc;
  uVar1 = in_t8[0x6085];
  *(undefined4 *)(param_1 + 400) = in_t8[0x6084];
  *(undefined4 *)(param_1 + 0x194) = uVar1;
  *(undefined4 **)(param_1 + 0x198) = in_t8 + 0x6084;
  return;
}


// part of triangle collision in the function below
undefined4
FUN_8001f928(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;

  puVar2 = param_3;
  if (*(short *)((int)param_1 + 6) == 3) {
    iVar3 = (int)*(short *)(param_2 + 1);
    iVar5 = *(short *)(param_3 + 1) - iVar3;
    iVar9 = *(short *)(param_4 + 1) - iVar3;
    iVar3 = *(short *)(param_1 + 5) - iVar3;
    iVar4 = iVar5;
    if (iVar5 < 0) {
      iVar4 = -iVar5;
    }
    iVar10 = iVar9;
    if (iVar9 < 0) {
      iVar10 = -iVar9;
    }
    iVar6 = iVar5;
    if (iVar4 - iVar10 < 0) {
      puVar2 = param_4;
      param_4 = param_3;
      iVar6 = iVar9;
      iVar9 = iVar5;
    }
    iVar4 = (int)*(short *)param_2;
    iVar5 = *(short *)puVar2 - iVar4;
    iVar10 = *(short *)param_4 - iVar4;
    iVar4 = *(short *)(param_1 + 4) - iVar4;
  }
  else {
    iVar3 = (int)*(short *)param_2;
    if (*(short *)((int)param_1 + 6) == 1) {
      iVar5 = *(short *)param_3 - iVar3;
      iVar9 = *(short *)param_4 - iVar3;
      iVar3 = *(short *)(param_1 + 4) - iVar3;
      iVar4 = iVar5;
      if (iVar5 < 0) {
        iVar4 = -iVar5;
      }
      iVar10 = iVar9;
      if (iVar9 < 0) {
        iVar10 = -iVar9;
      }
      iVar6 = iVar5;
      if (iVar4 - iVar10 < 0) {
        puVar2 = param_4;
        param_4 = param_3;
        iVar6 = iVar9;
        iVar9 = iVar5;
      }
      iVar4 = (int)*(short *)((int)param_2 + 2);
      iVar5 = *(short *)((int)puVar2 + 2) - iVar4;
      iVar10 = *(short *)((int)param_4 + 2) - iVar4;
      iVar4 = *(short *)((int)param_1 + 0x12) - iVar4;
    }
    else {
      iVar3 = (int)*(short *)((int)param_2 + 2);
      iVar5 = *(short *)((int)param_3 + 2) - iVar3;
      iVar9 = *(short *)((int)param_4 + 2) - iVar3;
      iVar3 = *(short *)((int)param_1 + 0x12) - iVar3;
      iVar4 = iVar5;
      if (iVar5 < 0) {
        iVar4 = -iVar5;
      }
      iVar10 = iVar9;
      if (iVar9 < 0) {
        iVar10 = -iVar9;
      }
      iVar6 = iVar5;
      if (iVar4 - iVar10 < 0) {
        puVar2 = param_4;
        param_4 = param_3;
        iVar6 = iVar9;
        iVar9 = iVar5;
      }
      iVar4 = (int)*(short *)(param_2 + 1);
      iVar5 = *(short *)(puVar2 + 1) - iVar4;
      iVar10 = *(short *)(param_4 + 1) - iVar4;
      iVar4 = *(short *)(param_1 + 5) - iVar4;
    }
  }
  iVar7 = -0x1000;
  iVar8 = -0x1000;
  if (iVar6 == 0) {
    iVar7 = -0x1000;
    if (iVar9 == 0) {
      return 0xffffffff;
    }
    iVar8 = (iVar3 << 0xc) / iVar9;
    if (iVar5 != 0) {
      iVar7 = (iVar4 * 0x1000 - iVar8 * iVar10) / iVar5;
    }
  }
  else {
    iVar10 = iVar10 * iVar6 - iVar9 * iVar5 >> 6;
    if ((iVar10 != 0) && (iVar8 = ((iVar4 * iVar6 - iVar3 * iVar5) * 0x40) / iVar10, iVar6 != 0)) {
      iVar7 = (iVar3 * 0x1000 - iVar8 * iVar9) / iVar6;
    }
  }
  if ((iVar7 == -0x1000) || (iVar7 == -0x1000)) {
    return 0xffffffff;
  }
  if (iVar7 < 0) {
    if (iVar8 < 0) {
      sVar1 = *(short *)(param_2 + 1);
      *param_1 = *param_2;
      *(short *)(param_1 + 1) = sVar1;
      return 0;
    }
    if (-1 < iVar7 + iVar8 + -0x1000) {
      sVar1 = *(short *)(param_4 + 1);
      *param_1 = *param_4;
      *(short *)(param_1 + 1) = sVar1;
      return 4;
    }
    FUN_8001ede4(param_1,param_2,param_4,param_1 + 4);
    return 5;
  }
  iVar3 = iVar7 + iVar8 + -0x1000;
  if (-1 < iVar8) {
    if (iVar3 < 1) {
      *param_1 = param_1[4];
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_1 + 5);
      return 6;
    }
    FUN_8001ede4(param_1,puVar2,param_4,param_1 + 4);
    return 3;
  }
  if (-1 < iVar3) {
    sVar1 = *(short *)(puVar2 + 1);
    *param_1 = *puVar2;
    *(short *)(param_1 + 1) = sVar1;
    return 2;
  }
  FUN_8001ede4();
  return 1;
}

// WARNING: Instruction at (ram,0x8001fefc) overlaps instruction at (ram,0x8001fef8)
//

// called once per triangle (why?)
// TigerTempleTeeth, AdvHubDoors, killplane, out of bounds, plus a lot more
void FUN_8001fc40(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;

  sVar1 = *(short *)(param_2 + 6);
  uVar5 = *(undefined4 *)(param_2 + 0xc);
  uVar6 = *(undefined4 *)(param_2 + 0x10);
  *(short *)(param_1 + 0xf) = *(short *)(param_1 + 0xf) + 1;
  *(short *)((int)param_1 + 0x52) = sVar1;
  param_1[0x15] = uVar5;
  param_1[0x16] = uVar6;
  iVar9 = param_1[0x19];

  // If collision on this quadblock is not scriptable
  // (TigerTempleTeeth, AdvHubDoors)
  if ((*(ushort *)(iVar9 + 0x12) & 0x400) == 0)
  {
    uVar5 = *param_1;
  }

  // if it is scriptable
  else
  {
    uVar5 = *param_1;

	// if the requirement is met to open the door
	if (((int)*(char *)(iVar9 + 0x38) & DAT_8008d728) != 0)
	{
	  // dont check for collision
      return;
    }
  }

  gte_ldR11R12(uVar5);
  gte_ldR13R21(param_1[4] << 0x10 | (uint)*(ushort *)(param_1 + 1));
  gte_ldR22R23((uint)param_1[4] >> 0x10 | (uint)*(ushort *)(param_1 + 5) << 0x10);
  gte_ldVXY0(param_1 + 0x15);
  gte_ldVZ0(param_1 + 0x16);
  gte_rtv0_b();
  iVar7 = gte_stMAC1();
  iVar8 = gte_stMAC2();

  iVar7 = iVar7 + (int)*(short *)((int)param_1 + 0x5a) * -2;
  iVar8 = iVar8 + (int)*(short *)((int)param_1 + 0x5a) * -2;
  if (iVar8 < 0) {
    if ((*(ushort *)(iVar9 + 0x12) & 0x40) == 0) {
      sVar1 = *(short *)(param_1 + 0x15);
      if (-1 < *(int *)(iVar9 + 0x14)) goto LAB_8001fd38;
    }
    else {
      sVar1 = *(short *)(param_1 + 0x15);
    }
    iVar7 = -iVar7;
    iVar8 = -iVar8;
    *(short *)(param_1 + 0x15) = -sVar1;
    *(short *)((int)param_1 + 0x56) = -*(short *)((int)param_1 + 0x56);
    *(short *)(param_1 + 0x16) = -*(short *)(param_1 + 0x16);
    *(short *)((int)param_1 + 0x5a) = -*(short *)((int)param_1 + 0x5a);
  }
LAB_8001fd38:
  uVar2 = *(ushort *)(iVar9 + 0x12);
  *(short *)(param_1 + 0xf) = *(short *)(param_1 + 0xf) + 1;
  if (-1 < iVar7 - *(short *)((int)param_1 + 6)) {
    return;
  }
  if (iVar8 < 0) {
    return;
  }
  if (((uVar2 & 0x40) == 0) && (0 < iVar7 - iVar8)) {
    return;
  }
  if (-1 < iVar7) {
    gte_ldIR0(iVar7);
    gte_ldsv_((int)*(short *)(param_1 + 0x15),(int)*(short *)((int)param_1 + 0x56),
              (int)*(short *)(param_1 + 0x16));
  }
  else {
    gte_ldIR1((int)*(short *)param_1 - (int)*(short *)(param_1 + 4));
    gte_ldIR2((int)*(short *)((int)param_1 + 2) - (int)*(short *)((int)param_1 + 0x12));
    gte_ldIR3((int)*(short *)(param_1 + 1) - (int)*(short *)(param_1 + 5));
    gte_ldIR0((iVar7 * -0x1000) / (iVar8 - iVar7));
  }

  gte_gpf12_b();
  uVar5 = gte_stMAC1();
  uVar6 = gte_stMAC2();

  *(short *)(param_1 + 0x17) = *(short *)param_1 - (short)uVar5;

  uVar5 = gte_stMAC3();

  *(short *)((int)param_1 + 0x5e) = *(short *)((int)param_1 + 2) - (short)uVar6;
  *(short *)(param_1 + 0x18) = *(short *)(param_1 + 1) - (short)uVar5;
  param_1[0x36] = param_2;
  param_1[0x37] = param_3;
  param_1[0x38] = param_4;
  iVar9 = FUN_8001f928(param_1 + 0x13);
  if (iVar9 < 0) {
    return;
  }
  if (-1 < iVar7) {
    *(short *)(param_1 + 0x39) = *(short *)param_1 - *(short *)(param_1 + 0x13);
    *(short *)((int)param_1 + 0xe6) = *(short *)((int)param_1 + 2) - *(short *)((int)param_1 + 0x4e)
    ;
    *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 1) - *(short *)(param_1 + 0x14);
  }
  else {
    *(short *)(param_1 + 0x39) = *(short *)(param_1 + 0x17) - *(short *)(param_1 + 0x13);
    *(short *)((int)param_1 + 0xe6) =
         *(short *)((int)param_1 + 0x5e) - *(short *)((int)param_1 + 0x4e);
    *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 0x18) - *(short *)(param_1 + 0x14);
  }


  gte_ldR11R12(param_1[0x39]);
  gte_ldR13R21((int)*(short *)(param_1 + 0x3a));
  gte_ldVXY0(param_1 + 0x39);
  gte_ldVZ0(param_1 + 0x3a);
  gte_mvmva(0,0,0,3,0);
  iVar3 = gte_stMAC1();

  // confirmed quadblock,
  // look at t9 on addr 8001fed4
  iVar10 = param_1[0x19];
  
  // quadblock -> flags
  uVar2 = *(ushort *)(iVar10 + 0x12);
  
  if (0 < iVar3 - param_1[2]) {
    return;
  }
  
  // if not triggerScript
  if ((uVar2 & 0x40) == 0) {
LAB_8001ff14:
    iVar8 = iVar8 - iVar7;
    if (iVar8 != 0) {
      iVar8 = 0x1000 - ((*(short *)((int)param_1 + 6) - iVar7) * 0x1000) / iVar8;
    }
    if (iVar8 - param_1[0x21] < 0) 
	{
	  // if not out of bounds
      if ((uVar2 & 0x10) == 0) 
	  {
        param_1[0x21] = iVar8;
        uVar5 = *(undefined4 *)(param_1[0x37] + 8);
        uVar6 = *(undefined4 *)(param_1[0x38] + 8);
        param_1[0x33] = *(undefined4 *)(param_1[0x36] + 8);
        param_1[0x34] = uVar5;
        param_1[0x35] = uVar6;
        param_1[0x1a] = param_1[0x13];
        param_1[0x1b] = param_1[0x14];
        param_1[0x1c] = param_1[0x15];
        param_1[0x1d] = param_1[0x16];
        param_1[0x1e] = param_1[0x17];
        param_1[0x1f] = param_1[0x18];
        param_1[0x20] = iVar10;
		
		// triangle ID (0-9)
        *(undefined *)((int)param_1 + 0x7f) = *(undefined *)((int)param_1 + 99);
		
        *(char *)((int)param_1 + 0x7e) = (char)iVar9;
        if (iVar8 < 1) {
          param_1[7] = param_1[4];
          *(short *)(param_1 + 8) = *(short *)(param_1 + 5);
        }
        else {
          gte_ldIR0(iVar8);
          gte_ldIR1((int)*(short *)param_1 - (int)*(short *)(param_1 + 4));
          gte_ldIR2((int)*(short *)((int)param_1 + 2) - (int)*(short *)((int)param_1 + 0x12));
          gte_ldIR3((int)*(short *)(param_1 + 1) - (int)*(short *)(param_1 + 5));
          gte_gpf12_b();
          uVar5 = gte_stMAC1();
          uVar6 = gte_stMAC2();

          *(short *)(param_1 + 7) = *(short *)(param_1 + 4) + (short)uVar5;

		  uVar5 = gte_stMAC3();

          *(short *)((int)param_1 + 0x1e) = *(short *)((int)param_1 + 0x12) + (short)uVar6;
          *(short *)(param_1 + 8) = *(short *)(param_1 + 5) + (short)uVar5;
        }
		
        *(short *)((int)param_1 + 0x3e) = *(short *)((int)param_1 + 0x3e) + 1;
      }
      else 
	  {
		// if killplane
        if ((uVar2 & 0x200) != 0) {
          param_1[0x69] = param_1[0x69] | 0x4000;
        }
      }
    }
  }
  else {
    if (iVar7 < 0) {
      uVar4 = param_1[0x69];
    }
    else {
      uVar4 = param_1[0x69];
      if (-1 < (iVar7 - *(short *)((int)param_1 + 6) | iVar8 - *(short *)((int)param_1 + 6)))
      goto LAB_8001ff14;
    }
    param_1[0x69] = uVar4 | *(byte *)(iVar10 + 0x38);
  }
  return;
}


// COLL_Quadblock_Physics
void FUN_80020064(int param_1,int param_2)

{
  uint uVar1;

  *(int *)(param_2 + 100) = param_1;

  if (
		(
			(
				// quadblock flags
				((*(uint *)(param_2 + 0x24) & (int)*(short *)(param_1 + 0x12)) != 0) &&

				// quadblock flags
				((*(uint *)(param_2 + 0x28) & (int)*(short *)(param_1 + 0x12)) == 0)
			) &&

			// min[y] less than [???]
			((*(int *)(param_1 + 0x2c) >> 0x10) - (int)*(short *)(param_2 + 0x38) < 1)
		) &&

		(
			(
				(
					// min[x] less than [???]
					(int)(short)*(int *)(param_1 + 0x2c) - (int)*(short *)(param_2 + 0x36) < 1 &&

					// max[x] more than [???]
					((int)*(short *)(param_2 + 0x30) - (*(int *)(param_1 + 0x30) >> 0x10) < 1)
				) &&

				(
					(
						// min[z] less than [???]
						(int)(short)*(int *)(param_1 + 0x30) - (int)*(short *)(param_2 + 0x3a) < 1 &&

						// min[z] more than [???]
						((int)*(short *)(param_2 + 0x34) - (*(int *)(param_1 + 0x34) >> 0x10) < 1)
					)
				)
			)
		)
	  )
  {
	// min[y] more than [???]
    if ((int)*(short *)(param_2 + 0x32) - (int)(short)*(int *)(param_1 + 0x34) < 1)
	{
	  // if 3P or 4P mode,
	  // then use low-LOD quadblock collision (two triangles)
      if ((*(ushort *)(param_2 + 0x22) & 2) == 0) 
	  {
		// 2 triangles on a low-poly quadblock
        FUN_8001f67c(param_2,param_1);
		
		// call FUN_8001fc40 two times, one per triangle
		
        *(undefined *)(param_2 + 99) = 0;
        FUN_8001fc40();
        uVar1 = *(uint *)(param_1 + 4);
        *(undefined *)(param_2 + 99) = 1;
        if (uVar1 >> 0x10 != (uVar1 & 0xffff)) {
          FUN_8001fc40();
        }
      }
      else {
        if ((*(ushort *)(param_2 + 0x22) & 8) == 0) 
		{
		  // 8 triangles on high-poly quadblock
          FUN_8001f6f0(param_2,param_1);
        }
		
		// call FUN_8001fc40 eight times, one per triangle
		
        *(undefined *)(param_2 + 99) = 2;
        FUN_8001fc40();
        *(undefined *)(param_2 + 99) = 3;
        FUN_8001fc40();
        *(undefined *)(param_2 + 99) = 4;
        FUN_8001fc40();
        FUN_8001fc40();
        uVar1 = *(uint *)(param_1 + 4);
        *(undefined *)(param_2 + 99) = 6;
        if (uVar1 >> 0x10 != (uVar1 & 0xffff)) {
          FUN_8001fc40();
          *(undefined *)(param_2 + 99) = 7;
          FUN_8001fc40();
          *(undefined *)(param_2 + 99) = 8;
          FUN_8001fc40();
          *(undefined *)(param_2 + 99) = 9;
          FUN_8001fc40();
          return;
        }
      }
    }
  }
  return;
}


// COLL_SearchCallback_QuadBlocks_Physics
// param_1 is VisData node
void FUN_800202a8(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;

  // if visData flag is water
  if ((*param_1 & 2) != 0) {
    *(uint *)(param_2 + 0x1a4) = *(uint *)(param_2 + 0x1a4) | 0x8000;
  }

  // number of quadblocks
  uVar1 = param_1[6];

  // pointer to quadblocks
  uVar2 = param_1[7];

  // loop through all quadblocks
  do {
    FUN_80020064(uVar2,param_2);

	// reduce count
    uVar1 = uVar1 - 1;

	// next quadblock
    uVar2 = uVar2 + 0x5c;

  } while (0 < (int)uVar1);

  if ((*(ushort *)(param_2 + 0x22) & 1) != 0)
  {
	// check collision with VisData instances
    FUN_8001d610(param_1,param_2);
  }
  return;
}


// NOPing this function makes your character constantly jump
// param_1 = ptrQuadblock
//
// param_3 = 0x1F800108
void FUN_80020334(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;

  uVar1 = *(ushort *)(param_3 + 0x22);

  // if no quadblock given
  if (param_1 == 0)
  {
	// if param_1 is rigged nullptr,
	// driver gets stuck, but doesn't bounce

    *(ushort *)(param_3 + 0x22) = uVar1 & 0xffdf;
    *(undefined2 *)(param_3 + 0xe) = 0;
    *(undefined4 *)(param_3 + 0x2c0) = 0;
    return;
  }

  iVar3 = *(int *)(param_3 + 0x2c0) + -1;
  if (-1 < iVar3) {
    iVar5 = iVar3 * 0xc + 0x20c;
    do {
      piVar4 = (int *)(param_3 + iVar5);
      if ((*piVar4 == param_1) && (piVar4[1] == param_2)) {
        iVar3 = piVar4[2];
        uVar2 = (undefined2)iVar3;
        if (iVar3 < 0x401) {
          uVar2 = (undefined2)(iVar3 + 0x100);
          piVar4[2] = iVar3 + 0x100;
        }
        *(ushort *)(param_3 + 0x22) = uVar1 | 0x20;
        *(undefined2 *)(param_3 + 0xe) = uVar2;
        return;
      }
      iVar3 = iVar3 + -1;
      iVar5 = iVar5 + -0xc;
    } while (-1 < iVar3);
  }
  piVar4 = (int *)(param_3 + *(int *)(param_3 + 0x2c0) * 0xc + 0x20c);
  *piVar4 = param_1;
  piVar4[1] = param_2;
  piVar4[2] = 0;

  // similar to if-statement body
  *(ushort *)(param_3 + 0x22) = uVar1 & 0xffdf;
  *(undefined2 *)(param_3 + 0xe) = 0;
  *(int *)(param_3 + 0x2c0) = *(int *)(param_3 + 0x2c0) + 1;

  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

// OnPhysics
// param_1 = driver thread
// param_2 = driver ptr
void FUN_80020410(undefined4 param_1,int param_2)
{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;

  DAT_1f80010e = 0x19;
  _DAT_1f800110 = 0x271;
  DAT_1f80011c._2_2_ = 0x19;
  DAT_1f800120 = 0x271;

  // pointer to LEV
  DAT_1f800134 = **(undefined4 **)(PTR_DAT_8008d2ac + 0x160);

  // ground and wall quadblock flags
  DAT_1f80012c = 0x3000;

  DAT_1f800130 = 0;

  // low-LOD collision (2 triangles)
  DAT_1f80012a = 1;

  // if number of screens is less than 3
  if ((byte)PTR_DAT_8008d2ac[0x1ca8] < 3)
  {
	// high-LOD collision (8 triangles)
    DAT_1f80012a = 3;
  }

  iVar13 = 0x1000;
  DAT_1f8001cc = 0;
  DAT_1f800114 = 0x18;
  DAT_1f8002ac = 0;
  FUN_80020334(0,0,&DAT_1f800108);
  iVar14 = 0xf;
  do {

    // x
    // iVar5 = ((driver.coordSpeed[0] * (elapsed milliseconds per frame, ~32) >> 5) * iVar13) >> 0xC
    iVar5 = (*(int *)(param_2 + 0x88) * *(int *)(PTR_DAT_8008d2ac + 0x1d04) >> 5) * iVar13 >> 0xc;

    // y
	// ((driver.coordSpeed[1] * (elapsed milliseconds per frame, ~32) >> 5) * iVar13) >> 0xC
	iVar6 = (*(int *)(param_2 + 0x8c) * *(int *)(PTR_DAT_8008d2ac + 0x1d04) >> 5) * iVar13 >> 0xc;

    DAT_1f800146 = 0;
    DAT_1f800144 = 0;
    DAT_1f80014a = 0;
    DAT_1f800148 = 0;
    DAT_1f80018c = 0x1000;

    // z
	// ((driver.coordSpeed[2] * (elapsed milliseconds per frame, ~32) >> 5) * iVar13) >> 0xC
    iVar7 = (*(int *)(param_2 + 0x90) * *(int *)(PTR_DAT_8008d2ac + 0x1d04) >> 5) * iVar13 >> 0xc;

	sVar9 = *(short *)(param_2 + 0x94) + (short)((uint)*(undefined4 *)(param_2 + 0x2d4) >> 8);
    sVar10 = *(short *)(param_2 + 0x98) + (short)((uint)*(undefined4 *)(param_2 + 0x2d8) >> 8);

    DAT_1f800118 = CONCAT22(sVar10,sVar9);
    DAT_1f80011c._0_2_ = *(short *)(param_2 + 0x9c) + (short)((uint)*(undefined4 *)(param_2 + 0x2dc) >> 8);
    sVar3 = *(short *)(param_2 + 0x94) + (short)((uint)(*(int *)(param_2 + 0x2d4) + iVar5) >> 8);
    sVar4 = *(short *)(param_2 + 0x98) + (short)((uint)(*(int *)(param_2 + 0x2d8) + iVar6) >> 8);

    _DAT_1f800108 = CONCAT22(sVar4,sVar3);
    iVar11 = (uint)*(ushort *)(param_2 + 0x9c) + (*(int *)(param_2 + 0x2dc) + iVar7 >> 8);
    DAT_1f80010c = (short)iVar11;
    if ((_DAT_1f800108 == DAT_1f800118) &&
       (uVar1 = DAT_1f80012a | 1, iVar11 * 0x10000 == (uint)(ushort)DAT_1f80011c << 0x10)) break;
    DAT_1f800138 = (short)((int)sVar9 - (int)DAT_1f80011c._2_2_);
    if ((int)sVar3 - (int)DAT_1f80010e < (int)sVar9 - (int)DAT_1f80011c._2_2_) {
      DAT_1f800138 = (short)((int)sVar3 - (int)DAT_1f80010e);
    }
    DAT_1f80013a = (short)((int)sVar10 - (int)DAT_1f80011c._2_2_);
    if ((int)sVar4 - (int)DAT_1f80010e < (int)sVar10 - (int)DAT_1f80011c._2_2_) {
      DAT_1f80013a = (short)((int)sVar4 - (int)DAT_1f80010e);
    }
    DAT_1f80013c = (short)((int)(short)(ushort)DAT_1f80011c - (int)DAT_1f80011c._2_2_);
    if ((int)DAT_1f80010c - (int)DAT_1f80010e <
        (int)(short)(ushort)DAT_1f80011c - (int)DAT_1f80011c._2_2_) {
      DAT_1f80013c = (short)((int)DAT_1f80010c - (int)DAT_1f80010e);
    }
    DAT_1f80013e = (short)((int)sVar9 + (int)DAT_1f80011c._2_2_);
    if ((int)sVar9 + (int)DAT_1f80011c._2_2_ < (int)sVar3 + (int)DAT_1f80010e) {
      DAT_1f80013e = (short)((int)sVar3 + (int)DAT_1f80010e);
    }
    DAT_1f800140 = (short)((int)sVar10 + (int)DAT_1f80011c._2_2_);
    if ((int)sVar10 + (int)DAT_1f80011c._2_2_ < (int)sVar4 + (int)DAT_1f80010e) {
      DAT_1f800140 = (short)((int)sVar4 + (int)DAT_1f80010e);
    }
    DAT_1f800142 = (short)((int)(short)(ushort)DAT_1f80011c + (int)DAT_1f80011c._2_2_);
    if ((int)(short)(ushort)DAT_1f80011c + (int)DAT_1f80011c._2_2_ <
        (int)DAT_1f80010c + (int)DAT_1f80010e) {
      DAT_1f800142 = (short)((int)DAT_1f80010c + (int)DAT_1f80010e);
    }
    DAT_1f80012a = DAT_1f80012a & 0xfff7 | 1;
    DAT_1f800124._0_2_ = sVar3;
    DAT_1f800124._2_2_ = sVar4;
    DAT_1f800128 = DAT_1f80010c;

    if (
		(
			// if LEV exists
			(*(int **)(PTR_DAT_8008d2ac + 0x160) != (int *)0x0) &&

			// if LEV mesh_info exists
			(iVar11 = **(int **)(PTR_DAT_8008d2ac + 0x160), iVar11 != 0)
		) &&

		// if mesh_info->visData exists
		(iVar11 = *(int *)(iVar11 + 0x18), iVar11 != 0)
	   )
	{
	  // search entire BSP tree (VisData),
	  // pass COLL_SearchCallback_QuadBlocks_Physics as parameter,
	  // this is for player collision
      FUN_8001ebec(iVar11,&DAT_1f800138,FUN_800202a8,&DAT_1f800108);
    }

	// if collision was found in BSP
    if (DAT_1f800146 != 0)
	{
      *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 4;
    }

    if (0 < DAT_1f80018c) {

      // x
      // driver.posCurr[0] += ??? * ??? >> 0xC
      *(int *)(param_2 + 0x2d4) = *(int *)(param_2 + 0x2d4) + (iVar5 * DAT_1f80018c >> 0xc);

      // y
      // driver.posCurr[1] += ??? * ??? >> 0xC
      *(int *)(param_2 + 0x2d8) = *(int *)(param_2 + 0x2d8) + (iVar6 * DAT_1f80018c >> 0xc);

      // z
      // driver.posCurr[2] += ??? * ??? >> 0xC
      *(int *)(param_2 + 0x2dc) = *(int *)(param_2 + 0x2dc) + (iVar7 * DAT_1f80018c >> 0xc);
    }
	
    if (DAT_1f80014a == 0) 
	{
	  uVar1 = DAT_1f80012a;
      
	  // if quadblock was not found, quit
	  if (DAT_1f800146 == 0) break;

	  // if quadblock is a killplane
      if ((*(ushort *)(DAT_1f800188 + 0x12) & 0x200) != 0)
	  {
		// player needs to be mask grabbed
        *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 1;
      }

      FUN_80020334(DAT_1f800188,(uint)DAT_1f800187,&DAT_1f800108);

	  // get quadblock flag
	  uVar1 = *(ushort *)(DAT_1f800188 + 0x12);

	  // if quadblock is not ground
	  if ((uVar1 & 0x1000) == 0) {
        uVar12 = 6;
        // is not invisible
        if ((uVar1 & 1) == 0) { 
          uVar12 = 0;
        }
      }

	  // if quadblock is ground
	  else
	  {
        if (

			// compare to quadblock under driver
			(DAT_1f800188 != *(int *)(param_2 + 0x350)) &&

			// if quadblock is "kicker"??? even DCxDemo doesn't
			// fully know what this is right now
			((uVar1 & 8) != 0)
		   )
		{
		  // quadblock under driver
          *(undefined4 *)(param_2 + 0x350) = 0;
        }
        uVar8 = _DAT_1f800178;

		// set quadblock you are touching
        *(int *)(param_2 + 0xa0) = DAT_1f800188;

		*(undefined4 *)(param_2 + 0xa4) = uVar8;
        uVar8 = _DAT_1f800178;
        *(undefined2 *)(param_2 + 0xa8) = DAT_1f80017c;
        uVar12 = 5;
        *(undefined4 *)(param_2 + 0x360) = uVar8;
        uVar2 = DAT_1f80017c;

		// driver is now on ground
        *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 8;

		*(undefined2 *)(param_2 + 0x364) = uVar2;
      }

	  // scrubMeta
	  uVar12 = FUN_80057c44(uVar12);

      uVar8 = DAT_1f800170;
      *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) | 2;
      *(undefined4 *)(param_2 + 0xac) = uVar8;
      uVar8 = _DAT_1f800178;
      *(undefined2 *)(param_2 + 0xb0) = (undefined2)DAT_1f800174;
      *(undefined4 *)(param_2 + 0xb4) = uVar8;
      *(undefined2 *)(param_2 + 0xb8) = DAT_1f80017c;

	  // COLL_Scrub
      iVar5 = FUN_80020c58(param_2,param_1,&DAT_1f800108,uVar12,param_2 + 0x88);

	  if (iVar5 == 2) {
        return;
      }
      if ((0 < DAT_1f80018c) &&
         (iVar13 = iVar13 - (iVar13 * DAT_1f80018c >> 0xc), uVar1 = DAT_1f80012a, iVar13 < 100))
      break;
      DAT_1f80012a = DAT_1f80012a | 8;
    }
    else {
      DAT_1f80012a = DAT_1f80012a & 0xfff7;
      *(ushort *)(param_2 + 0xaa) = *(ushort *)(param_2 + 0xaa) & 0xfffd;
      iVar5 = 1;
      if ((*DAT_1f800150 & 0x80) == 0) {
        if (((*DAT_1f800150 & 0x10) != 0) && (iVar6 = *(int *)(DAT_1f800150 + 0x1c), iVar6 != 0)) {
          sVar3 = *(short *)(*(int *)(iVar6 + 0x18) + 0x10);
          goto LAB_800209b0;
        }
      }
      else
	  {
        iVar7 = *(int *)(DAT_1f800150 + 0x1c);

		if (
				(
					// if InstDef is valid
					(iVar7 != 0) &&

					// InstDef->Instance
					(iVar6 = *(int *)(iVar7 + 0x2c), iVar6 != 0)
				) &&
				(
					// InstDef->modelID
					sVar3 = *(short *)(iVar7 + 0x3c),

					// Instance->flags are drawing to some degree
					(*(uint *)(iVar6 + 0x28) & 0xf) != 0
				)
			)
		{
LAB_800209b0:

		  // ThreadMeta for modelID
          iVar7 = FUN_8001d094((int)sVar3);

          if (
				// if it is not nullptr
				(iVar7 != 0) &&

				// If funcOnApproach is not nullptr
				(*(code **)(iVar7 + 8) != (code *)0x0)
			  )
		  {
			// initialize a thread for this instance
            iVar5 = (**(code **)(iVar7 + 8))(iVar6,param_1,&DAT_1f800108);
          }
        }
      }
      if ((iVar5 == 2) || (DAT_1f800150[1] == 4)) {
        *(byte **)(&DAT_1f800190 + DAT_1f8001cc) = DAT_1f800150;
        DAT_1f8001cc = DAT_1f8001cc + 1;
      }
      else {
        FUN_80020334(DAT_1f800150,0,&DAT_1f800108);
        DAT_1f800116 = DAT_1f800116 + 0x200;
        iVar5 = 0;

		// scrub meta
        uVar8 = FUN_80057c44((uint)DAT_1f800150[1]);

        if ((DAT_1f800150[1] == 4) ||

			// COLL_Scrub
		   (iVar5 = FUN_80020c58(param_2,param_1,&DAT_1f800108,uVar8,param_2 + 0x88), iVar5 == 0)) {

		  *(byte **)(&DAT_1f800190 + DAT_1f8001cc) = DAT_1f800150;
          DAT_1f8001cc = DAT_1f8001cc + 1;
        }
        if (iVar5 == 2) {
          return;
        }
      }
    }
    iVar14 = iVar14 + -1;
    uVar1 = DAT_1f80012a;
  } while (iVar14 != 0);

  DAT_1f80012a = uVar1;
  *(undefined4 *)(param_2 + 0xbc) = DAT_1f8002ac;
  return;
}

// COLL_Scrub
// "scrub" like rubbing, for sparks
// param_1 driver ptr
// param_2 driver thread
// param_3 scratchpad address 1f800108
// param_4 scrub meta
undefined4 FUN_80020c58(int param_1,undefined4 param_2,int param_3,int param_4,int *param_5)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 in_t2;
  undefined4 in_t3;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort local_48;
  ushort local_46;
  ushort local_44;
  int local_30;

  local_48 = *(ushort *)(param_3 + 0x70);
  local_46 = *(ushort *)(param_3 + 0x72);
  local_44 = *(ushort *)(param_3 + 0x74);

  // offset 0x350 is quadblock underneath driver

  if (
		(
			((*(short *)(param_1 + 0x40a) != 0) && (*(short *)(param_3 + 0x3e) != 0)) &&

			// if quadblock is ground
			((*(ushort *)(*(int *)(param_3 + 0x80) + 0x12) & 0x1000) != 0)
		) &&
		(
			(
				*(char *)(param_3 + 0x7e) != '\x06' &&

				// if quadblock is not the quadblock under the driver
				(*(int *)(param_3 + 0x80) != *(int *)(param_1 + 0x350))
			)
		)
	 )
  {
    iVar3 = (int)*(short *)(param_1 + 0x38e);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 0x300) {
      iVar3 = (int)*(short *)(param_1 + 0x390);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if ((iVar3 < 0x300) && (*(short *)(param_1 + 0x39e) == 0)) {
        uVar10 = (*(int *)(param_1 + 0x2d4) >> 8) - (int)*(short *)(param_3 + 0x68);
        uVar12 = (*(int *)(param_1 + 0x2dc) >> 8) - (int)*(short *)(param_3 + 0x6c);
        uVar9 = (*(int *)(param_1 + 0x2d8) >> 8) - (int)*(short *)(param_3 + 0x6a);
        if ((uVar10 | uVar9 | uVar12) != 0) {

          // iVar3 = sqrt(param_1 * 2 ^ param_2)
          iVar3 = FUN_80059070(uVar10 * uVar10 + uVar9 * uVar9 + uVar12 * uVar12,0);

          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (uVar10 * 0x1000 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (uVar9 * 0x1000 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (uVar12 * 0x1000 == -0x80000000)) {
            trap(0x1800);
          }
          local_48 = (ushort)((int)(uVar10 * 0x1000) / iVar3);
          local_46 = (ushort)((int)(uVar9 * 0x1000) / iVar3);
          local_44 = (ushort)((int)(uVar12 * 0x1000) / iVar3);
        }
      }
    }
  }

  iVar3 = (*param_5 >> 3) * (int)(short)local_48 + (param_5[1] >> 3) * (int)(short)local_46 +
          (param_5[2] >> 3) * (int)(short)local_44 >> 9;
  if (iVar3 < -0xa00) {
    //turn on 8th bit of Actions Flag set (means ?)
    *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 0x80;
  }
  iVar3 = iVar3 - *(short *)(param_3 + 0xe);
  uVar4 = 0;
  if (iVar3 < 0)
  {
	// scrubMeta->4
    uVar9 = *(uint *)(param_4 + 4);

	if ((uVar9 & 4) == 0)
	{
      //turn on 14th bit of Actions Flag set (means
      //racer is driving against a wall)
      *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 0x2000;
    }

	if ((uVar9 & 8) == 0)
	{
	  // reset reserves
      *(undefined2 *)(param_1 + 0x3e2) = 0;
      *(undefined2 *)(param_1 + 0x3de) = 0;
    }

	// scrubMeta->8
	iVar5 = *(int *)(param_4 + 8);

	// if just touched the wall for the first frame
	if (*(short *)(param_1 + 0x3fe) == 0)
	{
      bVar2 = 0x3e7ff < iVar5;
    }

	// if you've been touching the wall for several frames
	else
	{
      bVar2 = *(short *)(param_1 + 0x38a) < iVar5;
    }

	// just hit, (param_1 + 0x38a) >= iVar5;
	// or
	// already hit, 0x3e7ff >= iVar5;
	if (!bVar2)
	{
	  // if == 0xf0, emit wall sparks,
	  // millisecond timer since touching wall
      *(undefined2 *)(param_1 + 0x3fe) = 0xf0;

      *(undefined2 *)(param_1 + 0x38a) = (short)iVar5;
      *(undefined4 *)(param_1 + 900) = *(undefined4 *)(param_3 + 0x68);
      *(undefined2 *)(param_1 + 0x388) = *(undefined2 *)(param_3 + 0x6c);
    }

	uVar4 = 0;
    if ((uVar9 & 1) != 0) {
      iVar15 = iVar3 * (short)local_46;
      local_30 = 0;
      uVar10 = iVar3 * (short)local_48 >> 0xc;
      iVar5 = iVar15 >> 0xc;
      iVar14 = iVar3 * (short)local_44 >> 0xc;

	  // scrubMeta -> 0xC
      if (*(int *)(param_4 + 0xc) != 0) {
        iVar15 = param_5[2] * param_5[2];
        local_30 = *param_5 * *param_5 + param_5[1] * param_5[1] + iVar15 >> 0xf;
      }
      iVar11 = *param_5;
      iVar13 = param_5[2];
      *param_5 = iVar11 - uVar10;
      param_5[2] = iVar13 - iVar14;
      param_5[1] = param_5[1] - iVar5;
	  
	  gte_ldVXY0(uVar10 & 0xffff | iVar5 << 0x10);
	  gte_ldVZ0(iVar14);
	  gte_llv0();
	  
	  // second paramter is never used
	  read_mt(iVar5,???,iVar14);
	  
      if ((((*(short *)(param_3 + 0x3e) != 0) && ((*(ushort *)(param_3 + 0x22) & 0x10) == 0)) &&
          ((*(uint *)(param_1 + 0x2cc) & 1) == 0)) &&
         ((*(ushort *)(*(int *)(param_3 + 0x80) + 0x12) & 0x1000) != 0)) 
		 
	  {
		// gte_ldopv2
        setCopReg(2,in_t3,iVar13);
        setCopReg(2,iVar15,iVar11);
        setCopReg(2,in_t2,0);
		
		// gte_ldopv1SV
        setCopControlWord(2,0,(int)(short)local_48);
        setCopControlWord(2,0x1000,(int)(short)local_46);
        setCopControlWord(2,0x2000,(int)(short)local_44);

		// outer product
		gte_op12();
		
		uVar4 = gte_stR11R12();
        uVar7 = gte_stR22R23();
        uVar8 = gte_stR33();
        gte_ldsv_(uVar4,uVar7,uVar8);
		
		read_mt(uVar4,uVar7,uVar8);
		gte_ldR11R12(uVar4);
		gte_ldR22R23(uVar7);
		gte_ldR33(uVar8);

		// outer product
		gte_op12();
		
		// gte_stlvnl
		iVar15 = getCopReg(2,0x19);
        iVar11 = getCopReg(2,0x1a);
        iVar13 = getCopReg(2,0x1b);

		// some other approximation of speed?

        // uVar10 = sqrt(param_1 * 2 ^ param_2)
        uVar10 = FUN_80059070(iVar15 * iVar15 + iVar11 * iVar11 + iVar13 * iVar13,0x10);

        uVar10 = uVar10 >> 8;

		// speed approx
        iVar6 = (int)*(short *)(param_1 + 0x38e);

		// if you are moving
        if ((uVar10 != 0) && (0 < iVar6)) {
          *(ushort *)(param_3 + 0x22) = *(ushort *)(param_3 + 0x22) | 0x10;
          if (uVar10 == 0) {
            trap(0x1c00);
          }
          if ((uVar10 == 0xffffffff) && (iVar15 * iVar6 == -0x80000000)) {
            trap(0x1800);
          }
          *param_5 = (iVar15 * iVar6) / (int)uVar10;
          if (uVar10 == 0) {
            trap(0x1c00);
          }
          if ((uVar10 == 0xffffffff) && (iVar11 * iVar6 == -0x80000000)) {
            trap(0x1800);
          }
          param_5[1] = (iVar11 * iVar6) / (int)uVar10;
          if (uVar10 == 0) {
            trap(0x1c00);
          }
          if ((uVar10 == 0xffffffff) && (iVar13 * iVar6 == -0x80000000)) {
            trap(0x1800);
          }
          param_5[2] = (iVar13 * iVar6) / (int)uVar10;
          *param_5 = *param_5 - ((int)((uint)local_48 << 0x10) >> 0x11);
          param_5[1] = param_5[1] - ((int)((uint)local_46 << 0x10) >> 0x11);
          param_5[2] = param_5[2] - ((int)((uint)local_44 << 0x10) >> 0x11);
        }
      }
      if ((((uVar9 & 2) != 0) && (iVar3 < -0x13ff)) &&
         (
			// get approximate speed
			iVar5 = iVar5 * iVar5 + iVar14 * iVar14,

			// if speed is fast
			0x1900000 < iVar5))
	  {
		// if you are not being mask grabbed
        if (*(char *)(param_1 + 0x376) != '\x05')
		{
		  // simpTurnState
          if (*(char *)(param_1 + 0x4b) < '\x01') {
            uVar4 = 0x1f;
          }
          else {
            uVar4 = 0x2f;
          }

		  // controller vibration
          FUN_800263a0(param_1,uVar4,0x60);
        }

		// scrubMeta -> 0xC
        uVar9 = *(uint *)(param_4 + 0xc);

        if (uVar9 != 0)
		{
		  // approximate trigonometry
          iVar15 = *(int *)(&DAT_800845a0 + (uVar9 & 0x3ff) * 4);

		  if ((uVar9 & 0x400) == 0) {
            iVar15 = iVar15 << 0x10;
          }
          iVar15 = iVar15 >> 0x10;
          if ((uVar9 & 0x800) != 0) {
            iVar15 = -iVar15;
          }
          if (iVar3 * iVar3 >> 0xf <= (local_30 * iVar15 >> 0xc) * iVar15 >> 0xc) {
            return 1;
          }
        }

        if (
				// if you are not being mask-grabbed
				(*(char *)(param_1 + 0x376) != '\x05') &&

				// if speed is high
				(0x1900000 < iVar5)
			)
		{
		  // max volume, no distort, L/R
          uVar4 = 0xff8080;

		  // if echo required
          if ((*(uint *)(param_1 + 0x2c8) & 0x10000) != 0)
		  {
			// add echo
            uVar4 = 0x1ff8080;
          }

		  // OtherFX_Play_LowLevel
		  // play crashing sound
          FUN_800284d0(6,1,uVar4);

		  // Make driver talk
          FUN_8002cbe8(6,(int)(short)(&DAT_80086e84)[*(byte *)(param_1 + 0x4a)],0x10);

		  // both controller vibration
		  FUN_80026440(param_1,8,0);
          FUN_800264c0(param_1,8,0x7f);

		  // if you are power-sliding
          if (*(char *)(param_1 + 0x376) == '\x02')
		  {
			// get change in rotation for this frame
            sVar1 = *(short *)(param_1 + 0x3c6);
            *(undefined2 *)(param_1 + 0x3c6) = 0;

			// change character rotation
            *(short *)(param_1 + 0x39a) = *(short *)(param_1 + 0x39a) + sVar1;

			// change camera rotation (so camera wont spin with character)
            *(short *)(param_1 + 0x2f2) = *(short *)(param_1 + 0x2f2) - sVar1;
          }

		  // set animation to 2
          *(undefined *)(*(int *)(param_1 + 0x1c) + 0x52) = 2;

		  // set frame to zero
          *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0x54) = 0;

          *(undefined *)(param_1 + 0x4c) = 4;
          *(undefined *)(param_1 + 0x4d) = 0;

		  // Player_Crashing_Init
          FUN_80063bd4(param_2);
          return 2;
        }
      }
      uVar4 = 1;
    }
  }
  return uVar4;
}
