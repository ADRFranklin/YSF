#include "main.h"

CConsole__AddStringVariable_t			CSAMPFunctions::pfn__CConsole__AddStringVariable = NULL;
CConsole__GetStringVariable_t			CSAMPFunctions::pfn__CConsole__GetStringVariable = NULL;
CConsole__SetStringVariable_t			CSAMPFunctions::pfn__CConsole__SetStringVariable = NULL;
CConsole__GetIntVariable_t				CSAMPFunctions::pfn__CConsole__GetIntVariable = NULL;
CConsole__SetIntVariable_t				CSAMPFunctions::pfn__CConsole__SetIntVariable = NULL;
CConsole__GetBoolVariable_t				CSAMPFunctions::pfn__CConsole__GetBoolVariable = NULL;
CConsole__ModifyVariableFlags_t			CSAMPFunctions::pfn__CConsole__ModifyVariableFlags = NULL;
CConsole__FindVariable_t				CSAMPFunctions::pfn__CConsole__FindVariable = NULL;
CConsole__SendRules_t					CSAMPFunctions::pfn__CConsole__SendRules = NULL;
CConsole__Execute_t						CSAMPFunctions::pfn__CConsole__Execute = NULL;

CFilterscripts__LoadFilterscript_t		CSAMPFunctions::pfn__CFilterscripts__LoadFilterscript = NULL;
CFilterscripts__UnLoadFilterscript_t	CSAMPFunctions::pfn__CFilterscripts__UnLoadFilterscript = NULL;

CPlayer__SpawnForWorld_t				CSAMPFunctions::pfn__CPlayer__SpawnForWorld = NULL;
CPlayerPool__HandleVehicleRespawn_t		CSAMPFunctions::pfn__CPlayerPool__HandleVehicleRespawn = NULL;

Packet_WeaponsUpdate_t					CSAMPFunctions::pfn__Packet_WeaponsUpdate = NULL;
Packet_StatsUpdate_t					CSAMPFunctions::pfn__Packet_StatsUpdate = NULL;

format_amxstring_t						CSAMPFunctions::pfn__format_amxstring = NULL;

void CSAMPFunctions::Initialize()
{
	pfn__CConsole__AddStringVariable = (CConsole__AddStringVariable_t)(CAddress::FUNC_CConsole__AddStringVariable);
	pfn__CConsole__GetStringVariable = (CConsole__GetStringVariable_t)(CAddress::FUNC_CConsole__GetStringVariable);
	pfn__CConsole__SetStringVariable = (CConsole__SetStringVariable_t)(CAddress::FUNC_CConsole__SetStringVariable);
	pfn__CConsole__GetIntVariable = (CConsole__GetIntVariable_t)(CAddress::FUNC_CConsole__GetIntVariable);
	pfn__CConsole__SetIntVariable = (CConsole__SetIntVariable_t)(CAddress::FUNC_CConsole__SetIntVariable);
	pfn__CConsole__GetBoolVariable = (CConsole__GetBoolVariable_t)(CAddress::FUNC_CConsole__GetBoolVariable);
	pfn__CConsole__ModifyVariableFlags = (CConsole__ModifyVariableFlags_t)(CAddress::FUNC_CConsole__ModifyVariableFlags);
	pfn__CConsole__FindVariable = (CConsole__FindVariable_t)(CAddress::FUNC_CConsole__FindVariable);
	pfn__CConsole__SendRules = (CConsole__SendRules_t)(CAddress::FUNC_CConsole__SendRules);
	pfn__CConsole__Execute = (CConsole__Execute_t)(CAddress::FUNC_CConsole__Execute);

	pfn__CFilterscripts__LoadFilterscript = (CFilterscripts__LoadFilterscript_t)(CAddress::FUNC_CFilterscripts__LoadFilterscript);
	pfn__CFilterscripts__UnLoadFilterscript = (CFilterscripts__UnLoadFilterscript_t)(CAddress::FUNC_CFilterscripts__UnLoadFilterscript);

	pfn__CPlayer__SpawnForWorld = (CPlayer__SpawnForWorld_t)(CAddress::FUNC_CPlayer__SpawnForWorld);
	pfn__CPlayerPool__HandleVehicleRespawn = (CPlayerPool__HandleVehicleRespawn_t)(CAddress::FUNC_CPlayerPool__HandleVehicleRespawn);

	pfn__Packet_WeaponsUpdate = (Packet_WeaponsUpdate_t)(CAddress::FUNC_Packet_WeaponsUpdate);
	pfn__Packet_StatsUpdate = (Packet_WeaponsUpdate_t)(CAddress::FUNC_Packet_StatsUpdate);

	pfn__format_amxstring = (format_amxstring_t)(CAddress::FUNC_format_amxstring);
}

void CSAMPFunctions::AddStringVariable(char *szRule, int flags, char *szString, void *changefunc)
{
	pfn__CConsole__AddStringVariable(pConsole, szRule, flags, szString, changefunc);
}

char* CSAMPFunctions::GetStringVariable(char *szRule)
{
	return pfn__CConsole__GetStringVariable(pConsole, szRule);
}

void CSAMPFunctions::SetStringVariable(char *szRule, char *szString)
{
	pfn__CConsole__SetStringVariable(pConsole, szRule, szString);
}

int CSAMPFunctions::GetIntVariable(char *szRule)
{
	return pfn__CConsole__GetIntVariable(pConsole, szRule);
}

bool CSAMPFunctions::GetBoolVariable(char *szRule)
{
	return pfn__CConsole__GetBoolVariable(pConsole, szRule);
}

