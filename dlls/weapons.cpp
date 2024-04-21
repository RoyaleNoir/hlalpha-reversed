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

===== weapons.cpp ========================================================

  functions governing the selection/use of weapons for players

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"

DLL_GLOBAL		short g_sModelIndexShell;
DLL_GLOBAL		short g_sModelIndexShrapnel;


void W_Precache( void )
{
	PRECACHE_MODEL ("models/grenade.mdl");
	PRECACHE_MODEL ("sprites/shard.spr");
	PRECACHE_MODEL ("models/v_crowbar.mdl");
	PRECACHE_MODEL ("models/v_glock.mdl");
	PRECACHE_MODEL ("models/v_mp5.mdl");
	
	g_sModelIndexShell = PRECACHE_MODEL ("models/shell.mdl");
	g_sModelIndexShrapnel = PRECACHE_MODEL ("models/shrapnel.mdl");

	PRECACHE_SOUND ("weapons/debris1.wav");
	PRECACHE_SOUND ("weapons/debris2.wav");
	PRECACHE_SOUND ("weapons/debris3.wav");
	PRECACHE_SOUND ("player/pl_shell1.wav");
	PRECACHE_SOUND ("player/pl_shell2.wav");
	PRECACHE_SOUND ("player/pl_shell3.wav");
	PRECACHE_SOUND ("weapons/hks1.wav");
	PRECACHE_SOUND ("weapons/hks2.wav");
	PRECACHE_SOUND ("weapons/hks3.wav");
	PRECACHE_SOUND ("weapons/pl_gun1.wav");
	PRECACHE_SOUND ("weapons/pl_gun2.wav");
	PRECACHE_SOUND ("weapons/glauncher.wav");
	PRECACHE_SOUND ("weapons/glauncher2.wav");
	PRECACHE_SOUND ("weapons/g_bounce1.wav");
	PRECACHE_SOUND ("weapons/g_bounce2.wav");
	PRECACHE_SOUND ("weapons/g_bounce3.wav");
}


/*
===============================================================================

PLAYER WEAPON USE

===============================================================================
*/

void CBasePlayer::W_SetCurrentAmmo( void )
{
	if ( pev->weapon == WEAPON_CROWBAR )
	{
		pev->weaponmodel = ALLOC_STRING("models/v_crowbar.mdl");
		pev->currentammo = 99.0;
	}
	else if ( pev->weapon == WEAPON_GLOCK )
	{
		pev->weaponmodel = ALLOC_STRING("models/v_glock.mdl");
		pev->currentammo = 99.0;
	}
	else if ( pev->weapon == WEAPON_MP5 )
	{
		pev->weaponmodel = ALLOC_STRING("models/v_mp5.mdl");
		pev->currentammo = 99.0;
	}
	else
	{
		pev->weaponmodel = 0;
		pev->currentammo = 0;
	}
}