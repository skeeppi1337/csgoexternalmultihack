#include "hacks.h"
#include "gui.h"
#include "globals.h"
#include <thread>
#include <iostream>
#include <vector>
#include <cmath>
#include "vector.h"


namespace offsets
{
	constexpr ::std::ptrdiff_t cs_gamerules_data = 0x0;
	constexpr ::std::ptrdiff_t m_ArmorValue = 0x117CC;
	constexpr ::std::ptrdiff_t m_Collision = 0x320;
	constexpr ::std::ptrdiff_t m_CollisionGroup = 0x474;
	constexpr ::std::ptrdiff_t m_Local = 0x2FCC;
	constexpr ::std::ptrdiff_t m_MoveType = 0x25C;
	constexpr ::std::ptrdiff_t m_OriginalOwnerXuidHigh = 0x31D4;
	constexpr ::std::ptrdiff_t m_OriginalOwnerXuidLow = 0x31D0;
	constexpr ::std::ptrdiff_t m_SurvivalGameRuleDecisionTypes = 0x1328;
	constexpr ::std::ptrdiff_t m_SurvivalRules = 0xD00;
	constexpr ::std::ptrdiff_t m_aimPunchAngle = 0x303C;
	constexpr ::std::ptrdiff_t m_aimPunchAngleVel = 0x3048;
	constexpr ::std::ptrdiff_t m_angEyeAnglesX = 0x117D0;
	constexpr ::std::ptrdiff_t m_angEyeAnglesY = 0x117D4;
	constexpr ::std::ptrdiff_t m_bBombDefused = 0x29C0;
	constexpr ::std::ptrdiff_t m_bBombPlanted = 0x9A5;
	constexpr ::std::ptrdiff_t m_bBombTicking = 0x2990;
	constexpr ::std::ptrdiff_t m_bFreezePeriod = 0x20;
	constexpr ::std::ptrdiff_t m_bGunGameImmunity = 0x9990;
	constexpr ::std::ptrdiff_t m_bHasDefuser = 0x117DC;
	constexpr ::std::ptrdiff_t m_bHasHelmet = 0x117C0;
	constexpr ::std::ptrdiff_t m_bInReload = 0x32B5;
	constexpr ::std::ptrdiff_t m_bIsDefusing = 0x997C;
	constexpr ::std::ptrdiff_t m_bIsQueuedMatchmaking = 0x74;
	constexpr ::std::ptrdiff_t m_bIsScoped = 0x9974;
	constexpr ::std::ptrdiff_t m_bIsValveDS = 0x7C;
	constexpr ::std::ptrdiff_t m_bSpotted = 0x93D;
	constexpr ::std::ptrdiff_t m_bSpottedByMask = 0x980;
	constexpr ::std::ptrdiff_t m_bStartedArming = 0x3400;
	constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMax = 0x9D9;
	constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMin = 0x9D8;
	constexpr ::std::ptrdiff_t m_bUseCustomBloomScale = 0x9DA;
	constexpr ::std::ptrdiff_t m_clrRender = 0x70;
	constexpr ::std::ptrdiff_t m_dwBoneMatrix = 0x26A8;
	constexpr ::std::ptrdiff_t m_fAccuracyPenalty = 0x3340;
	constexpr ::std::ptrdiff_t m_fFlags = 0x104;
	constexpr ::std::ptrdiff_t m_flC4Blow = 0x29A0;
	constexpr ::std::ptrdiff_t m_flCustomAutoExposureMax = 0x9E0;
	constexpr ::std::ptrdiff_t m_flCustomAutoExposureMin = 0x9DC;
	constexpr ::std::ptrdiff_t m_flCustomBloomScale = 0x9E4;
	constexpr ::std::ptrdiff_t m_flDefuseCountDown = 0x29BC;
	constexpr ::std::ptrdiff_t m_flDefuseLength = 0x29B8;
	constexpr ::std::ptrdiff_t m_flFallbackWear = 0x31E0;
	constexpr ::std::ptrdiff_t m_flFlashDuration = 0x10470;
	constexpr ::std::ptrdiff_t m_flFlashMaxAlpha = 0x1046C;
	constexpr ::std::ptrdiff_t m_flLastBoneSetupTime = 0x2928;
	constexpr ::std::ptrdiff_t m_flLowerBodyYawTarget = 0x9ADC;
	constexpr ::std::ptrdiff_t m_flNextAttack = 0x2D80;
	constexpr ::std::ptrdiff_t m_flNextPrimaryAttack = 0x3248;
	constexpr ::std::ptrdiff_t m_flSimulationTime = 0x268;
	constexpr ::std::ptrdiff_t m_flTimerLength = 0x29A4;
	constexpr ::std::ptrdiff_t m_hActiveWeapon = 0x2F08;
	constexpr ::std::ptrdiff_t m_hBombDefuser = 0x29C4;
	constexpr ::std::ptrdiff_t m_hMyWeapons = 0x2E08;
	constexpr ::std::ptrdiff_t m_hObserverTarget = 0x339C;
	constexpr ::std::ptrdiff_t m_hOwner = 0x29DC;
	constexpr ::std::ptrdiff_t m_hOwnerEntity = 0x14C;
	constexpr ::std::ptrdiff_t m_hViewModel = 0x3308;
	constexpr ::std::ptrdiff_t m_iAccountID = 0x2FD8;
	constexpr ::std::ptrdiff_t m_iClip1 = 0x3274;
	constexpr ::std::ptrdiff_t m_iCompetitiveRanking = 0x1A84;
	constexpr ::std::ptrdiff_t m_iCompetitiveWins = 0x1B88;
	constexpr ::std::ptrdiff_t m_iCrosshairId = 0x11838;
	constexpr ::std::ptrdiff_t m_iDefaultFOV = 0x333C;
	constexpr ::std::ptrdiff_t m_iEntityQuality = 0x2FBC;
	constexpr ::std::ptrdiff_t m_iFOV = 0x31F4;
	constexpr ::std::ptrdiff_t m_iFOVStart = 0x31F8;
	constexpr ::std::ptrdiff_t m_iGlowIndex = 0x10488;
	constexpr ::std::ptrdiff_t m_iHealth = 0x100;
	constexpr ::std::ptrdiff_t m_iItemDefinitionIndex = 0x2FBA;
	constexpr ::std::ptrdiff_t m_iItemIDHigh = 0x2FD0;
	constexpr ::std::ptrdiff_t m_iMostRecentModelBoneCounter = 0x2690;
	constexpr ::std::ptrdiff_t m_iObserverMode = 0x3388;
	constexpr ::std::ptrdiff_t m_iShotsFired = 0x103E0;
	constexpr ::std::ptrdiff_t m_iState = 0x3268;
	constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
	constexpr ::std::ptrdiff_t m_lifeState = 0x25F;
	constexpr ::std::ptrdiff_t m_nBombSite = 0x2994;
	constexpr ::std::ptrdiff_t m_nFallbackPaintKit = 0x31D8;
	constexpr ::std::ptrdiff_t m_nFallbackSeed = 0x31DC;
	constexpr ::std::ptrdiff_t m_nFallbackStatTrak = 0x31E4;
	constexpr ::std::ptrdiff_t m_nForceBone = 0x268C;
	constexpr ::std::ptrdiff_t m_nModelIndex = 0x258;
	constexpr ::std::ptrdiff_t m_nTickBase = 0x3440;
	constexpr ::std::ptrdiff_t m_nViewModelIndex = 0x29D0;
	constexpr ::std::ptrdiff_t m_rgflCoordinateFrame = 0x444;
	constexpr ::std::ptrdiff_t m_szCustomName = 0x304C;
	constexpr ::std::ptrdiff_t m_szLastPlaceName = 0x35C4;
	constexpr ::std::ptrdiff_t m_thirdPersonViewAngles = 0x31E8;
	constexpr ::std::ptrdiff_t m_vecOrigin = 0x138;
	constexpr ::std::ptrdiff_t m_vecVelocity = 0x114;
	constexpr ::std::ptrdiff_t m_vecViewOffset = 0x108;
	constexpr ::std::ptrdiff_t m_viewPunchAngle = 0x3030;
	constexpr ::std::ptrdiff_t m_zoomLevel = 0x33E0;



