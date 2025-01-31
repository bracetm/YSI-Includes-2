/*
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the YSI framework.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2011
	the Initial Developer. All Rights Reserved.

Contributors:
	Y_Less
	koolk
	JoeBullet/Google63
	g_aSlice/Slice
	Misiur
	samphunter
	tianmeta
	maddinat0r
	spacemud
	Crayder
	Dayvison
	Ahmad45123
	Zeex
	irinel1996
	Yiin-
	Chaprnks
	Konstantinos
	Masterchen09
	Southclaws
	PatchwerkQWER
	m0k1
	paulommu
	udan111
	Cheaterman

Thanks:
	JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
	ZeeX - Very productive conversations.
	koolk - IsPlayerinAreaEx code.
	TheAlpha - Danish translation.
	breadfish - German translation.
	Fireburn - Dutch translation.
	yom - French translation.
	50p - Polish translation.
	Zamaroht - Spanish translation.
	Los - Portuguese translation.
	Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes for
		me to strive to better.
	Pixels^ - Running XScripters where the idea was born.
	Matite - Pestering me to release it and using it.

Very special thanks to:
	Thiadmer - PAWN, whose limits continue to amaze me!
	Kye/Kalcor - SA:MP.
	SA:MP Team past, present and future - SA:MP.

Optional plugins:
	Gamer_Z - GPS.
	Incognito - Streamer.
	Me - sscanf2, fixes2, Whirlpool.
*/

#if defined _INC_y_rconfix
	#endinput
#endif
#define _INC_y_rconfix

forward R__(const data[], length);

#if !_YSI_SAFE_STARTUP
	#if defined YSI_FIX_CALLBACKS
		forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);
	#endif

	#endinput
#endif

// Duplicated from amx_assembly.
#define __asm(%0,%1,%2,%3) (((0x%3) << 24) | ((0x%2) << 16) | (0x%1 << 8) | (0x%0))

