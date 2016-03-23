#define LUA_LIB
#include "lua.h"
#include "lauxlib.h"
#include <stdio.h>
#include <stddef.h>

typedef enum {
	LBYTES_LITTLE_ENDIAN,
	LBYTES_BIG_ENDIAN,
} luabytes_Endianness;

typedef struct {
	unsigned char *bytes;
	size_t n;
	luabytes_Endianness;
} luabytes_Bytes;

static uint32_t change_endianness_u64( uint64_t value ) {
	uint64_t result = 0;
	result |= (value & 0x00000000000000FF) << 56;
	result |= (value & 0x000000000000FF00) << 40;
	result |= (value & 0x0000000000FF0000) << 24;
	result |= (value & 0x00000000FF000000) << 8;
	result |= (value & 0x000000FF00000000) >> 8;
	result |= (value & 0x0000FF0000000000) >> 24;
	result |= (value & 0x00FF000000000000) >> 40;
	result |= (value & 0xFF00000000000000) >> 56;
	return result;
}

static uint32_t change_endianness_u32( uint32_t value ) {
	uint32_t result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return result;
}

static uint16_t change_endianness_u16( uint16_t value ) {
	uint16_t result = 0;
	result |= (value & 0x00FF) << 8;
	result |= (value & 0xFF00) >> 8;
	return result;
}

static int luabytes_new( lua_State *L ) {
}

static int luabytes_move( lua_State *L ) {
}

static int luabytes_blit( lua_State *L ) {
}

static int luabytes_slice( lua_State *L ) {
}

static int luabytes_concat( lua_State *L ) {
}

static int luabytes_reverse( lua_State *L ) {
}

static int luabytes_len( lua_State *L ) {
}

static int luabytes_fill( lua_State *L ) {
}

static int luabytes_tobase64( lua_State *L ) {
}

static int luabytes_frombase64( lua_State *L ) {
}

static int luabytes_getendianness( lua_State *L ) {
}

static int luabytes_setendianness( lua_State *L ) {
}

static int luabytes_set( lua_State *L ) {
}

static int luabytes_u16set( lua_State *L ) {
}

static int luabytes_u32set( lua_State *L ) {
}

static int luabytes_u64set( lua_State *L ) {
}

static int luabytes_s8set( lua_State *L ) {
}

static int luabytes_s16set( lua_State *L ) {
}

static int luabytes_s32set( lua_State *L ) {
}

static int luabytes_s64set( lua_State *L ) {
}

static int luabytes_f32set( lua_State *L ) {
}

static int luabytes_f64set( lua_State *L ) {
}

static int luabytes_get( lua_State *L ) {
}

static int luabytes_u16get( lua_State *L ) {
}

static int luabytes_u32get( lua_State *L ) {
}

static int luabytes_u64get( lua_State *L ) {
}

static int luabytes_s8get( lua_State *L ) {
}

static int luabytes_s16get( lua_State *L ) {
}

static int luabytes_s32get( lua_State *L ) {
}

static int luabytes_s64get( lua_State *L ) {
}

static int luabytes_f32get( lua_State *L ) {
}

static int luabytes_f64get( lua_State *L ) {
}

static const struct luaL_Reg luabytes_lib[] = {
	{"new",luabytes_new},
	{"move",luabytes_move},
	{"blit",luabytes_blit},
	{"fill",luabytes_fill},
	{"reverse",luabytes_reverse},
	{"len",luabytes_len},
	{"getendianness",luabytes_getendianness},
	{"setendianness",luabytes_setendianness},
	{"tobase64",luabytes_tobase64},
	{"frombase64",luabytes_frombase64},

	{"slice",luabytes_slice},
	{"concat",luabytes_concat},

	{"setbool",luabytes_setbool},
	{"getbool",luabytes_getbool},

	{"get",luabytes_get},
	{"u16get",luabytes_u16get},
	{"u32get",luabytes_u32get},
	{"u64get",luabytes_u64get},
	{"s8get",luabytes_s8get},
	{"s16get",luabytes_s16get},
	{"s32get",luabytes_s32get},
	{"s64get",luabytes_s64get},
	{"f32get",luabytes_f32get},
	{"f64get",luabytes_f64get},
	
	{"set",luabytes_set},
	{"u16set",luabytes_u16set},
	{"u32set",luabytes_u32set},
	{"u64set",luabytes_u64set},
	{"s8set",luabytes_s8set},
	{"s16set",luabytes_s16set},
	{"s32set",luabytes_s32set},
	{"s64set",luabytes_s64set},
	{"f32set",luabytes_f32set},
	{"f64set",luabytes_f64set},
	
	{NULL,NULL},
};

int luaopen_luabytes( lua_State *L ) {
	luaL_newlib( L, luabytes_lib );
	return 1;
}
