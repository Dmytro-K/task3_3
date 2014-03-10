#include "task3_3_funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char* StrChr( const char* str, char c )
{
	if( str == NULL ) {
		return NULL;
	}

	while( *str ) {
		if( *str == c ) {
			return (char*)str;
		}
		str++;
	}
	return NULL;
}

size_t StrLen( const char* str )
{
	size_t i;
	if( str == NULL ) {
		return 0;
	}
	for( i = 0; *str != 0; i++, str++ ) {
		; /* NULL */
	}
	return i;
}

bool IsGraph( char chr )
{
	return ( chr >= 0x21 ) && ( chr <= 0x7E );
}

bool IsDigit( char chr )
{
	return ( chr >= 0x30 ) && ( chr <= 0x39 );
}

bool IsUpper( char chr )
{
	return ( chr >= 0x41 ) && ( chr <= 0x5A );
}

bool IsLower( char chr )
{
	return ( chr >= 0x61 ) && ( chr <= 0x7A );
}

bool IsAlpha( char chr )
{
	return IsUpper( chr ) || IsLower( chr );
}

bool IsAlnum( char chr )
{
	return IsDigit( chr ) || IsAlpha( chr );
}

char* FindWord( const char* str, char chr )
{
	const char *word, *wordEnd;

	if( str == NULL ) {
		return 0;
	}

	word = StrChr( str, chr );
	if( word == NULL )
	{
		return NULL;
	}
	wordEnd = word + 1;
	while( *wordEnd )
	{
		if( !IsAlnum( *wordEnd ) )
		{
			break;
		}
		wordEnd++;
	}
	return (char*)wordEnd - 1;
}

#define BUF_LEN 256

char* Input( void )
{
	char buffer[BUF_LEN];
	char *str=NULL;
	size_t lastLen;

	puts( "Enter some text( enter empty line for end ):" );
	
	lastLen = 0;

	for( ; ; )
	{
		size_t len;
		char *tmp;
		fgets( buffer, BUF_LEN, stdin );
		len = StrLen( buffer );
		//buffer[len - 1] = 0;

		if( len == 1 )
		{
			break;
		}

		if( buffer[len - 1] == '\n' )
		{
			len--;
		}

		tmp = realloc( str, lastLen + len + 1 );
		if( tmp == NULL )
		{
			free( str );
			return NULL;
		} 
		else
		{
			str = tmp;
		}
		memcpy( str + lastLen, buffer, len );
		lastLen += len;
		str[lastLen] = 0;
	}

	return str;
}

#undef BUF_LEN