static
	// This is an AMX encoded in to an array.  See the end of this file for the
	// source (and feel free to recompile the source to verify that it is in
	// fact the same thing).
	YSI_g_sByteCode[] = {
		__asm(24,05,00,00), __asm(E0,F1,08,08), __asm(10,00,08,00), __asm(14,01,00,00),
		__asm(AC,04,00,00), __asm(24,05,00,00), __asm(24,05,00,08), __asm(FF,FF,FF,FF),
		__asm(38,00,00,00), __asm(70,00,00,00), __asm(98,00,00,00), __asm(98,00,00,00),
		__asm(98,00,00,00), __asm(98,00,00,00), __asm(08,00,00,00), __asm(9A,00,00,00),
		__asm(F4,01,00,00), __asm(9E,00,00,00), __asm(34,00,00,00), __asm(A2,00,00,00),
		__asm(30,03,00,00), __asm(A6,00,00,00), __asm(50,02,00,00), __asm(BC,00,00,00),
		__asm(A4,02,00,00), __asm(CF,00,00,00), __asm(94,00,00,00), __asm(DD,00,00,00),
		__asm(00,00,00,00), __asm(E1,00,00,00), __asm(00,00,00,00), __asm(E5,00,00,00),
		__asm(00,00,00,00), __asm(F1,00,00,00), __asm(00,00,00,00), __asm(F8,00,00,00),
		__asm(00,00,00,00), __asm(0B,01,00,00), __asm(15,00,43,5F), __asm(5F,00,47,5F),
		__asm(5F,00,4E,5F), __asm(5F,00,4F,6E), __asm(43,6C,69,65), __asm(6E,74,43,68),
		__asm(65,63,6B,52), __asm(65,73,70,6F), __asm(6E,73,65,00), __asm(4F,6E,46,69),
		__asm(6C,74,65,72), __asm(53,63,72,69), __asm(70,74,49,6E), __asm(69,74,00,4F),
		__asm(6E,52,63,6F), __asm(6E,43,6F,6D), __asm(6D,61,6E,64), __asm(00,53,5F,5F),
		__asm(00,59,53,49), __asm(00,73,65,74), __asm(70,72,6F,70), __asm(65,72,74,79),
		__asm(00,6D,65,6D), __asm(63,70,79,00), __asm(43,61,6C,6C), __asm(52,65,6D,6F),
		__asm(74,65,46,75), __asm(6E,63,74,69), __asm(6F,6E,00,73), __asm(74,72,63,6D),
		__asm(70,00,00,00), __asm(78,00,00,00), __asm(00,00,00,00), __asm(2E,00,00,00),
		__asm(1F,00,00,00), __asm(02,00,00,00), __asm(0F,00,00,00), __asm(70,00,00,00),
		__asm(0B,00,00,00), __asm(00,00,00,02), __asm(0F,00,00,00), __asm(6C,00,00,00),
		__asm(59,00,00,00), __asm(30,00,00,00), __asm(2A,00,00,00), __asm(7B,00,00,00),
		__asm(00,00,00,00), __asm(27,00,00,00), __asm(00,00,00,00), __asm(24,00,00,00),
		__asm(27,00,00,00), __asm(40,00,00,00), __asm(27,00,00,00), __asm(1B,00,00,00),
		__asm(27,00,00,00), __asm(10,00,00,00), __asm(7B,00,00,00), __asm(01,00,00,00),
		__asm(2C,00,00,00), __asm(14,00,00,00), __asm(2B,00,00,00), __asm(1F,00,00,00),
		__asm(04,00,00,00), __asm(4E,00,00,00), __asm(20,00,00,00), __asm(04,00,00,00),
		__asm(78,00,00,00), __asm(00,00,00,00), __asm(2E,00,00,00), __asm(01,00,00,00),
		__asm(6C,00,00,00), __asm(04,00,00,00), __asm(10,00,00,00), __asm(3E,00,00,00),
		__asm(B4,01,00,00), __asm(03,00,00,00), __asm(10,00,00,00), __asm(02,00,00,00),
		__asm(6C,00,00,00), __asm(50,00,00,00), __asm(0C,00,00,00), __asm(01,00,00,00),
		__asm(4F,00,00,00), __asm(0F,00,00,00), __asm(6C,00,00,00), __asm(27,00,00,00),
		__asm(00,00,00,00), __asm(28,00,00,00), __asm(70,00,00,00), __asm(27,00,00,00),
		__asm(40,00,00,00), __asm(27,00,00,00), __asm(1B,00,00,00), __asm(27,00,00,00),
		__asm(10,00,00,00), __asm(7B,00,00,00), __asm(01,00,00,00), __asm(2C,00,00,00),
		__asm(14,00,00,00), __asm(27,00,00,00), __asm(00,00,00,00), __asm(01,00,00,00),
		__asm(70,00,00,00), __asm(57,00,00,00), __asm(04,00,00,00), __asm(11,00,00,00),
		__asm(FC,FF,FF,FF), __asm(04,00,00,00), __asm(10,00,00,00), __asm(45,00,00,00),
		__asm(02,00,00,00), __asm(4E,00,00,00), __asm(20,00,00,00), __asm(02,00,00,00),
		__asm(04,00,00,00), __asm(10,00,00,00), __asm(14,00,00,00), __asm(70,00,00,00),
		__asm(0F,00,00,00), __asm(70,00,00,00), __asm(27,00,00,00), __asm(00,00,00,02),
		__asm(29,00,00,00), __asm(10,00,00,00), __asm(27,00,00,00), __asm(00,00,00,00),
		__asm(29,00,00,00), __asm(0C,00,00,00), __asm(29,00,00,00), __asm(FC,FF,FF,FF),
		__asm(27,00,00,00), __asm(14,00,00,00), __asm(7B,00,00,00), __asm(02,00,00,00),
		__asm(2C,00,00,00), __asm(18,00,00,00), __asm(2C,00,00,00), __asm(04,00,00,00),
		__asm(33,00,00,00), __asm(EC,01,00,00), __asm(27,00,00,00), __asm(00,00,00,00),
		__asm(27,00,00,00), __asm(00,00,00,00), __asm(27,00,00,00), __asm(40,00,00,00),
		__asm(27,00,00,00), __asm(1B,00,00,00), __asm(27,00,00,00), __asm(10,00,00,00),
		__asm(7B,00,00,00), __asm(01,00,00,00), __asm(2C,00,00,00), __asm(14,00,00,00),
		__asm(59,00,00,00), __asm(30,00,00,00), __asm(2E,00,00,00), __asm(01,00,00,00),
		__asm(70,00,00,00), __asm(20,00,00,00), __asm(02,00,00,00), __asm(03,00,00,00),
		__asm(0C,00,00,00), __asm(24,00,00,00), __asm(57,00,00,00), __asm(04,00,00,00),
		__asm(24,00,00,00), __asm(27,00,00,00), __asm(44,00,00,00), __asm(27,00,00,00),
		__asm(40,00,00,00), __asm(27,00,00,00), __asm(10,00,00,00), __asm(7B,00,00,00),
		__asm(03,00,00,00), __asm(2C,00,00,00), __asm(14,00,00,00), __asm(59,00,00,00),
		__asm(30,00,00,00), __asm(2E,00,00,00), __asm(27,00,00,00), __asm(00,00,00,00),
		__asm(27,00,00,00), __asm(00,00,00,00), __asm(27,00,00,00), __asm(40,00,00,00),
		__asm(27,00,00,00), __asm(1B,00,00,00), __asm(27,00,00,00), __asm(10,00,00,00),
		__asm(7B,00,00,00), __asm(01,00,00,00), __asm(2C,00,00,00), __asm(14,00,00,00),
		__asm(1F,00,00,00), __asm(02,00,00,00), __asm(0F,00,00,00), __asm(70,00,00,00),
		__asm(59,00,00,00), __asm(30,00,00,00), __asm(2E,00,00,00), __asm(27,00,00,00),
		__asm(FF,FF,FF,7F), __asm(27,00,00,00), __asm(01,00,00,00), __asm(27,00,00,00),
		__asm(50,00,00,00), __asm(29,00,00,00), __asm(0C,00,00,00), __asm(27,00,00,00),
		__asm(10,00,00,00), __asm(7B,00,00,00), __asm(04,00,00,00), __asm(2C,00,00,00),
		__asm(14,00,00,00), __asm(36,00,00,00), __asm(28,03,00,00), __asm(27,00,00,00),
		__asm(00,00,00,00), __asm(27,00,00,00), __asm(1B,00,00,00), __asm(27,00,00,00),
		__asm(50,00,00,00), __asm(27,00,00,00), __asm(1B,00,00,00), __asm(27,00,00,00),
		__asm(10,00,00,00), __asm(7B,00,00,00), __asm(01,00,00,00), __asm(2C,00,00,00),
		__asm(14,00,00,00), __asm(54,00,00,00), __asm(30,00,00,00), __asm(59,00,00,00),
		__asm(30,00,00,00), __asm(2E,00,00,00), __asm(01,00,00,00), __asm(74,00,00,00),
		__asm(35,00,00,00), __asm(4C,03,00,00), __asm(59,00,00,00), __asm(30,00,00,00),
		__asm(85,00,00,00), __asm(18,00,00,00), __asm(85,00,00,00), __asm(14,00,00,00),
		__asm(85,00,00,00), __asm(10,00,00,00), __asm(85,00,00,00), __asm(0C,00,00,00),
		__asm(27,00,00,00), __asm(48,00,00,00), __asm(27,00,00,00), __asm(50,00,00,00),
		__asm(27,00,00,00), __asm(18,00,00,00), __asm(7B,00,00,00), __asm(03,00,00,00),
		__asm(2C,00,00,00), __asm(1C,00,00,00), __asm(30,00,00,00), __asm(59,53,49,20),
		__asm(41,75,78,69), __asm(6C,69,61,72), __asm(79,20,52,75), __asm(6E,74,69,6D),
		__asm(65,2C,20,28), __asm(63,29,20,32), __asm(30,32,33,20), __asm(41,6C,65,78),
		__asm(20,22,59,5F), __asm(4C,65,73,73), __asm(22,20,43,6F), __asm(6C,65,2E,00),
		__asm(00,00,00,00), __asm(00,00,00,00), __asm(00,00,00,00), __asm(00,5F,5F,52),
		__asm(00,00,69,61), __asm(69,69,69,69), __asm(00,00,00,00), __asm(45,58,49,46),
		__asm(6E,4F,5F,53), __asm(65,69,6C,43), __asm(68,43,74,6E), __asm(52,6B,63,65),
		__asm(6F,70,73,65), __asm(00,65,73,6E), __asm(00,00,00,02), __asm(00,00,00,00),
		__asm(00,00,00,00)
	},
	YSI_g_sLastNative[64] = "-", // Invalid.
	YSI_g_sRequestedData = 0;

