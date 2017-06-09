#include <stdio.h>

int main( int argc, char** argv )
{

	FILE* fpin = fopen("tiles.txt", "r" );
	FILE* fpout = fopen("tiles.out", "w" );

	while( !feof( fpin ) )
	{
		int c = fgetc( fpin );
	    fputc( c, fpout );
		fputc( ',', fpout );
	}

	close( fpin );
	close( fpout );

	return 0;
}