	constexpr ::std::ptrdiff_t anim_overlays = 0x2990;
	constexpr ::std::ptrdiff_t clientstate_choked_commands = 0x4D30;
	constexpr ::std::ptrdiff_t clientstate_delta_ticks = 0x174;
	constexpr ::std::ptrdiff_t clientstate_last_outgoing_command = 0x4D2C;
	constexpr ::std::ptrdiff_t clientstate_net_channel = 0x9C;
	constexpr ::std::ptrdiff_t convar_name_hash_table = 0x301A0;
	constexpr ::std::ptrdiff_t dwClientState = 0x59F19C;
	constexpr ::std::ptrdiff_t dwClientState_GetLocalPlayer = 0x180;
	constexpr ::std::ptrdiff_t dwClientState_IsHLTV = 0x4D48;
	constexpr ::std::ptrdiff_t dwClientState_Map = 0x28C;
	constexpr ::std::ptrdiff_t dwClientState_MapDirectory = 0x188;
	constexpr ::std::ptrdiff_t dwClientState_MaxPlayer = 0x388;
	constexpr ::std::ptrdiff_t dwClientState_PlayerInfo = 0x52C0;
	constexpr ::std::ptrdiff_t dwClientState_State = 0x108;
	constexpr ::std::ptrdiff_t dwClientState_ViewAngles = 0x4D90;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DFFFC4;
	constexpr ::std::ptrdiff_t dwForceAttack = 0x322DDFC;
	constexpr ::std::ptrdiff_t dwForceAttack2 = 0x322DE08;
	constexpr ::std::ptrdiff_t dwForceBackward = 0x322DE50;
	constexpr ::std::ptrdiff_t dwForceForward = 0x322DE44;
	constexpr ::std::ptrdiff_t dwForceJump = 0x52BBD50;
	constexpr ::std::ptrdiff_t dwForceLeft = 0x322DE5C;
	constexpr ::std::ptrdiff_t dwForceRight = 0x322DDC0;
	constexpr ::std::ptrdiff_t dwGameDir = 0x63AD80;
	constexpr ::std::ptrdiff_t dwGameRulesProxy = 0x532F56C;
	constexpr ::std::ptrdiff_t dwGetAllClasses = 0xE0BF8C;
	constexpr ::std::ptrdiff_t dwGlobalVars = 0x59EE60;
	constexpr ::std::ptrdiff_t dwGlowObjectManager = 0x535AA70;
	constexpr ::std::ptrdiff_t dwInput = 0x525D598;
	constexpr ::std::ptrdiff_t dwInterfaceLinkList = 0x99C174;
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t dwMouseEnable = 0x52391F8;
	constexpr ::std::ptrdiff_t dwMouseEnablePtr = 0x52391C8;
	constexpr ::std::ptrdiff_t dwPlayerResource = 0x322C170;
	constexpr ::std::ptrdiff_t dwRadarBase = 0x5236A9C;
	constexpr ::std::ptrdiff_t dwSensitivity = 0xDEEB80;
	constexpr ::std::ptrdiff_t dwSensitivityPtr = 0xDEEB80;
	constexpr ::std::ptrdiff_t dwSetClanTag = 0x8DA80;
	constexpr ::std::ptrdiff_t dwViewMatrix = 0x4DF0DF4;
	constexpr ::std::ptrdiff_t dwWeaponTable = 0x525E674;
	constexpr ::std::ptrdiff_t dwWeaponTableIndex = 0x326C;
	constexpr ::std::ptrdiff_t dwYawPtr = 0xDEE910;
	constexpr ::std::ptrdiff_t dwZoomSensitivityRatioPtr = 0xDF4380;
	constexpr ::std::ptrdiff_t dwbSendPackets = 0xDD2B2;
	constexpr ::std::ptrdiff_t dwppDirect3DDevice9 = 0xA62C0;
	constexpr ::std::ptrdiff_t find_hud_element = 0x2B940090;
	constexpr ::std::ptrdiff_t force_update_spectator_glow = 0x3D96FA;
	constexpr ::std::ptrdiff_t interface_engine_cvar = 0x3FA9C;
	constexpr ::std::ptrdiff_t is_c4_owner = 0x3E6F10;
	constexpr ::std::ptrdiff_t m_bDormant = 0xED;
	constexpr ::std::ptrdiff_t m_bIsLocalPlayer = 0x3628;
	constexpr ::std::ptrdiff_t m_flSpawnTime = 0x103C0;
	constexpr ::std::ptrdiff_t m_pStudioHdr = 0x2950;
	constexpr ::std::ptrdiff_t m_pitchClassPtr = 0x52390F0;
	constexpr ::std::ptrdiff_t m_yawClassPtr = 0xDEE910;
	constexpr ::std::ptrdiff_t model_ambient_min = 0x5A1194;
	constexpr ::std::ptrdiff_t set_abs_angles = 0x1E76F0;
	constexpr ::std::ptrdiff_t set_abs_origin = 0x1E7530;

}

