// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool p, q, s;
	switch (p)
	{
	case 0:switch (q)
				{
					case 0:switch (s)
								{
								case 0://st1
								default://st1 & st2
								break;
								}
					case 1:switch (s)
								{
								case 0://st2 & st3
								default://st3 & st1
								break;
								}
				break;
				}

	case 1:switch (q)
				{
					case 0:switch (s)
								{
								case 0://st3
								default://st1 & st2 & st3
								break;
								}
					case 1:switch (s)
								{
								case 0://st1
								default://st2
								break;
								}
				
				break;
				}
		break;
	}
return 0;
}