static stock bool:YAR_DumpFile()
{
	new
		File:f = fopen("ysi_aux_runtime.amx", io_write);
	if (f)
	{
		fblockwrite(f, YSI_g_sByteCode);
		fclose(f);
		return true;
	}
	return false;
}

static stock YAR_WriteNative(const name[])
{
	// Data should always be aligned, I think.
	new
		pack[64 char],
		i = -1,
		// The data array we write the new name in to.  This is found strictly
		// at the start of DAT, so is at `*0x10`.
		o = __32(YSI_g_sByteCode[16 / cellbytes]);
	o = o / cellbytes - 1;
	strpack(pack, name);
	do
	{
		++i;
		++o;
		YSI_g_sByteCode[o] = swapchars(pack[i]);
	}
	while (YSI_g_sByteCode[o] > (cellmax >>> (charbits - 1)));
}

stock bool:Server_HasNative(const name[])
{
	if (strcmp(name, YSI_g_sLastNative) == 0)
	{
		// The script is already loaded with this native.  Can just call it.
		return true;
	}
	
	YAR_WriteNative(name);

	if (!YAR_DumpFile())
	{
		return false;
	}
	
	// Reload the FS, and test that it did load.  If it didn't the native we
	// want to use probably doesn't exist.
	deleteproperty(27, "R__");
	if (YSI_g_sLastNative[0] == '-')
	{
		YSI_SendRconCommand__("loadfs ../scriptfiles/ysi_aux_runtime");
	}
	else
	{
		YSI_SendRconCommand__("reloadfs ../scriptfiles/ysi_aux_runtime");
	}
	if (existproperty(27, "R__"))
	{
		// Succeeded, the new native must exist.
		// Cache it.
		YSI_g_sLastNative[0] = '\0',
		strcat(YSI_g_sLastNative, name);
		return true;
	}
	if (YSI_g_sLastNative[0] != '-')
	{
		// Reset to the previous version (known safe).
		YAR_WriteNative(YSI_g_sLastNative);
		if (YAR_DumpFile())
		{
			YSI_SendRconCommand__("loadfs ../scriptfiles/ysi_aux_runtime");
		}
	}
	
	return false;
}

