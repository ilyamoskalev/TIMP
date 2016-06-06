#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <stdio.h>



int main()
{
	FILE *in = fopen("input2.txt", "r");
	char buf[100];
	char buf2[100];

	int k = 0;

	int len, len2;

	if (in == NULL)
	{
		printf("File not found\n");
		return 2;
	}

	while (!feof(in))
	{
		fgets(buf, 99, in);

		len = strlen(buf);

		if (strncmp(buf, "/**", 3) == 0)
		{
			if (strncmp(buf + len - 3, "*/", 2) == 0)
			{
				if (strncmp(buf + 4, "\\func", 5) == 0)
				{
					++k;
					strncpy(buf2, buf + 9, len - 12);
					buf2[len - 12] = '\0';
					printf("%d.%s\n", k, buf2);

				}
			}

			else
			{
				bool f = false;
				while (!feof(in) && !f)
				{
					fgets(buf, 99, in);

					int i = 0;
					while (buf[i] == ' ')
						++i;

					len = strlen(buf);

					if (strncmp(buf + len - 3, "*/", 2) == 0)
						f = true;

					if (strncmp(buf + i, "\\func", 5) == 0)
					{
						++k;
						if (f)
							len2 = len - i - 8;
						else
							len2 = len - i - 6;

						strncpy(buf2, buf + i + 5, len2);
						buf2[len2] = '\0';

						printf("%d.%s\n", k, buf2);
					}


				}

				if (!f)
					printf("Error: unexpected end of file\n");

			}
		}

	}

	fclose(in);
	return 0;
}
