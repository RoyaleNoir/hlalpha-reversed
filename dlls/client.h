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
#ifndef CLIENT_H
#define CLIENT_H

extern void respawn( entvars_t* pev );
extern void DLLEXPORT ClientConnect( globalvars_t *pgv );
extern void DLLEXPORT ClientDisconnect( globalvars_t *pgv );
extern void DLLEXPORT ClientKill( globalvars_t *pgv );
extern void DLLEXPORT PutClientInServer( globalvars_t *pgv );
extern void DLLEXPORT StartFrame( globalvars_t *pgv );
extern void DLLEXPORT PlayerPostThink( globalvars_t *pgv );
extern void DLLEXPORT PlayerPreThink( globalvars_t *pgv );
extern void DLLEXPORT SetNewParms( globalvars_t *pgv );
extern void DLLEXPORT SetChangeParms( globalvars_t *pgv );

#endif		// CLIENT_H