public R__(const data[], length)
{
	if (YSI_g_sRequestedData)
	{
		// Save it.
		YSI_g_sRequestedData = 0;
	}
}

/*-------------------------------------------------------------------------*//**
 * <library>y_rconfix</library>
 * <remarks>
 *   This code is always needed, even if fixes.inc exists, because y_master can
 *   repeatedly load and unload it to use as a buffer filterscript.  Basically,
 *   because this FS is always loaded it ensures that 16 other filterscripts
 *   can't all be loaded at once.  So if 15 are loaded and we need an extra
 *   space to reload one while preserving data we can unload this one, use the
 *   spare space, then load this one back up again.
 * </remarks>
 *//*------------------------------------------------------------------------**/

y_rconfix_Load()
{
	// This is the old version from fixes.inc, just remove it.  Our version will
	// be correctly detected by fixes.inc and thus not replaced.
	YSI_SendRconCommand__("unloadfs ../scriptfiles/callbackfix");
	if (YSI_g_sLastNative[0] == '-')
	{
		// This is the location in the file of the pointer to the native we are
		// `*0x24 + 4`, replacing.  It should be the first native, so could be
		// found at i.e. one cell after the start of the native functions block.
		#if cellbits == 64
			new offset = YSI_g_sByteCode[36 / cellbytes] >>> 32;
		#elseif cellbits == 32
			new offset = YSI_g_sByteCode[36 / cellbytes];
		#else
			#error Unsupported `cellbits`.
		#endif
		// Rewrite the bytecode to include the name of the new native.
		YSI_g_sByteCode[offset / cellbytes + 1] = __32(YSI_g_sByteCode[16 / cellbytes]);
		YSI_g_sByteCode[sizeof (YSI_g_sByteCode) - 1] = __OPEN_MP_VERSION;
		// Not loaded yet.  We don't care if the file already exists because
		// this is the first time we've got here this server run, thus the
		// available natives may have changed since the last time we wrote it.
		Server_HasNative("heapspace");
	}
	else
	{
		YSI_SendRconCommand__("loadfs ../scriptfiles/ysi_aux_runtime");
	}
	if (fexist("ysi_aux_runtime.amx"))
	{
		#if defined YSI_FIX_CALLBACKS
			state OnClientCheckResponse : OnClientCheckResponse_GM;
		#endif
	}
	else
	{
		Debug_Warning("Could not load RconCommand/ClientCheckResponse fix FS.");
		Debug_Info("Ignore this error if the FS already loaded.");
	}
}

