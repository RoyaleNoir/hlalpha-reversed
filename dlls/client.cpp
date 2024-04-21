/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
/*

===== client.cpp ========================================================

  client/server game specific stuff

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "client.h"

extern DLL_GLOBAL ULONG		g_ulModelIndexPlayer;
extern DLL_GLOBAL BOOL		g_fGameOver;
extern DLL_GLOBAL int		g_iSkillLevel;
extern DLL_GLOBAL ULONG		g_ulFrameCount;

extern void CopyToBodyQue(entvars_t *pev);
extern void set_suicide_frame(entvars_t *pev);

DLL_GLOBAL EOFFSET g_eoLastSpawn;


/*
===========
ClientConnect

called when a player connects to a server
============
*/
void DLLEXPORT ClientConnect( globalvars_t *pgv )
{

}


/*
===========
ClientDisconnect

called when a player disconnects from a server

GLOBALS ASSUMED SET:  g_fGameOver
============
*/
void DLLEXPORT ClientDisconnect( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);

	if ( !g_fGameOver )
	{
		EMIT_SOUND(ENT(pev), CHAN_BODY, "player/tornoff2.wav", 1, ATTN_NONE);
		set_suicide_frame( pev );
	}
}


// called by ClientKill and DeadThink
void respawn(entvars_t* pev)
{
	globalvars_t *pgv = pev->pSystemGlobals;

	if (pgv->coop || pgv->deathmatch)
	{
		// make a copy of the dead body for appearances sake
		CopyToBodyQue(pev);

		// set default spawn parms
		if ( !pgv->coop )
			SetNewParms(pgv);

		// respawn player
		pgv->self = OFFSET(pev);
		PutClientInServer(pgv);
	}
	else
	{	// restart the entire server
		SERVER_COMMAND("reload\n");
	}
}


/*
============
ClientKill

Player entered the suicide command
============
*/
void DLLEXPORT ClientKill( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);

	set_suicide_frame( pev );
	pev->modelindex = g_ulModelIndexPlayer;
	pev->frags -= 2;		// extra penalty
	respawn( pev );
}

void DLLEXPORT SetChangeParms( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);
	float *parms = pgv->spawn_parms;

	if (pev->health <= 0)
	{
		SetNewParms( pgv );
		return;
	}

// cap super health
	if (pev->health >= 100)
		pev->health = 100;
	if (pev->health < 50)
		pev->health = 50;
	parms[0] = pev->items;
	parms[3] = pev->health;
	parms[4] = pev->armorvalue;
	parms[5] = pev->ammo_1;
	parms[6] = pev->ammo_2;
	parms[7] = pev->ammo_3;
	parms[8] = pev->ammo_4;
	parms[9] = pev->weapon;
	parms[10] = pev->armortype * 100;
}


/*
============
EntSelectSpawnPoint

Returns the entity to spawn at
============
*/
edict_t *EntSelectSpawnPoint( globalvars_t *pgv )
{
	edict_t *pSpot;

	// choose a info_player_deathmatch point
	if ( pgv->coop )
	{
		pSpot = FIND_ENTITY_BY_STRING( ENT(g_eoLastSpawn), "classname", "info_player_coop" );
		if ( !FNullEnt(pSpot) )
			goto ReturnSpot;
		pSpot = FIND_ENTITY_BY_STRING( ENT(g_eoLastSpawn), "classname", "info_player_start" );
		if ( !FNullEnt(pSpot) )
			goto ReturnSpot;
	}
	else if ( pgv->deathmatch )
	{
		int totalspots = 25;
		int numspots = UTIL_RandomFloat(0, totalspots);

		do
		{
			if ( totalspots-- == 0 )
				break;

			pSpot = FIND_ENTITY_BY_STRING( ENT(g_eoLastSpawn), "classname", "info_player_deathmatch" );
			if ( !FNullEnt(pSpot) )
				goto ReturnSpot;
		} while ( numspots-- > 0 );
	}

	if ( pgv->serverflags )
	{ // return with a rune to start
		pSpot = FIND_ENTITY_BY_STRING( NULL, "classname", "info_player_start2" );
		if ( !FNullEnt(pSpot) )
			goto ReturnSpot;
	}

	pSpot = FIND_ENTITY_BY_STRING( NULL, "classname", "info_player_start" );

ReturnSpot:
	if ( FNullEnt( pSpot ) )
	{
		ALERT(at_error, "PutClientInServer: no info_player_start on level");
		return ENT(0);
	}

	g_eoLastSpawn = OFFSET( pSpot );
	return pSpot;
}

/*
===========
PutClientInServer

called each time a player enters a new level
============
*/
void DLLEXPORT PutClientInServer( globalvars_t *pgv )
{
	CBasePlayer *pPlayer;

	entvars_t *pev = VARS(pgv->self);

	pPlayer = GetClassPtr((CBasePlayer *)pev);

	// Allocate a CBasePlayer for pev, and call spawn
	pPlayer->Spawn();
}

void DLLEXPORT SetNewParms( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);

	float *parms = (float*)malloc( 120 );
	memset( parms, 0, 120 );

	parms[0] = 2;
	parms[3] = 100;
	parms[0] = pev->items;
	parms[4] = pev->armorvalue;
	parms[9] = pev->weapon;
	parms[11] = FBitSet( pev->flags, FL_DUCKING );
	parms[12] = 0;

	pgv->spawn_parms = parms;
}

//
// GLOBALS ASSUMED SET:  g_ulFrameCount
//
void DLLEXPORT StartFrame( globalvars_t *pgv )
{
	g_iSkillLevel = CVAR_GET_FLOAT("skill");
	g_ulFrameCount++;
}