void CSAMPFunctions::SetIntVariable(char *szRule, int value)
{
	pfn__CConsole__SetIntVariable(pConsole, szRule, value);
}

void CSAMPFunctions::ModifyVariableFlags(char *szRule, int value)
{
	pfn__CConsole__ModifyVariableFlags(pConsole, szRule, value);
}

ConsoleVariable_s* CSAMPFunctions::FindVariable(char *szRule)
{
	return pfn__CConsole__FindVariable(pConsole, szRule);
}

void CSAMPFunctions::SendRules(SOCKET s, char* data, const sockaddr_in* to, int tolen)
{
	pfn__CConsole__SendRules(pConsole, s, data, to, tolen);
}

void CSAMPFunctions::Execute(char* pExecLine)
{
	pfn__CConsole__Execute(pConsole, pExecLine);
}

bool CSAMPFunctions::LoadFilterscript(char *szName)
{
	return pfn__CFilterscripts__LoadFilterscript(pNetGame->pFilterScriptPool, szName);
}

bool CSAMPFunctions::UnLoadFilterscript(char *szName)
{
	return pfn__CFilterscripts__UnLoadFilterscript(pNetGame->pFilterScriptPool, szName);
}

void CSAMPFunctions::SpawnPlayer_(int playerid)
{
	pfn__CPlayer__SpawnForWorld(pNetGame->pPlayerPool->pPlayer[playerid]);
}

void CSAMPFunctions::Packet_WeaponsUpdate(Packet *p)
{
	pfn__Packet_WeaponsUpdate(pNetGame, p);
}

void CSAMPFunctions::Packet_StatsUpdate(Packet *p)
{
	pfn__Packet_StatsUpdate(pNetGame, p);
}

char* CSAMPFunctions::format_amxstring(AMX *amx, cell *params, int parm, int &len)
{
	return pfn__format_amxstring(amx, params, parm, len);
}

void CSAMPFunctions::RespawnVehicle(CVehicle *pVehicle)
{
/*
	memset(&pVehicle->vehMatrix, 0, sizeof(MATRIX4X4));
	memset(&pVehicle->vecVelocity, 0, sizeof(CVector));
	memset(&pVehicle->vecTurnSpeed, 0, sizeof(CVector));
	memset(&pVehicle->vehModInfo, 0, sizeof(CVehicleModInfo));

	pVehicle->vehModInfo.iColor1 = -1;
	pVehicle->vehModInfo.iColor2 = -1;
	pVehicle->vehMatrix.pos = pVehicle->customSpawn.vecPos;
	pVehicle->vecPosition = pVehicle->customSpawn.vecPos;
	pVehicle->vehLightStatus = 0;
	pVehicle->fHealth = 1000.0f;
	pVehicle->vehDoorStatus = 0;
	pVehicle->vehTireStatus = 0;
	pVehicle->vehPanelStatus = 0;
	pVehicle->bDead = 0;
	pVehicle->bDeathNotification = 0;
	pVehicle->bOccupied = 0;
	pVehicle->vehRespawnTick = GetTickCount();
	pVehicle->vehParamEx.alarm = -1;
	pVehicle->vehParamEx.bonnet = -1;
	pVehicle->vehParamEx.boot = -1;
	pVehicle->vehParamEx.doors = -1;
	pVehicle->vehParamEx.engine = -1;
	pVehicle->vehParamEx.lights = -1;
	pVehicle->vehParamEx.objective = -1;
	pVehicle->vehOccupiedTick = GetTickCount();

	if (pNetGame && pNetGame->pPlayerPool)
		pfn__CPlayerPool__HandleVehicleRespawn(pNetGame->pPlayerPool, pVehicle->wVehicleID);

	std::map<int, CVehicleSpawn>::iterator v = pServer->vehicleSpawnData.find(pVehicle->wVehicleID);
	if(v == pServer->vehicleSpawnData.end())
	{
		CCallbackManager::OnVehicleSpawn(pVehicle->wVehicleID);
	}
	else // T�rl�s �s l�trehoz�s de ez kurv�ra nem k�sz itt
	{			
		
		RakNet::BitStream bsVehicleSpawn;
		

		CVehicleModInfo CarModInfo;
		memset(&CarModInfo,0,sizeof(CVehicleModInfo));

		bsVehicleSpawn.Write(pVehicle->wVehicleID);
		bsVehicleSpawn.Write(spawn.iModelID);
		bsVehicleSpawn.Write(spawn.vecPos);
		bsVehicleSpawn.Write(spawn.fRot);
		bsVehicleSpawn.Write(spawn.iColor1);
		bsVehicleSpawn.Write(spawn.iColor2);
		bsVehicleSpawn.Write((float)1000.0f);

		// now add spawn co-ords and rotation
		bsVehicleSpawn.Write(spawn.vecPos);
		bsVehicleSpawn.Write(spawn.fRot);
		bsVehicleSpawn.Write(spawn.iInterior);

		if(pVehicle->szNumberplate[0] == '\0') {
			bsVehicleSpawn.Write(false);
		} else {
			bsVehicleSpawn.Write(true);
			bsVehicleSpawn.Write((PCHAR)pVehicle->szNumberplate, 9);
		}

		if(!memcmp((void *)&CarModInfo,(void *)&CarModInfo,sizeof(CVehicleModInfo))) {
			bsVehicleSpawn.Write(false);
		} else {
			bsVehicleSpawn.Write(true);
			bsVehicleSpawn.Write((PCHAR)&CarModInfo, sizeof(CarModInfo));
		}
		
		pServer->vehicleSpawnData.erase(pVehicle->wVehicleID);
	}
*/
}