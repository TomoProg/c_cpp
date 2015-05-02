#include <stdio.h>
#include <string.h>

int Replace(char *src, char *target, char *replace, char *dest)
{
	int i = 0, j = 0;
	int target_len = 0;
	int replace_len = 0;
	char result[1024];
	int result_size = 0;

	// 初期化
	memset(result, 0x00, sizeof(result));

	// 文字列長を取得
	target_len = strlen(target);
	replace_len = strlen(replace);

	// 置換処理
	while(1) {
		if(*(src + i) == '\0') {
			break;
		}

		if(memcmp((src + i), target, target_len) == 0) {
			// 対象文字列の場合
			memcpy(&result[j], replace, replace_len);
			result_size += replace_len;
			i += target_len;
			j += replace_len;
		}
		else {
			// 対象文字でない場合
			memcpy(&result[j], (src + i), 1);
			result_size++;
			i++;
			j++;
		}
	}

	// 取得結果をコピー
	memcpy(dest, result, result_size);

	return 0;
}

int main(void)
{
	char src[] = "abcdefghide";
	char dest[1024];
	char target[] = "de";
	char replace[] = "XXX";

	memset(dest, 0x00, sizeof(dest));
	
	Replace(src, target, replace, dest);
	printf("src:%s\n", src);
	printf("dest:%s\n", dest);

	return 0;
}
