#include "task3_3_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main( void )
{
	char *text, *word, *ptr, *wordEnd;
	size_t len;
	char chr, tmpchr;
	puts( "This program search character in a text and print all words, that contain given character." );
	puts( "Enter character(a-z, A-Z, 0-9):" );
	while( 1 )
	{
		chr = (char)getchar();
		if( IsGraph( tmpchr = (char)getchar() ) ) {
			ungetc( tmpchr, stdin );
		}
		if( IsAlnum( chr ) == false )
		{
			puts( "Wrong character, try again:" );
		}
		else
		{
			break;
		}
	}

	text = Input();
	if( text == NULL )
	{
		puts( "Not enough memory." );
		return 1;
	}

	ptr = text;
	while( wordEnd = FindWord( ptr, chr ) )
	{
		len = 1;
		word = wordEnd;
		while( IsAlnum( word[-1] )  && word >= text )
		{
			word--;
			len++;
		}
		word = memcpy( malloc( len + 1 ), word, len );
		if( word == NULL )
		{
			puts( "Memory is not enough" );
			break;
		}
		else
		{
			word[len] = 0;

			printf( "\"%s\" is the word, that contain '%c'\n", word, chr );
			free( word );
		}
		ptr = wordEnd + 1;
	}
	free( text );

	return 0;
}