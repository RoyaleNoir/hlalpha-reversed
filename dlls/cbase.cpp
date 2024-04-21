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
#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"

void DispatchSpawn( entvars_t *pev )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pev));

	if ( pEntity )
		pEntity->Spawn();
}


void DispatchKeyValue( entvars_t *pevKeyvalue, KeyValueData *pkvd )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pevKeyvalue));

	if ( pEntity )
		pEntity->KeyValue( pkvd );

	if ( !pkvd || pkvd->fHandled )
		return;

	if ( !stricmp( "transitionid", pkvd->szKeyName ) )
	{
	}
}


void DispatchTouch( entvars_t *pevTouched, entvars_t *pevOther )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pevTouched));

	if ( pEntity )
		pEntity->Touch( pevOther );
}


void DispatchUse( entvars_t *pevUsed, entvars_t *pevOther )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pevUsed));

	if ( pEntity )
		pEntity->Use( pevOther );
}


void DispatchThink( entvars_t *pev )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pev));

	if ( pEntity )
		pEntity->Think();
}


void DispatchBlocked( entvars_t *pevBlocked, entvars_t *pevOther )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pevBlocked));

	if ( pEntity )
		pEntity->Blocked( pevOther );
}


void DispatchSave( entvars_t *pev, void *pSaveData )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pev));

	if ( pEntity )
		pEntity->Save( pSaveData );
}


void DispatchRestore( entvars_t *pev, void *pSaveData )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(ENT(pev));

	if ( pEntity )
		pEntity->Restore( pSaveData );
}


int CBaseEntity::Save( void *pSaveData )
{
	ALERT( at_console, "Saving %s\n", STRING(pev->classname) );
	return 0;
}


void CBaseEntity::Restore( void *pSaveData )
{
}