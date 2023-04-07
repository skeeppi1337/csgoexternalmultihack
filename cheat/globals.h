#include <cstdint>
#include <cstddef>

namespace globals
{
	inline std::uintptr_t clientAddress = 0;
	inline std::uintptr_t engineAddress = 0;

	inline bool glow = false;
	inline float glowColor[] = { 0.706f, 0.235f, 0.471f, 0.65f };
	inline bool glowTeam = false;
	inline bool chams = false;
	inline bool chamsVis = false;
	inline float chamColorEnemy[] = { 0.588f, 0.784f, 0.235f };
	inline float chamColorFriendly[] = { 0.235f, 0.471f, 0.706f };
	inline float chamBrightness = 0.f;
	inline bool triggerBot = false;
	inline int triggerBotDelay = 0;
	inline bool triggerBotMagnet = false;
	inline float triggerBotMagnetFov = 0.f;
	inline float triggerBotMagnetSmooth = 0.f;
	inline bool aimbot = false;
	inline float aimbotSmooth = 0.f;
	inline float aimbotFov = 1.f;
	inline bool radar= false;
	inline bool bunnyHop = false;
	inline bool recoil = false;
	static const char* currentItem = NULL;
}