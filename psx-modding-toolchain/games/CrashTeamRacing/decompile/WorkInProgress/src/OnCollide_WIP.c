#include <common.h>

void Turbo_Increment(struct Driver* driver, int reserves, u_int type, int fireLevel);
void THREAD_CollidePointWithBucket(struct Thread* thread, u_short* param_2);
void DriverCrash_AnyTwoCars(struct Thread* thread, u_short* param_2, int* param_3);

// OnCollide
// handle collision with turbo pads and robotcars
void DECOMP_OnCollide(struct Thread* bread, struct Driver* driver)
{
	struct Instance* breadInstance;
	u_int reservesIncrement;
	int iVar3;
	u_int fireLevel;
	u_int stepFlagSet;
	u_short posX;
	u_short posY;
	u_short posZ;
	struct Thread* collideThread;
	int distance;
	short driverHitRadius;

	driver->coordSpeed[1] -= driver->coordSpeedSubtract[1];
	driver->coordSpeed[0] -= driver->coordSpeedSubtract[0];
	stepFlagSet = driver->stepFlagSet;
	driver->coordSpeed[2] -= driver->coordSpeedSubtract[2];

	if (stepFlagSet & 0x4000)
	{
		*(u_short*)&driver->fill18_postQuadBlock[6] |= 1;
	}

	// If this is not a super turbo pad
	if ((stepFlagSet & 2) == 0)
	{

		// If this is not an ordinary turbo pad
		if ((stepFlagSet & 1) == 0) goto LAB_8005ec70;

		// add one second reserves
		reservesIncrement = 0x3c0;

		// If Super Turbo Pads is enabled
		if (sdata.gGT->advFlags & 0x100000)
		{
			// Skip a few lines
			goto LAB_8005ec50;
		}

		// set speed of turbo to normal speed
		fireLevel = 0x100;
	}

	// If this is a super turbo pad (only on some tracks)
	else
	{
LAB_8005ec50:

		// add 0.12s reserves
		reservesIncrement = 0x78;

		// Set speed of turbo to big speed
		fireLevel = 0x800;
	}

	// Turbo_Increment
	// add reserves and speed of turbo pad
	Turbo_Increment(driver, reservesIncrement, 5, fireLevel);

LAB_8005ec70:
	if ((stepFlagSet & 0x8000) == 0)
	{
		// thread -> instance -> flags
		// instance is not in water or mud
		bread->inst->flags &= 0xffffdfff;
	}

	// if instance is in water or mud
	else
	{
		// thread -> instance
		breadInstance = bread->inst;

		// set vertical split height
		// (Y=0 for all water and mud)
		breadInstance->vertSplit = 0;

		// instance -> flags
		// split the instance
		breadInstance->flags |= 0x2000;
	}

	// if collision is not disabled for this thread
	if ((bread->flags & 0x1000) == 0)
	{
		// 40, 3e, 3c, 38, 34, allocated in that order

		// position X and Y
		posX = (u_short)((u_int)driver->posCurr[0] >> 8);
		posY = (u_short)((u_int)driver->posCurr[1] >> 8);

		// distance between two objects
		distance = 0x7fffffff;

		// thread you collide with
		collideThread = 0;

		// position Z
		posZ = (u_short)((u_int)driver->posCurr[2] >> 8);

		// check for collision with all sibling threads
		THREAD_CollidePointWithBucket(bread->siblingThread, &posX);

		// pointer to first robotcar thread
		THREAD_CollidePointWithBucket(sdata.gGT->threadBuckets[ROBOT].thread, &posX);

		if
		(
			// if there was a collision
			(collideThread != 0) &&
			(
				// thread offset 0x42?
				driverHitRadius = bread->driver_HitRadius + collideThread->driver_HitRadius,

				distance < driverHitRadius * driverHitRadius
			)
		)
		{
			// pass the thread, collision data, and driver->88 is velocity?
			DriverCrash_AnyTwoCars(bread, &posX, &driver->coordSpeed[0]);
		}
	}
	if (*(u_short*)&driver->fill18_postQuadBlock[6] & 2) 
	{
		iVar3 = (driver->posCurr[0] >> 8) - *(short*)&driver->fill18_postQuadBlock[8];
		driverHitRadius = (driver->posCurr[2] >> 8) - *(short *)&driver->fill18_postQuadBlock[0xC];
		
		if
		(
			*(short*)&driver->fill18_postQuadBlock[0x10] * iVar3 + *(short*)&driver->fill18_postQuadBlock[0x12] * 
			(
				((driver->quadBlockHeight >> 8) - *(short *)&driver->fill18_postQuadBlock[0xA]) + 4
			)
			+ *(short*)&driver->fill18_postQuadBlock[0x14] * driverHitRadius < 0
		) 
		{
			// calculate speed vector
			driver->coordSpeed[0] += iVar3 * 0x40;
			driver->coordSpeed[1] += ((driver->posCurr[1] >> 8) - *(short *)&driver->fill18_postQuadBlock[0xA]) * 0x40;
			driver->coordSpeed[2] += driverHitRadius * 0x40;
		}
	}
	return;
}