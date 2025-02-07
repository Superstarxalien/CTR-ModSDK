#include <common.h>

// to do: make header
void DrawBoxOutline_LowLevel(RECT* r, int thickX, int thickY, int* colorPtr, int unk, void* ot);

// stored in RDATA
void CustomSplit()
{
	int i;
	struct Camera110* c110;
	POLY_F4* p;
	int numPlayers;

	numPlayers = sdata.gGT->numPlayers;

	// JMP to CustomSplit happens right after this, in RenderFrame
	//if ((sdata.gGT->renderFlags & 0x8000) != 0)

    if (
		(
			// If you're in Battle Mode
			(sdata.gGT->gameMode & BATTLE_MODE) &&

			// if number of screens is more than 2
			(2 < numPlayers)
		)
	 )
	{
		for(i = 0; i < numPlayers; i++)
		{
			c110 = &sdata.gGT->camera110[i];

			// Draw a 2D box made of four rectangles
			DrawBoxOutline_LowLevel(

				// dimensions, thickness
				(RECT*)&c110->windowStartX,4,2,

				// color data, 0x18 is enum offset of BLUE
				data.ptrColor[sdata.gGT->drivers[i]->BattleHUD.teamID + 0x18],

				0,

				// camera110_UI = 0x1388
				&sdata.gGT->camera110_UI.ptrOT[3]);
		}
    }

	// changed in this mod:
	// draw horizontal split when
	// numPlayers > 2, instead of 1

    if (numPlayers > 2)
	{
		p = (POLY_F4*)sdata.gGT->backBuffer->primMem.curr;

		// set R, G, B, CODE, all to zero,
		// this makes black color, and invalid CODE
		*(int*)&p->r0 = 0;

		// this sets CODE to the proper value
		setPolyF4(p);

		// Make four (x,y) coordinates
		p->y0 = 0x6a;
		p->y1 = 0x6a;
		p->x0 = 0;
		p->x1 = 0x200;

		p->x2 = 0;
		p->y2 = 0x6e;
		p->x3 = 0x200;
		p->y3 = 0x6e;

		// Draw a bar from left to right,
		// dividing the screen in half on top and bottom
		AddPrim(&sdata.gGT->camera110_UI.ptrOT[3],p);

		// backBuffer->primMem.curr
		sdata.gGT->backBuffer->primMem.curr = (void*)(p + 1);
    }

	// changed in this mod:
	// draw vertical split when
	// numPlayers > 1, instead of 2

	if (numPlayers > 1)
	{
		p = sdata.gGT->backBuffer->primMem.curr;

		// set R, G, B, CODE, all to zero,
		// this makes black color, and invalid CODE
		*(int*)&p->r0 = 0;

		// this sets CODE to the proper value
		setPolyF4(p);

		// Make four (x,y) coordinates
		p->x0 = 0xfd;
		p->x2 = 0xfd;
		p->y0 = 0;
		p->x1 = 0x103;

		p->y1 = 0;
		p->y2 = 0xd8;
		p->x3 = 0x103;
		p->y3 = 0xd8;

		// Draw a bar from left to right,
		// dividing the screen in half on top and bottom
		AddPrim(&sdata.gGT->camera110_UI.ptrOT[3],p);

		// backBuffer->primMem.curr
		sdata.gGT->backBuffer->primMem.curr = (void*)(p + 1);
    }

	// if number of screens is 3
    if (numPlayers == 3)
	{
		// This is useless, cause it gets cleared
		// to black anyway, even without this block,
		// at least it does it Crash Cove, does it always?

		p = sdata.gGT->backBuffer->primMem.curr;

		// set R, G, B, CODE, all to zero,
		// this makes black color, and invalid CODE
		*(int*)&p->r0 = 0;

		// this sets CODE to the proper value
		setPolyF4(p);

		// xy0
		p->x0 = 0x100;
		p->x2 = 0x100;
		p->y0 = 0x6c;
		p->y1 = 0x6c;
		p->x1 = 0x200;
		p->y2 = 0xd8;
		p->x3 = 0x200;
		p->y3 = 0xd8;

		// Draw a bar from left to right,
		// dividing the screen in half on top and bottom
		AddPrim(&sdata.gGT->camera110_UI.ptrOT[3],p);

		// backBuffer->primMem.curr
		sdata.gGT->backBuffer->primMem.curr = (void*)(p + 1);
    }
}