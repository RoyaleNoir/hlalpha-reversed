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

===== world.cpp ========================================================

  precaches and defs for entities and other data that must always be available.

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"

extern DLL_GLOBAL EOFFSET		g_eoLastSpawn;
DLL_GLOBAL EOFFSET				g_eoBodyQueueHead;

extern void W_Precache(void);

//
// This must match the list in util.h
//
const char *gDecals[] = {
	"{shot1",
	"{shot2",
	"{shot3",
	"{shot4",
	"{shot5",
	"{hl",
	"{lambda01",
	"{lambda02",
	"{lambda03",
	"{lambda04",
	"{lambda05",
	"{lambda06",
	"{scorch1",
	"{scorch2",
	"{blood1",
	"{blood2",
	"{blood3",
	"{blood4",
	"{blood5",
	"{blood6",
	"{yblood1",
	"{yblood2",
	"{yblood3",
	"{yblood4",
	"{yblood5",
	"{yblood6",
	"{break1",
	"{break2",
	"{break3",
};


/*
==============================================================================

BODY QUE

==============================================================================
*/

static void InitBodyQue(void)
{
	entvars_t	*pev;
	string_t	istrClassname = ALLOC_STRING("bodyque");

	g_eoBodyQueueHead = OFFSET(CREATE_ENTITY());
	pev = VARS(g_eoBodyQueueHead);
	pev->classname = istrClassname;

	for ( int i = 0; i < 3; i++ )
	{
		pev->owner = OFFSET(CREATE_ENTITY());
		pev = VARS( pev->owner );
		pev->classname = istrClassname;
	}

	pev->owner = g_eoBodyQueueHead;
}


//
// make a body que entry for the given ent so the ent can be respawned elsewhere
//
// GLOBALS ASSUMED SET:  g_eoBodyQueueHead
//
void CopyToBodyQue(entvars_t *pev)
{
	entvars_t *pevHead	= VARS(g_eoBodyQueueHead);

	pevHead->angles		= pev->angles;
	pevHead->model		= pev->model;
	pevHead->modelindex	= pev->modelindex;
	pevHead->frame		= pev->frame;
	pevHead->colormap	= pev->colormap;
	pevHead->movetype	= pev->movetype;
	pevHead->velocity	= pev->velocity;
	pevHead->flags		= 0;
	pevHead->deadflag	= pev->deadflag;
	pevHead->sequence	= pev->sequence;

	UTIL_SetOrigin(pevHead, pev->origin);
	UTIL_SetSize(pevHead, pev->mins, pev->maxs);
	g_eoBodyQueueHead = pev->owner;
}

//=======================
// CWorld
//
// This spawns first when each level begins.
//=======================
class CWorld : public CBaseEntity
{
public:
	void Spawn( void );
	void KeyValue( KeyValueData *pkvd );
};

LINK_ENTITY_TO_CLASS( worldspawn, CWorld );