/*-------------------------------------------------------------------------*//**
 * <library>y_rconfix</library>
 * <remarks>
 *   Unload the callback fix filterscript.
 * </remarks>
 *//*------------------------------------------------------------------------**/

stock y_rconfix_Unload()
{
	YSI_SendRconCommand__("unloadfs ../scriptfiles/ysi_aux_runtime");
}

#if !defined YSI_FIX_CALLBACKS
	#endinput
#endif

/*-------------------------------------------------------------------------*//**
 * <library>y_rconfix</library>
 * <remarks>
 *   Call the hooked version of <c>OnClientCheckResponse</c>, regardless of how
 *   this version is called.  So either natively or using the fix here.
 * </remarks>
 *//*------------------------------------------------------------------------**/

forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
{
	// Enable, then disable, the call in to the real version (if it exists).
	state OnClientCheckResponse : OnClientCheckResponse_GM;
	new
		ret = FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
	state OnClientCheckResponse : OnClientCheckResponse_FS;
	return ret;
}

/*-------------------------------------------------------------------------*//**
 * <library>y_rconfix</library>
 * <remarks>
 *   Call the hooked version of <c>OnClientCheckResponse</c>, regardless of how
 *   this version is called.  So either natively or using the fix here.  But
 *   use states to only call the fix version in the gamemode, not in
 *   filterscripts, since it works there already.
 * </remarks>
 *//*------------------------------------------------------------------------**/

forward FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata);

public FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata) <OnClientCheckResponse : OnClientCheckResponse_FS>
{
	return 0;
}

public FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata) <>
{
	return 0;
}

/*-------------------------------------------------------------------------*//**
 * <library>y_rconfix</library>
 * <remarks>
 *   Define the states for calling the fix callbacks, or not.
 * </remarks>
 *//*------------------------------------------------------------------------**/

static stock _FIXES_OnClientCheckResponse() <OnClientCheckResponse : OnClientCheckResponse_GM, OnClientCheckResponse : OnClientCheckResponse_FS>
{
	// Define states only.
}

