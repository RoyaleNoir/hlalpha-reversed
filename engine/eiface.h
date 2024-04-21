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

// Returned by TraceLine
typedef struct
	{
	int		fAllSolid;			// if true, plane is not valid
	int		fStartSolid;		// if true, the initial point was in a solid area
	int		fInOpen;
	int		fInWater;
	float	flFraction;			// time completed, 1.0 = didn't hit anything
	vec3_t	vecEndPos;			// final position
	float	flPlaneDist;
	vec3_t	vecPlaneNormal;		// surface normal at impact
	edict_t	*pHit;				// entity the surface is on
	int		iHitgroup;			// 0 == generic, non zero is specific body part
	} TraceResult;

// Engine hands this to DLLs for functionality callbacks
typedef struct enginefuncs_s
{
	int			(*pfnPrecacheModel)			(char* s);
	int			(*pfnPrecacheSound)			(char* s);
	void		(*pfnSetModel)				(edict_t *e, const char *m);
	void		(*pfnModelIndex)			(const char *m);
	void		(*pfnSetSize)				(edict_t *e, const float *rgflMin, const float *rgflMax);
	void		(*pfnChangeLevel)			(char* s1, char* s2);
	void		(*pfnGetSpawnParms)			(edict_t *ent);
	void		(*pfnSaveSpawnParms)		(edict_t *ent);
	float		(*pfnVecToYaw)				(const float *rgflVector);
	void		(*pfnVecToAngles)			(const float *rgflVectorIn, float *rgflVectorOut);
	void		(*_UNKNOWN_1)				(void);
	void		(*pfnMoveToOrigin)			(edict_t *ent, const float *pflGoal, float dist, int iMoveType);
	void		(*pfnChangeYaw)				(edict_t *ent);
	void		(*pfnChangePitch)			(edict_t *ent);
	edict_t*	(*pfnFindEntityByString)	(edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue);
	void		(*pfnGetEntityIllum)		(edict_t *pEnt);
	void		(*pfnFindEntityInSphere)	(const float *org, float rad);
	void		(*pfnFindClientInPVS)		(void);
	void		(*pfnMakeVectors)			(const float *rgflVector);
	edict_t*	(*pfnCreateEntity)			(void);
	void		(*pfnRemoveEntity)			(edict_t* e);
	void		(*pfnMakeStatic)			(edict_t *ent);
	int			(*pfnEntIsOnFloor)			(edict_t *e);
	int			(*pfnDropToFloor)			(edict_t* e);
	float		(*pfnWalkMove)				(edict_t *ent, float yaw, float dist);
	void		(*pfnSetOrigin)				(edict_t *e, const float *rgflOrigin);
	void		(*pfnEmitSound)				(edict_t *e, int channel, const char *sample, float volume, float attenuation);
	void		(*pfnEmitAmbientSound)		(float *pos, const char *samp, float vol, float attenuation);
	void		(*pfnTraceLine)				(const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr);
	void		(*_UNKNOWN_2)				(void);
	void		(*pfnGetAimVector)			(edict_t* ent, float speed, float *rgflReturn);
	void		(*pfnServerCommand)			(char *str);
	void		(*pfnClientCommand)			(edict_t* pEdict, char* szFmt, ...);
	void		(*pfnParticleEffect)		(const float *org, const float *dir, float color, float count);
	void		(*pfnLightStyle)			(int style, char* val);
	void		(*pfnDecalIndex)			(int index, const char* name);
	void		(*pfnPointContents)			(const float *rgflVector);
	void		(*pfnWriteByte)				(int msg_dest, int iValue);
	void		(*pfnWriteChar)				(int msg_dest, int iValue);
	void		(*pfnWriteShort)			(int msg_dest, int iValue);
	void		(*pfnWriteLong)				(int msg_dest, int iValue);
	void		(*pfnWriteAngle)			(int msg_dest, float flValue);
	void		(*pfnWriteCoord)			(int msg_dest, float flValue);
	void		(*pfnWriteString)			(int msg_dest, const char *sz);
	void		(*pfnWriteEntity)			(int msg_dest, int iValue);
	float		(*pfnCVarGetFloat)			(const char *szVarName);
	const char*	(*pfnCVarGetString)			(const char *szVarName);
	void		(*pfnCVarSetFloat)			(const char *szVarName, float flValue);
	void		(*pfnCVarSetString)			(const char *szVarName, const char *szValue);
	void		(*pfnAlertMessage)			(ALERT_TYPE atype, char *szFmt, ...);
	void		(*pfnEngineFprintf)			(void *pfile, char *szFmt, ...);
	void*		(*pfnPvAllocEntPrivateData)	(edict_t *pEdict, long cb);
	void*		(*pfnPvEntPrivateData)		(edict_t *pEdict);
	void		(*pfnFreeEntPrivateData)	(edict_t *pEdict);
	void*		(*pfnGetDispatchFunction)	(edict_t *pEdict, int iFunc);
	void		(*pfnUNUSED)				(void);
	const char*	(*pfnSzFromIndex)			(int iString);
	int			(*pfnAllocString)			(const char *szValue);
	entvars_t*	(*pfnGetVarsOfEnt)			(edict_t *pEdict);
	edict_t*	(*pfnPEntityOfEntOffset)	(int iEntOffset);
	int			(*pfnEntOffsetOfPEntity)	(const edict_t *pEdict);
	int			(*_UNKNOWN3)				(int iEntOffset);
	edict_t*	(*pfnFindEntityByVars)		(struct entvars_s* pvars);
	void*		(*pfnGetModelPtr)			(edict_t *pEdict);
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