void CWorld :: Spawn( void )
{
	g_eoLastSpawn = 0;
	InitBodyQue ();

	CVAR_SET_STRING("sv_gravity", "800");
	CVAR_SET_STRING("room_type", "0");

	//CTentacle::g_fSquirmSound = FALSE;
	//CTentacle::g_fFlySound = FALSE;

// player precaches
	W_Precache ();

// sounds used from C physics code
	PRECACHE_SOUND ("common/null.wav");				// clears sound channels
	PRECACHE_SOUND ("common/thump.wav");
	PRECACHE_SOUND ("common/h2ohit1.wav");		// landing splash
	PRECACHE_SOUND ("common/outwater.wav");
	PRECACHE_SOUND ("common/talk.wav");

// setup precaches always needed
	PRECACHE_SOUND ("player/gasp2.wav");		// taking breath
	PRECACHE_SOUND ("player/sprayer.wav");		// spray paint sound for PreAlpha
	PRECACHE_SOUND ("player/pl_jumpland2.wav");			// player landing
	PRECACHE_SOUND ("player/pl_fallpain1.wav");			// player hurt landing
	PRECACHE_SOUND ("player/pl_fallpain2.wav");
	PRECACHE_SOUND ("player/pl_fallpain3.wav");
	PRECACHE_SOUND ("player/gasp1.wav");		// gasping for air

	PRECACHE_SOUND ("player/pl_jump1.wav");		// player jump
	PRECACHE_SOUND ("player/pl_jump2.wav");

	PRECACHE_SOUND ("player/pl_step1.wav");
	PRECACHE_SOUND ("player/pl_step2.wav");
	PRECACHE_SOUND ("player/pl_step3.wav");
	PRECACHE_SOUND ("player/pl_step4.wav");

	PRECACHE_SOUND ("hgrunt/gr_step1.wav");
	PRECACHE_SOUND ("hgrunt/gr_step2.wav");
	PRECACHE_SOUND ("hgrunt/gr_step3.wav");
	PRECACHE_SOUND ("hgrunt/gr_step4.wav");

	PRECACHE_SOUND ("player/inh2o.wav");

// player gib sounds
	PRECACHE_SOUND ("common/bodysplat.wav");        // player gib sound
	PRECACHE_SOUND ("player/tornoff2.wav");         // gib sound

// player pain sounds

	PRECACHE_SOUND ("player/pl_pain2.wav");
	PRECACHE_SOUND ("player/pl_pain4.wav");
	PRECACHE_SOUND ("player/pl_pain5.wav");
	PRECACHE_SOUND ("player/pl_pain6.wav");
	PRECACHE_SOUND ("player/pl_pain7.wav");

	PRECACHE_SOUND ("common/water1.wav");
	PRECACHE_SOUND ("common/water2.wav");

	PRECACHE_MODEL ("models/doctor.mdl");
	PRECACHE_MODEL ("models/gib_b_bone.mdl");
	PRECACHE_MODEL ("models/gib_b_gib.mdl");
	PRECACHE_MODEL ("models/gib_legbone.mdl");
	PRECACHE_MODEL ("models/gib_skull.mdl");
	PRECACHE_MODEL ("models/gib_lung.mdl");


//
// Setup light animation tables. 'a' is total darkness, 'z' is maxbright.
//
	// 0 normal
	LIGHT_STYLE(0, "m");
	
	// 1 FLICKER (first variety)
	LIGHT_STYLE(1, "mmnmmommommnonmmonqnmmo");
	
	// 2 SLOW STRONG PULSE
	LIGHT_STYLE(2, "abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
	
	// 3 CANDLE (first variety)
	LIGHT_STYLE(3, "mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
	
	// 4 FAST STROBE
	LIGHT_STYLE(4, "mamamamamama");
	
	// 5 GENTLE PULSE 1
	LIGHT_STYLE(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
	
	// 6 FLICKER (second variety)
	LIGHT_STYLE(6, "nmonqnmomnmomomno");
	
	// 7 CANDLE (second variety)
	LIGHT_STYLE(7, "mmmaaaabcdefgmmmmaaaammmaamm");
	
	// 8 CANDLE (third variety)
	LIGHT_STYLE(8, "mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
	
	// 9 SLOW STROBE (fourth variety)
	LIGHT_STYLE(9, "aaaaaaaazzzzzzzz");
	
	// 10 FLUORESCENT FLICKER
	LIGHT_STYLE(10, "mmamammmmammamamaaamammma");

	// 11 SLOW PULSE NOT FADE TO BLACK
	LIGHT_STYLE(11, "abcdefghijklmnopqrrqponmlkjihgfedcba");
	
	// 12 UNDERWATER LIGHT MUTATION
	// this light only distorts the lightmap - no contribution
	// is made to the brightness of affected surfaces
	LIGHT_STYLE(12, "mmnnmmnnnmmnn");
	
	// styles 32-62 are assigned by the light program for switchable lights

	// 63 testing
	LIGHT_STYLE(63, "a");

	for ( int i = 0; i < ARRAYSIZE(gDecals); i++ )
		DECAL_INDEX( i, gDecals[i] );
}


//
// Just to ignore the "wad" field.
//
void CWorld :: KeyValue( KeyValueData *pkvd )
{

}
