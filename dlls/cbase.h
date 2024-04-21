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

// C functions for external declarations that call the appropriate C++ methods

extern void DispatchSpawn( entvars_t *pev );
extern void DispatchKeyValue( entvars_t *pevKeyvalue, KeyValueData *pkvd );
extern void DispatchTouch( entvars_t *pevTouched, entvars_t *pevOther );
extern void DispatchUse( entvars_t *pevUsed, entvars_t *pevOther );
extern void DispatchThink( entvars_t *pev );
extern void DispatchBlocked( entvars_t *pevBlocked, entvars_t *pevOther );
extern void DispatchSave( entvars_t *pev, void *pSaveData );
extern void DispatchRestore( entvars_t *pev, void *pSaveData );


//
// Base Entity. All entity types derive from this
//
class CBaseEntity
{
public:
	entvars_t *pev;		// Don't need to save/restore this pointer, the engine resets it
	globalvars_t *pgv;

	virtual void	Spawn( void ) { return; }
	virtual void	KeyValue( KeyValueData *pkvd ) { pkvd->fHandled = FALSE; }
	virtual void	Unknown() { return; }
	virtual int		Save( void *pSaveData );
	virtual void	Restore( void *pSaveData );

	// fundamental callbacks
	void (CBaseEntity ::*m_pfnThink)( void );
	void (CBaseEntity ::*m_pfnTouch)( entvars_t *pevOther );
	void (CBaseEntity ::*m_pfnUse)( entvars_t *pevOther );
	void (CBaseEntity ::*m_pfnBlocked)( entvars_t *pevOther );

	virtual void Think( void ) { if (m_pfnThink) (this->*m_pfnThink)(); };
	virtual void Touch( entvars_t *pevOther ) { if (m_pfnTouch) (this->*m_pfnTouch)( pevOther ); };
	virtual void Use( entvars_t *pevOther ) { if (m_pfnUse) (this->*m_pfnUse)( pevOther ); };
	virtual void Blocked( entvars_t *pevOther ) { if (m_pfnBlocked) (this->*m_pfnBlocked)( pevOther ); };

	// allow engine to allocate instance data
    void *operator new( size_t stAllocateBlock, entvars_t *pev )
	{
		return (void *)ALLOC_PRIVATE(ENT(pev), stAllocateBlock);
	};

	// common member functions
	void SUB_DoNothing( void );
};



// Ugly technique to override base member functions
// Normally it's illegal to cast a pointer to a member function of a derived class to a pointer to a 
// member function of a base class.  static_cast is a sleezy way around that problem.

#define SetThink( a ) m_pfnThink = static_cast <void (CBaseEntity::*)(void)> (a);
#define SetTouch( a ) m_pfnTouch = static_cast <void (CBaseEntity::*)(entvars_t*)> (a);
#define SetUse( a ) m_pfnUse = static_cast <void (CBaseEntity::*)(entvars_t*)> (a);
#define SetBlocked( a ) m_pfnBlocked = static_cast <void (CBaseEntity::*)(entvars_t*)> (a);

//
// Converts a entvars_t * to a class pointer
// It will allocate the class and entity if necessary
//
template <class T> T * GetClassPtr( T *a )
{
	entvars_t *pev = (entvars_t *)a;

	// allocate entity if necessary
	if (pev == NULL)
		pev = VARS(CREATE_ENTITY());

	// get the private data
	a = (T *)GET_PRIVATE(ENT(pev));

	if (a == NULL) 
	{
		// allocate private data 
		a = new(pev) T;
		a->pev = pev;
		a->pgv = pev->pSystemGlobals;
	}
	return a;
}