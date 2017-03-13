#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"
#include"DummyEsc.h"

#define NUM_MODULES 2

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		modules[1] = new ModuleDummyESC();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player it ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// INIT all modules
	bool Init() 
	{
		bool ret_value = true;
			for (int i = 0; i < NUM_MODULES; ++i)
			{
				modules[i]->Init();
				if (!modules[i]->Init())
				{
					ret_value = false;
				}
			}
			return ret_value;
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
		// an exit code App exits correctly.
	
	}

	// TODO 4: Add PreUpdate and PostUpdate calls

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	update_status Update()
	{
		for (int i = 0; i < NUM_MODULES; ++i)
		{
			update_status pre_status = modules[i]->Update();
			if (pre_status == update_status::UPDATE_STOP || pre_status == update_status::UPDATE_ERROR)
			{
				return pre_status;
			}
		}
	
		for (int i = 0; i < NUM_MODULES; ++i)
		{
			update_status up_stat = modules[i]->Update();
			if (up_stat == update_status::UPDATE_STOP || up_stat == update_status::UPDATE_ERROR)
			{
				return up_stat;
			}
		}
			for (int i = 0; i < NUM_MODULES; ++i)
			{
				update_status post_stat = modules[i]->Update();
				if (post_stat == update_status::UPDATE_STOP || post_stat == update_status::UPDATE_ERROR)
				{
					return post_stat;
				}
			}
	
		return update_status::UPDATE_CONTINUE;
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		bool value = true;
		for (int i = NUM_MODULES-1; i >= 0; --i)
		{
		
			if (!modules[i]->CleanUp())
			{
				value = false;
			}
		}
		delete modules;
		return value;
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
		// an exit code App exits correctly.
	
	}

};

#endif // __APPLICATION_H__