#if defined _ALS_OnClientCheckResponse
	#error _ALS_OnClientCheckResponse defined
#endif
#define _ALS_OnClientCheckResponse
#define OnClientCheckResponse(%0) FIXES_OnClientCheckResponse(%0) <OnClientCheckResponse : OnClientCheckResponse_GM>

#endinput

/*
                                                                                                                 
    88888888888  88  88                                                                     88                       
    88           ""  88    ,d                                                               ""                ,d     
    88               88    88                                                                                 88     
    88aaaaa      88  88  MM88MMM  ,adPPYba,  8b,dPPYba,  ,adPPYba,   ,adPPYba,  8b,dPPYba,  88  8b,dPPYba,  MM88MMM  
    88"""""      88  88    88    a8P_____88  88P'   "Y8  I8[    ""  a8"     ""  88P'   "Y8  88  88P'    "8a   88     
    88           88  88    88    8PP"""""""  88           `"Y8ba,   8b          88          88  88       d8   88     
    88           88  88    88,   "8b,   ,aa  88          aa    ]8I  "8a,   ,aa  88          88  88b,   ,a8"   88,    
    88           88  88    "Y888  `"Ybbd8"'  88          `"YbbdP"'   `"Ybbd8"'  88          88  88`YbbdP"'    "Y888  
                                                                                                88                   
                                                                                                88                   

*/

//#pragma option -a
#define SPACE_IN_MB (128)

// This is the source code of the filterscript embedded in an array avove.  Feel
// free to recompile it yourself and compare the bytes.  I use compiler version
// 3.10.11; settings don't matter since these next few lines override them all
// anyway.

#pragma compress 0
#pragma option -O1
#pragma option -d0
#pragma option -;+
#pragma option -(+
#pragma pack 0

#if !defined __PawnBuild
	#error Requires compiler version 3.10.11.
#endif
#if __PawnBuild != 11
	#error Requires compiler version 3.10.11.
#endif

// A few conveniences.
const
	#if cellbits == 64
		SHIFT = 3,
	#elseif cellbits == 32
		SHIFT = 2,
	#else
		#error Unknown bit width.
	#endif
	cellbytes = cellbits / charbits,
	__hea = 2,
	__stk = 4;

// Allocate a lot of space for temporary storage.
#pragma dynamic SPACE_IN_MB * 1024 * 1024 / cellbytes

#define open.mp __OPEN_MP_VERSION

forward OnFilterScriptInit();
forward OnRconCommand(const cmd[]);
forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

forward N__(); // Native
forward C__(); // Clear
forward S__(const data[], length); // Set
forward G__(address); // Get

// PUT NO NATIVES ABOVE HERE!
// This is just a placeholder.  We rewrite the name when generating the FS.
native YSI();

// Custom versions of natives, some of which allow us to pass raw addresses.
native bool:SetProperty(id, const name[], value, const string[]) = setproperty;
native StrCmp(const string1[], const string2[], bool:ignorecase, length) = strcmp;
native bool:MemCpy(dest, const src[], index, bytes, max) = memcpy;

native CallRemoteFunction(const function[], const specifier[], ...) = CallRemoteFunction;

// Reserve space in the header for a function name up to 63 characters.
new const
	// This is at DAT address 0, which is brilliant for locating it.  It is also
	// dead space before the native name is written to it, so put something in.
	NATIVE[64 char] = !" ISYixuArailuR ymitn( ,e2 )c 320xelA_Y\" sseLoC \"\0.el",
	RESULT[] = !"R__",
	AI[] = !"ai",
	IIII[] = !"iiii",
	// Use the same string for everything, so we only need one.  And pack it.
	FIXES_RESPONSE[] = !"FIXES_OnClientCheckResponse";

new
	gAvailable = SPACE_IN_MB * 1024 * 1024 / cellbytes,
	// This might be a constant...
	gAllocated = 0;

