#include <common.h>

void DECOMP_MEMPACK_PopToState(int id)
{
	register struct sData* sdata asm("gp");

	struct Mempack* ptrMempack;
	int numBookmarks;

	// Get the pointer to the memory allocation system
	ptrMempack = sdata->PtrMempack;

	// upate count
	ptrMempack->numBookmarks = id;

	// go to bookmark address
	ptrMempack->firstFreeByte = ptrMempack->bookmarks[id];
}