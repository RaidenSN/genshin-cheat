#pragma once

#include <il2cpp-appdata.h>
#include <cheat-base/Event.h>

namespace cheat::events
{
	extern TEvent<> GameUpdateEvent;
	extern TEvent<uint32_t, app::MotionInfo*> MoveSyncEvent;
}