new const
	// This is written by our loader, NOT the server.  We do this just to save
	// space in the header from not needing to make this `public`.  To
	// facilitate this, it is the very last thing in the file.
	open.mp = 0;

public C__()
{
	#emit LCTRL        __hea
	#emit STOR.pri     gAllocated
	gAvailable = SPACE_IN_MB * 1024 * 1024 / cellbytes;
}

#pragma naked
public N__()
{
	const
		args = 4 * cellbytes,
		clear = 5 * cellbytes;
	
	// Remove the return address.
	#emit POP.pri
	
	// The correct parameters are already on the stack.  Reuse them.
	#emit SYSREQ.C     YSI

	// Save the return value.
	#emit PUSH.C       NATIVE
	#emit PUSH.pri
	#emit PUSH.C       RESULT
	#emit PUSH.C       27
	#emit PUSH.C       args
	#emit SYSREQ.C     SetProperty

	// Clear the stack.  Getting the stack earlier isn't more efficient.
	#emit STACK        clear
	#emit POP.alt
	#emit LCTRL        __stk
	#emit ADD
	#emit SCTRL        __stk
	// This is a public entry point, so the return address is always `0`.  Not that
	// it matters, because we can just call `HALT` ourselves.  So we make it naked.
	#emit HALT         0
}

public S__(const data[], length)
{
	// Strictly `>` to ensure we have space for the hidden length.
	if (gAvailable > length)
	{
		gAvailable = gAvailable - length - 1;
		SetProperty(27, RESULT, gAllocated, NATIVE);

		new dest = 0;
		// First, re-allocate the heap.
		#emit LOAD.pri     gAllocated
		#emit ADD.C        cellbytes
		#emit STOR.S.pri   dest
		#emit LOAD.S.alt   length
		#emit SHL.C.alt    SHIFT
		#emit ADD
		#emit SCTRL        __hea

		// Save the length to the slot.
		#emit LOAD.S.alt   length
		#emit SREF.alt     gAllocated
		#emit STOR.pri     gAllocated

		// gAllocated is the return address.  The first cell is the length.
		MemCpy(dest, data, 0, length, SPACE_IN_MB * 1024 * 1024 / cellbytes);
	}
	else
	{
		// We don't need the last parameter, so it doesn't matter what it is.
		// Save some space by re-using something irrelevant.
		SetProperty(27, RESULT, 0, NATIVE);
	}
}

public G__(address)
{
	const
		args = 4 * cellbytes,
		clear = 5 * cellbytes;
	// Re-allocate the heap.
	#emit LOAD.pri     gAllocated
	#emit SCTRL        __hea

	// Push raw addresses to `CallRemoteFunction`.
	#emit LOAD.S.pri   address
	#emit PUSH.pri
	#emit ADD.C        cellbytes
	#emit PUSH.pri
	#emit PUSH.C       AI
	#emit PUSH.C       RESULT
	#emit PUSH.C       args
	#emit SYSREQ.C     CallRemoteFunction
	#emit STACK        clear
}

public OnFilterScriptInit()
{
	// Force the `NATIVE` data to be in the output.
	SetProperty(27, RESULT, 0, NATIVE);
	#emit LCTRL        __hea
	#emit STOR.pri     gAllocated
}

// This callback just needs to exist in one filterscript.
public OnRconCommand(const cmd[])
{
	// The smallest I could make the assembly without `#emit`.
	if (StrCmp(cmd, FIXES_RESPONSE, true, cellmax) == 0)
	{
		// We used to use padding, but now the FS isn't packed (unfortunatley).
		return !SetProperty(27, FIXES_RESPONSE, 27, NATIVE);
	}
	return 0;
}

// This callback needs to invoke a different callback in GMs.
public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
{
	if (open.mp)
	{
		return 0;
	}
	// Invoke the global callback.
	return CallRemoteFunction(FIXES_RESPONSE, IIII, playerid, actionid, memaddr, retndata);
}

