
# include <limits.h>
# include <string.h>
# include <stdio.h>

# define SIZECHAR 256


int max (int a, int b) { return (a > b)? a: b; }


void harspool( char *str, int size, 
						int bchar[SIZECHAR])
{
	int i;


	for (i = 0; i < SIZECHAR; i++)
		bchar[i] = -1;

	
	for (i = 0; i < size; i++)
		bchar[(int) str[i]] = i;
}

void search( char *txt, char *pat)
{
	int m = strlen(pat);
	int n = strlen(txt);

	int bchar[SIZECHAR];
	harspool(pat, m, bchar);

	int s = 0; 
	while(s <= (n - m))
	{
		int j = m-1;
		while(j >= 0 && pat[j] == txt[s+j])
			j--;

	
		if (j < 0)
		{
			printf("\n pattern occurs at shift = %d", s+1);
			s += (s+m < n)? m-bchar[txt[s+m]] : 1;

		}

		else
	
			s += max(1, j - bchar[txt[s+j]]);
	}
}


int main()
{
	char txt[] = "JIM SAW ME IN BARBER SHOP";
	char pat[] = "BARBER";
	search(txt, pat);
	return 0;
}
