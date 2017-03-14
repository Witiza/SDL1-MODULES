#ifndef __DummyESC_H__
#define __DummyESC_H__

#include<conio.h>
#include "Module.h"
#include "Globals.h"
#include "MemLeaks.h"


class ModuleDummyESC : public Module
{
	bool Init()
	{
		LOG("DummyESC Init!");
		return true;
	}

	update_status PreUpdate()
	{
		LOG("DummyESC PreUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	update_status Update()
	{
		LOG("DummyESC Update!");
		if (_kbhit())
		{
			return update_status::UPDATE_STOP;
		}
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		LOG("DummyESC PostUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		LOG("DummyESC CleanUp!");
		return true;
	}
};

#endif // __DummyESC_H__