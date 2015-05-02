#include <stdio.h>

int FindChara(char *string, char find_chara)
{
	int i = 0;
	int result = -1;

	while(1) {
		if(string[i] == '\0') {
			break;
		}
		if(string[i] == find_chara) {
			result = i;
			break;
		}
		i++;
	}

	return result;
}

int main(void)
{
	int index;
	char str[] = "abcdefghijkl";

	// 見つけた場合は配列の要素番号を返す
	index = FindChara(str, 'd');
	printf("index:%d\n", index);

	// 見つからない場合は-1を返す
	index = FindChara(str, 'x');
	printf("index:%d\n", index);

	return 0;
}

