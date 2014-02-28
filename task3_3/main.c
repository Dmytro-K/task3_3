#include "task3_3_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main( void )
{
	char *text, *word, *ptr, *wordEnd;
	size_t len;
	char chr, tmpchr;

	puts("Enter character:");
	chr = (char)getchar();
	if( IsGraph( tmpchr = (char)getchar() ) )
	{
		ungetc( tmpchr, stdin );
	}

	text = Input();
	if( text == NULL )
	{
		puts( "Something wrong" );
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