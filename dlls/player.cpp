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

===== player.cpp ========================================================

  functions dealing with the player

*/

#include "extdll.h"
#include "util.h"

#include "cbase.h"
#include "player.h"
#include "weapons.h"

extern DLL_GLOBAL ULONG		g_ulModelIndexPlayer;

extern void DLLEXPORT SetChangeParms( globalvars_t *pgv );
extern edict_t *EntSelectSpawnPoint( globalvars_t *pgv );


// used by kill command and disconnect command
void set_suicide_frame(entvars_t *pev)
{

	if (!FStrEq(STRING(pev->model), "models/player.mdl"))
		return; // allready gibbed

//	pev->frame		= $deatha11;
	pev->solid		= SOLID_NOT;
	pev->movetype	= MOVETYPE_TOSS;
	pev->deadflag	= DEAD_DEAD;
	pev->nextthink	= -1;
}


void CBasePlayer::Spawn( void )
{
	pev->classname		= ALLOC_STRING("player");
	pev->health			= 100;
	pev->takedamage		= DAMAGE_AIM;
	pev->solid			= SOLID_SLIDEBOX;
	pev->movetype		= MOVETYPE_WALK;
	pev->max_health		= 100;
	pev->flags			= FL_CLIENT;
	pev->air_finished	= pgv->time + 12;
	pev->dmg			= 2;				// initial water damage
	pev->effects		= 0;
	pev->sequence		= 9;
	pev->deadflag		= DEAD_NO;
	SetChangeParms( pgv );

	// TODO: SaveRestore
	{
		// default to normal spawn
		edict_t* pentSpawnSpot = EntSelectSpawnPoint( pgv );
		pev->weapon = 2;
		pev->origin = VARS(pentSpawnSpot)->origin;
	}

	pev->origin;
	pev->angles;
	pev->fixangle = TRUE;           // turn this way immediately

	SAVE_SPAWN_PARMS(ENT(pev));

    SET_MODEL(ENT(pev), "models/doctor.mdl");
    g_ulModelIndexPlayer = pev->modelindex;

	UTIL_SetSize(pev, VEC_HULL_MIN, VEC_HULL_MAX);

	pev->weapons = 0x17;
	W_SetCurrentAmmo();

    pev->view_ofs = VEC_VIEW;
}


void CBasePlayer::Jump( void )
{
	if (FBitSet(pev->flags, FL_WATERJUMP))
		return;

	if (pev->waterlevel >= 2)
	{
		if (pev->watertype == CONTENT_WATER)
			pev->velocity.z = 100;
		else if (pev->watertype == CONTENT_SLIME)
			pev->velocity.z = 80;
		else
			pev->velocity.z = 50;

// play swimming sound
		// TODO
	}

	if (!FBitSet(pev->flags, FL_ONGROUND))
		return;

	if (!FBitSet(pev->flags, FL_JUMPRELEASED))
		return;		// don't pogo stick

	ClearBits(pev->flags, FL_JUMPRELEASED);

	ClearBits(pev->flags, FL_ONGROUND);	// don't stairwalk

	//SetAnimation( PLAYER_JUMP );

	pev->button &= ~IN_JUMP;
// player jumping sound
	if ( UTIL_RandomFloat(0.0, 1.0) < 0.5 )
		EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_jump1.wav", 1, ATTN_NORM);
	else
		EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_jump2.wav", 1, ATTN_NORM);
	pev->velocity.z += 270;
}


void CBasePlayer::Duck( void )
{
}


void DLLEXPORT PlayerPreThink( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);
	CBasePlayer *pPlayer = (CBasePlayer *)GET_PRIVATE(ENT(pev));
	if ( pPlayer )
		pPlayer->PreThink();
}


void CBasePlayer::PreThink( void )
{
	if (pev->view_ofs == g_vecZero)
		return;	// intermission or finale

	//UTIL_MakeVectors(pev->v_angle);		// is this still used?

	//Something1();
	//Something2();
	//WaterMove();

	//if (pev->waterlevel == 2)
	//	CheckWaterJump();

	if (pev->deadflag >= DEAD_DYING)
	{
		//PlayerDeadThink();
		return;
	}

	if (pev->button & IN_JUMP)
	{
		// If on a latter, jump off the ladder
		// else Jump
		Jump();
	}
	else
		SetBits(pev->flags, FL_JUMPRELEASED);
}


void DLLEXPORT PlayerPostThink( globalvars_t *pgv )
{
	entvars_t *pev = VARS(pgv->self);
	CBasePlayer *pPlayer = (CBasePlayer *)GET_PRIVATE(ENT(pev));
	if ( pPlayer )
		pPlayer->PostThink();
}


void CBasePlayer::PostThink( void )
{
}
