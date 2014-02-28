/*
 * =====================================================================================
 *
 *       Filename:  Cvartest.c
 *
 *    Description:  Testing localization ranges of variables.
 *
 *        Version:  1.0
 *        Created:  02/26/14 20:06:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/*-----------------------------------------------------------------------------
 *  Invalid declarations are commented out. The reasons why are below:
 *
 *  REASON 1
 *  This is invalid, as declaring an EXTERN variable requires a non-extern
 *  declaration somewhere else in the matching range.
 *-----------------------------------------------------------------------------*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// DECLARATIONS
static string global = "global set!";
static string globext = "globext set!";
void func(void);
void side(void);
void subfunc(void);


// PROGRAM STARTS HERE
int main(void)
{
	static string mainstat = "mainstat set!";
	string mainauto = "mainauto set!";
	// extern string mainext;	/* INVALID */
	// mainext = "mainext set!"; 	/* Reason1 */
	extern string globext;

	printf ( "Printing variable contents: \n" );
	printf ( "var global = '%s'\n", global );
	printf ( "var globext = '%s'\n", globext );
	printf ( "\n" );
	printf ( "var mainstat = '%s'\n", mainstat );
	printf ( "var mainauto = '%s'\n", mainauto );
	printf ( "var mainext = '%s'\n", mainext );
	printf ( "\n" );
	
	for ( int i = 0 ; i < 2; i++ ) {
		string forauto = "forauto set!";
		static string forstatic = "forstatic set!";
		extern string forextern;
		forextern = "forextern set!";

		printf ( "Now inside the for loop!\n" );
		printf ( "var global = '%s'\n", global );
		printf ( "var globext = '%s'\n", globext );
		printf ( "\n" );
		printf ( "var mainstat = '%s'\n", mainstat );
		printf ( "var mainauto = '%s'\n", mainauto );
		printf ( "var mainext = '%s'\n", mainext );
		printf ( "\n" );
		printf ( "var forauto = '%s'\n", forauto );
		printf ( "var forstatic = '%s'\n", forstatic );
		printf ( "var forextern = '%s'\n", forextern );
		printf ( "\n" );
	}
	printf ( "Back in main -- let's do another quick test.\n" );
	extern string forauto; 
	printf ( "var forauto = '%s'\n", forauto );
	extern string forextern;	
	printf ( "var forextern = '%s'\n", forextern );
	printf ( "\n" );

	func();

	printf ( "Back in main! It's the home stretch!\n" );
	printf ( "var global = '%s'\n", global );
	printf ( "var globext = '%s'\n", globext );
	printf ( "\n" );
	printf ( "var mainstat = '%s'\n", mainstat );
	printf ( "var mainauto = '%s'\n", mainauto );
	printf ( "var mainext = '%s'\n", mainext );
	printf ( "\n" );
	printf ( "var forauto = '%s'\n", forauto );
	printf ( "var forextern = '%s'\n", forextern );
	printf ( "\n" );
	extern string funcstat;
	printf ( "var funcstat = '%s'\n", funcstat );
	extern string funcauto;
	printf ( "var funcauto = '%s'\n", funcauto );
	extern string funcext;
	printf ( "var funcext = '%s'\n", funcext );
	printf ( "\n" );
	extern string subfstat;
	printf ( "var subfstat = '%s'\n", subfstat );
	extern string subfauto;
	printf ( "var subfauto = '%s'\n", subfauto );
	extern string subfext;
	printf ( "var subfext = '%s'\n", subfext );
	printf ( "\n" );
	extern string sidestat;
	printf ( "var sidestat = '%s'\n", sidestat );
	extern string sideauto;
	printf ( "var sideauto = '%s'\n", sideauto );
	extern string sideext;
	printf ( "var sideext = '%s'\n", sideext );
	printf ( "\n" );
	printf ( "Done!\n" );
	printf ( "Bye!\n" );
	return 0;
}

