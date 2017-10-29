#pragma once

#ifndef RETURNCODES_
#define RETURNCODES_

/*
*  When writing a method that returns void, consider returning a return code instead that you can use for debugging
*/

enum class retcode
{
	success,
	failure,
	null,
	notfound
};

#endif