constexpr Vector3 CalculateAngle(
	const Vector3& localPosition,
	const Vector3& enemyPosition,
	const Vector3& viewAngles)
{
	return ((enemyPosition - localPosition).ToAngle() - viewAngles);
}


void hacks::cheatThread(const Memory& mem) noexcept //kun heräte
{
	// initialize memory class
	const auto memory = Memory{ "csgo.exe" };

	// module addresses
	const auto client = memory.GetModuleAddress("client.dll");
	const auto engine = memory.GetModuleAddress("engine.dll");

	while (gui::isRunning)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		struct Color
		{
			std::uint8_t r{}, g{}, b{};
		};

		const auto localPlayer = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwLocalPlayer);
		const auto localTeam = mem.Read<std::int32_t>(localPlayer + offsets::m_iTeamNum);
		const auto glowManager = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwGlowObjectManager);
		const auto localHealth = mem.Read<std::int32_t>(localPlayer + offsets::m_iHealth);


		if (globals::glow || globals::radar) //glow ja radar
		{

			if (!localPlayer)
				continue;

			if (!glowManager)
				continue;

			for (auto i = 0; i < 64; ++i) //glow loop
			{
				const auto& entity = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwEntityList + i * 0x10);
				const auto& entityTeam = mem.Read<std::uintptr_t>(entity + offsets::m_iTeamNum);

				if (!entity)
					continue;

				if (entityTeam == localTeam && !globals::glowTeam)
					continue;

				const auto lifeState = mem.Read<std::int32_t>(entity + offsets::m_lifeState);

				if (lifeState != 0)
					continue;

				if (globals::glow)
				{
					const auto glowIndex = mem.Read<std::int32_t>(entity + offsets::m_iGlowIndex);

					mem.Write<float>(glowManager + (glowIndex * 0x38) + 0x8, globals::glowColor[0]); //red
					mem.Write<float>(glowManager + (glowIndex * 0x38) + 0xC, globals::glowColor[1]); //green
					mem.Write<float>(glowManager + (glowIndex * 0x38) + 0x10, globals::glowColor[2]); //blue
					mem.Write<float>(glowManager + (glowIndex * 0x38) + 0x14, globals::glowColor[3]); //alpha

					mem.Write<bool>(glowManager + (glowIndex * 0x38) + 0x28, true);
					mem.Write<bool>(glowManager + (glowIndex * 0x38) + 0x29, true);
				}

				if (globals::radar)
					mem.Write(entity + offsets::m_bSpotted, true);
			}
		}

		if (globals::aimbot)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			// aimbot key
			if (!GetAsyncKeyState(VK_LBUTTON))
				continue;

			// eye position = origin + viewOffset
			const auto localEyePosition = memory.Read<Vector3>(localPlayer + offsets::m_vecOrigin) +
				memory.Read<Vector3>(localPlayer + offsets::m_vecViewOffset);

			const auto clientState = memory.Read<std::uintptr_t>(engine + offsets::dwClientState);

			/*const auto& localPlayerId =
				memory.Read<std::int32_t>(clientState + offsets::dwClientState_GetLocalPlayer);*/

			const auto viewAngles = memory.Read<Vector3>(clientState + offsets::dwClientState_ViewAngles);
			const auto aimPunch = memory.Read<Vector3>(localPlayer + offsets::m_aimPunchAngle) * 2;

			// aimbot fov
			auto bestFov = globals::aimbotFov;
			auto bestAngle = Vector3{ 1, 1, 0 };
			auto newAngle = Vector3{ };
			auto smoothAngle = Vector3{ };

			for (auto i = 1; i <= 32; ++i)
			{
				const auto player = memory.Read<std::uintptr_t>(client + offsets::dwEntityList + i * 0x10);
				const auto playerTeam = memory.Read<std::int32_t>(player + offsets::m_iTeamNum);
				const auto isDormant = memory.Read<bool>(player + offsets::m_bDormant);
				const auto playerHealt = memory.Read<std::int32_t>(player + offsets::m_iHealth);
				const auto spottedByMask = memory.Read<bool>(player + offsets::m_bSpottedByMask);

				if (playerTeam == localTeam)
					continue;

				if (isDormant)
					continue;

				if (!playerHealt) //voi olla
					continue;

				if (!spottedByMask /*&& (1 << localPlayerId)*/)
					continue;

				const auto boneMatrix = memory.Read<std::uintptr_t>(player + offsets::m_dwBoneMatrix);

				// pos of player head in 3d space
				// 8 is the head bone index :)
				const Vector3 playerHeadPosition = Vector3{
					memory.Read<float>(boneMatrix + 0x30 * 8 + 0x0C),
					memory.Read<float>(boneMatrix + 0x30 * 8 + 0x1C),
					memory.Read<float>(boneMatrix + 0x30 * 8 + 0x2C)
				};

				auto calcAngle = CalculateAngle(
					localEyePosition,
					playerHeadPosition,
					viewAngles 
				);

				auto fov = std::hypot(calcAngle.x, calcAngle.y);

				if (fov < globals::aimbotFov)
				{
					float smooth = globals::aimbotSmooth + 1.f;
					bestFov = fov;
					bestAngle = calcAngle;
					newAngle = (viewAngles + bestAngle / smooth); // toimii ilman smooth
					memory.Write<Vector3>(clientState + offsets::dwClientState_ViewAngles, newAngle); // smoothing
				}
			}
		}

			// if we have a best angle, do aimbot
			

		if (globals::bunnyHop)//bhop
		{
			//const auto& localPlayer = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwLocalPlayer);

			if (localPlayer)
			{
				const auto onGround = mem.Read<bool>(localPlayer + offsets::m_fFlags);
				if (GetAsyncKeyState(VK_SPACE) && onGround & (1 << 0))
				{
					mem.Write<BYTE>(globals::clientAddress + offsets::dwForceJump, 6);
				}
			}
		}

		if (globals::triggerBot) //triggerbot loop
		{
			if (!GetAsyncKeyState(VK_MBUTTON))
				continue;

			if (globals::triggerBotMagnet)
			{
				// eye position = origin + viewOffset
				const auto localEyePosition = memory.Read<Vector3>(localPlayer + offsets::m_vecOrigin) +
					memory.Read<Vector3>(localPlayer + offsets::m_vecViewOffset);

				const auto clientState = memory.Read<std::uintptr_t>(engine + offsets::dwClientState);

				/*const auto& localPlayerId =
					memory.Read<std::int32_t>(clientState + offsets::dwClientState_GetLocalPlayer);*/

				const auto viewAngles = memory.Read<Vector3>(clientState + offsets::dwClientState_ViewAngles);
				const auto aimPunch = memory.Read<Vector3>(localPlayer + offsets::m_aimPunchAngle) * 2;

				// aimbot fov
				auto bestFovTrigger = globals::triggerBotMagnetFov;
				auto bestAngleTrigger = Vector3{ 1, 1, 0 };
				auto newAngleTrigger = Vector3{ };
				auto smoothAngleTrigger = Vector3{ };

				for (auto i = 1; i <= 32; ++i)
				{
					const auto player = memory.Read<std::uintptr_t>(client + offsets::dwEntityList + i * 0x10);
					const auto playerTeam = memory.Read<std::int32_t>(player + offsets::m_iTeamNum);
					const auto isDormant = memory.Read<bool>(player + offsets::m_bDormant);
					const auto playerHealt = memory.Read<std::int32_t>(player + offsets::m_iHealth);
					const auto spottedByMask = memory.Read<bool>(player + offsets::m_bSpottedByMask);

					if (playerTeam == localTeam)
						continue;

					if (isDormant)
						continue;

					if (!playerHealt) //voi olla
						continue;

					if (!spottedByMask /*&& (1 << localPlayerId)*/)
						continue;

					const auto boneMatrix = memory.Read<std::uintptr_t>(player + offsets::m_dwBoneMatrix);

					// pos of player head in 3d space
					// 8 is the head bone index :)
					const Vector3 playerHeadPosition = Vector3{
						memory.Read<float>(boneMatrix + 0x30 * 8 + 0x0C),
						memory.Read<float>(boneMatrix + 0x30 * 8 + 0x1C),
						memory.Read<float>(boneMatrix + 0x30 * 8 + 0x2C)
					};

					auto calcAngle = CalculateAngle(
						localEyePosition,
						playerHeadPosition,
						viewAngles
					);

					auto fov = std::hypot(calcAngle.x, calcAngle.y);

					if (fov < globals::triggerBotMagnetFov)
					{
						float smoothTrigger;
						bestFovTrigger = fov;
						bestAngleTrigger = calcAngle;
						smoothTrigger = globals::triggerBotMagnetSmooth + 1.f;
						newAngleTrigger = (viewAngles + bestAngleTrigger / smoothTrigger); // toimii ilman smooth
						memory.Write<Vector3>(clientState + offsets::dwClientState_ViewAngles, newAngleTrigger); // smoothing
					}
				}
			}

			Sleep(globals::triggerBotDelay);

			if (!localHealth) //ignore if local dead
				continue;

			const auto& CrosshairId = mem.Read<std::int32_t>(localPlayer + offsets::m_iCrosshairId);

			if (!CrosshairId || CrosshairId > 64)//ignore wall or npc
				continue;

			const auto& entity = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwEntityList + (CrosshairId - 1) * 0x10);

			if (mem.Read<std::int32_t>(entity + offsets::m_lifeState) != 0)//ignore entity is dead
				continue;

			if (mem.Read<std::int32_t>(entity + offsets::m_iTeamNum) != mem.Read<std::int32_t>(localPlayer + offsets::m_iTeamNum))

				mem.Write<std::uintptr_t>(globals::clientAddress + offsets::dwForceAttack, 6);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
			mem.Write<std::uintptr_t>(globals::clientAddress + offsets::dwForceAttack, 4);
		}

		if (globals::chams)
		{


			if (!localPlayer) //local not found
				continue;

			if (!localTeam) //team not found
				continue;

			for (auto i = 0; i < 64; ++i)
			{
				const auto& entity = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwEntityList + i * 0x10);
				const auto& entityTeam = mem.Read<std::int32_t>(entity + offsets::m_iTeamNum);

				if (entity == localPlayer) //skip local player
					continue;

				//Basically you only need to take your float value, clamp between 0.0 and 1.0, multiply it by 255 and cast to integer.

				//change float to int

				unsigned char enemyRed = (globals::chamColorEnemy[0] * 255);
				unsigned char enemyGreen = (globals::chamColorEnemy[1] * 255);
				unsigned char enemyBlue = (globals::chamColorEnemy[2] * 255);
				auto enemyColor = Color{ enemyRed,  enemyGreen , enemyBlue };

				unsigned char friendlyRed = (globals::chamColorFriendly[0] * 255);
				unsigned char friendlyGreen = (globals::chamColorFriendly[1] * 255);
				unsigned char friendlyBlue = (globals::chamColorFriendly[2] * 255);
				auto teamColor = Color{ friendlyRed,  friendlyGreen , friendlyBlue };

				//&globals::chamColorEnemy[int(0)] , &globals::chamColorEnemy[1] , &globals::chamColorEnemy[2]};
				//brightness
				const auto _this = static_cast<std::uintptr_t>(globals::engineAddress + offsets::model_ambient_min - 0x2c); //cant change single player brightness
				mem.Write<std::int32_t>(globals::engineAddress + offsets::model_ambient_min, *reinterpret_cast<std::uintptr_t*>(&globals::chamBrightness) ^ _this);

				if (entityTeam != localTeam) //enemy chams
				{
					mem.Write<>(entity + offsets::m_clrRender, enemyColor);
				}
				else //friendly chams
				{
					mem.Write<>(entity + offsets::m_clrRender, teamColor);
				}

			}
		}
	}
}