void func(void)
{
	static string funcstat = "funcstat set!";
	string funcauto = "funcauto set!";
	extern string funcext;
	funcext = "funcext set!";
	printf ( "Now inside the function!\n" );
	printf ( "\n" );

	side();

	printf ( "Back inside the function!\n" );
	printf ( "var global = '%s'\n", global );
	printf ( "var globext = '%s'\n", globext );
	printf ( "\n" );
	extern string mainstat;
	printf ( "var mainstat = '%s'\n", mainstat );
	extern string mainauto;
	printf ( "var mainauto = '%s'\n", mainauto );
	extern string mainext;
	printf ( "var mainext = '%s'\n", mainext );
	printf ( "\n" );
	extern string forauto;
	printf ( "var forauto = '%s'\n", forauto );
	extern string forextern;
	printf ( "var forextern = '%s'\n", forextern );
	printf ( "\n" );
	printf ( "var funcstat = '%s'\n", funcstat );
	printf ( "var funcauto = '%s'\n", funcauto );
	printf ( "var funcext = '%s'\n", funcext );
	printf ( "\n" );
	extern string sidestat;
	printf ( "var sidestat = '%s'\n", sidestat );
	extern string sideauto;
	printf ( "var sideauto = '%s'\n", sideauto );
	extern string sideext;
	printf ( "var sideext = '%s'\n", sideext );
	printf ( "\n" );

	subfunc();

	printf ( "Back in func()...\n" );
	extern string subfstat;
	printf ( "var subfstat = '%s'\n", subfstat );
	extern string subfauto;
	printf ( "var subfauto = '%s'\n", subfauto );
	extern string subfext;
	printf ( "var subfext = '%s'\n", subfext );
	printf ( "\n" );
	
}


void side(void)
{
	string sideauto = "sideauto set!";
	static string sidestatic = "sidestatic set!";
	extern string sideextern;
	sideextern = "sideextern set!";
	fprintf ( stderr, "mandatory sideauto usage, it's set to %s\n", sideauto );
	fprintf ( stderr, "mandatory sidestatic usage, it's set to %s\n", sidestatic );

	printf ( "Passing through side()...\n" );
	printf ( "(sideauto, sidestatic, and sideextern are set)\n" );
	printf ( "\n" );
}

void subfunc(void)
{
	string subfauto = "subfauto set!";
	static string subfstatic = "subfstatic set!";
	extern string subfextern;
	subfextern = "subfextern set!";
	
	printf ( "Ooh, a subfunction! How exotic!\n" );
	printf ( "var global = '%s'\n", global );
	printf ( "var globext = '%s'\n", globext );
	printf ( "\n" );
	extern string mainstat;
	printf ( "var mainstat = '%s'\n", mainstat );
	extern string mainauto;
	printf ( "var mainauto = '%s'\n", mainauto );
	extern string mainext;
	printf ( "var mainext = '%s'\n", mainext );
	printf ( "\n" );
	extern string forauto;
	printf ( "var forauto = '%s'\n", forauto );
	extern string forextern;
	printf ( "var forextern = '%s'\n", forextern );
	printf ( "\n" );
	extern string funcstat;
	printf ( "var funcstat = '%s'\n", funcstat );
	extern string funcauto;
	printf ( "var funcauto = '%s'\n", funcauto );
	extern string funcext;
	printf ( "var funcext = '%s'\n", funcext );
	printf ( "\n" );
	printf ( "var subfstat = '%s'\n", subfstatic );
	printf ( "var subfauto = '%s'\n", subfauto );
	extern string subfext;
	printf ( "var subfext = '%s'\n", subfext );
	printf ( "\n" );
	extern string sidestat;
	printf ( "var sidestat = '%s'\n", sidestat );
	extern string sideauto;
	printf ( "var sideauto = '%s'\n", sideauto );
	extern string sideext;
	printf ( "var sideext = '%s'\n", sideext );
	printf ( "\n" );
}

