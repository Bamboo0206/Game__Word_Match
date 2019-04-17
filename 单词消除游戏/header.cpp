#include "header.h"

bool operator==(const participant & A, const participant & B)
{
	if (A.name == B.name)
		return true;
	else
		return false;
}
