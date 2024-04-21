/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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
#ifndef EIFACE_H
#define EIFACE_H
//
// Defines entity interface between engine and DLLs.
// This header file included by engine files and DLL files.
//
// Before including this header, DLLs must:
//		include progdefs.h
// This is conveniently done for them in extdll.h
//


#define DLLEXPORT __stdcall

typedef enum
	{
	at_notice,
	at_console,		// same as at_notice, but forces a ConPrintf, not a message box
	at_aiconsole,	// same as at_console, but only shown if developer level is 2!
	at_warning,
	at_error,
	at_logged		// Server print to console ( only in multiplayer games ).
	} ALERT_TYPE;

// Engine hands this to DLLs for functionality callbacks
typedef struct enginefuncs_s
{
	int			(*pfnPrecacheModel)			(char* s);
	int			(*pfnPrecacheSound)			(char* s);
	void		(*pfnSetModel)				(edict_t *e, const char *m);
	void		(*_UNKNOWN_1)				(void);
	void		(*pfnSetSize)				(edict_t *e, const float *rgflMin, const float *rgflMax);
	void		(*pfnChangeLevel)			(void);
	void		(*pfnGetSpawnParms)			(edict_t *ent);
	void		(*pfnSaveSpawnParms)		(edict_t *ent);
	void		(*pfnVecToYaw)				(void);
	void		(*pfnVecToAngles)			(void);
	void		(*_UNKNOWN_2)				(void);
	void		(*pfnMoveToOrigin)			(void);
	void		(*pfnChangeYaw)				(void);
	void		(*pfnChangePitch)			(void);
	edict_t*	(*pfnFindEntityByString)	(edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue);
	void		(*pfnGetEntityIllum)		(void);
	void		(*pfnFindEntityInSphere)	(void);
	void		(*pfnFindClientInPVS)		(void);
	void		(*pfnMakeVectors)			(void);
	edict_t*	(*pfnCreateEntity)			(void);
	void		(*pfnRemoveEntity)			(void);
	void		(*pfnMakeStatic)			(void);
	void		(*pfnEntIsOnFloor)			(void);
	void		(*pfnDropToFloor)			(void);
	void		(*pfnWalkMove)				(void);
	void		(*pfnSetOrigin)				(edict_t *e, const float *rgflOrigin);
	void		(*pfnEmitSound)				(edict_t *e, int channel, const char *sample, float volume, float attenuation);
	void		(*pfnEmitAmbientSound)		(float *pos, const char *samp, float vol, float attenuation);
	void		(*pfnTraceLine)				(void);
	void		(*_UNKNOWN_3)				(void);
	void		(*pfnGetAimVector)			(void);
	void		(*pfnServerCommand)			(char *str);
	void		(*pfnClientCommand)			(void);
	void		(*pfnParticleEffect)		(void);
	void		(*pfnLightStyle)			(int style, char* val);
	void		(*pfnDecalIndex)			(int index, const char* name);
	void		(*pfnPointContents)			(void);
	void		(*pfnWriteByte)				(void);
	void		(*pfnWriteChar)				(void);
	void		(*pfnWriteShort)			(void);
	void		(*pfnWriteLong)				(void);
	void		(*pfnWriteAngle)			(void);
	void		(*pfnWriteCoord)			(void);
	void		(*pfnWriteString)			(void);
	void		(*pfnWriteEntity)			(void);
	float		(*pfnCVarGetFloat)			(const char *szVarName);
	const char*	(*pfnCVarGetString)			(const char *szVarName);
	void		(*pfnCVarSetFloat)			(const char *szVarName, float flValue);
	void		(*pfnCVarSetString)			(const char *szVarName, const char *szValue);
	void		(*pfnAlertMessage)			(ALERT_TYPE atype, char *szFmt, ...);
	void		(*pfnEngineFprintf)			(void);
	void*		(*pfnPvAllocEntPrivateData)	(edict_t *pEdict, long cb);
	void*		(*pfnPvEntPrivateData)		(edict_t *pEdict);
	void		(*_UNKNWON_9)				(void);
	void		(*_UNKNWON_10)				(void);
	void		(*_UNKNWON_11)				(void);
	const char*	(*pfnSzFromIndex)			(int iString);
	int			(*pfnAllocString)			(const char *szValue);
	entvars_t*	(*pfnGetVarsOfEnt)			(edict_t *pEdict);
	edict_t*	(*pfnPEntityOfEntOffset)	(int iEntOffset);
	int			(*pfnEntOffsetOfPEntity)	(const edict_t *pEdict);
	void		(*_UNKNOWN12)				(void);
	void		(*_UNKNOWN13)				(void);
	void		(*_UNKNOWN14)				(void);
} enginefuncs_t;

// Passed to pfnKeyValue
typedef struct KeyValueData_s
{
	char	*szClassName;	// in: entity classname)
	char	*szKeyName;		// in: name of key)
	char	*szValue;		// in: value of key)
	long	fHandled;		// out: DLL sets to true if key-value pair was understood
} KeyValueData;

#define ARRAYSIZE(p)		(sizeof(p)/sizeof(p[0]))

#endif EIFACE_H
;